#include <bitmap.hpp>
#include <wx/rawbmp.h>

void uva::wx::bitmap::for_each_pixel(wxBitmap& bitmap, void(*f)(const uva::color&, void*), void* data) {
    wxAlphaPixelData rgba_data(bitmap);
    wxAlphaPixelData::Iterator it = rgba_data.GetPixels();

    for(size_t y = 0; y < rgba_data.GetHeight(); ++y)
    {
        wxAlphaPixelData::Iterator row_start = it;

        for(size_t x = 0; x < rgba_data.GetWidth(); ++x, it++)
        {
            uva::color c(it.Red(), it.Green(), it.Blue(), it.Alpha());
            f(c, data);
        }

        it = row_start;
        it.OffsetY(rgba_data, 1);
    }
}

uva::image uva::wx::bitmap::to_image(wxBitmap& bitmap)
{
    uva::image image;
    image.create({bitmap.GetWidth(),bitmap.GetHeight()});

    struct image_iterator {
        uva::color* colors;
        size_t index;
    };

    image_iterator it = { image.data(), 0 };

    uva::wx::bitmap::for_each_pixel(bitmap, [](const uva::color& c, void* data) {
        image_iterator* self = (image_iterator*)data;
        self->colors[self->index] = c;
        ++(self->index);
    }, &it);

    return image;
}

wxBitmap uva::wx::bitmap::to_image(uva::image& image)
{
    wxBitmap bitmap(image.getWidth(), image.getHeight(), 32);

    // struct image_iterator {
    //     uva::color* colors;
    //     size_t index;
    // };

    // image_iterator it = { image.data(), 0 };

    // uva::wx::bitmap::for_each_pixel(bitmap, [](const uva::color& c, void* data) {
    //     image_iterator* self = (image_iterator*)data;
    //     self->colors[self->index] = c;
    //     ++(self->index);
    // }, &it);

    return bitmap;
}

uva::drawing::palette uva::wx::bitmap::extract_colors(wxBitmap& bitmap)
{
    uva::drawing::palette colors;

    struct image_iterator {
        uva::drawing::palette* palette;
    };

    image_iterator it = { &colors };

    uva::wx::bitmap::for_each_pixel(bitmap, [](const uva::color& c, void* data) {
        image_iterator* it = (image_iterator*)data;

        it->palette->push(c);
    }, &it);

    return colors;
}
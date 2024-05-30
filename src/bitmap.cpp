#include <wx/rawbmp.h>

#include <uva/image.hpp>
#include <uva/wx/bitmap.hpp>

void uva::wx::bitmap::for_each_pixel(wxBitmap& bitmap, void(*f)(uva::color&, void*), void* data) {
    if(bitmap.GetDepth() != 32)
    {
        bitmap.UseAlpha(true);
        bitmap.ResetAlpha();
    }

    if(bitmap.GetDepth() != 32)
    {
        wxMessageBox(L"Error: cannot convert tile palette to 32 bits", L"Warning", wxICON_ERROR);
        return;
    }

    wxAlphaPixelData rgba_data(bitmap);
    wxAlphaPixelData::Iterator it = rgba_data.GetPixels();

    for(size_t y = 0; y < rgba_data.GetHeight(); ++y)
    {
        wxAlphaPixelData::Iterator row_start = it;

        for(size_t x = 0; x < rgba_data.GetWidth(); ++x, it++)
        {
            uva::color c(it.Red(), it.Green(), it.Blue(), it.Alpha());
            f(c, data);
            it.Red()   = c.r;
            it.Green() = c.g;
            it.Blue()  = c.b;
            it.Alpha() = c.a;
        }

        it = row_start;
        it.OffsetY(rgba_data, 1);
    }
}

uva::image uva::wx::bitmap::to_image(wxBitmap& bitmap)
{
    uva::image image({bitmap.GetWidth(),bitmap.GetHeight()});

    struct image_iterator {
        uva::color* colors;
        size_t index;
    };

    image_iterator it = { image.data(), 0 };

    uva::wx::bitmap::for_each_pixel(bitmap, [](uva::color& c, void* data) {
        image_iterator* self = (image_iterator*)data;
        self->colors[self->index] = c;
        ++(self->index);
    }, &it);

    return image;
}

wxBitmap uva::wx::bitmap::to_bitmap(const uva::image& image)
{
    wxBitmap bitmap(image.width(), image.height(), 32);

    struct image_iterator {
        uva::color* colors;
        size_t index;
    } it;

    it.colors = image.data();
    it.index = 0;

    uva::wx::bitmap::for_each_pixel(bitmap, [](uva::color& pixel, void* data) {
        image_iterator* it = (image_iterator*)data;
        uva::color* c = it->colors + it->index;

        pixel.r = c->r;
        pixel.g = c->g;
        pixel.b = c->b;
        pixel.a = c->a;

        it->index++;
    }, &it);

    return bitmap;
}

void uva::wx::bitmap::clear(wxBitmap &bitmap, uva::color color)
{
    uva::wx::bitmap::for_each_pixel(bitmap, [](uva::color& pixel, void* data) {
        pixel = *(uva::color*)data;
    }, &color);
}
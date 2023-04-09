#include <wx/wx.h>
#include <color.hpp>
#include <image.hpp>
#include <drawing.hpp>

namespace uva
{
    namespace wx
    {
        //platform independent bitmap manipulation
        namespace bitmap
        {
            void for_each_pixel(wxBitmap& bitmap, void(*f)(const uva::color&, void*), void* data = nullptr);
            uva::image to_image(wxBitmap& bitmap);
            wxBitmap to_image(uva::image& image);
            uva::drawing::palette extract_colors(wxBitmap& bitmap);
        } // namespace bitmap
        
    } // namespace wx
    
} // namespace uva

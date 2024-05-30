#pragma once

#include <wx/wx.h>
#include <uva/color.hpp>
#include <uva/image.hpp>

namespace uva
{
    namespace wx
    {
        //platform independent bitmap manipulation
        namespace bitmap
        {
            void for_each_pixel(wxBitmap& bitmap, void(*f)(uva::color&, void*), void* data = nullptr);
            uva::image to_image(wxBitmap& bitmap);
            wxBitmap   to_bitmap(const uva::image& image);
            void       clear(wxBitmap& bitmap, uva::color color);
        } // namespace bitmap
        
    } // namespace wx
    
} // namespace uva

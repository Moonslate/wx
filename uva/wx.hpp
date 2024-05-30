#include <wx/wx.h>

#include <uva/wx/bitmap.hpp>
#include <uva/color.hpp>
#include <uva/core.hpp>

namespace uva
{
    namespace wx
    {
        wxString to_wxstring(const var& v);
        wxColour to_wxcolour(const color& c);
        wxSize   to_wxsize(const uva::size& s);
    }; // namespace wx
    
}; // namespace uvaw
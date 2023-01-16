#include <wx/wx.h>
#include <core.hpp>
#include <color.hpp>

namespace uva
{
    namespace wx
    {
        wxString to_wxstring(const var& v);
        wxColour to_wxcolour(const color& c);
    }; // namespace wx
    
}; // namespace uva

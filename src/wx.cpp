#include "wx.hpp"

wxString uva::wx::to_wxstring(const var &v)
{
    if(v.is_a<var::string>()) {
        return wxString(v.as<var::string>().c_str(), wxMBConvUTF8(), v.as<var::string>().size());
    }

    return v.to_s();
}

wxColour uva::wx::to_wxcolour(const color &c)
{
    return wxColour(c.r, c.g, c.b, c.a);
}

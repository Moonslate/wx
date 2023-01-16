#include "wx.hpp"

wxString uva::wx::to_wxstring(const var &v)
{
    if(v.type == var::var_type::string) {
        return wxString(v.as<var::var_type::string>().c_str(), wxMBConvUTF8(), v.as<var::var_type::string>().size());
    }

    return v.to_s();
}

wxColour uva::wx::to_wxcolour(const color &c)
{
    return wxColour(c.r, c.g, c.b, c.a);
}

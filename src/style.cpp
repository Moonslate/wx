#include "style.hpp"

using namespace uva;

static std::map<wxString, var> s_palette = {
    { "foreground",     color(0, 0, 0) },
    { "background",     color(255, 255, 255) },
    { "shadow",         color(128, 128, 128) },
    { "border_radius",  0                    },
};

void uva::wx::style::set_stylesheet(const std::map<wxString, var> &palette)
{
    s_palette = palette;
}

var &uva::wx::style::get_style(const wxString &index)
{
    auto it = s_palette.find(index);
    if(it == s_palette.end()) {
        throw std::runtime_error(std::format("error: {} not found in current palette.", index));
    }

    return it->second;
}

void uva::wx::style::set_style(const wxString &index, const var &style)
{
    s_palette[index] = style;
}

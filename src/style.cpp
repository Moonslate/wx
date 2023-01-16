#include "style.hpp"

using namespace uva;

static std::map<std::string, var> s_stylesheet = {
    { "foreground",     color(0, 0, 0) },
    { "background",     color(255, 255, 255) },
    { "shadow",         color(128, 128, 128) },
    { "border_radius",  0                    },
    { "border_radius",  0                    },
    { "control_height", 32                    },
};

void uva::wx::style::set_stylesheet(const std::map<std::string, var> &stylesheet)
{
    s_stylesheet = stylesheet;
}

var &uva::wx::style::get_style(const std::string &index)
{
    auto it = s_stylesheet.find(index);
    if(it == s_stylesheet.end()) {
        throw std::runtime_error(std::format("error: {} not found in current stylesheet.", index));
    }

    return it->second;
}

void uva::wx::style::set_style(const std::string &index, const var &style)
{
    s_stylesheet[index] = style;
}

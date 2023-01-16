#pragma once

#include <wx/wx.h>
#include <string>
#include <vector>
#include <map>

#include <format.hpp>
#include <core.hpp>

namespace uva
{
    namespace wx
    {
        namespace style
        {
            void set_stylesheet(const std::map<std::string, var>& palette);
            var& get_style(const std::string& index);
            void set_style(const std::string& index, const var& style);
        };
    }; // namespace wx
    
}; // namespace uva

#include <wx/wx.h>
#include <array>

#include <core.hpp>

namespace uva
{
    namespace wx
    {
        class basic_button : public wxWindow
        {
        protected:
            wxString m_foreground;
            wxString m_background;
            wxString m_shadow;
            wxString m_border_radius;
            wxString m_title;
        public:
            basic_button(wxWindow* parent, wxWindowID id, const wxString& title, const wxString& border_radius = "border_radius", const wxString& foreground = "foreground", const wxString& background = "background", const wxString& shadow = "shadow");
        }; // class button
        
    }; // namespace wx
    
}; // namespace uva

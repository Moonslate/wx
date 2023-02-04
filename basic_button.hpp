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
            basic_button(wxWindow* parent, wxWindowID id, const wxString& title, std::map<var, var>&& __styles);
        }; // class button

        class primary_button : public basic_button
        { 
        public:
            primary_button(wxWindow* parent, wxWindowID id, const wxString& title)
                : basic_button(parent, id, title, {
                    { "foreground", "white" },
                    { "background", "primary-color" },
                    { "shadow",     "primary-color-darker" },
                })
            {

            }
        };
        
    }; // namespace wx
    
}; // namespace uva

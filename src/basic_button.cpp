#include "basic_button.hpp"

#include <wx/graphics.h>

#include <wx.hpp>
#include <core.hpp>
#include <style.hpp>

using namespace uva;
using namespace wx;

basic_button::basic_button(wxWindow* parent, wxWindowID id, const wxString& title, const var& styles)
    : wxWindow(parent, id)
{

    int m_height = style::get_style(styles.fetch("control_height", "control_height"));
    wxSize text_extent = GetTextExtent(title);

    int width = styles.fetch("width", -1);

    wxColour foreground = to_wxcolour(style::get_style(styles.fetch("foreground", "foreground")));
    wxColour background = to_wxcolour(style::get_style(styles.fetch("background", "background")));
    wxColour shadow = to_wxcolour(style::get_style(styles.fetch("shadow", "shadow")));

    size_t border_radius = style::get_style(styles.fetch("border_radius", "border_radius"));

    if(width == std::string::npos) {
        width = text_extent.GetWidth();
        width *= 2;
    }

    SetMinSize({width, m_height});

    SetBackgroundStyle(wxBackgroundStyle::wxBG_STYLE_CUSTOM);

    Bind(wxEVT_PAINT, [=,this](wxPaintEvent& event) {
        wxPaintDC dc(this);

        wxSize my_size = GetSize();

        dc.SetBrush(wxBrush(background, wxBRUSHSTYLE_SOLID));
        dc.SetPen(*wxTRANSPARENT_PEN);
        dc.DrawRoundedRectangle(0,0,my_size.x,my_size.y, border_radius);
        dc.SetTextForeground(foreground);
        dc.DrawText(title, (my_size.GetWidth() - text_extent.x) / 2, (my_size.GetHeight() - text_extent.y) / 2);

        event.Skip();
    });
}
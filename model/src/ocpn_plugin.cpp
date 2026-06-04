/***************************************************************************
 *   Copyright (C) 2010 by David S. Register                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <https://www.gnu.org/licenses/>. *
 **************************************************************************/

/**
 * \file
 *
 * Partial ocpn_plugin.h implementation -- aisnesia_plugin and later versions,
 * some utilities
 */

#include "config.h"

#include <algorithm>
#include <set>
#include <typeinfo>
#include <unordered_map>

#include <wx/wx.h>
#include <wx/arrstr.h>
#include <wx/dc.h>
#include <wx/dcmemory.h>
#include <wx/event.h>
#include <wx/glcanvas.h>
#include <wx/notebook.h>
#include <wx/string.h>
#include <wx/window.h>

#include "ocpn_plugin.h"

//-----------------------------------------------------------------------------------------
//    The aisnesia_plugin base class implementation
//-----------------------------------------------------------------------------------------

/**  FIXME
static wxBitmap* LoadSVG(const wxString filename, unsigned int width,
                         unsigned int height) {
  if (!gFrame) return new wxBitmap(width, height);  // We are headless.
#ifdef __ANDROID__
  return loadAndroidSVG(filename, width, height);
#elif defined(ocpnUSE_SVG)
  wxSVGDocument svgDoc;
  if (svgDoc.Load(filename))
    return new wxBitmap(svgDoc.Render(width, height, NULL, true, true));
  else
    return new wxBitmap(width, height);
#else
  return new wxBitmap(width, height);
#endif
}


wxBitmap* aisnesia_plugin::GetPlugInBitmap() {
  auto bitmap =  PluginLoader::GetInstance()->GetPluginDefaultIcon();
  return const_cast<wxBitmap*>(bitmap);
}

**/

wxBitmap* aisnesia_plugin::GetPlugInBitmap() {
  static wxBitmap* bitmap = 0;
  if (!bitmap) bitmap = new wxBitmap(1, 1);
  return bitmap;
}

aisnesia_plugin::~aisnesia_plugin() {}

int aisnesia_plugin::Init() { return 0; }

bool aisnesia_plugin::DeInit() { return true; }

int aisnesia_plugin::GetAPIVersionMajor() { return 1; }

int aisnesia_plugin::GetAPIVersionMinor() { return 2; }

int aisnesia_plugin::GetPlugInVersionMajor() { return 1; }

int aisnesia_plugin::GetPlugInVersionMinor() { return 0; }

wxString aisnesia_plugin::GetCommonName() { return "BaseClassCommonName"; }

wxString aisnesia_plugin::GetShortDescription() {
  return "AISNESIA PlugIn Base Class";
}

wxString aisnesia_plugin::GetLongDescription() {
  return "AISNESIA PlugIn Base Class\n\
PlugInManager created this base class";
}

void aisnesia_plugin::SetPositionFix(PlugIn_Position_Fix& pfix) {}

void aisnesia_plugin::SetNMEASentence(wxString& sentence) {}

void aisnesia_plugin::SetAISSentence(wxString& sentence) {}

int aisnesia_plugin::GetToolbarToolCount() { return 0; }

int aisnesia_plugin::GetToolboxPanelCount() { return 0; }

void aisnesia_plugin::SetupToolboxPanel(int page_sel, wxNotebook* pnotebook) {}

void aisnesia_plugin::OnCloseToolboxPanel(int page_sel, int ok_apply_cancel) {}

void aisnesia_plugin::ShowPreferencesDialog(wxWindow* parent) {}

void aisnesia_plugin::OnToolbarToolCallback(int id) {}

void aisnesia_plugin::OnContextMenuItemCallback(int id) {}

bool aisnesia_plugin::RenderOverlay(wxMemoryDC* dc, PlugIn_ViewPort* vp) {
  return false;
}

void aisnesia_plugin::SetCursorLatLon(double lat, double lon) {}

void aisnesia_plugin::SetCurrentViewPort(PlugIn_ViewPort& vp) {}

void aisnesia_plugin::SetDefaults() {}

void aisnesia_plugin::ProcessParentResize(int x, int y) {}

void aisnesia_plugin::SetColorScheme(PI_ColorScheme cs) {}

void aisnesia_plugin::UpdateAuiStatus() {}

wxArrayString aisnesia_plugin::GetDynamicChartClassNameArray() {
  wxArrayString array;
  return array;
}

//    Opencpn_Plugin_16 Implementation
aisnesia_plugin_16::aisnesia_plugin_16(void* pmgr) : aisnesia_plugin(pmgr) {}

aisnesia_plugin_16::~aisnesia_plugin_16() {}

bool aisnesia_plugin_16::RenderOverlay(wxDC& dc, PlugIn_ViewPort* vp) {
  return false;
}

void aisnesia_plugin_16::SetPluginMessage(wxString& message_id,
                                         wxString& message_body) {}

//    Opencpn_Plugin_17 Implementation
aisnesia_plugin_17::aisnesia_plugin_17(void* pmgr) : aisnesia_plugin(pmgr) {}

aisnesia_plugin_17::~aisnesia_plugin_17() {}

bool aisnesia_plugin_17::RenderOverlay(wxDC& dc, PlugIn_ViewPort* vp) {
  return false;
}

bool aisnesia_plugin_17::RenderGLOverlay(wxGLContext* pcontext,
                                        PlugIn_ViewPort* vp) {
  return false;
}

void aisnesia_plugin_17::SetPluginMessage(wxString& message_id,
                                         wxString& message_body) {}

//    Opencpn_Plugin_18 Implementation
aisnesia_plugin_18::aisnesia_plugin_18(void* pmgr) : aisnesia_plugin(pmgr) {}

aisnesia_plugin_18::~aisnesia_plugin_18() {}

bool aisnesia_plugin_18::RenderOverlay(wxDC& dc, PlugIn_ViewPort* vp) {
  return false;
}

bool aisnesia_plugin_18::RenderGLOverlay(wxGLContext* pcontext,
                                        PlugIn_ViewPort* vp) {
  return false;
}

void aisnesia_plugin_18::SetPluginMessage(wxString& message_id,
                                         wxString& message_body) {}

void aisnesia_plugin_18::SetPositionFixEx(PlugIn_Position_Fix_Ex& pfix) {}

//    Opencpn_Plugin_19 Implementation
aisnesia_plugin_19::aisnesia_plugin_19(void* pmgr) : aisnesia_plugin_18(pmgr) {}

aisnesia_plugin_19::~aisnesia_plugin_19() {}

void aisnesia_plugin_19::OnSetupOptions() {}

//    Opencpn_Plugin_110 Implementation
aisnesia_plugin_110::aisnesia_plugin_110(void* pmgr) : aisnesia_plugin_19(pmgr) {}

aisnesia_plugin_110::~aisnesia_plugin_110() {}

void aisnesia_plugin_110::LateInit() {}

//    Opencpn_Plugin_111 Implementation
aisnesia_plugin_111::aisnesia_plugin_111(void* pmgr) : aisnesia_plugin_110(pmgr) {}

aisnesia_plugin_111::~aisnesia_plugin_111() {}

//    Opencpn_Plugin_112 Implementation
aisnesia_plugin_112::aisnesia_plugin_112(void* pmgr) : aisnesia_plugin_111(pmgr) {}

aisnesia_plugin_112::~aisnesia_plugin_112() {}

bool aisnesia_plugin_112::MouseEventHook(wxMouseEvent& event) { return false; }

void aisnesia_plugin_112::SendVectorChartObjectInfo(
    wxString& chart, wxString& feature, wxString& objname, double lat,
    double lon, double scale, int nativescale) {}

//    Opencpn_Plugin_113 Implementation
aisnesia_plugin_113::aisnesia_plugin_113(void* pmgr) : aisnesia_plugin_112(pmgr) {}

aisnesia_plugin_113::~aisnesia_plugin_113() {}

bool aisnesia_plugin_113::KeyboardEventHook(wxKeyEvent& event) { return false; }

void aisnesia_plugin_113::OnToolbarToolDownCallback(int id) {}
void aisnesia_plugin_113::OnToolbarToolUpCallback(int id) {}

//    Opencpn_Plugin_114 Implementation
aisnesia_plugin_114::aisnesia_plugin_114(void* pmgr) : aisnesia_plugin_113(pmgr) {}

aisnesia_plugin_114::~aisnesia_plugin_114() {}

//    Opencpn_Plugin_115 Implementation
aisnesia_plugin_115::aisnesia_plugin_115(void* pmgr) : aisnesia_plugin_114(pmgr) {}

aisnesia_plugin_115::~aisnesia_plugin_115() {}

//    Opencpn_Plugin_116 Implementation
aisnesia_plugin_116::aisnesia_plugin_116(void* pmgr) : aisnesia_plugin_115(pmgr) {}

aisnesia_plugin_116::~aisnesia_plugin_116() {}

bool aisnesia_plugin_116::RenderGLOverlayMultiCanvas(wxGLContext* pcontext,
                                                    PlugIn_ViewPort* vp,
                                                    int max_canvas) {
  return false;
}

bool aisnesia_plugin_116::RenderOverlayMultiCanvas(wxDC& dc, PlugIn_ViewPort* vp,
                                                  int max_canvas) {
  return false;
}

void aisnesia_plugin_116::PrepareContextMenu(int canvasIndex) { return; }

//    Opencpn_Plugin_117 Implementation
aisnesia_plugin_117::aisnesia_plugin_117(void* pmgr) : aisnesia_plugin_116(pmgr) {}

int aisnesia_plugin_117::GetPlugInVersionPatch() { return 0; };

int aisnesia_plugin_117::GetPlugInVersionPost() { return 0; };

const char* aisnesia_plugin_117::GetPlugInVersionPre() { return ""; };

const char* aisnesia_plugin_117::GetPlugInVersionBuild() { return ""; };

void aisnesia_plugin_117::SetActiveLegInfo(Plugin_Active_Leg_Info& leg_info) {}

//    Opencpn_Plugin_118 Implementation
aisnesia_plugin_118::aisnesia_plugin_118(void* pmgr) : aisnesia_plugin_117(pmgr) {}

bool aisnesia_plugin_118::RenderGLOverlayMultiCanvas(wxGLContext* pcontext,
                                                    PlugIn_ViewPort* vp,
                                                    int max_canvas,
                                                    int priority) {
  return false;
}

bool aisnesia_plugin_118::RenderOverlayMultiCanvas(wxDC& dc, PlugIn_ViewPort* vp,
                                                  int max_canvas,
                                                  int priority) {
  return false;
}

//    Opencpn_Plugin_119 Implementation
aisnesia_plugin_119::aisnesia_plugin_119(void* pmgr) : aisnesia_plugin_118(pmgr) {}

void aisnesia_plugin_119::PreShutdownHook() { return; }

//    Opencpn_Plugin_120 Implementation
aisnesia_plugin_120::aisnesia_plugin_120(void* pmgr) : aisnesia_plugin_119(pmgr) {}

void aisnesia_plugin_120::OnContextMenuItemCallbackExt(int id,
                                                      std::string obj_ident,
                                                      std::string obj_type,
                                                      double lat, double lon) {}

//    Opencpn_Plugin_121 Implementation
aisnesia_plugin_121::aisnesia_plugin_121(void* pmgr) : aisnesia_plugin_120(pmgr) {}

void aisnesia_plugin_121::UpdateFollowState(int canvas_index, bool state) {}

void aisnesia_plugin_121::OnTideCurrentClick(TCClickInfo info) {}

DateTimeFormatOptions::DateTimeFormatOptions()
    : format_string("$weekday_short_date_time"),
      time_zone(""),
      show_timezone(true),
      longitude(NAN),
      version(1) {}

DateTimeFormatOptions::~DateTimeFormatOptions() {}

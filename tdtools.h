#ifndef GTKMM_TDTOOLS_H
#define GTKMM_TDTOOLS_H

#include <gtkmm.h>
#include "tdmap.h"

class TDTools : public Gtk::Window {
public:

	TDTools();
	virtual ~TDTools();

protected:
	
	Gtk::HBox m_Box;
	Gtk::ToolPalette m_Tools;
	TDMap m_Map;
};

#endif

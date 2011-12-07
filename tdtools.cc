#include "tdtools.h"
//#include "tdmap.cc"

TDTools::TDTools() : m_Box(false,6) {

	//set_size_request(950,466);
	set_border_width(20);

	add(m_Box);

	m_Box.pack_start(m_Map);
	m_Box.pack_start(m_Tools);

	show_all_children();
}

TDTools::~TDTools() {}

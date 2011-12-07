/* CSE 240 Assignment 6
 * Christopher Barnes  |  Frank Liu
 * ctbarne1@asu.edu    |  fwliu@asu.edu
 */

#include "tdmap.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <iostream>

TDMap::TDMap() {
  
  // Retrieves image from file
  m_image = Gdk::Pixbuf::create_from_file("MAP1 SW TD.png");

  // Sets the size of the window to fit entire image
  set_size_request(m_image->get_width(), m_image->get_height());
}

TDMap::~TDMap() {}

bool TDMap::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

  // Retrieves the sizes allocated for the height and width
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // Draws image and keeps it centered with resize
  Gdk::Cairo::set_source_pixbuf(cr, m_image,
				(width - m_image->get_width())/2, 
				(height - m_image->get_height())/2);
  cr->paint();

  return true;
}

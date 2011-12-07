/* CSE 240 Assignment 6
 * Christopher Barnes  |  Frank Liu
 * ctbarne1@asu.edu    |  fwliu@asu.edu
 */

#ifndef GTKMM_TDMAP_H
#define GTKMM_TDMAP_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>


class TDMap : public Gtk::DrawingArea {
public:
  TDMap();
  virtual ~TDMap();

protected:
  // Overrides default signal handler:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

  Glib::RefPtr<Gdk::Pixbuf> m_image;
};

#endif

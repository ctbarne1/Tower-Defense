/* CSE 240 Assignment 6
 * Christopher Barnes  |  Frank Liu
 * ctbarne1@asu.edu    |  fwliu@asu.edu
 */

#ifndef GTKMM_TDWINDOW_H
#define GTKMM_TDWINDOW_H

#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/socket.h>
#include <gtkmm.h>
#include <SDL/SDL.h>

class TDWindow : public Gtk::DrawingArea {
public:
  TDWindow(int argc, char** argv);
  virtual ~TDWindow();
  
  virtual bool bucleSDL();
  virtual void clear(void);
  virtual void ejecutar();
  virtual SDL_Surface* obtSuperficie();

private:
	Gtk::Main m_main;
	Gtk::Socket m_socket; 
	Gtk::Window m_window; 
	Gtk::VBox m_vbox; 
	SDL_Surface * m_superficie; 

  // Overrides default signal handler:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

  Glib::RefPtr<Gdk::Pixbuf> m_image;
  
  
};

#endif

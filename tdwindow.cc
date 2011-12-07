/* CSE 240 Assignment 6
 * Christopher Barnes  |  Frank Liu
 * ctbarne1@asu.edu    |  fwliu@asu.edu
 */

#include "tdwindow.h"
#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <glib.h>
#include <SDL/SDL.h>

#include <iostream>
#include <sstream>

using namespace std;

TDWindow::TDWindow(int argc, char ** argv) : m_main(&argc, &argv), m_superficie(0) { 
	m_window.set_title("Ventana SDL"); 
	m_socket.set_size_request(320,200); 
	m_window.set_border_width(6); 
  
  // Retrieves image from file
  m_image = Gdk::Pixbuf::create_from_file("MAP1 SW TD.png");

  // Sets the size of the window to fit entire image
  set_size_request(m_image->get_width(), m_image->get_height());
  
  //bool bucleSDL();
  //void ejecutar();
}

bool TDWindow::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

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

bool TDWindow::bucleSDL(){ 
		SDL_Event event; 
		SDL_Surface *display = this->m_superficie; 
		while ( SDL_PollEvent( &event ) ) { 
		// Handle quit event, not sure if this will ever appear 
		if ( event.type == SDL_QUIT ) return FALSE; 
		// Handle clear userevent 
		if ( event.type == SDL_USEREVENT && event.user.code == 0 ) { 
			SDL_FillRect( display, NULL, 0 ); 
			SDL_Flip( display ); 
		} 

		// Handle draw rect userevent 
		if ( event.type == SDL_USEREVENT && event.user.code == 1 ) { 
			SDL_Rect rect; 

			rect.x = rand() % 320; 
			rect.y = rand() % 200; 
			rect.w = rand() % 100 + 10; 
			rect.h = rand() % 100 + 10; 
	
			SDL_FillRect( display, &rect, SDL_MapRGB( display->format, 
			rand()%255, rand()%255, rand()%255 ) ); 
			SDL_Flip( display ); 
		} 
	} 
	// Forzar a que se dibuje un cuadrado nuevo 
	event.type = SDL_USEREVENT; 
	event.user.code = 1; 
	SDL_PushEvent( &event ); 

	return true; 
	} 

void TDWindow::clear(void) { 
	/* Put clear userevent on queue */ 
	SDL_Event event;
	event.type = SDL_USEREVENT; 
	event.user.code = 0; 
	SDL_PushEvent( &event ); 
} 

void TDWindow::ejecutar() { 

	m_vbox.pack_start(m_socket, false, false); 

	m_window.add(m_vbox); 
	m_window.show_all(); 

	stringstream sdlhack; 
	sdlhack << "SDL_WINDOWID=" << m_socket.get_id() << endl; 

	char* winhack=new char[32]; 
	sprintf(winhack,sdlhack.str().c_str()); 
	SDL_putenv(winhack); 

	if (SDL_Init(SDL_INIT_VIDEO)) 
		throw runtime_error("Error al inicializar la SDL"); 
	else{ 
		m_superficie = SDL_SetVideoMode(320, 200, 0, 0); 
		clear(); 
	} 


	Glib::signal_timeout().connect(sigc::mem_fun	(*this,&TDWindow::bucleSDL), 5);
 
	// Use this for global (non class) functions: 
	// Glib::signal_timeout().connect(sigc::ptr_fun(&bucleSDL), 	100); 

	m_main.run(m_window); 
} 


TDWindow::~TDWindow() { 
	if (m_superficie) SDL_FreeSurface(m_superficie); 
} 

SDL_Surface* TDWindow::obtSuperficie() {
	return m_superficie;
} 




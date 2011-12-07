/* CSE 240 Assignment 6
 * Christopher Barnes  |  Frank Liu
 * ctbarne1@asu.edu    |  fwliu@asu.edu
 *
 * Description: This program uses the gtkmm(C++) library to display a window
 *              to hold a map for a version of the game, Tower Defense.
 */

#include "tdwindow.h"
#include <gtkmm/main.h>
#include <gtkmm/window.h>

int main(int argc, char** argv) {

	TDWindow app(argc, argv); 

	app.ejecutar();
/*
	Gtk::Main kit(argc, argv);

	Gtk::Window win;
	win.set_title("Tower Defense Map");
	//win.set_default_size(740, 466);
	win.set_border_width(6);

	TDWindow win_Area;
	win.add(win_Area);
	win_Area.show();

	Gtk::Main::run(win);

	return 0;
	*/
}

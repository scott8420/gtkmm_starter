#ifndef __UTILITIES__
#define __UTILITIES__

#include <gtkmm.h>

class Utilities {
public:
	Utilities(){}

	static void alert_message(Gtk::Window*, Glib::ustring, Glib::ustring);

};

#endif
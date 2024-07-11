#include <utilities.h>

void Utilities::alert_message(Gtk::Window* parent, Glib::ustring message, Glib::ustring detail) {
	Glib::RefPtr<Gtk::AlertDialog> dlg = Gtk::AlertDialog::create();

	dlg->set_modal(true);
	dlg->set_buttons({});
    dlg->set_default_button(-1);
    dlg->set_cancel_button(-1);
	dlg->set_message(message);
	dlg->set_detail(detail);
	dlg->show(*parent);
}
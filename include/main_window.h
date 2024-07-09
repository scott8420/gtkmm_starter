#ifndef __MAIN_WINDOW__
#define __MAIN_WINDOW__

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
	MainWindow(Glib::RefPtr<Gtk::Application>);

protected:
	void setup_ui();
	void setup_actions();
	void on_action_about();
	void on_action_quit();
	void on_action_preferences();

private:
    Gtk::HeaderBar m_header_bar;
    Gtk::MenuButton m_menu_button_open_menu_symbolic;
	Gtk::MenuButton m_menu_button_adw_expander_arrow_symbolic;
	Glib::RefPtr<Gio::SimpleActionGroup> m_action_group;
    Glib::RefPtr<Gio::Menu> m_menu_main;
	Glib::RefPtr<Gio::Menu> m_menu_dropdown;
    Glib::RefPtr<Gtk::Builder> m_builder;
	Glib::RefPtr<Gtk::Application> m_app;
	Gtk::AboutDialog m_about_dialog;
	Glib::RefPtr<Gtk::AlertDialog> m_alert_dialog;

};

#endif
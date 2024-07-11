#include <main_window.h>
#include <utilities.h>
#include <main_menu.ui>
#include <dropdown_menu.ui>
#include <icon.xpm>
#include <license.h>

MainWindow::MainWindow(Glib::RefPtr<Gtk::Application> app)
	: m_app(app) {
	this->set_title("My Application");
	this->set_default_size(600, 400);

	this->setup_ui();
}

void MainWindow::setup_ui() {
	// About Dialog Setup
	this->m_about_dialog.set_transient_for(*this);
	this->m_about_dialog.set_hide_on_close();
	this->m_about_dialog.set_logo(Gdk::Texture::create_for_pixbuf(Gdk::Pixbuf::create_from_xpm_data(icon))); //  create_from_resource("../rsc/icon.svg"));
	this->m_about_dialog.set_program_name("Headerbar application");
	this->m_about_dialog.set_version("1.0.0");
	this->m_about_dialog.set_copyright("Scott Combs");
	this->m_about_dialog.set_comments("This is just an Headerbar example application.");
	this->m_about_dialog.set_license(license);
	this->m_about_dialog.set_website("http://www.github.com/scott8420");
	this->m_about_dialog.set_website_label("github website");

	// HeaderBar Setup
	this->m_menu_button_open_menu_symbolic.set_label("main-menu");
	this->m_menu_button_open_menu_symbolic.set_icon_name("open-menu-symbolic");
	this->m_menu_button_open_menu_symbolic.set_has_frame(false);
	this->m_builder = Gtk::Builder::create_from_string(ui_menu_main);
	this->m_menu_main = m_builder->get_object<Gio::Menu>("menu-main-popup");
	this->m_menu_button_open_menu_symbolic.set_menu_model(this->m_menu_main);
	this->m_header_bar.pack_end(this->m_menu_button_open_menu_symbolic);

	this->m_menu_button_adw_expander_arrow_symbolic.set_label("dropdown-menu");
	this->m_menu_button_adw_expander_arrow_symbolic.set_icon_name("adw-expander-arrow-symbolic");
	this->m_menu_button_adw_expander_arrow_symbolic.set_has_frame(false);
	this->m_builder->add_from_string(ui_menu_dropdown);
	this->m_menu_dropdown = m_builder->get_object<Gio::Menu>("menu-dropdown-popup");
	this->m_menu_button_adw_expander_arrow_symbolic.set_menu_model(this->m_menu_dropdown);
	this->m_header_bar.pack_start(this->m_menu_button_adw_expander_arrow_symbolic);

	this->set_titlebar(this->m_header_bar);

	// Connect MenuItems To Actions
	this->setup_actions();
}

void MainWindow::setup_actions() {
	this->m_action_group = Gio::SimpleActionGroup::create();

	// Connect Signals
	this->m_action_group->add_action("quit", sigc::mem_fun(*this, &MainWindow::on_action_quit));
	this->m_action_group->add_action("about", sigc::mem_fun(*this, &MainWindow::on_action_about));
	this->m_action_group->add_action("preferences", sigc::mem_fun(*this, &MainWindow::on_action_preferences));

	this->insert_action_group("main_actions", this->m_action_group);

	// Set Acceleration Keys
	if(this->m_app != nullptr) {
		this->m_app->set_accel_for_action("main_actions.quit", "<Primary>q");
		this->m_app->set_accel_for_action("main_actions.about", "<Primary>i");
		this->m_app->set_accel_for_action("main_actions.preferences", "<Primary>comma");
	}
}

void MainWindow::on_action_about() {
	this->m_about_dialog.set_visible(true);
	this->m_about_dialog.present();
}

void MainWindow::on_action_preferences() {
	Utilities::alert_message(this, "Preferences Menu Item selected", "Just extra info");
}

void MainWindow::on_action_quit() {
	this->close();
	this->m_app->quit();
}

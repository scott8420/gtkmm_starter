#include <gtkmm.h>
#include <main_window.h>

int main(int argc, char *argv[]) {
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create();
    return app->make_window_and_run<MainWindow>(argc, argv, app);
}
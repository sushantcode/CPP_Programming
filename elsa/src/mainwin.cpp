#include "mainwin.h"

Mainwin::Mainwin() : store{nullptr}{
	set_default_size(1000, 500);
	set_title("Exceptional Laptops and Supercomputer Assessories");
	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
	add(*vbox);
	//adding menubar
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	
	//adding File menubar
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//adding View menubar
	
}
		virtual ~Mainwin();

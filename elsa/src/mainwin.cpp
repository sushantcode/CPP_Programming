#include "mainwin.h"

Mainwin::Mainwin() {
	set_default_size(800, 500);
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
	
	//adding Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    
    //adding View menubar
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

   	//adding view peipheral to View menu
	Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripherals", true));
    menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_view_peripheral);
    
    //adding view desktop to View menu
	Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("_Desktops", true));
   	menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_view_desktop);
    
    //adding view order to View menu
	Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
   	menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_view_order);
    
    //adding view customer to View menu
	Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("_Customers", true));
   	menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_view_customer);
    
   	//adding Insert menubar
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar->append(*menuitem_insert);
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert->set_submenu(*insertmenu);
	
	//adding insert peipheral to Insert menu
	Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripherals", true));
    menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
    insertmenu->append(*menuitem_insert_peripheral);
    
    //adding insert desktop to Insert menu
	Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktops", true));
   	menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_insert_desktop);
    
    //adding insert order to Insert menu
	Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Orders", true));
   	menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_insert_order);
    
    //adding insert customer to Insert menu
	Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_Customers", true));
   	menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_insert_customer);
	
	//adding a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    
    //adding About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);
    
    /*//adding a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
	
	// Push the quit botton all the way to the right by setting set_expand true
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);
    toolbar->append(*sep);
    
    //adding icon to quit
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit game");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);*/
    
    //providing text entry box to show data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    
    //providing a status bar for app messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    
    //making the box and everything visible to each other
    vbox->show_all();
    
    store = new Store();
}

Mainwin::~Mainwin(){ }

void Mainwin::on_quit_click() {
	close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    auto logo = Gdk::Pixbuf::create_from_file("comp.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.1.1");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Sushant Gupta"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by Designmantic, free license https://s3.amazonaws.com/designmantic-logos/logos/2020/Mar/medium-9340-5e7a99a4aecfb.png"};
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_view_peripheral_click(){
	std::ostringstream optList;
	for(int i=0; i<store->num_options(); ++i) 
		optList << i << ") " << store->option(i) << "\n";
	set_data("<b> <span size = '20000'> Peripherals </span></b> \n\n" + optList.str());
}

void Mainwin::on_view_desktop_click(){
	std::ostringstream DeskList;
	for(int i=0; i<store->num_desktops(); ++i) 
		DeskList << i << ") " << store->desktop(i) << "\n";
	set_data("<b> <span size = '20000'> Desktop </span></b> \n\n" + DeskList.str());
}

void Mainwin::on_view_order_click(){
	std::ostringstream orderList;
	for(int i=0; i<store->num_customers(); ++i) 
		orderList << i << ") " << store->customer(i) << "\n";
	set_data("<b> <span size = '20000'> Order </span></b> \n\n" + orderList.str());
}

void Mainwin::on_view_customer_click(){
	std::ostringstream custList;
	for(int i = 0; i < store->num_customers(); ++i)
	{
		custList << "\n" << i << ") " << store->customer(i);
	}
	set_data("<b> <span size = '20000'> Customers </span></b> \n\n" + custList.str());	
}

void Mainwin::on_insert_peripheral_click(){
	std::string name = get_string("Name of new peripheral?");
	double cost = get_double("Cost?");
	Options option{name, cost};
	store->add_option(option);
	set_msg("Added new peripheral");
	on_view_peripheral_click();
}

void Mainwin::on_insert_desktop_click(){
	int desktop = store->new_desktop();
	while(true){
		std::ostringstream thisDesk;
		thisDesk << store->desktop(desktop);
		std::ostringstream optList;
		for(int i=0; i<store->num_options(); ++i){
			optList << i << ") " << store->option(i) << "\n";
		}
		thisDesk << "\n\n<b> <span size = '15000'> Available Peripherals: </span></b>\n" << optList.str();
		set_data(thisDesk.str());
		int option = get_in("Add which peripheral (-1 when done)");
		if (option == -1) break;
		try{
			store->add_option(option, desktop);
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "#### INVALID OPTION ####", true}.run();
		}
	}
	set_msg("Added new desktop");
	on_view_desktop_click();
}

void Mainwin::on_insert_order_click(){
	on_view_customer_click();
	int customer = get_in("Select Customer:");
	int order = store->new_order(customer);
	while(true){
		on_view_desktop_click();
		int desktop = get_in("Select desktop (-1 when done):");
		if(desktop == -1) break;
		try{
			store->add_desktop(desktop, order);
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "#### INVALID OPTION ####", true}.run();
		}
	}
	set_msg("++++ New Order Placed ++++");
	on_view_order_click();
}

void Mainwin::on_insert_customer_click(){
	std::string name = get_string("Customer name?");
	if(name.size()) {
		std::string phone = get_string("Customer phone (xxx-xxx-xxxx)?");
		std::string email = get_string("Customer email (xxx@domain.com)?");
		Customer customer{name, phone, email};
		store->add_customer(customer);
		set_msg("Added customer " + name);
		on_view_customer_click();
	}
}

std::string Mainwin::get_string(std::string prompt){
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("write here...");
    edialog.run();
	return edialog.get_text();
}

double Mainwin::get_double(std::string prompt){
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("write here...");
    edialog.run();
    double result = std::stod(edialog.get_text(), nullptr);
	return result;
}

int Mainwin::get_in(std::string prompt){
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("write here...");
    edialog.run();
    int result = std::stoi(edialog.get_text());
	return result;
}

void Mainwin::set_data(std::string s){
	data->set_markup(s);
}

void Mainwin::set_msg(std::string s){
	msg->set_text(s);
}


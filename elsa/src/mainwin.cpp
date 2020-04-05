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
	
	//adding Open to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);
	
	//adding Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
    
    //adding Save As to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);
    
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
    
    //providing text entry box to show data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    data->set_halign(Gtk::ALIGN_START);
    data->set_valign(Gtk::ALIGN_START);
    vbox->add(*data);
    Gtk::Label{"", Gtk::ALIGN_START, Gtk::ALIGN_START};
    
    //providing a status bar for app messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    
    //making the box and everything visible to each other
    vbox->show_all();
    
    store = new Store();
    
    filename = "untitled.elsa";
}

Mainwin::~Mainwin(){ }

void Mainwin::on_new_store_click(){ }

void Mainwin::on_save_click(){ }

void Mainwin::on_save_as_click(){ }

void Mainwin::on_open_click(){ }

void Mainwin::on_quit_click() {
	close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("ELSA");
    auto logo = Gdk::Pixbuf::create_from_file("comp.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.1.1");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Sushant Gupta"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Open Clip Art Libray through Public Domain Files, http://www.publicdomainfiles.com/show_file.php?id=13938399629439"};
    dialog.set_artists(artists);
    dialog.run();
}

void Mainwin::on_view_peripheral_click(){
	std::ostringstream optList;
	for(int i=0; i<store->num_options(); ++i) 
		optList << i << ") " << store->option(i) << "\n";
	set_data("<b> <span size = '20000'>Peripherals</span></b> \n" + optList.str());
}

void Mainwin::on_view_desktop_click(){
	std::ostringstream DeskList;
	for(int i=0; i<store->num_desktops(); ++i) 
		DeskList << "<b> <span size = '10000'>" << i << ") " << "</span></b>" << store->desktop(i) << "\n";
	set_data("<b> <span size = '20000'>Desktop</span></b> \n" + DeskList.str());
}

void Mainwin::on_view_order_click(){
	std::ostringstream orderList;
	for(int i=0; i<store->num_orders(); ++i) 
		orderList << i << ") " << store->order(i) << "\n";
	set_data("<b> <span size = '20000'>Order</span></b> \n" + orderList.str());
}

void Mainwin::on_view_customer_click(){
	std::ostringstream custList;
	for(int i = 0; i < store->num_customers(); ++i)
	{
		custList << i << ") " << store->customer(i) << "\n";
	}
	set_data("<b> <span size = '20000'>Customers</span></b> \n" + custList.str());	
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
		thisDesk << "\n\n<b> <span size = '10000'>Available Peripherals: </span></b>\n" << optList.str();
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
	int order;
	int customer;
	while(true){
		customer = get_in("Select Customer (-1 to Cancel)");
		if (customer == -1) break;
		try{
			order = store->new_order(customer);
			break;
		} 
		catch(std::exception& e) {
			Gtk::MessageDialog{*this, "#### INVALID OPTION ####", true}.run();
		}
	}
	while(true){
		if (customer == -1) break;
		on_view_desktop_click();
		int desktop = get_in("Select desktop (-1 when done):");
		if(desktop == -1) break;
		try{
			store->add_desktop(desktop, order);
		} catch(std::exception& e) {
			Gtk::MessageDialog{*this, "#### INVALID OPTION ####", true}.run();
		}
	}
	if (customer != -1){
		set_msg("++++ New Order Placed ++++");
	}
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

void Mainwin::on_easter_egg_click(){ }

std::string Mainwin::get_string(std::string prompt){
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("Type text here...");
    edialog.run();
	return edialog.get_text();
}

double Mainwin::get_double(std::string prompt){
	double result;
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("Type number here...");
    while(true)
    {
    	try{
			edialog.run();
    		result = std::stod(edialog.get_text(), nullptr);
    		break;
		} 
		catch(std::exception& e) {
			Gtk::MessageDialog{*this, "#### INVALID INPUT ####", true}.run();
		}
	}
	return result;
}

int Mainwin::get_in(std::string prompt){
	int result;
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("Type number here...");
    while(true)
    {
    	try{
			edialog.run();
    		result = std::stoi(edialog.get_text());
    		break;
		} 
		catch(std::exception& e) {
			Gtk::MessageDialog{*this, "#### INVALID INPUT ####", true}.run();
		}
	}
	return result;
}

void Mainwin::set_data(std::string s){
	data->set_markup(s);
}

void Mainwin::set_msg(std::string s){
	msg->set_text(s);
}


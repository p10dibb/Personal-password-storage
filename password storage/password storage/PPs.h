#include "PasswordSet.h"


class PPS {

public:

	PPS();
	~PPS();

	void run();    //main runner

	bool input_set();  //gets user input

	bool login();

	bool search();

	bool display_ALL();

	void trash();

	void edit_passwords();

	void first_time_setup();

	bool recover_Password();



private:
	string user;
	string password;
	fstream infile;
	map<string, Set> storage;
	int size;
	int hour;
	int min;
	bool first;

	bool store_All();

	bool load_All();


};
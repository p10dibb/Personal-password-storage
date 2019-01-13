#include "header.h"


class Set {

public:

	Set();
	~Set();

	bool set_Password(string pass);
	bool set_Name(string name);
	string get_password();
	string get_Name();

	string encrypt(int addH, int addM);

	Set decrypt(string e, int timeH, int timeM);

	string dec_loop(string e, int sub);

private:
	string Name;
	string Password;

};
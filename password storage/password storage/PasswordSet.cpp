#include "PasswordSet.h"


Set::Set() {
	this->Password = "";
	this->Name = "";
}
Set::~Set() {

}

bool Set::set_Password(string pass) {
	Password = pass;
	return 1;
}
bool Set::set_Name(string name) {
	Name = name;
	return 1;
}
string Set::get_password() {
	return Password;
}
string Set::get_Name() {
	return Name;
}

string Set::encrypt(int addH, int addM) {
	string ret = "~";
	int temp = 0;
	char t = '\0';
	int add = addM / addH;





	//encrypts password
	for (int i = 0; i < this->Password.length(); i++) {
		temp = Password[i];

		temp += (add + i);
		if (temp > ascii_max) {
			temp = (temp % ascii_dif) + ascii_min;
		}
		t = temp;
		ret = ret + t;
	}




	ret = ret + '}';//inserts key for next

					//encrypts name
	for (int i = 0; i < this->Name.length(); i++) {
		temp = Name[i];

		temp += (add + i);
		if (temp > ascii_max) {
			temp = (temp % ascii_dif) + ascii_min;
		}
		t = temp;
		ret = ret + t;
	}

	ret = ret + '~';

	return ret;


}

Set Set::decrypt(string e, int timeH, int timeM) {
	string first = "", second = "";
	int sub = timeM / timeH;
	int temp = 0, Ntemp = 0;
	int i = 0;
	Set ret;

	//splits into first and second word-----------
	while (e[i] != '}') {//searches for the split key
		second += e[i];
		i++;
	}
	i++;
	for (; i < e.size(); i++) {
		first = first + e[i];
	}
	//-----------------------------------



	first = dec_loop(first, sub);


	second = dec_loop(second, sub);

	ret.set_Name(first);
	ret.set_Password(second);



	return ret;
}

string Set::dec_loop(string e, int sub) {

	int temp = 0, Ntemp = 0;

	for (int j = 0; j < e.size(); j++) {
		temp = e[j];
		temp = temp - j - sub; //shifts characer

							   //checks if invalid character
		if (temp < ascii_min) {
			Ntemp = ascii_min - temp;
			temp = ascii_max - Ntemp;
			e[j] = (char)temp;
		}
		else {
			e[j] = (char)temp;
		}
	}

	return e;
}
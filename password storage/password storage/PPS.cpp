#include "PPs.h"



PPS::PPS() {
		time_t t = time(NULL);
		struct tm*at = localtime(&t);
		
	
		
		this->size = 0;
		this->hour =at->tm_hour;
		this->min = at->tm_min;
		this->password = "1234";
		this->user = "Paul Dibble";
		first = true;
		
	
		//makes sure not invalid  hour or min
		if (hour == 0) {
			hour = 1;
		}
		if (min == 0) {
			min = 1;
		}
		load_All();
	
		this->infile.open("stored.txt");
	}

	PPS::~PPS() {
		store_All();

		this->storage.clear();
	}

	void PPS::run()   //main runner
	{
		trash();
		infile << '~' << (int)hour << "~";   //stores hour

		trash();


		infile << "~" << (int)min << '~';  //stors minuts


		int choice = 0;

		if (login()) {
			while (choice != 4) {
				cout << "\nwould you like to\n1.enter new Passwords\n2.search for a password\n3.view all passwords\n4.Exit\nEnter choice:";
				cin >> choice;
				if (choice == 1) {
					input_set();
				}
				else if (choice == 2) {
					search();
				}
				else if (choice == 3) {
					display_ALL();
				}




			}
		}



	}

	bool PPS::login() {  //prompts user for master password
		string input = "";
		cout << "Hello " << user << " please enter your Password or '0' to exit:";
		while (input != password || input == "0") {
			cin >> input;
			if (input != password) {
				if (input == "0") {
					return 0;
				}
				cout << "try again:";

			}
		}


		return 1;

	}

	//gets user input
	bool PPS::input_set()
	{
		Set temp;
		string input = "";
		cout << "Enter Name of Password: ";
		getline(cin, input);
		getline(cin, input);
		temp.set_Name(input);//gets full line including spaces
		cout << "Enter Password: ";
		getline(cin, input);
		temp.set_Password(input);

		this->storage[temp.get_Name()] = temp;


		return 1;

	}

	//stores all encrypted data into the txt file
	bool PPS::store_All() {

		trash();



		for (std::map<string, Set>::iterator it = storage.begin(); it != storage.end(); ++it)
			infile << it->second.encrypt(hour, min);

		return 0;
	}

	bool PPS::search() {
		string input;

		cout << "Enter the name:";
		cin >> input;

		map<string, Set>::iterator foundIter = storage.find(input); // Creates an iterator for the position map

		if (foundIter != storage.end()) // Checks if the position is already being used
		{
			cout << endl << storage[input].get_Name() << " Password: " << storage[input].get_password() << endl;
			return true;
		}
		else
		{
			cout << endl << input << " is not in the records\n";
			return false;													//returrn false
		}


		return 1;

	}

	//prints out entire map
	bool PPS::display_ALL() {
		int i = 1;
		for (std::map<string, Set>::iterator it = storage.begin(); it != storage.end(); ++it) {
			cout << i << ". " << it->first << " Password: " << it->second.get_password() << endl;
			i++;

		}

		return true;
	}

	//reads in txt file and stores all info in a map
	bool PPS::load_All() {
		this->infile.open("stored.txt");
		string input = "", newW = "";
		int check = 0, word = 0, timeH = 0, timeM = 0;
		Set temp;

		while (infile >> input) {

			for (int i = 0; i < input.size(); i++) {
				if (input[i] == '~') {
					if (word == 1) {
						word = 0;
						if (check == 0) {
							timeH = StoI(newW);
							check++;
							newW = "";
						}
						else if (check == 1) {
							timeM = StoI(newW);
							check++;
							newW = "";
						}
						else {
							temp = temp.decrypt(newW, timeH, timeM);
							storage[temp.get_Name()] = temp;
							newW = "";
						}


					}
					else {
						word = 1;
					}
				}
				else {
					if (word == 1) {
						newW += input[i];
					}
				}
			}




		}
		this->infile.close();

		return 1;
	}


	//adds random characters to txt file
	void PPS::trash() {
		int j = (rand() % 15) + 2;
		char filler = '\0';
		for (int i = 0; i < j; i++) {
			filler = (rand() % 93) + 32;
			infile << filler;
		}

	}
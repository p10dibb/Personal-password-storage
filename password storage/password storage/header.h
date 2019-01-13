#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include<map>


/*
Creator: Paul Dibble

date started:11/28/2018

Name: Personal password storage (PPS)

Purpose: to store all of your passwords in one space that is safe and secure. i got irritated at the default one on my PC and decided to make my own.

outline: prompts user for initial password then gives options to add new passwords or look at old. it stores all the data to a txt file. for security it encrypts the txt file

current encrypt algorithm:  character +(minuits/hour) +(character position in string)

*/


/*
TO Do:

- create password recovery
-create multiple user?
-add more comments
-make exe work on desktop

*/



#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include<map>
#include<math.h>
#include <ctime>
#include <time.h>

using namespace::std;

#define ascii_max 124
#define ascii_min 32
#define ascii_dif 92     //max-min

int StoI(string h);
string get_line_input();




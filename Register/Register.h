#ifndef Register_h
#define Register_h

#include <string>
#include <utility>
#include <iostream>
#include <fstream>
//#include "User_ID.h"
//#include "Person.h"
//#include "Subject.h"

using namespace std;

class Register {
public:
	void setYear(int& y);
	void setMonth(int& m);
	int menu();
	int info(int howMany);
	string average_Grade_Sub();
	void higer_Avarage_Grade(string &, float&);
	void birthday(int & m1, int & m2, int & y1, int & y2);
	string address();
	void deleteStudent(long long &);
};
#endif

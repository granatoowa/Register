#ifndef Subject_h
#define Subject_h

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Person.h"
//#define REMOVE_SPACES(x) x.erase(std::remove(x.begin(), x.end(), ' '), x.end())
using namespace std;

class Subject : User_ID {
	string subject;
	float mark;
	string test;
public:
	Subject(long long, string, float, string);
	~Subject();
	long long getSID() const;
	string getSubject() const;
	float getMark() const;
	string getTest() const;
	void write();
	void write(string);
	void writeFNewList(string);
	void writeFNewListE(string subjectFileName);
	void search(string, long long);
	void search(string, double&, int&);
	float search(string, long long, int&);
	
};

#endif








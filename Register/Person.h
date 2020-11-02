#ifndef Person_h
#define Person_h

#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Person : User_ID{
	string name;
	string sec_Name;
	int day, month, year;
	string street;
	string house_No;
	char* city;
public:
	Person(long long, string, string, int, int, int, string, string, string);
	Person(const Person& ob);
	~Person();
	string getName() const;
	string getSec_Name() const;
	long long getPID() const;
	void write();
	void writeN();
	void write(string);
	void writeFShortInfo(string);
	void writeFNewList(string personFileName);
	void writeFNewListE(string);
	void search(string, string);
	void birthdayP(string, int, int, int, int);
	
	
};

#endif


//void search(string);

/*int getDay() const;
	int getMonth() const;
	int getYear() const;
	string getStreet() const;
	string getHouse_No() const;
	char * getCity() const;*/
	//Person& operator=(const Person& ob);
#include "User_ID.h"
#include "Subject.h"
#include "Register.h"
#include "Person.h"
#include <string>

Person::Person(long long id, string n, string sec_n, int d, int m, int y, string st, string No, string c) : User_ID(id) {
	name = n;
	sec_Name = sec_n;
	if (d> 0 && d < 32 && m>0 && m < 13) {
		day = d;
		month = m;
		year = y;
	}
	street = st;
	house_No = No;
	int x = strlen(c.c_str())+1;
	city = new char[x];
	strcpy_s(city, x, c.c_str());
	//cout << "C-tor Person " << ID << endl;
}

Person::Person(const Person& ob) : User_ID(ob.ID) {
	name = ob.name;
	sec_Name = ob.sec_Name;
	day = ob.day;
	month = ob.month;
	year = ob.year;
	street = ob.street;
	house_No = ob.house_No;
	int x = strlen(ob.city);
	city = new char[x + 1];
	strcpy_s(city, x+1, ob.city);
	//cout << "C-tor Person " << ID << endl;
}

Person::~Person() {
	//cout <<"D-tor Person " << ID << endl;
	delete[] city;
}

string Person::getName() const {
	return name;
}

string Person::getSec_Name() const {
	return sec_Name;
}

long long int Person::getPID() const {
	return getID();
}

void Person::write() {
	cout << "PESEL: " << ID << endl;
	cout << "Imie: " << name << endl;
	cout << "Nazwisko: " << sec_Name << endl;
	cout << "Data urodzenia: " << day << "." << month << "." << year << endl;
	cout << "Miejsce zamieszkania: " << street << " " << house_No << ", " << city << endl;
}


void Person::writeN() {
	cout << name << " " << sec_Name << endl;
}

void Person::write(string endFileName) {
	fstream file;
	file.open(endFileName, ios::out | ios::app);
	if (file.good()) {
		file << "INFORMACJE NA TEMAT UCZNIA" << endl << "-----------------------------" << endl;
		file << "PESEL: " << ID << endl << "Imie: " << name << endl << "Nazwisko: " << sec_Name << endl <<
			"Data urodzenia: " << day << "." << month << "." << year << endl <<
			"Miasto: " << city << endl << "Ulica: " << street << endl << "Numer domu:" << house_No << endl
			<< "-----------------------------" << endl;
		file.close();
	}
	else cout << "Nie udalo sie otworzyc pliku " << endFileName << endl;
}

void Person::writeFShortInfo(string endFileName) { 
	fstream file;
	file.open(endFileName, ios::out | ios::app);
	if (file.good()) {
		file << name << " " << sec_Name << endl;
		file.close();
	}
	else cout << "Nie udalo sie wpisac do pliku " << endFileName<< endl;
}

void Person::writeFNewList(string personFileName) {
	fstream file;
	file.open(personFileName, ios::out | ios::app);
	if (file.good()) {
		file << ID << "," << name << "," << sec_Name << "," << day << "," << month << "," << year << "," << street << "," << house_No << "," << city;
		file.close();
	}
	else cout << "Nie udalo sie wpisac do pliku " << personFileName<< endl;
}

void Person::writeFNewListE(string personFileName) {
	fstream file;
	file.open(personFileName, ios::out | ios::app);
	if (file.good()) {
		file << ID << "," << name << "," << sec_Name << "," << day << "," << month << "," << year << "," << street << "," << house_No << "," << city << endl;
		file.close();
	}
	else cout << "Nie udalo sie wpisac do pliku " << personFileName << endl;
}


void Person::search(string endFileName, string str) {
	if (this->street == str) {
		writeFShortInfo(endFileName);
		//write();
	}
}

void Person::birthdayP(string endFileName, int m1, int m2, int y1, int y2) {
		if (m1 <= this->month && this->month <= m2) {
			if (y1 <= this->year && this->year <= y2) {
				//write(); 
				writeFShortInfo(endFileName);
			}
		}
}







//void Person::search(string endFileName) {
//		writeFInfo(endFileName);
//}

//int Person::getDay() const {
//	return day;
//}
//
//int Person::getMonth() const {
//	return month;
//}
//
//int Person::getYear() const {
//	return year;
//}
//
//string Person::getStreet() const {
//	return street;
//}
//
//string Person::getHouse_No() const {
//	return house_No;
//}
//
//char* Person::getCity() const {
//	return city;
//}

//Person & Person::operator=(const Person& ob){
//	if (this != &ob) {
//		ID = ob.ID;
//		name = ob.name;
//		sec_Name = ob.sec_Name;
//		day = ob.day;
//		month = ob.month;
//		year = ob.year;
//		street = ob.street;
//		house_No = ob.house_No;
//		delete[] city;
//		int x = strlen(ob.city);
//		city = new char[x + 1];
//		strcpy_s(city, x + 1, ob.city);
//	}
//	return *this;
//}
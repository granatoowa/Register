#include "User_ID.h"
#include "Subject.h"
#include "Register.h"
#include "Person.h"

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
	city = c;
	//cout << "C-tor Person " << ID << endl;
}

Person::~Person() {
	//cout <<"D-tor Person " << ID << endl;
}


//int Person::operator==(const Person & o) {
//	return 1;
//}

//int Person::operator>(const Person& pt) {  //porówuje daty
//	return day;
//}

void Person::search(long long id) {
	if (this->ID == id)
		write();
}

void Person::write() {
	cout << "PESEL: " << ID << endl;
	cout << "Imie: " << name << endl;
	cout << "Nazwisko: " << sec_Name << endl;
	cout << "Data urodzenia: " << day << "." << month << "." << year << endl;
	cout << "Miejsce zamieszkania: " << street << " " << house_No << ", " << city << endl;
}


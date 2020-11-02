#include "User_ID.h"
#include "Person.h"
#include "Subject.h"
#include "Register.h"

Subject::Subject(long long id, string sub, float m, string t) : User_ID(id) {
	subject = sub;
	mark = m;
	test = t;
	//cout << "C-tor Subject " << ID << endl;
}

Subject::~Subject() {
	//cout << "D-tor Subject " << ID << endl;
}

long long Subject::getSID() const {
	return getID();
}

string Subject::getSubject() const {
	return subject;
}


float Subject::getMark() const {
	return mark;
}

string Subject::getTest() const {
	return test;
}

void Subject::write() {
	cout << "PESEL: " << ID << endl;
	cout << "Przedmiot: " << subject << endl;
	cout << "Ocena: " << mark << endl;
	cout << "Forma testu: " << test << endl;
}

void Subject::write(string endFileName) {
	fstream file;
	file.close();
	file.open(endFileName, ios::out | ios::app);
	if (file.good()) {
		file << "Przedmiot: " << subject << endl << "Ocena: " << mark << endl <<
			"Forma sprawdzenia: " << test << endl << "-----------------------------" << endl;
		file.close();
	}
	else cout << "Nie udalo sie otworzyc pliku " << endFileName << endl;
	
}

void Subject::writeFNewList(string subjectFileName) {
	fstream file;
	file.open(subjectFileName, ios::out | ios::app);
	if (file.good()) {
		file << ID << "," << subject << "," << mark << "," << test;
		file.close();
	}
	else cout << "Nie udalo sie wpisac do pliku " << subjectFileName << endl;
}

void Subject::writeFNewListE(string subjectFileName) {
	fstream file;
	file.open(subjectFileName, ios::out | ios::app);
	if (file.good()) {
		file << ID << "," << subject << "," << mark << "," << test << endl;
		file.close();
	}
	else cout << "Nie udalo sie wpisac do pliku " << subjectFileName << endl;
}

void Subject::search(string endFileName, long long id) {
	if (id == this->ID)
	{
		write(endFileName);
		//write();
	}
}

void Subject::search(string sub, double &sr, int & l) {
	if ( sub == this->subject)
	{
		sr+=getMark();
		l++;
	}
}

float Subject::search(string sub, long long ID, int & l) {
	if (sub == this->subject)
	{
		if (ID == this->ID) {
			l++;
			return this->mark;
			//write();
		}
		return 0;
	}
	else {
		return 0;
	}
}










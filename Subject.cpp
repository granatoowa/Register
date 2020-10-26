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

void Subject::search(long long id) {
	if (id == this->ID)
	{
		write();
	}
}

void Subject::write() {
	cout << "PESEL: " << ID << endl;
	cout << "Przedmiot: " << subject << endl;
	cout << "Ocena: " << mark << endl;
	cout << "Forma testu: " << test << endl;
}


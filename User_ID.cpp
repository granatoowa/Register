#include "User_ID.h"
#include "Person.h"
#include "Subject.h"
#include "Register.h"

User_ID::User_ID(long long id) {
	ID = id;
	//cout << "C-tor ID" << id << endl;
}

long long User_ID::operator==(const User_ID & o) {  // porownywanie ID obiektow
	return (ID == o.ID);
}

void User_ID::search_ID(long long id)
{
	if (id == this->ID) {
		cout << "To id";
	}
}

User_ID::~User_ID() {
	//cout << "D-tor ID" << ID << endl;
}
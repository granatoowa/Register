#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "Register.h"
#include "User_ID.h"
#include "Person.h"
#include "Subject.h"
#include "Functions.h"
#include "Lists.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------LIST_PERSON------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------

List_P::List_P() : pHead_P(nullptr), pTail_P(nullptr) {

};

long long List_P::getIDL(elem_P* p) const {
	return p->p.getPID();
}

elem_P* List_P::getPHead_P() const {
	return pHead_P;
}

List_P& List_P::operator+=(const Person& ob) {
	elem_P* pt = new elem_P(ob);
	if (pHead_P)
		pTail_P->pNext_P = pt;
	else
		pHead_P = pt;

	pTail_P = pt;

	return *this;
}

void List_P::switchStr(string & str, int & i, long long & ID, string &n, string & sN, int &d, int &m, int &y, string & street, string & h_No, string &c) {
	switch (i) {
	case 0:
		ID = stoll(str);
		break;
	case 1:
		n = str;
		break;
	case 2:
		sN = str;
		break;
	case 3:
		d = stoi(str);
		break;
	case 4:
		m = stoi(str);
		break;
	case 5:
		y = stoi(str);
		break;
	case 6:
		street = str;
		break;
	case 7:
		h_No = str;
		break;
	case 8:
		c = str;
		break;
	}
	i++;
}

bool List_P::loadP(List_P& lp, string personFileName) {
	string n;
	string sN;
	long long ID;
	int d, m, y;
	string street, h_No, c;
	ifstream file(personFileName);
	if (file) {
		while (!file.eof()) {
			string line;
			string str;
			int i = 0;
			getline(file, line);
			istringstream iss(line);
			while (getline(iss, str, ',')) {
				//REMOVE_SPACES(str);
				switchStr(str, i, ID, n, sN, d, m, y, street, h_No, c);
			}
			lp += Person(ID, n, sN, d, m, y, street, h_No, c);
			/*cout << n << sN<< d << m << y << street << h_No << c << endl;
			cout << endl;*/
		}
		file.close();
		return true;
	}
	else {
		cout << "Nie mozna otworzyc pliku " << personFileName << "!" << endl;
		return false;
	}
}

void List_P::write(int & howMany) {
	elem_P* pt = pHead_P;
	int i = 0;
	while (pt) {
		//pt->s.writeFNewList();
		cout << i+1 << ". ";
		pt->p.writeN();
		//cout << endl;
		pt = pt->pNext_P;
		i++;
		
	}
	howMany = i;
	delete pt;
}

void List_P::write() {
	elem_P* pt = pHead_P;
	while (pt) {
		//pt->s.writeFNewList();
		pt->p.write();
		//cout << endl;
		pt = pt->pNext_P;
	}
	delete pt;
}

void List_P::writeF(string personFileName) {
	elem_P* pt = pHead_P;
	while (pt) {
		//pt->p.write();
		if (pt->pNext_P == nullptr) {
			pt->p.writeFNewList(personFileName);
		}
		else {
			pt->p.writeFNewListE(personFileName);
		}
		pt = pt->pNext_P;
	}
	delete pt;
}

long long List_P::searchID(string endFileName, int nr) {
	elem_P* pt = pHead_P;
	int i = 0;
	while (pt) {
		if (i == nr - 1){
			pt->p.write(endFileName);
			return pt->p.getPID();
		}
		pt = pt->pNext_P;
		i++;
	}
}

void List_P::searchStr(string endFileName, string str) {
	elem_P* pt = pHead_P;
	while (pt) {
		pt->p.search(endFileName, str);
		pt = pt->pNext_P;
	}
}

void List_P::birthdayLP(string endFileName, int m1, int m2, int y1, int y2) {
	elem_P* pt = pHead_P;
	while (pt) {
		pt->p.birthdayP(endFileName, m1, m2, y1, y2);
		pt = pt->pNext_P;
	}
}

void List_P::deletePS(long long ID) {
	elem_P* pt = pHead_P;
	while (pt->pNext_P != NULL)
	{
		if (pt->pNext_P->p.getPID() == ID)      
		{
			elem_P* us = pt->pNext_P;   //zapamiêtujemy usuwany element
			pt->pNext_P = us->pNext_P;  //przestawiamy wskaŸnik next by omija³ usuwany element
			us->p.~Person();
			free(us);                   //usuwamy z pamiêci
		}
		else
		{
			pt = pt->pNext_P;            
		}                             
	}
}

List_P::~List_P() {
	while (pHead_P) {
		const elem_P* pt = pHead_P;
		pHead_P = pHead_P->pNext_P;
		delete pt;
	}
	//cout << "D-tor List P " << endl;
}

//---------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------LIST_SUBJECT-------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------

List_S::List_S() : pHead_S(nullptr), pTail_S(nullptr) {};

List_S& List_S::operator+=(const Subject& ob) {
	elem_S* pt = new elem_S(ob);
	if (pHead_S)
		pTail_S->pNext_S = pt;
	else
		pHead_S = pt;

	pTail_S = pt;

	return *this;
}

void List_S::switchStr(string &str, int &i, long long & ID, string & sub, float & mark, string & test) {
	switch (i) {
	case 0:
		ID = stoll(str); 
		break;
	case 1:
		sub = str;
		break;
	case 2:
		mark = stof(str);
		break;
	case 3:
		test = str;
		break;
	}
	i++;
}

bool List_S::loadS(List_S& ls, string subjectFileName) {
	long long ID;
	string sub;
	float mark;
	string test;
	ifstream file(subjectFileName);
	if (file) {
		while (!file.eof()) {
			string line;
			string str;
			int i = 0;
			getline(file, line);
			istringstream iss(line);
			while (getline(iss, str, ',')) {
				//REMOVE_SPACES(str);
				switchStr(str, i, ID, sub, mark, test);
			}
			ls += Subject(ID, sub, mark, test);
			////cout << ID << subName << mark << test << endl;
			////cout << endl;
		}
		file.close();
		return true;
	}
	else {
		cout << "Nie mozna otworzyc pliku " << subjectFileName << "!" << endl;
		return false;
	}
	//ls.write();
}

void List_S::write() {
	elem_S* pt = pHead_S;
	while (pt) {
		//pt->s.writeFNewList();
		pt->s.write();
		//cout << endl;
		pt = pt->pNext_S;
	}
	delete pt;
}

void List_S::write(string subjectFileName) {
	elem_S* pt = pHead_S;
	while (pt) {
		if (pt->pNext_S == nullptr)
		{
			pt->s.writeFNewList(subjectFileName);
		}
		else {
			pt->s.writeFNewListE(subjectFileName);
			//pt->s.write();
			//cout << endl;
		}
		pt = pt->pNext_S;
	}
	delete pt;
}

void List_S::searchID(string endFileName, long long ID) {
	elem_S* pt = pHead_S;
	while (pt) {
		pt->s.search(endFileName, ID);
		//cout << endl;
		pt = pt->pNext_S;
	}
}

void List_S::writeFAV_GR(string endFileName, string sub, double sr, int l) {
	fstream file;
	file.close();
	file.open(endFileName, ios::out | ios::app);
	file << "Srednia ocen z przedmiotu\n\n" << "Przedmiot: " << sub << endl << "Srednia: " << sr / l << endl;
	file.close();
}

void List_S::searchSub(string endFileName, string sub, double& sr, int& l) {
	elem_S* pt = pHead_S;
	while (pt) {
		pt->s.search(sub, sr, l);
		//cout << endl;
		pt = pt->pNext_S;
		//cout << sr << "  " << l;
	}
	writeFAV_GR(endFileName, sub, sr, l);
}

void List_S::searchAvarageGrade(string sub, long long ID, float& mark1, int& l) {
	elem_S* pt = pHead_S;
	while (pt) {
		mark1 += pt->s.search(sub, ID, l);
		//cout << endl;
		pt = pt->pNext_S;
	}

}

void List_S::deletePS(long long ID) {
	elem_S* pt = pHead_S;
	while (pt->pNext_S != NULL)
	{
		if (pt->pNext_S->s.getSID() == ID)   
		{
			elem_S* us = pt->pNext_S;   //zapamiêtujemy usuwany element
			pt->pNext_S = us->pNext_S;  //przestawiamy wskaŸnik next by omija³ usuwany element 
			us->s.~Subject();
			free(us);                   //usuwamy z pamiêci
		}
		else
		{
			pt = pt->pNext_S;          
		}                              
	}
}

List_S::~List_S() {
	while (pHead_S) {
		const elem_S* pt = pHead_S;
		pHead_S = pHead_S->pNext_S;
		delete pt;
	}
	//cout << "D-tor List S " << endl;
}
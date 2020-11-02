#ifndef Lists_h
#define Lists_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "User_ID.h"
#include "Subject.h"
#include "Register.h"
#include "Person.h"

using namespace std;

class List {
public:
	virtual void deletePS(long long ID) = 0;
};

struct elem_P {
	Person p;
	elem_P* pNext_P;
	elem_P(const Person& ob) : p(ob), pNext_P(nullptr) {}
};

class List_P : public List {
protected:
	elem_P* pHead_P;
	elem_P* pTail_P;

public:
	List_P();

	long long getIDL(elem_P* p) const;

	elem_P* getPHead_P() const;
	
	virtual List_P& operator+=(const Person& ob);

	void switchStr(string& str, int& i, long long& ID, string& n, string& sN, int& d, int& m, int& y, string& street, string& h_No, string& c);

	bool loadP(List_P& lp, string personFileName);

	void write();

	void write(int & howmany);


	void writeF(string personFileName);


	long long searchID(string endFileName, int nr);
	

	void searchStr(string endFileName, string str);


	void birthdayLP(string endFileName, int m1, int m2, int y1, int y2);
	

	virtual void deletePS(long long ID);

	~List_P();
	
};

struct elem_S {
	Subject s;
	elem_S* pNext_S;
	elem_S(const Subject& ob) : s(ob), pNext_S(nullptr) {}
};

class List_S : public List {
protected:

	elem_S* pTail_S;
	elem_S* pHead_S;
public:

	List_S();


	virtual List_S& operator+=(const Subject& ob);

	void switchStr(string& str, int& i, long long& ID, string& sub, float& mark, string& test);

	bool loadS(List_S& ls, string subjectFileName);

	void write();

	void write(string subjectFileName);

	void searchID(string endFileName, long long ID);

	void writeFAV_GR(string endFileName, string sub, double sr, int l);

	void searchSub(string endFileName, string sub, double& sr, int& l);

	void searchAvarageGrade(string sub, long long ID, float& mark1, int& l);

	virtual void deletePS(long long ID);

	~List_S();
};

#endif

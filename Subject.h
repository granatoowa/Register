#include <string>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

class Subject : User_ID {
	string subject;
	float mark;
	string test;
public:
	Subject(long long, string, float, string);
	~Subject();
	void search(long long);
	void write();
};

struct elem_S {
	Subject s;
	elem_S* pNext_S;
	elem_S(const Subject & ob) : s(ob), pNext_S(nullptr) {}
};

class List_S {
protected:
	elem_S* pHead_S;
	elem_S* pTail_S;

public:
	List_S() : pHead_S(nullptr), pTail_S(nullptr) {};

	virtual List_S& operator+=(const Subject & ob) {
		elem_S* qep = new elem_S(ob);
		if (pHead_S)
			pTail_S->pNext_S = qep;
		else
			pHead_S = qep;

		pTail_S = qep;

		return *this;
	}

	void load_Sub(List_S & ls) {
		long long ID;
		string sub;
		float mark;
		string test;
		streamoff pos = 0;
		ifstream File("subject.txt");
		if (File) {
			while (File && (pos != -1)) {
				File >> ID >> sub >> mark >> test ;
				ls += Subject(ID, sub, mark, test);
				//cout << ID << subName << mark << test << endl;
				//cout << endl;
				pos = File.tellg();
			}
		}
		File.close();
		ls.write();
	}

	void write() {
		elem_S* pt = pHead_S;
		while (pt) {
			pt->s.write();
			cout << endl;
			pt = pt->pNext_S;
		}
		delete pt;
	}

	void search_ID(long long id) {
		elem_S* pt = pHead_S;
		while (pt) {
			pt->s.search(id);
			cout << endl;
			pt = pt->pNext_S;
		}
	}

	void information(long long ID) {
		/*long long PESEL;
		cout << "WYSZUKANIE INFORMACJI O UCZNIU\n\n";
		cout << "Podaj PESEL ucznia:";
		cin >> PESEL;*/
		search_ID(ID);
	}
	

	~List_S() {
		while (pHead_S) {
			const elem_S* qep = pHead_S;
			pHead_S = pHead_S->pNext_S;
			delete qep;
		}
		//cout << "D-tor List S " << endl;
	}
};


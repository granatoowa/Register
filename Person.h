#include <string>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

class Person : User_ID{
	string name;
	string sec_Name;
	int day, month, year;
	string street;
	string house_No;
	string city;
public:
	Person(long long, string, string, int, int, int, string, string, string);
	~Person();
	void search(long long);
	//int operator==(const Person&);
	//int operator>(const Person&);
	void write();
};

struct elem_P {
	Person p;
	elem_P* pNext_P;
	elem_P(const Person & ctr): p(ctr), pNext_P(nullptr){}
};

class List_P {
protected:
	elem_P* pHead_P;
	elem_P* pTail_P;

public:
	List_P(): pHead_P(nullptr), pTail_P(nullptr) {};

	virtual List_P& operator+=(const Person& rq) {
		elem_P* qep = new elem_P(rq);
		if (pHead_P)
			pTail_P->pNext_P = qep;
		else
			pHead_P = qep;

		pTail_P = qep;

			return *this;
	}

	void load_Per( List_P & lp) {
		string n;
		string s_n;
		long long ID;
		int d, m, y;
		string n_street, h_No, c;
		streamoff pos = 0;
		ifstream File("person.txt");
		if (File) {
			while (File && (pos != -1)) {
				File >> ID >> n >> s_n >> d >> m >> y >> n_street >> h_No >> c;
				lp += Person(ID, n, s_n, d, m, y, n_street, h_No, c);
				//cout << n << s_n << d << m << y << n_street << h_No << c << endl;
				//cout << endl;
				pos = File.tellg();
			}
		}
		File.close();
		lp.write();
	}

	void write() {
		elem_P* pt = pHead_P;
		while (pt) {
			pt->p.write();
			cout << endl;
			pt=pt->pNext_P;
		}
		delete pt;
	}

	void search_ID(long long id) {
		elem_P* pt = pHead_P;
		while (pt) {
			pt->p.search(id);
			cout << endl;
			pt = pt->pNext_P;
		}
	}

	void information(long long ID) {
		/*long long PESEL;
		cout << "WYSZUKANIE INFORMACJI O UCZNIU\n\n";
		cout << "Podaj PESEL ucznia:";
		cin >> PESEL;*/
		search_ID(ID);
	}

	~List_P() {
		while (pHead_P) {
			const elem_P* qep = pHead_P;
				pHead_P = pHead_P->pNext_P;
				delete qep;
		}
		//cout << "D-tor List P " << endl;
	}
};
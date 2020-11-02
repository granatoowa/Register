#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "Register.h"
#include "User_ID.h"
#include "Person.h"
#include "Subject.h"
#include "Functions.h"
#define BOTTOM_Y 1950
#define TOP_Y 2020

using namespace std;

int Register::info(int howMany){
	int nr;
	do {
		cout << "\nPodaj numer: ";
		cin >> nr;
		
	} while (nr< 0 || nr > howMany);
	return nr;
}


string Register::average_Grade_Sub() {
	cout << "\nSREDNIA OCEN Z PRZEDMIOTU\n\n";
	string sub;
	cout << "Podaj przedmiot: ";
	cin >> sub;
	return sub;
}

void Register::higer_Avarage_Grade(string & sub, float & m ) {
	cout << "\nLISTA UCZNIOW Z WYZSZA SREDNIA Z DANEGO PRZEDMIOTU NIZ ZADANA OCENA\n\n";
	cout << "Podaj przedmiot: ";
	cin >> sub;
	cout << "\n\nPodaj ocene: ";
	cin >> m;
}

void Register::setMonth(int & m) {
	do {
		cout << "\nPodaj miesiac: ";
		cin >> m;
	} while (m < 0 || m > 13);
}

void Register::setYear(int& y) {
	do {
		cout << "\nPodaj rok: ";
		cin >> y;
	} while (y < BOTTOM_Y || y > TOP_Y);
}

void Register::birthday(int& m1, int& m2, int& y1, int& y2) {
	cout << "\nLISTA UCZNIOW URODZONYCH W DANYM PRZEDZIALE CZASOWYM\n\n";
	cout << "Pierwsza data:\n"; 
	setMonth(m1);
	setYear(y1);
	cout << "Druga data:\n";
	setMonth(m2);
	setYear(y2);
}

string Register::address() {
	cout << "\n\nLISTA UCZNIOW MIESZKAJACYCH NA TEJ SAMEJ ULICY\n\n";
	cout << "Podaj nazwe ulicy: ";
	string street;
	cin >> street;
	return street;
}

void Register::deleteStudent(long long & id) {
	cout << "\n\nUSUNIECIE UCZNIA\n\n";
	cout << "Podaj PESEL ucznia: ";
	cin >> id;
}

int Register::menu() {
	int inst;
	cout <<"----------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tDziennik lekcyjny\n\n";
	cout << "\t1. Informacje na temat ucznia" << endl;
	cout << "\t2. Srednia ocen z przedmiotu" << endl;
	cout << "\t3. Uczniowie z wyzsza srednia z danego przedmiotu niz zadana ocena" << endl;
	cout << "\t4. Uczniowie urodzenie w podanym przedziale czasowym" << endl;
	cout << "\t5. Uczniowie mieszkajacy na takiej samej ulicy" << endl;
	cout << "\t6. Usuniecie ucznia\n\n";
	cout << "----------------------------------------------------------------------------------" << endl;
	do {
		cout << "\nProsze podac numer operacji:";
		cin >> inst;
	} while (inst < 0 || inst > 7);
	return inst;
}


int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	string personFileName;
	string subjectFileName;
	string endFileName; 
	for (int i = 0; i < argc; i++) {
		string a = argv[i];
		if (a == "-inper") {
			personFileName = argv[i + 1];
			i++;
		}
		else if (a == "-insub") {
			subjectFileName = argv[i + 1];
			i++;
		}
		else if (a == "-out") {
			endFileName = argv[i + 1];
			i++;
		}
	}
	runProgram(personFileName, subjectFileName, endFileName);
	return 0;
}

//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	string personFileName ="person.txt";
//	string subjectFileName = "subject.txt";
//	string endFileName = "end.txt";
//
//	runProgram(personFileName, subjectFileName, endFileName);
//	return 0;
//}
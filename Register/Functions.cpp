#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "Register.h"
#include "User_ID.h"
#include "Person.h"
#include "Subject.h"
#include "Functions.h"
#include <windows.h>
#include <time.h>

using namespace std;

void system_2CLS() {
	Sleep(2000);
	system("cls");
}

void clearFile(string fileName) {
	ofstream plik;
	plik.open(fileName);
	plik.close();
}

void case1(Register C_R, string endFileName, List_P& lp, List_S& ls) {
	int nr;
	int howMany = 0;
	long long ID;
	cout << "\nWYSZUKANIE INFORMACJI O UCZNIU\n\n";
	//cout << pesel;
	lp.write(howMany);
	nr = C_R.info(howMany);
	ID = lp.searchID(endFileName, nr);
	ls.searchID(endFileName, ID);
}

void case2(Register C_R, string endFileName, List_S& ls) {
	string sub;
	double suma = 0;
	int l = 0;
	sub = C_R.average_Grade_Sub();
	ls.searchSub(endFileName, sub, suma, l);
	//cout << suma << "  " << l << " ";
	//cout << "Srednia: " << suma / l;
}


void case3(Register C_R, string endFileName, List_P& lp, List_S& ls) {
	string subject;
	long long ID;
	float mark;
	string name;
	string sN;
	elem_P* pt = lp.getPHead_P();
	C_R.higer_Avarage_Grade(subject, mark);
	while (pt) {
		float mark1 = 0;
		int l = 0;
		ID = lp.getIDL(pt);
		//cout << ID << endl;
		ls.searchAvarageGrade(subject, ID, mark1, l);
		if (mark1 / l > mark) {
			name = pt->p.getName(); //cout << name;
			sN = pt->p.getSec_Name(); //cout << sN << endl;
			fstream file;
			file.open(endFileName, ios::out | ios::app);
			file << "Imie: "<< name << "\nNazwisko: " << sN<< "\nSrednia:"<< mark1/l << "\n\n";
			file.close();
			/*cout << "\n" << ID << "\n" << mark1 << "\t" << l << endl;*/
			//cout << "Srednia: " << mark1 / l << endl;
		}
		pt = pt->pNext_P;
	}
}

void case4(Register C_R, string endFileName, List_P& lp) {
	int m1, m2, y1, y2;
	C_R.birthday(m1, m2, y1, y2);
	lp.birthdayLP(endFileName, m1, m2, y1, y2);
}

void case5(Register C_R, string endFileName, List_P& lp) {
	string street;
	street = C_R.address();
	cout << endl;
	lp.searchStr(endFileName, street);
}



void case6(Register C_R, string personFileName, string subjectFileName, List_P& lp, List_S& ls) {
	long long pesel;
	C_R.deleteStudent(pesel);
	List* wskP;
	List* wskS;
	wskP = &lp;
	wskS = &ls;
	wskP->deletePS(pesel);
	wskS->deletePS(pesel);
	clearFile(personFileName);
	clearFile(subjectFileName);
	lp.writeF(personFileName);
	ls.write(subjectFileName);
	cout << "UCZEN USUNIETY!\n";
}

void switchM(int inst, Register C_R, string endFileName, string personFileName, string subjectFileName, List_P& list_P, List_S& list_S) {
	switch (inst) {
	case 1:
		case1(C_R, endFileName, list_P, list_S);
		break;
	case 2:
		case2(C_R, endFileName, list_S);
		break;
	case 3:
		case3(C_R, endFileName, list_P, list_S);
		break;
	case 4:
		case4(C_R, endFileName, list_P);
		break;
	case 5:
		case5(C_R, endFileName, list_P);
		break;
	case 6:
		case6(C_R, personFileName, subjectFileName, list_P, list_S);
		break;
	default:
		break;
	}
}

void runProgram(string personFileName, string subjectFileName, string endFileName) {
	Register Class_Register;
	List_P list_P;
	List_S list_S;
	bool x1;
	bool x2;
	//clearFile(endFileName);   // jezeli chcemy wyczyscic plik koncowy
	x1 = list_P.loadP(list_P, personFileName);
	x2 = list_S.loadS(list_S, subjectFileName);
	if (x1 == true && x2 == true) {
		cout << endl << "Plik z osobami: " << personFileName << endl <<
			"Plik z przedmiotami: " << subjectFileName << endl
			<< "Plik wyjsciowy: " << endFileName << endl;
		system_2CLS();
		int inst = Class_Register.menu();
		switchM(inst, Class_Register, endFileName, personFileName, subjectFileName, list_P, list_S);
	}
}
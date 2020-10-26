#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include "User_ID.h"
#include "Person.h"
#include "Subject.h"
#include "Register.h"

using namespace std;

void Register::info(List_S & ls, List_P & lp) { //List_P & lp, 
	long long PESEL;
	cout << "WYSZUKANIE INFORMACJI O UCZNIU\n\n";
	cout << "Podaj PESEL ucznia:";
	cin >> PESEL;
	lp.information(PESEL);
	ls.information(PESEL);
}

void Register::average_Grade_Sub() {
	cout << "ŚREDNIA OCEN Z PRZEDMIOTU\n\n";
	cout << "Podaj przedmiot:";
}

void Register::higer_Avarage_Grade() {
	cout << "LISTA UCZNIOW Z WYZSZA SREDNIA Z DANEGO PRZEDMIOTU NIZ ZADANA OCENA\n\n";
	cout << "Podaj przedmiot:";
	cout << "Podaj ocene:";
}

void Register::birthday() {
	cout << "LISTA UCZNIOW URODZONYCH W DANYM PRZEDZIALE CZASOWYM\n\n";
	cout << "Pierwsza data: \n";
	cout << "\nPodaj dzien:";
	cout << "\nPodaj miesiac:";
	cout << "\nPodaj rok:";
	cout << "Druga data:\n";
	cout << "\nPodaj dzien:";
	cout << "\nPodaj miesiac:";
	cout << "\nPodaj rok:";

}

void Register::address() {
	cout << "LISTA UCZNIOW MIESZKAJACYCH NA TEJ SAMEJ ULICY\n\n";
	cout << "Podaj nazwe ulicy:";
	// miasto??
}

void Register::switch_M(int inst){//,List_P & lp){ //, List_S & ls){ // List_S & ls, List_P& lp) {
	switch (inst) {
	case 1:
		//info(ls); //lp,
		cout << " to tuuuu 1";
		break;
	case 2:
		break;
	case 3: 
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	}
}

void Register::menu() {
	int inst;
	cout << "Dziennik lekcyjny" << endl;
	cout << "1. Informacje na temat ucznia" << endl;
	cout << "2. Srednia ocen z przedmiotu" << endl;
	cout << "3. Uczniowie z wyzsza srednia z danego przedmiotu niz zadana ocena" << endl;
	cout << "4. Uczniowie urodzenie w podanym przedziale czasowym" << endl;
	cout << "5. Uczniowie mieszkajacy na takiej samej ulicy" << endl;
	cout << "6. Dodanie ucznia" << endl;
	cout << "7. Usuniecie ucznia" << endl;
	do {
		cout << "Prosze podac numer operacji:";
		cin >> inst;
	} while (inst < 0 || inst > 7);
}

void Register::run_Program() {
	List_P list_P;
	List_S list_S;
	list_P.load_Per(list_P);
	list_S.load_Sub(list_S);
	menu();
	//switch_M(x, list_P);//, list_S); //, list_P);
	info(list_S, list_P);
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Register Class_Register;
	Class_Register.run_Program();

}

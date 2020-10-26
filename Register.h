#include <string>
#include <utility>
#include <iostream>
#include <fstream>

using namespace std;

class Register{
public:
	void info(List_S &, List_P &); //List_P &,
	void average_Grade_Sub();
	void higer_Avarage_Grade();
	void birthday();
	void address();
	void switch_M(int); //, List_P & lp); //,List_S&); //, List_P&);
	void menu();
	void run_Program();
};


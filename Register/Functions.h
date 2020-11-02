#ifndef Functions_h
#define Functions_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lists.h"

using namespace std;

/**Funkcja czyszczaca ekran z opoznieniem 2000.*/
void system_2CLS();

/**Funkcja czyszcz¹ca plik.
@param fileName zawiera nazwê pliku
*/
void clearFile(string fileName);

/**Funkcja
@param C_R
@param endFileName
@param lp
@param ls
*/
void case1(Register C_R, string endFileName, List_P& lp, List_S& ls);

/**Funkcja
@param C_R
@param endFileName
@param lp
*/
void case2(Register C_R, string endFileName, List_S& ls);

/**Funkcja
@param C_R
@param endFileName
@param lp
@param ls
*/
void case3(Register C_R, string endFileName, List_P& lp, List_S& ls);

/**Funkcja
@param C_R
@param endFileName
@param lp
*/
void case4(Register C_R, string endFileName, List_P& lp);

/**Funkcja
@param C_R
@param endFileName
@param lp
*/
void case5(Register C_R, string endFileName, List_P& lp);

/**Funkcja
@param C_R
@param endFileName
@param lp
@param ls
*/
void case6(Register C_R, string, string, List_P& lp, List_S& ls);

/**Funkcja
@param inst
@param C_R
@param endFileName
@param personFileName
@param subjectFileName
@param lp
@param ls
*/
void switchM(int inst, Register C_R, string endFileName, string personFileName, string subjectFileName , List_P& lp, List_S& ls);

/**Funkcja 
@param personFileName
@param subjectFileName
@param endFileName
*/
void runProgram(string personFileName, string subjectFileName, string endFileName);

#endif

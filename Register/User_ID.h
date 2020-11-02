#ifndef User_ID_h
#define User_ID_h

#include <string>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

class User_ID {
protected:
	long long ID;
public:
	User_ID(long long );
	~User_ID();
	long long getID() const;
	void search_ID(long long);
};
#endif
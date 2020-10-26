#include <string>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;

class User_ID {
protected:
	long long ID;
public:
	User_ID(long long);
	~User_ID();
	long long operator==(const User_ID&);
	virtual void write() = 0;
	void search_ID(long long);
};



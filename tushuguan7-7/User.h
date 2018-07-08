#ifndef USER_H_
#define USER_H_

#include"People.h"
#include<fstream>
class User
{
private:
	People *head;
	People *end;
	ifstream in;
	ofstream out;

public:
	void Show_people();
	User();
	~User();
};

#endif USER_H_
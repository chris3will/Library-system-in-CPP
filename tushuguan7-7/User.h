#ifndef USER_H_
#define USER_H_

#include"People.h"
#include<fstream>
class User
{
private:
	People *u_head;
	People *u_end;
	ifstream u_in;
	ofstream u_out;

public:
	User() {};
	~User() {};
	void User_init();
	void Show_people();
	void User_Save();
	void Add_People();
};

#endif USER_H_
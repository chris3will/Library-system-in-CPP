#ifndef USER_H_
#define USER_H_

#include"People.h"
#include"Library.h"
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
	void Add_People();//As a system assistant, to do the most powerful thing!
	void Sign_in();
	void Find_people(string ss);
	void Know_self(People *P_temp);
	void Add_Book();
	void ChangePW(string _id);
};

#endif USER_H_
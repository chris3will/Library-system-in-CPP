
#include "User.h"
#include"People.h"
#include<cstring>
#include<iostream>
#include<string>
#include<fstream>



void User::User_init()
{
	u_head = new People;
	u_head->next = new People;
	u_end = u_head->next;

	ifstream u_in("people.csv");//the book's message were all
							  //stored in this file.And this is a major step in the process.
							  //we read the file first to find if it is empty. for eof()can not be 
							  //used as a tool to tell if it is empty. It is only when we are reading
							  //the file and meet the end can we know its is-empty.//or in.eof won't//
							  //won't return the positive,though it is empty.
							  //char ch = in.get();
	if (u_in.eof())
	{
		cout << "file is empty" << endl;
	}

	//if it is not empty
	while (!u_in.eof())
	{
		string temp;
		getline(u_in, temp);
		u_end->ReadFile(temp);
		if (u_end->s_id[0] == '\0')
			break;
		u_end->next = new People;
		u_end = u_end->next;
	}
}
void User::Show_people()
{
	if (u_head->next == u_end)
	{
		cout << "The library is Empty! Or there must be something wrong in the list! Please find the fault and solve it first before use." << endl;
	}
	else
	{
		cout << "\t**ID**\t**PASSWORD**\t**HOWMANY**\t**" << endl;
		People *pos;
		pos = u_head->next;
		for (pos; pos != u_end; pos = pos->next)
		{
			cout << endl;
			cout << "\t" << pos->s_id << "\t" << pos->s_password << "\t" << endl;
			cout << endl;
		}
	}
	system("pause");
}
void User::User_Save()
{
	u_out.open("people.csv");
	People *pos = u_head->next;
	if (pos == u_end)
	{
		cout << "User is empty.." << endl;
		return;
	}
	else
	{
		for (pos; pos != u_end; pos = pos->next)
		{
			u_out << pos->s_id << "," << pos->s_password<<"\n";
		}
		//for()
	}
	u_out.close();
	cout << "Good Bye! (Save node successfully!)" << endl;
}






#include "User.h"
#include"People.h"
#include<cstring>
#include<iostream>
#include<string>
#include<fstream>


User::User()
{
	head = new People;
	head->next = new People;
	end = head->next;

	ifstream in("people.csv");//the book's message were all
							//stored in this file.And this is a major step in the process.
							//we read the file first to find if it is empty. for eof()can not be 
							//used as a tool to tell if it is empty. It is only when we are reading
							//the file and meet the end can we know its is-empty.//or in.eof won't//
							//won't return the positive,though it is empty.
							//char ch = in.get();
	if (in.eof())
	{
		cout << "file is empty" << endl;
	}

	//if it is not empty
	while (!in.eof())
	{
		//cout << "xigoucishu+1";
		string temp;
		getline(in, temp);
		end->ReadFile(temp);
		if (end->s_id[0] == '\0')
			break;
		end->next = new People;
		end = end->next;
	}
	in.close();
}

void User::Show_people()
{
	if (head->next == end)
	{
		cout << "The library is Empty! Or there must be something wrong in the list! Please find the fault and solve it first before use." << endl;
	}
	else
	{
		cout << "\t**NAME**\t**ISBN**\t**PRICE**\t**WRITER**\t**APPRAISE**\t**STATE**" << endl;
		People *pos;
		pos = head->next;
		for (pos; pos != end; pos = pos->next)
		{
			cout << endl;
			cout << "\t" << pos->s_id << "\t" << pos->s_password << "\t" << endl;
			cout << endl;
		}
	}
	system("pause");
}

User::~User()
{
}


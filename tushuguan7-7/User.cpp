#include "User.h"
#include"People.h"
#include<cstring>
#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <conio.h>
#define MAX_STR_LEN  32  


/*1:return the book
2:find the book
3:delete the book*/
char *GetPasswd(void)
{
	char passwd[MAX_STR_LEN] = { 0 };
	char c;
	int i = 0;
	int len = MAX_STR_LEN - 1;

	while ((c = _getch()) != '\r')
	{
		passwd[i] = c;
		putchar('*');
		i++;
		if (i >= len)
		{
			break;
		}
	}
	return passwd;
}
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
		cout << "File is empty" << endl;
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
		cout << "The User list is Empty! Or there must be something wrong in the list! Please find the fault and solve it first before use." << endl;
	}
	else
	{
		cout << "\t**ID**\t**PASSWORD**\t**HOWMANYBOOK**\t**THEBOOKLIST:"<<endl ;
		People *pos;
		pos = u_head->next;
		for (pos; pos != u_end; pos = pos->next)
		{
			cout << endl;
			cout << "\t" << pos->s_id << "\t" << pos->s_password << "\t" << pos->i_the_book<<"\t";
			if (pos->i_the_book > 0)
			{
				for (int i = 0; i < pos->i_the_book; i++)
				{
					cout << pos->v_Bbook[i] << "\t";
				}
			}
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
			u_out << pos->s_id << "," << pos->s_password << "," << pos->i_the_book<<",";
			if (pos->i_the_book > 0)
			{
				for (int i = 0; i < pos->i_the_book; i++)
				{
					if (i < pos->i_the_book - 1)
					{
						u_out << pos->v_Bbook[i] << ",";
					}
					else
					{
						u_out << pos->v_Bbook[i] << '\n';
					}
				}
			}
			else {
				u_out << '\n';
			}
		}
	}
	u_out.close();
	cout << "..." << endl;
}
void User::Add_People()
{
	char quit;
	while (1)
	{
		u_end->input();
		u_end->next = new People;
		u_end = u_end->next;

		cout << "Continue to add or not?,Y/N" << endl;
		cin >> quit;
		switch (quit)
		{
		case'Y':
		case'y':break;
		case'N':
		case'n': return;
			break;
		default:
			cout << "An error input,again,please..y/n";
			cin >> quit;
		}
	}
}
void User::Sign_in()
{
	cout << "Hello Welcome to our library, please enter your id and password" << endl;
	string t_id;
	string t_password;
	int alive = 0;
	int Enter_Account;
	int wrong_num = 1;
	while (alive==0)
	{
		if (wrong_num > 1)
		{
			cout << "This is the " << wrong_num << " time for you to sign in, Be careful, Please!" << endl;
			cout << "Or you can choose to backward sometime to think the ID-PASSWORD.\n(If so, please enter ***** as your next ID)" << endl;
		
		}
		cout << "Please enter your ID" << endl;
		cin >> t_id;
		if (t_id == "*****")
		{
			return;
		}
		cout << endl;
		cout << "Please enter your password now!" << endl;
		t_password = GetPasswd();
		
		Enter_Account = t_id.size();
		People *pos = u_head->next;
		for (pos; pos != u_end; pos = pos->next)
		{
			if (pos->s_id == t_id)
			{
				if (pos->s_password == t_password)
				{
					alive = 1;
				}
			}
		}
		wrong_num++;
	}
	People *pos = u_head->next;
	if (pos == u_end)
	{
		cout << "Sorry, we now have no user once avaliable." << endl;
	}
	else
	{
		for (pos; pos != u_end; pos = pos->next)
		{
			if (pos->s_id == t_id)
			{
				if (pos->s_password == t_password)
				{
					alive = 1;
					switch (Enter_Account)//根据账号长度判断用户类型
					{
					case 1:
						cout << "Hi System assistant";
						break;
					case 2:
						cout << "Hello Book assistant";
						break;
					case 3:
						cout << "Hey Teacher";
						break;
					case 4:
						cout << "Student";
						break;
					default:
						break;
					}
					cout << endl;
					cout << "Sign in successfully!" << endl;
					cout << endl;
					cout << "So what do you want to do now?" << endl;
					int choice;
					string ss;
					int round = 1;
					while (1)
					{
						cout << endl;
						if (round > 1)
						{
							cout << "***So, what about now?***" << endl;
						}
						if (Enter_Account == 1)
						{
							cout << "\t1:Find a book to do something\n\t2:Help somebody change the password\n\t3:Find a message about a people\n\t4:Backward" << endl;
							cin >> choice;
							if (choice == 3)
							{
								cout << "Please enter the Id of the person you want to know" << endl;
								cin >> ss;
							}
							switch (choice)
							{
							case 1:pos->FindBook(); break;
							case 2:; break;
							case 3:Find_people(ss); break;
							case 4:return;
							}
						}
						else if (Enter_Account == 2)
						{
							cout << "1:Find a book to do somthing\n2:Backward" << endl;
							cin >> choice;
							switch (choice)
							{
							case 1:pos->FindBook();
							case 2:return;
							}
						}
						else if (Enter_Account == 3)
						{
							cout << "1:Find a book for some information or borrow some.\n2:Backward" << endl;
							cin >> choice;
							switch (choice)
							{
							case 1:pos->FindBook();
							case 2:return;
							}
						}
						else
						{
							cout << "1:Find a book for some information or borrow some.\n2:Backward" << endl;
							cin >> choice;
							switch (choice)
							{
							case 1:pos->FindBook();
							case 2:return;
							}
						}
					}
				}
			}
		}
		if (alive == 0)
		{
			cout << "You must input something wrong! Please think about it seriously then come back to us!" << endl;
		}
	}
}
void User::Find_people(string ss)
{
	People *pos = u_head->next;
	if (pos == u_end)
	{
		cout << "Sorry, there is no one for you to find!" << endl;
	}
	else
	{
		int alive = 0;
		for (pos; pos != u_end; pos = pos->next)
		{
			if (pos->s_id == ss)
			{
				alive = 1;
				cout << pos->s_id << "\t" << pos->s_password << "\t" << pos->i_the_book;
				if (pos->i_the_book > 0)
				{
					cout << "\t";
					int k = pos->i_the_book;
					while (k > 0)
					{
						cout << pos->v_Bbook[k - 1]<<"\t";
						k--;
					}
				}
				cout << endl;
			}
		}
		if (alive == 0)
		{
			cout << "Sorry, we can't find him in the list!" << endl;
		}
	}
}




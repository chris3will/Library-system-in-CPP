#include "User.h"
#include"People.h"
#include"Library.h"
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
	system("cls");
	if (u_head->next == u_end)
	{
		cout << "The User list is Empty! Or there must be something wrong in the list! Please find the fault and solve it first before use." << endl;
	}
	else
	{
		cout << "        " << " -------------------------------------------------------" << endl;
		cout << "\t**ID****PASSWORD****HOWMANYBOOK****THEBOOKLIST:" << endl;
		People *pos;
		pos = u_head->next;
		for (pos; pos != u_end; pos = pos->next)
		{
			cout << endl;
			cout << "\t" << pos->s_id << "\t" << pos->s_password << "           " << pos->i_the_book << "                ";
			if (pos->i_the_book > 0)
			{
				for (int i = 0; i < pos->i_the_book; i++)
				{
					cout << pos->v_Bbook[i] << "        ";
				}
			}
			cout << endl;
		}

		cout << "What do you want to do now? \n1:Help somebody to change his password or \n2:Add a new user in our list. Please enter your choice!" << endl;
		char choice;
		cin >> choice;
		if (choice == '1')
		{
			cout << "Please tell us the id, if you want to help him to change the word or for some other reason." << endl;
			string s_changeone;
			cin >> s_changeone;
			ChangePW(s_changeone);
		}
		else if (choice == '2')
		{
			Add_People();
		}
		else
		{
			cout << "Backward in success!" << endl;
		}


	}
	system("pause");

}
void User::ChangePW(string _id)
{
	int alive = 0;
	string thenew;
	People *pos = u_head->next;
	if (pos == u_head)
	{
		cout << "Sorry, there is no one in the list." << endl;
	}
	else
	{
		for (pos; pos != u_end; pos=pos->next)
		{
			if (pos->s_id == _id)
			{
				alive = 1;
				cout << "We find the user you want now, Do you really want to change his password?(**Enter 1 or others**)" << endl;
				int choice;
				cin >> choice;
				if (choice == 1)
				{
					cout << "Please tell us the new password you want to achieve." << endl;
					cin >> thenew;
					pos->s_password = thenew;
					cout << "Congratulation!" << endl;
				}
			}
		}
	}
	cout << "See you!" << endl;
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
		//t_password = GetPasswd();
		cin >> t_password;
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
					}
					cout << endl;
					cout << "You login successfully!" << endl;
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
							system("cls");
							cout << "***So, what about now?***" << endl;
						}
						if (Enter_Account == 1)
						{
							cout << "\t1:Return a book\n\t2:Find a book to do something\n\t3:Help somebody change the password.(*Unachieved*)\n\t4:Find a message about a person(include yourself.\n\t5:Show all the people in the list.\n\t6:Re-login.\n\t7:Backward to windows." << endl;
							cin >> choice;
							if (choice == 3)
							{
								cout << "Please enter the Id of the person you want to know." << endl;
								cin >> ss;
							}
							switch (choice)
							{
							case 1:pos->ReturnBook(); break;
							case 2:pos->FindBook(); break;
							case 3:; break;
							case 4:Find_people(ss); break;
							case 5:Show_people(); break;
							case 6:Sign_in(); break;
							case 7:return; break;
							}
						}
						else if (Enter_Account == 2)
						{
							cout << "1:Find a book to do something.\n2:Know the book you have borrowed.\n3:Return a book or a kind of books.\n4:Backward to windows." << endl;
							cin >> choice;
							switch (choice)
							{
							case 1:pos->FindBook(); break;
							case 2:Know_self(pos); break;
							case 3:pos->ReturnBook(); break;
							case 4:return; break;
							}
						}
						else if (Enter_Account == 3)
						{
							cout << "1:Find a book to do something.\n2:Know the book you have borrowed.\n3:Return a book or a kind of books.\n4:Backward to windows." << endl;
							cin >> choice;
							switch (choice)
							{
							case 1:pos->FindBook(); break;
							case 2:Know_self(pos); break;
							case 3:pos->ReturnBook(); break;
							case 4:return; break;
							}
						}
						else
						{
							cout << "1:Find a book to do something.\n2:Know the book you have borrowed.\n3:Return a book or a kind of books.\n3:Backward to windows." << endl;
							cin >> choice;
							switch (choice)
							{
							case 1:pos->FindBook(); break;
							case 2:Know_self(pos); break;
							case 3:pos->ReturnBook(); break;
							case 4:return; break;
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
	return;
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
void User::Know_self(People *P_temp) 
{
	People *pos = u_head->next;
	if (pos == u_end)
	{
		cout << "Sorry, there is no one on the list." << endl;
	}
	else
	{
		int alive = 0;
		for (pos; pos != u_end; pos = pos->next)
		{
			if (pos->s_id == P_temp->s_id)
			{
				alive = 1;
				cout << "Here is the book you have borrowed!" << endl;
				int k = P_temp->i_the_book;
				if(k>0)
				while (k)
				{
					cout << P_temp->v_Bbook[k - 1] << "\t";
					k--;
				}
			}
		}
		if (alive == 1)
		{
			cout << endl;
		}
	}
}
void User::Add_Book()
{
	Library test;
	test.Lib_init();
	test.Save();
}




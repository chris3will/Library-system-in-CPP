#include "User.h"
#include"People.h"
#include<cstring>
#include<iostream>
#include<string>
#include<fstream>
/*1:return the book
2:find the book
3:delete the book*/
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
	cout << "(Save node successfully!)" << endl;
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
	cout << "Hello,Wplease enter your id and pass word" << endl;
	string t_id;
	string t_password;
	cin >> t_id;
	cout << endl;
	cout << "Please enter your password now!" << endl;
	cin >> t_password;
	People *pos = u_head->next;
	if (pos == u_end)
	{
		cout << "Sorry, we now have now user once avaliable." << endl;
	}
	else
	{
		int alive = 0;
		int Enter_Account = t_id.size();
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
					cout << " Sign in successfully!" << endl;
					cout << "So what do you want to do now?" << endl;
					if (Enter_Account == 1)
					{
						cout<<
					}
						//pos->FindBook();
						//pos->ReturnBook();
					
				}
				
			}
		}
		if (alive == 0)
		{
			cout << "You must input something wrong!" << endl;
		}
	}

}




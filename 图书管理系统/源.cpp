#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include"People.h"
using namespace std;

class PeopleLib 
{
private:
	static int count;
	People *head;
	People *tail;
	ifstream in;
	ofstream out;
public:
	PeopleLib();
	~PeopleLib();
	void Add_People();
	void Del_People();
	void FindPeople();
	void Save();
	void Clean();
	void Sort_instring();
	int GetaPeoplename(string P_name);
	void ShowAllPeople();
}

PeopleLib::PeopleLib() {
	head = new People;
	head->next = new People;
	end = head->next;
	ifstream in("peoplelist.txt");
}

char ch = in.get();
if (in.eof())
{
	cout << "file is empty" << endl;
}

//if it is not empty
while (!in.eof())
{
	end->ReadFile(in);
	if (end->s_name[0] == '\0')
		break;
	end->next = new People;
	end = end->next;
}

PeopleLib::~PeopleLib()
{
	Save();
	People *pos = head->next;
	People *temp;
	while (pos != end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head, end;
}

void PeopleLib::Add_People()
{
	char quit;
	while (1)
	{
		end->input();
		end->next = new People;
		end = end->next;

		cout << "continue or not?,Y/N" << endl;
		cin >> quit;
		switch (quit)
		{
		case'Y':
		case'y':break;
		case'N':
		case'n': return;
			break;
		default:
			cout << "error input,again,please..y/n";
			cin >> quit;
		}
	}
	cout << "add People successfully" << endl;
	system("pause");
}


void PeopleLib::Del_People()
{
	int del_flag = 0;
	string t_name;
	if (head->next = end)
	{
		cout << "empty..." << endl;
		return;
	}

	cout << "please enter the name you want to delete:";
	cin >> t_name;

	People *p = head->next;
	People *q = head;
	for (p; p != end; p->next)
	{
		if (p->s_name == t_name)
		{
			del_flag = 1;
			q->next = p->next;
			delete p;
			break;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	if (del_flag == 0)
	{
		cout << "Can't find the name you want." << endl;
	}
	cout << "del node successfully!" << endl;
	system("pause");
}
int PeopleLib::GetaPeoplename(string st_name)
{
	int count = 0;
	Book *pos = head->next;
	for (pos; pos != end; pos = pos->next)
	{
		if (st_name == pos->s_name)
		{
			count++;
		}
	}
	return count;
}
void PeopleLib::FindPeople()//input the name of book then output all the message about the book ,including the remain number.
{
	string t_name;
	People *pos = head->next;
	if (pos == end)
	{
		cout << "The library is empty now,we can find no book here!" << endl;
	}
	else
	{
		cin >> t_name;
		int count = GetPeoplename(t_name);
		if (count>0)
		{
			while (pos->s_name != t_name)
				pos = pos->next;
			cout << endl;
			cout << "\t" << pos->s_name << "\t" << pos->s_id;
		}
		else
		{
			cout << "Sorry,we can't find the people" << endl;
		}
	}
	system("pause");
}
void PeopleLib::Save()
{
	out.open("Peoplelist.txt");
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "PeopleLib is empty.." << endl;
		return;
	}
	else
	{
		for (pos; pos != end; pos = pos->next)
		{
			out << "\t" << pos->s_name << "\t" << pos->s_isbn << "\t" << pos->s_price
				<< "\t" << pos->s_writer << "\t" << pos->s_point;
		}
	}
	out.close();
	cout << "Save node successfully!" << endl;
}


void PeopleLib::ShowAllPeople()
{
	if (head->next == end)
	{
		cout << "empty" << endl;
	}
	People *pos;
	pos = head->next;
	for (pos; pos != end; pos = pos->next)
	{
		cout << endl;
		cout << "\t" << pos->s_name << "\t" << pos->s_id;
		cout << endl;
	}
	system("pause");
}


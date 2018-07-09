#include "People.h"
#include"Library.h"
#include"Book.h"
#include<iostream>
using namespace std;
People::People()
{
	count++;//
}

People::People(int id, string pawd)//
{
	s_id = id;
	s_password = pawd;
}


People::~People()
{
}

void People::FindBook() {
	cout << "find which book you want：" << endl;
	string str1;
	cin >> str1;
	void Library::Findacurate();//Find the book's information but NOW still can not make a bond to the one who borrowed it.
}

void People::ChgPawd()
{
	cout << "请输入当前的密码：";
	string str1, str2;
	cin >> str1;
	if (str1 == s_password) {
		cout << "请输入新的密码：";
		void People::SetPawd();
	}
}

void People::SetPawd(string s1)
{
	s_password = s1;
	cout << "Success to Set PassWord";
}

BookAdmer::~BookAdmer()
{
}

BookAdmer::BookAdmer(int t_id, string t_pawd)
{
	t_id = s_id;
	t_pawd = s_password;
}

void BookAdmer::AddBook()
{
	void Library::Add_Booknode();
}

void BookAdmer::DeleteBook()
{
	void Library::Del_Booknode();
}

void BookAdmer::FindWhoBorrow()
{
	void 
}

void BookAdmer::ShowBooks()
{
	void Library::Show_allbook();
}


BookAdmer::~BookAdmer()
{
}

void Systemadmer::AddUsers()
{
	int i;
	cout << "AddUsers:";
	cout << "Choice people's authority" << endl;
	cout << "1.BOOK Admer\n2.Teacher\n3.Student";
	cin >> i;
	if (i == 1) {
		new BookAdmer();
	}
	else if (i == 2) {
		new Teacher();
	}
	else if (i == 3) {
		new Student();
	}
	else {
		cout << "input error";
	}
}

void Systemadmer::DeleteUsers()
{
	int i;
	cout << "DeleteUsers:";
	cout << "Choice who you want to delete?" << endl;
	cout << "1.Name 2.Id";
	cin >> i;
	if (i == 1) {
		void FindName();
	}
	else if (i == 2) {
		void FindId();
	}
	else {
		cout << "input error";
	}
}

void Student::BookReport()
{
	cout << "Please make a point to the book";
	cout << "1.* 2.** 3.*** 4.**** 5.******";
	int i;
	cin >> i;
	Book::s_point = i;

}

void Student::ShowBooks()
{

	for (int i = 0; i < NumOfBook; i++) {
		cout << books[i].GetName() << endl;
	}
}

void Teacher::ShowBooks()
{

	for (int i = 0; i < NumOfBook; i++) {
		cout << books[i].GetName() << endl;
	}
}

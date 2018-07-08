#include "People.h"
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
	cout << "输入你要查找的书籍：" << endl;
	string str1;
	cin >> str1;
	void Library::FindBook(str1);
}

void People::ChgPawd()
{
	cout << "请输入当前的密码：";
	string str1,str2;
	cin >> str1;
	if (str1 == s_password) {
		cout << "请输入新的密码：";
		cin >> str2;
		void People::SetPawd(str2);
	}
}

void People::SetPawd(string s1)
{
	s_password = s1;
	cout << "Success to Set PassWord";
}

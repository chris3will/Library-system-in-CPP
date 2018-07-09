#pragma once
# include <iostream>
using namespace std;
class People
{
public:
	People();
	People(int id, string pawd);//
	virtual ~People();
	void FindBook();//
	void ChgPawd();//
	void SetPawd(string);//
	People * next;
	People * end;
private:

	int s_id;//
	string s_password;//
	int static count;
};

int People::count = 0;//

class BookAdmer :public People
{
public:
	BookAdmer() {};
	~BookAdmer();
	BookAdmer(int t_id, string t_pawd) :People(t_id, t_pawd) {};
	void AddBook();
	void DeleteBook();
	void FindWhoBorrow();
	void ShowBooks();
};

class Systemadmer :public BookAdmer {
public:
	~Systemadmer();
	Systemadmer(int t_id, string t_pawd) :BookAdmer(t_id, t_pawd) {};
	void AddUsers();
	void DeleteUsers();
	void ChangeUserPawd();
};

class Student :public People {
public:
	Student() {};
	Student(int t_id, string t_pawd) :People(t_id, t_pawd) {};
	~Student() {};
	void BookReport();
	void ShowBooks();

private:
	int NumOfBook;
	Book * books;
	const int LimitBooks = 10;

};


class Teacher :public People {
public:
	Teacher() {};
	Teacher(int t_id, string t_pawd) :People(t_id, t_pawd) {};
	~Teacher() {};
	void BookReport();
	void ShowBooks();
private:
	int NumOfBook;
	Book *books;
	const int LimitBooks = 30;

};
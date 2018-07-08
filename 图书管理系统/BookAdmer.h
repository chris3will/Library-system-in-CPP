
#include"Library.h"
#include"People.h"
class BookAdmer:public People
{
public:
	BookAdmer() {};
	~BookAdmer();
	BookAdmer(int t_id, string t_pawd) :People(t_id, t_pawd) {};
	void AddBook();
	void DeleteBook();
	void FindWhoBorrow();
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
	Book books[];
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
	Book books[];
	const int LimitBooks = 30;

};
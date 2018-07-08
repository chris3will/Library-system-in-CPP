#include "BookAdmer.h"



BookAdmer::~BookAdmer()
{
}

BookAdmer::BookAdmer(int t_id, string t_pawd)
{
}

void BookAdmer::AddBook()
{
	void Library::AddBook();
}

void BookAdmer::DeleteBook()
{
	void Library::DeleteBook();
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
	Book::Book_rep(Book, i);

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

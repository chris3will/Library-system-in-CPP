#include<iostream>
#include"Book.h"
#include<ctime>
#include"Library.h"
using namespace std;
Library::Library()
{
	head = new Book;
	head->next = new Book;
	end = head->next;

	ifstream in("test.csv");//the book's message were all
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
		if (end->s_name[0] == '\0')
			break;
		end->next = new Book;
		end = end->next;
	}
}
//xigou function
Library::~Library()
{
	Save();
	Book *pos = head->next;
	Book *temp;
	while (pos != end)
	{
		temp = pos;
		pos = pos->next;
		delete temp;
	}
	delete head, end;
}
//add new book
void Library::showtime()
{
	time_t now_time = time(0);
	struct tm tt;
	now_time = time(0);
	localtime_s(&tt, &now_time);
	cout << tt.tm_hour << "-" << tt.tm_min << "-" << tt.tm_sec;
	cout << endl;

}
void Library::Surface()//We now just have a common  surface without distinguish the identity.
{
	cout << "Now the time is:"; showtime();
	cout << "Welcome to our library!" << endl;
	int i_choice;
	while (1)
	{
		cout << "What are you want to do now?" << endl;
		cout << "1:Look all the book" << endl;
		cout << "2:Add a book" << endl;
		cout << "3:Delete(Borrow?) a book" << endl;
		cout << "4:Return a book" << endl;
		cout << "5:Clear the list(attention)" << endl;
		cout << "6:Find a book" << endl;//if he is a reader,add the function for him to borrow the book.
		cout << "7:Leave the library" << endl;
		cin >> i_choice;
		if (i_choice >= 1 && i_choice <= 7)
		{
			switch (i_choice)
			{
			case 1:Show_allbook(); break;
			case 2:Add_Booknode(); break;
			case 3:Del_Booknode(); break;
			case 4:; break;
			case 5:Clean(); break;
			case 6:Findacurate(); break;
			case 7:Save(); break;
			}
		}
		else
		{
			cout << "You entered something beyond our ability!" << endl;
		}
		
		if (i_choice == 7)
		{
			return;
		}
	}
	return;
}
void Library::Add_Booknode()
{
	char quit;
	while (1)
	{
		end->input();
		end->next = new Book;
		end = end->next;

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
	cout << "Add Book successfully" << "\t";
	showtime();
	cout<<endl;
	system("pause");
	system("cls");
}
void Library::Add_Booknode(Book *B_temp)
{
	end->s_name = B_temp->s_name;
	end->s_isbn = B_temp->s_isbn;
	end->s_price = B_temp->s_price;
	end->s_writer = B_temp->s_writer;
	end->s_point = B_temp->s_point;
	end->i_flag = 0;
	end->next = new Book;
	end = end->next;
	cout << "We have made it!" << endl;
}
void Library::Clean()
{
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "The library is empty now£¬there is no need to clean it." << endl;
	}
	else
	{
		ofstream out("booklist.txt", ios::trunc);
		out.close();
		system("pause");
		exit(0);
	}
}
void Library::Modify()
{
	string t_name;
	cout << "Enter the name you want to modify:";
	cin >> t_name;
	Book *pos = head->next;
	//int i_num = Getabooknum(t_name);
	
	for (pos; pos != end; pos = pos->next)
	{
		if (t_name == pos->s_name)
		{
			pos->input();
			break;
		}
	}
	cout << "Modify successfully..." << endl;
	system("pause");
}//change the information of a book.
void Library::Del_Booknode(string t_name)
{
	int num = Getabooknum(t_name);//the flag==0's num.
	Book *pos = head->next;
	int i_actDel;
	if (num > 0)
	{//make sure here are the book we need to delete.
		cout << "Attention!Here,we have:" << num << " copy(copies) remain that are not be borrowed currently. How many book(s) do you want to delete?" << endl;
		cin >> i_actDel;
		cout << "\b";
		for (int i = 0; i < i_actDel; i++)
		{
			Book *p = head->next;
			Book *q = head;
			for (p; p != end; p->next)
			{
				if (p->s_name == t_name)
				{
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
		}
		if (i_actDel>0)
			cout << "You have delete the book successfully!" << endl;
	}
	cout << "We have made it as you wish!" << endl;
}//in corporation with other function!
void Library::Del_Booknode()
{
	string t_name;
	Book *pos = head->next;
	if (pos	== end)
	{
		cout << "Empty...So there is nothing to delete" << endl;
		return;
	}

	cout << "Please enter the name you want to delete:";
	cin >> t_name;
	cout << endl;
	int num = Getabooknum(t_name);//the flag==0's num.
	int i_actDel;
	
	if (num > 0)
	{//make sure here are the book we need to delete.
		cout << "Attention!Here,we have:" << num << " copy(copies) remain that are not be borrowed currently. How many book(s) do you want to delete?" << endl;
		cin >> i_actDel;
		cout << "\b";
		for (int i = 0; i < i_actDel; i++)
		{
			Book *p = head->next;
			Book *q = head;
			for (p; p != end; p->next)
			{
				if (p->s_name == t_name)
				{
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
		}
		if(i_actDel>0)
		cout << "You have delete the book successfully!" << endl;
	}
	else
	{
		cout << "Can't find the name you want." << endl;
	}



	system("pause");
	system("cls");
}
void Library::Borrowbook()
{//this fuction must be used by a student or a teacher. We need 
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "Sorry, my dear reader. We have no book to lend now." << endl;
	}
	else
	{
		cout << "Please tell us which book do you want to borrow?" << endl;
	}
}//still not accomplish!
int Library::Getabooknum(string st_name)
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
}//Once all we have in the library ,but whether it can be borrow, we need other function to tell.
void Library::Findacurate()//input the name of book then output all the message about the book ,including the remain number.
{
	string t_name;
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "The library is empty now,we can find no book here!" << endl;
	}
	else
	{
		cout << "Please enter the book's name,if you want to know something about it." << endl;
		cin >> t_name;
		int count = Getabooknum(t_name);
		if (count>0)
		{//We can find the book in library.
			while (pos->s_name != t_name)
				pos = pos->next;
			cout << endl;
			cout << "\t" << pos->s_name << "\t" << pos->s_isbn << "\t" << pos->s_price
				<< "\t" << pos->s_writer << "\t" << pos->s_point << "\t" << "Remain:" << count << endl;
			
			cout << "Do you want to borrow it(1)? Or delete it(2)? Or Add a new one just same like it(3)?" << endl;
			int choice;
			cin >> choice;
			cout << "\b";
			switch (choice)
			{
				case 1:Borrowbook(); break;
				case 2:Del_Booknode(t_name);break;
				case 3:Add_Booknode(pos);break;
			}
			
		}
		else
		{
			cout << "Sorry,we can't find the book here now,maybe it was borrowed by somebody else!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void Library::Save()
{
	out.open("test.csv");
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "Library is empty.." << endl;
		return;
	}
	else
	{
		for (pos; pos != end; pos = pos->next)
		{
			out << pos->s_name << "," << pos->s_isbn << "," << pos->s_price
				<< "," << pos->s_writer << "," << pos->s_point<<","<<pos->i_flag<<"\n";
		}
	}
	out.close();
	cout << "Good Bye! (Save node successfully!)" << endl;
}
//show the library
void Library::Show_allbook()
{
	if (head->next == end)
	{
		cout << "The library is Empty! Or there must be something wrong in the list! Please find the fault and solve it first before use." << endl;
	}
	else
	{
		cout << "\t**NAME**\t**ISBN**\t**PRICE**\t**WRITER**\t**APPRAISE**\t**STATE**" << endl;
		Book *pos;
		pos = head->next;
		for (pos; pos != end; pos = pos->next)
		{
			cout << endl;
			cout << "\t" << pos->s_name << "\t" << pos->s_isbn << "\t" << pos->s_price
				<< "\t" << pos->s_writer << "\t" << pos->s_point << "\t" << pos->i_flag << endl;
			cout << endl;
		}
	}
	system("pause");
}
void Library::Swap_Booknode(Book *p, Book *q)
{
	string tname;
	string tisbn;
	string tprice;
	string twriter;
	double tpoint;
	q->s_name.swap(p->s_name);
	q->s_isbn.swap(p->s_isbn);
	q->s_price.swap(p->s_price);
	q->s_writer.swap(p->s_writer);
	tpoint = p->s_point;
	p->s_point = q->s_point;
	q->s_point = tpoint;
}
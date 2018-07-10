#include<iostream>
#include"Book.h"
#include<ctime>
#include"Library.h"
using namespace std;
Library::Library()
{
	/*
	No file working in the gou zao function, we use a Lib_init() instead
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
	*/
}
//constructed function
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
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "        " << " ---------------"; cout << "Now the time is:"; showtime(); cout << "-----------------" << endl;
	cout << endl;
	cout << "        " << " --------------- "; cout << "Welcome to our library!"; cout << "----------------" << endl;
	cout << endl;

	int i_choice;
	while (1)
	{
		cout << "        " << " -------------------------------------------------------" << endl;
		cout << "        " << "丨" << "              What are you want to do now?           丨" << endl;
		cout << "        " << "丨                                                     丨" << endl;
		cout << "        " << "丨" << "               1:Look all the book                   丨" << endl;
		cout << "        " << "丨" << "               2:Add a book                          丨" << endl;
		cout << "        " << "丨" << "               3:Delete(Borrow?) a book              丨" << endl;
		cout << "        " << "丨" << "               4:Return a book                       丨" << endl;
		cout << "        " << "丨" << "               5:Clear the list(attention)           丨" << endl;
		cout << "        " << "丨" << "               6:Find a book                         丨" << endl;//if he is a reader,add the function for him to borrow the book.
		cout << "        " << "丨" << "               7:Leave the library                   丨" << endl;
		cout << "        " << " -------------------------------------------------------" << endl;
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
			cout << "Now the time is:"; showtime();
			cout << "Please tell us what do you want to do now?" << endl;
			cout << "1:Display all the book" << endl;
			cout << "2:Add a book" << endl;
			cout << "3:Delete(borrow?) a book" << endl;
			cout << "4:Return the book" << endl;
			cout << "5:Clear the list(attention)" << endl;
			cout << "6:Find a book" << endl;
			cout << "7:Leave the library" << endl;
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
	cout << "Do you want to see the new booklist?(If so, please enter 1)" << endl;
	char choice;
	cin >> choice;
	if (choice == '1')
	{
		Show_allbook();
	}
	else
	{
		
	}
}
void Library::Clean()
{
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "The library is empty now，there is no need to clean it." << endl;
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
	cout << "Do you want to see the new booklist?(If so, please enter 1)" << endl;
	char choice;
	cin >> choice;
	if (choice == '1')
	{
		Show_allbook();
		
	}
	else
	{
		
	}
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
void Library::Borrowbook(Book *pos,People *temp)
{//this fuction must be used by a student or a teacher. We need
	if (pos->i_flag == 1 || (temp->i_the_book >= 10 && temp->s_id.size() == 4))
	{
		cout << "Sorry,you can't borrow it, for it has be borrowed by others before or you have gotten to the limited num!" << endl;
	}
	else if (temp->i_the_book >= 30 && temp->s_id.size() < 4)
	{
		cout << "Sorry , you can't borrow it, for you have gotten to the limited num!" << endl;
	}
	else
	{
		pos->i_flag = 1;//show its state 's change.
		pos->s_people = temp->s_id;
		temp->v_Bbook.push_back(pos->s_name);
		temp->i_the_book++;
		Save();
		cout << "We have helped you to borrow it, and we make a record in our list." << endl;
	}
}
void Library::Returnbook(People *temp,string s_dest)
{
	int alive = 0;
	Book *pos = head->next;
	if (pos == end)
	{
		cout << "There is no book for you to return, there must be something wrong hh!" << endl;
	}
	else
	{
		for (pos; pos != end; pos = pos->next)
		{
			if (pos->s_name == s_dest&&pos->i_flag==1)
			{//we find the combination
				alive = 1;
				pos->i_flag = 0;
				pos->s_people = '\0';
				temp->i_the_book--;
				vector<string>::iterator it = temp->v_Bbook.begin();
				while (it<temp->v_Bbook.end())
				{
					if (*it == s_dest)
					{
						it = temp->v_Bbook.erase(it);
						continue; //删除后it已经指向下一个元素了，所以不能++了，直接continue
					}
					++it;
				}
				cout << "Congratulation!" << endl;
			}
		}
		if (alive == 0)
		{
			cout << "Sorry, you don't have the book, be carefule please." << endl;
		}
	}
}
int Library::Getabooknum(string st_name)
{
	int count = 0;
	Book *pos = head->next;
	for (pos; pos != end; pos = pos->next)
	{
		if (st_name == pos->s_name&&pos->i_flag==0)
		{
			count++;
		}
	}
	return count;
}//Once all we have in the library ,but whether it can be borrow, we need other function to tell.
int Library::GetALLbooknum(string st_name)
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
void Library::Findacurate(int i_id, People *temp)
{
	system("cls");
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
		int countall = GetALLbooknum(t_name);
		//if (count>0)
		//{//We can find the book in library.
		if (count > 0)
		{
			while ((pos->s_name != t_name)||pos->i_flag==1)
			{
				pos = pos->next;
			}
		}
		if (countall == 0)
		{
			cout << "The book is not in our library! Sorry for that." << endl;
		}
		else
		{
			cout << endl;
			cout << "\t" << pos->s_name << "\t" << pos->s_isbn << "\t" << pos->s_price
			<< "\t" << pos->s_writer << "\t" << pos->s_point << "\t" << "Remain:" << count << endl;
		}
		//It 's a bit hard for us to find who has(have) borrowed the book now, sorry!
			int choice;
			cout << "What do you want to do now?" << endl;
			if (i_id == 1 || i_id == 2)
			{//system assistant
				cout << "1:Delete it (only when the remain>0 Or for some readers is keeping the book)\n2:Add a new just like it 3:Borrow it (only when remain>0)4:Find the one who borrowed it(***But it a bit hard for my ablilty, sorry***)" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:Del_Booknode(pos->s_name); break;
				case 2:Add_Booknode(pos); break;
				case 3:Borrowbook(pos, temp); break;//we need to store the change of state and the one who borrowed it.
				case 4:break;
				}
			}
			else if (i_id == 3 || i_id == 4)
			{//teacher,student
				cout << "Do you want to borrow it (only when remain>0)? If so please enter 1 or enter others for the return back." << endl;
				cin >> choice;
				if (choice == 1)
				{
					Borrowbook(pos, temp);
					
				}
				else
				{
					
				}
			}
		}
	//else
	////all the book have be borrowed by others.
	//	cout << "Sorry,we can't find the book here now,maybe it was borrowed by somebody else!" << endl;
	//
	system("pause");
	system("cls");
}
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
			switch (choice)
			{
				//case 1:Borrowbook(pos,temp); break;
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
				<< "," << pos->s_writer << "," << pos->s_point<<","<<pos->i_flag<<","<<pos->s_people<<"\n";
		}
	}
	out.close();
	cout << "..." << endl;
}
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
void Library::Lib_init()
{
	head = new Book;
	head->next = new Book;
	end = head->next;

	ifstream in("Book.csv");//the book's message were all
							//stored in this file.And this is a major step in the process.
							//we read the file first to find if it is empty. for eof()can not be 
							//used as a tool to tell if it is empty. It is only when we are reading
							//the file and meet the end can we know its is-empty.//or in.eof won't//
							//won't return the positive,though it is empty.
							//char ch = in.get();
	if (in.eof())
	{
		cout << "File is empty" << endl;
	}

	//if it is not empty
	while (!in.eof())
	{
		string temp;
		getline(in, temp);
		end->ReadFile(temp);
		if (end->s_name[0] == '\0')
			break;
		end->next = new Book;
		end = end->next;
	}
}
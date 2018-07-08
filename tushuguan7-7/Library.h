#ifndef LIBRARY_H_
#define LIBRARY_H_
#include<cstring>
#include"Book.h"
class Library 
{
//里面存着各个结点，每个结点中存储着书的信息
private:
	static int count;
public:
	Library();
	~Library();
	//关于图书馆类所用到的函数
	void showtime();
	void Surface();
	void Add_Booknode();//Add the book,whatever the library buy from others or from the reader who once borrowed it;
	void Add_Booknode(Book *B_temp);
	void Del_Booknode(string t_name);
	void Del_Booknode();//Delete the book from the list which shows the book remain in the library.
	void Borrowbook();//
	void Findacurate();//Find the book's information but NOW still can not make a bond to the one who borrowed it.
	void Modify();//Change the information of the book;
	//void FindReader();
	//void Load();
	void Save();//save
	void Clean();//clean
	void Swap_Booknode(Book *q, Book *p);//sawp the node.
	void Sort_instring();//排序，以字符串未关键词
	int Getabooknum(string st_name);//得到书籍余量
	void Show_allbook();//显示所有书籍
private:
	Book * head;
	Book *end;
	ifstream in;
	ofstream out;
};
#endif // !LIBRARY_H_
#pragma once

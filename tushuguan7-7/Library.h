#ifndef LIBRARY_H_
#define LIBRARY_H_
#include<cstring>
#include"People.h"
#include"Book.h"
class People;
class User;
class Library 
{
//������Ÿ�����㣬ÿ������д洢�������Ϣ
private:
	static int count;
public:
	Library();
	~Library();
	//����ͼ��������õ��ĺ���
	void showtime();
	void Lib_init();
	void Surface();
	void Add_Booknode();//Add the book,whatever the library buy from others or from the reader who once borrowed it;
	void Add_Booknode(Book *B_temp);
	void Del_Booknode(string t_name);
	void Del_Booknode();//Delete the book from the list which shows the book remain in the library.
	void Borrowbook(Book *pos,People *temp);//
	void Findacurate();//Find the book's information but NOW still can not make a bond to the one who borrowed it.
	void Findacurate(int i_id,People *temp);
	void Modify();//Change the information of the book;
	//void FindReader();
	//void Load();
	void Save();//save
	void Clean();//clean
	void Returnbook(People *temp,string s_dest);
	void Swap_Booknode(Book *q, Book *p);//sawp the node.
	void Sort_instring();//�������ַ���δ�ؼ���
	int Getabooknum(string st_name);//�õ��鼮����
	void Show_allbook();//��ʾ�����鼮
private:
	Book * head;
	Book *end;
	ifstream in;
	ofstream out;
};
#endif // !LIBRARY_H_
#pragma once

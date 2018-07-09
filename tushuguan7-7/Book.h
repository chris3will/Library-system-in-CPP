#ifndef BOOK_H_
#define BOOK_H_
#define IN_PARAM
#define OUT_PARAM
#include<string>
#include<fstream>
using namespace std;

class Book
{
public:
	Book * next;
	string s_name;
	string s_isbn;
	string s_price;
	string s_writer;
	double s_point;
	int i_flag;
	string s_people;
public:
	Book(){}
	Book(string s1, string s2, string s3, string s4, double po)
	{
		s_name = s1;
		s_isbn = s2;
		s_price = s3;
		s_writer = s4;
		s_point = po;
		i_flag = 0;//store the situation of a book;
		s_people ='\0';
	}
	void updatepoint(double t_d);
	void input();//a way to input the message.
	void ReadFile(string &temp);//the main part in this class.!
};
#endif // !BOOK_H_
#pragma once

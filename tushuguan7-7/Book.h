#ifndef BOOK_H_
#define BOOK_H_
#define IN_PARAM
#define OUT_PARAM
#include<string>
#include<fstream>
using namespace std;
//class People;
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
	//People P_people;还并未写出人的实现，所以现在人的存储还存在问题
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
		//P_people();无参的函数对象更改？
	}
	void updatepoint(double t_d);
	void input();//a way to input the message.
	void ReadFile(string &temp);//the main part in this class.!
};
#endif // !BOOK_H_
#pragma once

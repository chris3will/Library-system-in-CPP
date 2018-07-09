#pragma once
#ifndef PEOPLE_H_
#define PEOPLE_H_
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class People
{

public:
	People() {};
	~People() {};
	void FindBook();
	void ChangePW();
	void  input();//a way to input the message.
	void  ReadFile(string &temp);//we have different fuction for different 

public:
	vector<string> v;//need a list to store the book one has borrowed
	string s_id;
	string s_password;
	int i_the_book;//to store how many book he has borrorwed, we give him a max-30 vector to store the record.
	People *next;
};

#endif PEOPLE_H_

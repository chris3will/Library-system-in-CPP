#include "Book.h"
#include<iostream>
#include<sstream>
using namespace std;

void Book::input()
{
	cout << "***Please enter book's name(no space)***:";
	cin>> s_name;
	cout << endl;
	cout << "***Please enter book's isbn(no space)***:";
	cin >> s_isbn;
	cout << endl;
	cout << "***Please enter book's price(no space)***:";
	cin >> s_price;
	cout << endl;
	cout << "***Please enter book's writer(no space)***:";
	cin >> s_writer;
	cout << endl;
	cout << "***Please enter book's point(type:double):***";
	cin >> s_point;
//we can know the state of a book's loan?.
	return;
}

void Book::updatepoint(double t_d)
{
	s_point += t_d;
	s_point /= 2;
}
//read the message from the txtbook to the node;
void Book::ReadFile(string &temp)
{
		string s_temp(temp);
		int j = 0;
		int i = 0;
		int flag = 1;
		string s_out_temp;
		int i_len = s_temp.size();
		while (i < i_len)
		{
			j = i;
			while (s_temp[j] != ','&&j < i_len)
			{
				j++;//to store every son string's length j-i is just the length.
			}
			s_out_temp.assign(s_temp, i, j - i);
			//cout << s_out_temp << endl;
			stringstream ss;
			ss.clear();
			ss << s_out_temp;
			switch (flag)
			{
			case 1:ss >> s_name; break;
			case 2:ss >> s_isbn; break;
			case 3:ss>>s_price; break;
			case 4:ss>>s_writer; break;
			case 5:ss>>s_point; break;
			case 6:ss >> i_flag; break;
			default:break;
			}
			//cout << s_name << " " << s_isbn << " " << s_price << " " << s_writer << " " << s_point << " " << i_flag << endl;
			flag++;
			i = j + 1;
		}
}
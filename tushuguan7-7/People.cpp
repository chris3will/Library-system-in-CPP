#include"People.h"
#include<string>
#include<sstream>
void People::input()
{
	cout << "***Please enter people's ID(no space)***:";
	cin >> s_id;
	cout << endl;
	cout << "***Please enter people's password(no space)***:";
	cin >> s_password;
	cout << endl;
	cout << "***Please enter booknum if he has borrowed some(int please)***:";
	cin >> i_the_book;
	cout << endl;
	string name_temp;
	int i_all = 0;
	while(i_the_book > 0)
	{
		cout << "***Please enter book's name(no space)***:";
		cin >> name_temp;
		v_Bbook.push_back(name_temp);
		i_the_book--;
		cout << endl;
	}
	//we can know the state of a book's loan?.
	return;
}
void People::ReadFile(string &temp) 
{
	int identi;
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
		identi = s_out_temp.size();
		//cout << s_out_temp << endl;
		stringstream ss;
		ss.clear();
		ss << s_out_temp;
		string tempp;
		switch (flag)
		{
		case 1:ss >> s_id; break;
		case 2:ss >> s_password; break;
		case 3:ss >> i_the_book; break;
		default:break;
		}
		if (flag <= 3)
		{
			flag++;
			i = j + 1;	
		}
		else
		{
			if (i_the_book > 0)
			{
				flag++;
				i = j + 1;
				cout << s_out_temp;
				system("pause");
				v_Bbook.push_back(s_out_temp);
			}
			else
			{
				i = j + 1;
				break;
			}
		}
	}
	//begin to read the book if he borrowed something.
	
}
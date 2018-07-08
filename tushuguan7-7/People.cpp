#include"People.h"
#include<sstream>


void People::ReadFile(string &temp) 
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
		string tempp;
		switch (flag)
		{
		case 1:ss >> s_id; break;
		case 2:ss >> s_password; break;
		default:ss >> tempp; break;
		}
  		v[flag - 2] = tempp;
		//cout << s_name << " " << s_isbn << " " << s_price << " " << s_writer << " " << s_point << " " << i_flag << endl;
		flag++;
		i = j + 1;
	}
}
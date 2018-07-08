
# include <iostream>
using namespace std;
class People
{
public:
	People();
	People(int id, string pawd);//
	virtual ~People();
	void FindBook();//
	void ChgPawd();//
	void SetPawd(string);//
	People * next;
	People * end;
private:
	
	int s_id;//
	string s_password;//
	int static count;
};

int People::count = 0;//


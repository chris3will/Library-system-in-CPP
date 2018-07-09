#include"Book.h"
#include"Library.h"
#include"People.h"
#include"User.h"
#include<ctime>
#include<time.h>
#include<iostream>
using namespace std;

int main()
{
	//Library aa;
	//aa.Lib_init();
	//aa.Surface();
	User eobb;
	eobb.User_init();
	eobb.Show_people();
	eobb.User_Save();

	system("pause");
	return 0;
}
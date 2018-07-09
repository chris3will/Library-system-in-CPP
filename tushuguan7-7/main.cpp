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
	//First init the library,User
	//Then start the login procedure.
	//For his different identity we then show the different 
	//Library aa;
	//aa.Lib_init();
	//aa.Surface();
	User xswl;
	//People test;
	//test.input();
	//test.FindBook();
	xswl.User_init();
	xswl.Sign_in();
	//eobb.Add_People();
	//eobb.Show_people();
	xswl.User_Save();
	system("pause");
	return 0;
}
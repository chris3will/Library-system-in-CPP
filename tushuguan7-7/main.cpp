#include"Book.h"
#include"Library.h"
#include"People.h"
#include"User.h"
#include<ctime>
#include<time.h>
#include<iostream>
/*2018/7/10-Õı≥Á÷«*/
using namespace std;
int main()
{
	//First init the library,User
	//Then start the login procedure.
	//For his different identity we then show the different 
	User xswl;
	
	xswl.User_init();
	//xswl.Show_people();
	xswl.Sign_in();
	xswl.User_Save();
	return 0;
}
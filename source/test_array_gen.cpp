#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define m 10000
using namespace std;

char cmd[15][15]={"add","remove","contains","addindex","set","removeindex"};
char s[100][10];
long size=0;

void randstr(char *s)
{
	long l=rand()%7+1;
	for (int i=0;i<l;++i)
	 s[i]=rand()%26+'a';
	s[l]=0;
}

void randItrOp()
{
	cout << "new" << endl;
	if (rand()%5==0)
	 cout << "removeitr" << endl;
	for (int i=0; i<size; ++i)
	 {
		 cout << "hasnext\nnext" << endl;
		 if (rand()%5==0)
		 { 
			 cout << "removeitr" << endl;
		 	 if (rand()%5==0)
			 {
				 cout << "removeitr" << endl;
				 break;
			 }
		 }
	 }
}

int main()
{
	freopen("input.txt","w",stdout);
	long n,x;
	srand(time(NULL));
	for (int i=0;i<50;++i)
	 randstr(s[i]);
	if (rand()%3==0)
	 n=10;
	else if (rand()%2)
	 n=30;
	else
	 n=50;
	for (int i=1; i<=m; ++i)
	{
		if (rand()%2==0)
		 x=0;
		else if (rand()%2==0)
		 x=3;
		else
		 x=rand()%8;
		if (rand()%1000==0)
		 {
			 size=0;
			 cout << "clear\nprint" << endl;
			if (rand()%3==0)
			 n=10;
			else if (rand()%2)
			 n=30;
			else
			 n=50;
			continue;
		 }
		if (x==7)
		 randItrOp();
		else if (x<3)
		 {
			 cout << cmd[x] << " " << s[rand()%n] << endl;
			 if (x==0)
			  ++size;
		 }
		else if (x<5)
		 {
			 cout << cmd[x] << " " << rand()%(size+1) << " " << s[rand()%n] << endl;
			 if (x==3)
			  ++size;
		 }
		else if (x==5)
		 cout << cmd[x] << " " << rand()%(size+1) << endl;

		cout << "print" << endl;

	}
	cout << "exit" << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
using namespace std;
char board[20][80];
int length=4;
int flag=0;
class food
{
	public:
	int x,y;
	char value;
	food()
	{
	x=rand()%20;
	y=rand()%80;
	value='@';
	}
	void foodvalue()
	{
	x=rand()%20;
	y=rand()%80;
	}
	void insertfood()
	{
		board[x][y]=value;
	}
};
class snake
{
	public:
	int x,y;
	char value;
};
vector <snake> s;
food f;
void print()
{
	for(int a=0;a<20;a++)
	{
		for(int b=0;b<80;b++)
		{
			cout << board[a][b];
		}
		cout << endl;
	}
}
void makeobject()
{
	snake s1;
	s1.x=4;
	s1.y=4;
	s1.value='H';
	s.push_back(s1);
	for(int i=1;i<3;i++)
	{
		s1.x=4;
		s1.y=4+i;
		s1.value='#';
		s.push_back(s1);
	}
	s1.x=4;
	s1.y=7;
	s1.value='T';
	s.push_back(s1);
}
void insertsnake()
{
	for(int i=0;i<length;i++)
	{
		board[s[i].x][s[i].y]=s[i].value;
	}
}
void makeboundary()
{
	for(int i=0;i<20;i++)
	{
		board[i][0]='*';
	}
	for(int i=0;i<80;i++)
	{
		board[19][i]='*';
	}
	for(int i=19;i>0;i--)
	{
		board[i][79]='*';
	}
	for(int i=0;i<80;i++)
	{
		board[0][i]='*';
	}
}
char value;
void nullboard()
{
	for(int a=0;a<20;a++)
	{
		for(int b=0;b<80;b++)
		{
			board[a][b]=' ';
		}
	}
}
void takeinput()
{
	value=getch();
}
void snakemove()
{
	for(int i=length;i>0;i--)
	{
		s[i].x=s[i-1].x;
		s[i].y=s[i-1].y;
	} 
	if(value=='w')
	{
		s[0].x=s[0].x-1;
	}
	else if(value=='a')
	{
		s[0].y=s[0].y-1;
	}
	else if(value=='s')
	{
		s[0].x=s[0].x+1;
	}
	else if(value=='d')
	{
		s[0].y=s[0].y+1;
	}
	insertsnake();
}
void snakemodify()
{
	snake s2;
	s[length-1].value='#';
	s2.x=s[length-1].x;
	s2.y=s[length-1].y;
	s2.value='T';
	s.push_back(s2);
	length+=1;
	s[length-1].value='T';
	//insertsnake();
}
void delay()
{
	int i,j;
	for(i=0;i<327;i++)
	{
		for(j=0;j<320799;j++)
		{
		}
	}
}
void boundarycheck()
{
	if(s[0].x==30)
	{
		//
	}
	if(s[0].x==19)
	{
		s[0].x=0;
	}
	if(s[0].x==0)
	{
		s[0].x=19;
	}
	if(s[0].y==79)
	{
		s[0].y=0;
	}
	if(s[0].y==0)
	{
		s[0].y=79;
	}
}
void endgame()
{
	for(int i=1;i<length;i++)
	{
		if(s[0].x==s[i].x && s[0].y==s[i].y)
		{
		flag=1;
	    cout << s[0].x << s[i].x << s[0].y <<s[i].y << i << endl;
		delay();
		}
	}
}
int main()
{
	f.insertfood();
	makeobject();
	insertsnake();
	makeboundary();
	print();
	takeinput();
	while(1)
	{
	if(kbhit())
	{
	takeinput();
    }
    delay();
	f.insertfood();
	boundarycheck();
	snakemove();
	endgame();
	nullboard();
	makeobject();
	f.insertfood();
	insertsnake();
	if(f.x==s[0].x&&f.y==s[0].y)
	{
	snakemodify();
	f.foodvalue();
	f.insertfood();
    }
	makeboundary();
	system("cls");
	print();
	if(flag==1)
    {
    	break;
	}	
	}
}
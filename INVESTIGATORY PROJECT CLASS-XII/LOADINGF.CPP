#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main()
{ clrscr();
   for(int i=0; i<38 ;i++)
     { clrscr();
	gotoxy(i,20);
	 cout<<"WELCOME";
	 delay(100);
   if(i==37)
    { for(int j=80;j>39;j--)
     { clrscr();
	gotoxy(38,20);
	 cout<<"WELCOME";
	gotoxy(j,23);
	 cout<<"TO";
	delay(100);
      }
       gotoxy(38,26);
	cout<<"TRAVEL X";
       delay(2000);
    }
  }
  clrscr();
       gotoxy(38,20);
	cout<<"TRAVEL X";
       gotoxy(38,21);
	 cout<<"________";
       gotoxy(30,23);
	   cout<<"Your Travel System Manager";
       gotoxy(30,24);
	     cout<<"__________________________";
       gotoxy(36,32);
	       cout<<"<BUS VERSION>";
 getch();
 }
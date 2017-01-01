#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void securityfunc();
void loadstart();
void loaderfunc();
  void securityfunc()
  {      char mcode[]={'a','i','b','u','s','1','0','b','#','\0'};
	 char code[10];
	 int try=0;
	 gotoxy(23,24);
	 cout<<"FOR SECURITY REASONS YOU ARE REQUIRED TO";
	 tryagain:
	 gotoxy(23,26);
	 cout<<"ENTER THE PASSWORD TO ACCESS THE PROGRAM";
	 lasttry:
	 gotoxy(37,30);
	 cout<<"_________";
	 gotoxy(37,29);
	 gets(code);
	 ++try;
	   if(strcmp(code,mcode)==0)
	     { clrscr();
	       gotoxy(38,26);
	       cout<<"CORRECT!!";
	      delay(1500);
	      loadstart();
	      loaderfunc();
	     }
	   else if(try<3)
	     { clrscr();
	       gotoxy(38,26);
	       cout<<"WRONG!!";
	       gotoxy(28,28);
	       cout<<"Do you wish to try again?(y/n)";
	       char ans;
	       gotoxy(20,30);
	       cout<<"-> ";
	       cin>>ans;

		  if(ans=='y'||ans=='Y')
		   { clrscr();
		     goto tryagain;
		   }
		  else
		   { clrscr();
		     gotoxy(25,28);
		     cout<<"YOU ARE NOW EXITING OUT OF PROGRAM";
		     delay(3000);
		     exit(0);
		   }
	       }
	     else if(try==3)
	      {  clrscr();
		 gotoxy(20,24);
		 cout<<"You have tried 3 times to enter into this program."
		     <<"\t\t\t\tThis is your last chance.Be careful!!\n";
		  goto lasttry;

	       }
	  else
	      { clrscr();
		gotoxy(25,25);
		cout<<"YOU ARE NOW EXITING OUT OF PROGRAM";
		delay(3000);
		exit(0);
	      }

  }

  void loadstart()
    {   clrscr();
	for(int i=0;i<80;i++)
	  {   clrscr();
	      gotoxy(36,22);
	      cout<<"LOADING";
	      gotoxy(i,24);
	      cout<<"*****";
	      delay(60);
	   }
   }

 void loaderfunc()
   {     clrscr();
	 for(int i=0;i<40;i++)
	  {  clrscr();
	       gotoxy(i,20);
	       cout<<"WELCOME";
	       delay(100);
	   if(i==39)
	    { for(int j=75;j>41;j--)
		 {  clrscr();
		   gotoxy(39,20);
		      cout<<"WELCOME";
		     gotoxy(j,23);
		      cout<<"TO";
		     delay(100);
		 }
	      }
	   }
	  gotoxy(39,26);
	    cout<<"TRAVEL X";
	   delay(1000);
	  clrscr();
	   gotoxy(38,20);
	    cout<<"TRAVEL X";
	   gotoxy(38,21);
	    cout<<"________";
	   gotoxy(26,23);
	    cout<<"Your Travel Systems Manager Program";
	   gotoxy(26,24);
	    cout<<"___________________________________";
	   gotoxy(36,28);
	    cout<<"<BUS VERSION>";
	   }

 void main()
   {     clrscr();
	 securityfunc();

	 getch();
   }
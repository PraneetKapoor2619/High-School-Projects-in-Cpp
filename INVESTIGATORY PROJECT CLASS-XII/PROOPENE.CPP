#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{clrscr();
char filename[25],characterf,inputf[15];
char hamburger[10];
 cout<<"ENTER THE NAME OF THE FILE TO B E OPENED: ";
 gets(filename);
 cout<<"\n ENTER THE WORD TO BE CHECKED FOR : ";
 gets(inputf);
 cout<<"\n";
 int i=0;
 ifstream ppk(filename,ios::in);
 while(ppk)
 {
   ppk.get(characterf);
   if(characterf!=' '||characterf!='\n')
     {  hamburger[i]=characterf;
     ++i;
   }

   else if(characterf==' ')
   {
     hamburger[i]='\0';
    cout<<i<<"   STRING OBTAINED : ";
	  puts(hamburger);
	  int p=strcmp(hamburger,inputf);
	  if(p==0)
	    cout<<"     MATCH!!\n";
	   else
	     cout<<"    NO MATCH!!\n";
	  i=0;
	 strcpy(hamburger,'\0');
	}
	if(ppk.eof())
	 { hamburger[i]='\0';
	  cout<<i<<"   STRING OBTAINED: "<<hamburger;
	  if(strcmp(hamburger,inputf)==0)
	   cout<<"  MATCH!!";
	   else
	     cout<<"  NO MATCH!!";
	    }

	       }
   cout<<" \n I = "<<i;
   ppk.close();
   getch();
   }
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
	      delay(30);
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
class basicfunc
   {  char file[40],line[80];
char key[15],words[15];
     public:
  void openfile();
void modifyfile();
}
void basicfunc::openfile()
 {  cout<<"\n Enter the name of the name of the file to be opened(use ".txt" extension) : ";
    gets(file);
 clrscr();
cout<<"<-"<<"\n"<<file<<"\n__________________________________________________________________________________________";
ifstream opener(file,ios::in);
if(!file)
{    cout<<"\n\n\n\t\t\aNO SUCH FILE EXISTS!!\n\tDO YOU WISH TO CREATE ONE?(y/n)";
     char ch;
     cin>>ch;
if(ch=='y'||ch=='Y')
 {   
      char ret='y';
     return ret;
}
else
  return;
}
else
{   retry:
  while(opener)
    {  opener.getline(line,80);
      cout<<"\n\n"<<line;
   }
}
char bp[3];
gets(bp);
  if(bp=="<-")
    return;
else
   { clrscr();
gotoxy(28,24);
   cout<<"NOT VALID!!";
clrscr();
 goto retry;
      }
}
void basicfunc::modify()
{  retryf:
     clrscr();
   gotoxy(12,24);
     cout<<"1. MODIFY FILE";
   gotoxy(12,25);
     cout<<"2. DELETE FILE";
gotoxy(12,26)
      cout<<"3. GO BACK";
   int choice;
       switch(choice)
        {     case 1: reter:  
                         retryt:
                        clrscr();
                      gotoxy(5,10);
                      cout<<"Enter the name of the file to opened(use ".txt extension) : ";
                      gets(file);
                        
                        cout<<file<<"\n___________________________________________________________________________________________________________";
                        ifstream modifier(file,ios::in,ios::app,ios::nocreate);
                         ofstream newfile("temporary.txt",ios::out);
                           if(!modifier)
                           {    cout<<"\n\n\n\t\t\aNO SUCH FILE EXISTS!!\n\tDO YOU WISH TO CREATE ONE?(y/n)";
                                char ch;
                                  cin>>ch;
                        if(ch=='y'||ch=='Y')
                           {   
                                    char ret='y';
                                        return ret;

                              }
                      else
                            return;
                               }
                            else
                             {      cout<<"\nEnter keyword from the line you wish to change : ";
                                     gets(key);
                                 while(modifier)
                             {   modifier.gets(words);
                                  if(strcmp(word,key)==0)
                         	{   ++count;
                                             cout<<"\n\nDO YOU WISH TO ENTER NEW LINE?(y/n)";
                                            char a;
                                              cin>>a;
                                        if(a=='y'||a=='Y')
                                         {  cout<<"\n \n Enter new line : ";
	char newl[80];
	gets(newl);
	  newfile<<"\n"<<newl;
                                          }
                                     }
                          else
                       {  newfile<<"\n"<<word;
		  
                          }          
                     }
                 remove(file);
                 rename("temporary.txt",file);
               modifier.close();
                 newfile.close();
             if(count==1)
                {   clrscr();
                       gotoxy(25,24);
        	cout<<"WORD NOT FOUND!!"; 
                       cout<<"\n\t\tDO YOU WISH TO TRY AGAIN?(y/n)";
                       char chg;
                         cin>>chg;
                        if(chg=='y'||chg=='Y')
                           { 
	      goto retryt;
                           }
                      else
                         goto retryf;
                   }
                  break();
        case 2: clrscr(); 
                      gotoxy(05,24);
                      cout<<"Enter the name of the file to be deleted : ";
                     gets(file);
                  ofstream delt(file,ios::out);
                    remove(file);
                     delt.close();
                   break();
      case 3: clrscr();
                    return;
                   break();
     default:clrscr();
                  gotoxy(32,24);
                cout<<"WRONG CHOICE";
                  cout<<"\n\t Do you wish to try again?(y/n)";
               char bb;
              cin>>bb;
                   if(bb=='y'||bb=='Y')
                     goto reter;
               else
                 return;
               break();
      }
}
 void main()
   {     clrscr();
	 securityfunc();

	 getch();
   }

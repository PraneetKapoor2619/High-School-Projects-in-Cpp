#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void securityfunc();
void menu();
void loadstart();
void loaderfunc();
float Calc_op();
void customer_enter();
void customer_view();
void customer_modify();
void customer_delete();
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
	      menu();
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
 class basicfunctions
 { char filename[20],choice[4],choice1,lineinput[70],pgcommand[4],newline[70];
    int lineno,linenoI,newlineno;
   public:
    basicfunctions constructor()
    { lineno=0;
       newlineno=0;
    };
    int opentxtf(char filen[],int size);
    int modifymenu();
    int modifytxtf();
    int addlinetxtf();
    void deletetxtf();
 };
   int basicfunctions::opentxtf(char filen[],int size)
   {  clrscr();
	if(filen[size]!=0)
	  { strcpy(filename,filen);
	    goto ex;
	  }
     cout<<"\n Enter the name of the you wish to open\n(use'.txt'extension): ";
     gets(filename);
     ex:
     ifstream opentxtf(filename,ios::in|ios::nocreate);
       if(!opentxtf)
       { clrscr();
	 gotoxy(24,24);
	 cout<<"FILE DOESN'T";
	 gotoxy(26,26);
	 cout<<"EXISTS!!";
	 delay(3000);
	 clrscr();
	 gotoxy(1,23);
	 cout<<"Do you wish to create one?(y/n)\n ->";
	   gets(choice);
	   if(strcmp(choice,"y")==0||strcmp(choice,"Y")==0)
	     return -1;
	   else
	    return 0;
	  }
       else
       { previouspg:
	  cout<<"<-  ->\n"
	       <<filename
	       <<"\n_____________________________________________________________\n";
	   while(opentxtf)
	   { opentxtf.getline(lineinput,68);
	      ++lineno;
	      cout<<lineno<<". "<<lineinput<<"\n\n";
	      if(lineno==20)
	      { cout<<"\n\n Enter command : ";
		 gets(pgcommand);
		 if(strcmp(pgcommand,"<-")==0&&lineno==20)
		  { opentxtf.close();
		    return 0;
		   }
		 else if(strcmp(pgcommand,"<-")==0&&lineno>20)
		   { opentxtf.seekg(0,ios::beg);
		     lineno=1;
		     goto previouspg;
		     clrscr();
		   }
		 else if(strcmp(pgcommand,"->")==0&&lineno==20)
		  { clrscr();
		     goto previouspg;
		   }
		}
	     }
	     opentxtf.close();
	     }
	     return 0;
	 }
  int basicfunctions::modifymenu()
   { clrscr();
       cout<<"<-";
	gotoxy(25,20);
	cout<<"MODIFY MENU";
	gotoxy(24,21);
	cout<<"_____________";
	gotoxy(24,23);
	cout<<"1. Replace and change a line";
	gotoxy(24,25);
	cout<<"2. Add a new line";
	gotoxy(24,26);
	cout<<"_____________";
	cout<<"\n\n Enter Command : ";
	 gets(choice);
	if(strcmp(choice,"<-")==0)
	   return 0;
	else if(strcmp(choice,"1")==0)
	 { int r1=modifytxtf();
	     return r1;
	    }
	 else if(strcmp(choice,"2")==0)
	  { int r2=addlinetxtf();
	     return r2;
	   }
	   return 0;
	 }

 int basicfunctions::modifytxtf()
  {  MF:
     clrscr();
     cout<<"<- ->\n"
	 <<"\n Enter file name\n(Use'.txt' extension) : ";
      gets(filename);
      fstream apptxtf(filename,ios::in|ios::out|ios::nocreate);
      ofstream newtxtf("tcc.txt",ios::out);
       if(!apptxtf)
	 { clrscr();
	   gotoxy(24,24);
	    cout<<"FILE DOESN'T";
	    gotoxy(26,26);
	   cout<<"EXISTS !!";
	   delay(3000);
	   clrscr();
	   gotoxy(1,23);
	   cout<<"Do you wish to create one?(y/n)\n ->";
	    cin>>choice1;
	   if(choice1=='y'||choice1=='Y')
	     return 0;
	   else
	     return -1;
	 }
       else
	{ ML:
	   cout<<filename<<"\n___________________________________________________\n";
	  cout<<" It is recommended that you first note down the line number\n of the line you wish to change."
	       <<"\n Do you wish to view "<<filename<<" for that purpose first?(y/n)";
	  cin>>choice1;
	   if(choice1=='y'||choice1=='Y')
	    { clrscr();
	     gotoxy(10,24);
	      cout<<" File "<<filename<<" is being opened";
		gotoxy(10,26);
	       cout<<"Press any key to continue";
		clrscr();
		cout<<"\n\n See the line number to be changed";
		delay(2000);
		opentxtf(filename,20);
		}
	       else
		 gotoxy(32,24);
		 cout<<"OKAY";
		 }
	      clrscr();
	      cout<<"<- \nModifying "<<filename<<"\n___________________________________________________________________________________________________\n";
	      cout<<" \n Enter the line number you wish to modify : ";
	      cin>>linenoI;
	      while(!apptxtf.eof())
	       {  apptxtf.getline(lineinput,70);
		 ++lineno;
		 if(lineno==linenoI)
		  { cout<<" \n The line is : \n "<<lineno<<". "<<lineinput;
		 gotoxy(12,30);
		  cout<<"Do you wish to remove this line?(y/n)";
		   cin>>choice1;
		  if(choice1=='y'||choice1=='Y')
		   { cout<<"\n The afforsaid line will be removed from record";
		       cout<<"\n Do you wish to enter a line to replace to remove the chosen line?(y/n)";
		       cin>>choice1;
		       if(choice1=='y'||choice1=='Y')
		       { clrscr();
			cout<<" The line to be removed is : \n"<<lineinput;
			 cout<<"\n\n Enter new line : \n";
			 gets(newline);
			  newtxtf<<newline<<"\n\n";
			 }
		      else
			cout<<"OKAY!!";
			 }
	       else
		newlineno==-1;
	     }
	   else
	    { newtxtf<<lineinput<<"\n\n";
	       }
	  remove(filename);
	  rename("tcc.txt",filename);
	  apptxtf.close();
	    newtxtf.close();
       if( newlineno==-1)
	 { cout<<"\n\n    IT SEEMS THAT THE LINE YOU WISHED TO FIND WAS NOT FIND"
	       <<"\n\n  DO YOU WISH TO TRY AGAIN ?(y/n)";
	    cin>>choice1;
	    if(choice1=='y'||choice1=='Y')
	      goto ML;
	    }
	 clrscr();
	 gotoxy(20,25);
	 cout<<"Press 1 to modify another line";
	 gotoxy(20,27);
	 cout<<"Press 2 to modify a different file";
	 gotoxy(20,29);
	 cout<<"Enter '<-' to go back to the respective menu";
	 gotoxy(20,31);
	 cout<<" Enter Command : ";
	   gets(choice);
	   if(strcmp(choice,"<-")==0)
	      return 0;
	   else if(strcmp(choice,"1")==0)
	      goto ML;
	   else if(strcmp(choice,"2")==0)
	      goto MF;
	  }
	    return 0;
	}


 void basicfunctions::deletetxtf()
 { MF:
  clrscr();
   cout<<" \n\n Enter the name of the file you wish to delete(use .txt extension) : ";
   gets(filename);
     ifstream deletex(filename,ios::in);

       while(!deletex.eof())
	{ deletex.getline(lineinput,70);
	 ++lineno;
	 cout<<"\n"<<lineno<<". "<<lineinput<<"\n";
	 }
	 cout<<"\nAre you sure that you wish to delete the file?(y/n)";
	   gets(choice);
	   if(strcmp(choice,"y")==0||strcmp(choice,"Y"))
	      remove(filename);
	    else
	     { clrscr();
	       gotoxy(26,24);
		cout<<"\a GOING BACK ";
		return ;
	       }
	  }
int basicfunctions::addlinetxtf()
  { MF:
    clrscr();
     cout<<"<- ->\n"
	 <<"\n Enter file name\n(Use'.txt' extension) : ";
      gets(filename);
      fstream apptxtf(filename,ios::in|ios::out|ios::nocreate);
      ofstream newtxtf("tcc.txt",ios::out);
       if(!apptxtf)
	 { clrscr();
	   gotoxy(24,24);
	    cout<<"FILE DOESN'T";
	    gotoxy(26,26);
	   cout<<"EXISTS !!";
	   delay(3000);
	   clrscr();
	   gotoxy(1,23);
	   cout<<"Do you wish to create one?(y/n)\n ->";
	    cin>>choice1;
	   if(choice1=='y'||choice1=='Y')
	     return -1;
	   else
	     return 0;
	 }
       else
	{  cout<<filename<<"\n___________________________________________________\n";
	      cout<<" It is recommended that you first note down the line number"
		 <<"\n Do you wish to view "<<filename<<" for that purpose first?(y/n)";
	  cin>>choice1;
	   if(choice1=='y'||choice1=='Y')
	    { clrscr();
	     gotoxy(10,24);
	      cout<<" File "<<filename<<" is being opened";
		gotoxy(10,26);
	       cout<<"Press any key to continue";
		clrscr();
		cout<<"\n\n See the line number to be changed";
		delay(2000);
		opentxtf(filename,20);
		}
	       else
		 gotoxy(32,24);
		 cout<<"OKAY";
		 }
	       ML:
	      clrscr();
	      cout<<"<- \nModifying "<<filename<<"\n___________________________________________________________________________________________________\n";
		   cout<<"Enter the lineno. of the line you wish you wish to add : ";
	     cin>>newlineno;
	      while(!apptxtf.eof())
	    { apptxtf.getline(lineinput,70);
		++lineno;
		   if(lineno==newlineno)
		     {  cout<<"Enter the line you wish to add : \n";
			   gets(newline);
			 newtxtf<<newline<<"\n\n";
		  }
	      else
		newtxtf<<lineinput<<"\n\n";
	  }
       remove(filename);
      rename("tcc.txt",filename);
	 apptxtf.close();
	    newtxtf.close();
clrscr();
	 gotoxy(20,25);
	 cout<<"Press 1 to add another line";
	 gotoxy(20,27);
	 cout<<"Press 2 to add line to a different file";
	 gotoxy(20,29);
	 cout<<"Enter '<-' to go back to the respective menu";
	 gotoxy(20,31);
	 cout<<" Enter Command : ";
	   gets(choice);
	   if(strcmp(choice,"<-")==0)
	      return 0;
	   else if(strcmp(choice,"1")==0)
	      goto ML;
	   else if(strcmp(choice,"2")==0)
	      goto MF;
	    return 0;
       }


    //CLASS BASICFUNCTIONS' DEFINITIONS END HERE

class driver:public basicfunctions
  {  //Variable set
      //Detail Set 1
       char filename1[20],name[40],mname[40],fname[40],dob[12],doj[12],bgroup[3];
       //Detail Set 2
       char residence[60],licenseno[20];
       long int phone_no;
       long int aadharno;
       //Details dealing with skills and criminal record
       char education[60],permit[60],crime_rec[70];
       //Salary
       float salary;
       //Other details
       char other_det[70];
       char Dchoice[4],choice;
       public:
	 int driver_menu();
	  int driver_createf();
      };
      int driver::driver_menu()
       { clrscr();
	 Dloop:
	 clrscr();
	  cout<<"<-";
	  gotoxy(24,12);
	  cout<<"DRIVER MENU";
	  gotoxy(23,14);
	  cout<<"_____________";
	  gotoxy(23,16);
	  cout<<"1. Create File";
	  gotoxy(23,18);
	  cout<<"2. View File";
	  gotoxy(23,20);
	  cout<<"3. Modify File";
	  gotoxy(23,22);
	  cout<<"4. Delete File";
	  gotoxy(23,24);
	  cout<<"-------------";
	  gotoxy(23,26);
	  cout<<"Enter Command : ";
	   gets(Dchoice);
	 if(strcmp(Dchoice,"<-")==0)
	  return 0;
	 else if(strcmp(Dchoice,"1")==0)
	   { driver_createf();
		goto Dloop;
	      }
	      else if(strcmp(Dchoice,"2")==0)
	       {  int rod=opentxtf(0,0);
		  if(rod==0)
		    goto Dloop;
		   else
		     driver_createf();
		 }
	     else if(strcmp(Dchoice,"3")==0)
	      {  int mod=modifymenu();
		     if(mod==0)
			goto Dloop;
		      else
			driver_createf();
		  }
	      else if(strcmp(Dchoice,"4")==0)
	       { deletetxtf();
		  goto Dloop;
		}
	       return 0;
	   }
int driver::driver_createf()
 { rpp:
   clrscr();
    cout<<"New File\n\n\n Enter the name the with which you wish to save the file(use '.txt' extension) : ";
      gets(filename1);
   clrscr();
      cout<<filename1<<"\n________________________________________________________________________";
	ofstream createstrm(filename1,ios::out|ios::app);
	   if(createstrm)
	     { rcc:
	       clrscr();
		gotoxy(10,20);
		  cout<<"\aA file with the same name already exists";
		gotoxy(15,22);
		  cout<<"Do you wish to : ";
		gotoxy(17,24);
		  cout<<"1. View that file";
		 gotoxy(17,26);
		   cout<<"2. Replace that file";
		 gotoxy(17,28);
		   cout<<"3. Change the name of present file";
		 cout<<"\n\n\nEnter command : ";
		 cin>>choice;
		if(choice=='1')
		 {  opentxtf(filename1,20);
		     goto rcc;
		   }
	       else if(choice=='2')
		 { remove(filename1);
		     clrscr();
		     gotoxy(24,24);
		     cout<<filename1<<" was effictively removed from disk";
		     delay(3000);
		     goto rpp;
		  }
	      else if(choice=='3')
		{ clrscr();
		   cout<<"\n\nEnter new filename(usd '.txt' extension) : ";
		    strcpy(filename1,"\0");
		     gets(filename1);
		   goto rcc;
		}
	     }
	  else
	     {   cout<<"\nEnter the name of the driver : ";
		     gets(name);
		     createstrm<<" Name : "<<name<<"\n\n";
		  cout<<"\nEnter the name of Mother of the driver : ";
		    gets(mname);
		    createstrm<<" Mother's name : "<<mname<<"\n\n";
		  cout<<"\nEnter the name of Father of the driver : ";
		    gets(fname);
		    createstrm<<" Father's name : "<<fname<<"\n\n";
		  cout<<"\nEnter date of birth of the driver : ";
		    gets(dob);
		    createstrm<<" Date of Birth : "<<dob<<"\n\n";
		 cout<<"\nEnter blood group of the driver : ";
		   gets(bgroup);
		   createstrm<<" Blood Group : "<<bgroup<<"\n\n";
		 cout<<"\nEnter residence address of the driver : ";
		  gets(residence);
		  createstrm<<" Residence Address : "<<residence<<"\n\n";
		 cout<<"\nEnter Aadhar No.of the driver :";
		  cin>>aadharno;
		  createstrm<<" Aadhar Number : "<<aadharno<<"\n\n";
		cout<<"\nEnter License No. of the driver : ";
		  gets(licenseno);
		  createstrm<<" License Number : "<<licenseno<<"\n\n";
               cout<<"\n Phone Number : ";
		  cin>>phone_no;
		createstrm<<"Phone Number : "<<phone_no<<"\n\n";
		cout<<"\nEnter the maximum academic qualification of the driver : ";
		  gets(education);
		  createstrm<<" Maximum academic qualification : "<<education<<"\n\n";
		cout<<"\nEnter the date of joining of the driver : ";
		  gets(doj);
		  createstrm<<" Date of Joining : "<<doj<<"\n\n";
		cout<<"\nEnter the permit of the driver : ";
		 gets(permit);
		 createstrm<<" Permit : "<<permit<<"\n\n";
		cout<<"\n Enter criminal record,if any,to which the driver was a part : ";
		  gets(crime_rec);
		  createstrm<<" Criminal Record : "<<crime_rec<<"\n";
		  cout<<"\nOther details\n";
		 choice='y';
		while(choice=='y'||choice=='Y')
		 { cout<<": ";
		    gets(other_det);
		    createstrm<<other_det<<"\n\n";
		   cout<<"\n\n  Do you wish to enter another line?(y/n)";
		     cin>>choice;
		  }
		}
		clrscr();
		 cout<<"Do you wish to create another file?(Y/N)";
		cin>>choice;
	       if(choice=='y'||choice=='Y')
		 goto rpp;
	       else
		 return 0;
	      }

 class conductor:public basicfunctions
  {  //Variable set
      //Detail Set 1
       char filename1[20],name[40],mname[40],fname[40],dob[12],doj[12],bgroup[3];
       //Detail Set 2
       char residence[60],licenseno[20];
    long int phone_no;
       long int aadharno;
       //Details dealing with skills and criminal record
       char education[60],permit[60],crime_rec[70];
       //Salary
       float salary;
       //Other details
       char other_det[70];
       char Dchoice[4],choice;
       public:
	 int conductor_menu();
	  int conductor_createf();
      };

int conductor::conductor_menu()
       { clrscr();
	 Dloop:
	 clrscr();
	  cout<<"<-";
	  gotoxy(24,12);
	  cout<<"CONDUCTOR MENU";
	  gotoxy(23,14);
	  cout<<"________________";
	  gotoxy(23,16);
	  cout<<"1. Create File";
	  gotoxy(23,18);
	  cout<<"2. View File";
	  gotoxy(23,20);
	  cout<<"3. Modify File";
	  gotoxy(23,22);
	  cout<<"4. Delete File";
	  gotoxy(23,24);
	  cout<<"________________";
	  gotoxy(23,26);
	  cout<<"Enter Command : ";
	   gets(Dchoice);
	 if(strcmp(Dchoice,"<-")==0)
	  return 0;
	 else if(strcmp(Dchoice,"1")==0)
	   { conductor_createf();
		goto Dloop;
	      }
	      else if(strcmp(Dchoice,"2")==0)
	       {  int rod=opentxtf(0,0);
		  if(rod==0)
		    goto Dloop;
		   else
		     conductor_createf();
		 }
	     else if(strcmp(Dchoice,"3")==0)
	      {  int mod=modifymenu();
		     if(mod==0)
			goto Dloop;
		      else
			conductor_createf();
		  }
	      else if(strcmp(Dchoice,"4")==0)
	       { deletetxtf();
		  goto Dloop;
		}
	       return 0;
	   }
int conductor::conductor_createf()
 { rpp:
   clrscr();
    cout<<"New File\n\n\n Enter the name the with which you wish to save the file(use '.txt' extension) : ";
      gets(filename1);
   clrscr();
      cout<<filename1<<"\n________________________________________________________________________";
	ofstream createstrm(filename1,ios::out|ios::app);
	   if(createstrm)
	     { rcc:
	       clrscr();
		gotoxy(10,20);
		  cout<<"\aA file with the same name already exists";
		gotoxy(15,22);
		  cout<<"Do you wish to : ";
		gotoxy(17,24);
		  cout<<"1. View that file";
		 gotoxy(17,26);
		   cout<<"2. Replace that file";
		 gotoxy(17,28);
		   cout<<"3. Change the name of present file";
		 cout<<"\n\n\nEnter command : ";
		 cin>>choice;
		if(choice=='1')
		 {  opentxtf(filename1,20);
		     goto rcc;
		   }
	       else if(choice=='2')
		 { remove(filename1);
		     clrscr();
		     gotoxy(24,24);
		     cout<<filename1<<" was effictively removed from disk";
		     delay(3000);
		     goto rpp;
		  }
	      else if(choice=='3')
		{ clrscr();
		   cout<<"\n\nEnter new filename(usd '.txt' extension) : ";
		    strcpy(filename1,"\0");
		     gets(filename1);
		   goto rcc;
		}
	     }
	  else
	     {   cout<<"\nEnter the name of the conductor : ";
		     gets(name);
		     createstrm<<" Name : "<<name;
		  cout<<"\nEnter the name of Mother of the conductor : ";
		    gets(mname);
		    createstrm<<"\n\n Mother's Name : "<<mname;
		  cout<<"\nEnter the name of Father of the conductor : ";
		    gets(fname);
		    createstrm<<"\n\n Father's Name : "<<fname;
		  cout<<"\nEnter date of birth of the conductor : ";
		    gets(dob);
		    createstrm<<"\n\n Date of Birth : "<<dob;
		 cout<<"\nEnter blood group of the conductor : ";
		   gets(bgroup);
		   createstrm<<"\n\n Blood Group : "<<bgroup;
		 cout<<"\nEnter residence address of the conductor : ";
		  gets(residence);
		  createstrm<<"\n\n Residence Address : "<<residence;
		 cout<<"\nEnter Aadhar No.of the conductor :";
		  cin>>aadharno;
		  createstrm<<"\n\n Aadhar Number : "<<aadharno;
		cout<<"\nEnter License No. of the conductor : ";
		  gets(licenseno);
		  createstrm<<"\n\n License Number : "<<licenseno;
		cout<<"\n Phone Number : ";
		  cin>>phone_no;
		createstrm<<"Phone Number : "<<phone_no<<"\n\n";
		cout<<"\nEnter the maximum academic qualification of the conductor : ";
		  gets(education);
		  createstrm<<"\n\ Maximum academic qualification : "<<education;
		cout<<"\nEnter the date of joining of the conductor : ";
		  gets(doj);
		  createstrm<<"\n\n Date of Joining : "<<doj;
		cout<<"\nEnter the permit of the conductor : ";
		 gets(permit);
		 createstrm<<"\n\n Permit : "<<permit;
		cout<<"\n Enter criminal record,if any,to which the conductor was a part : ";
		  gets(crime_rec);
		  createstrm<<"\n\nCriminal Record : "<<crime_rec;
		  cout<<"\nOther details\n";
		  createstrm<<"\n\n Other Details ";
		 choice='y';
		while(choice=='y'||choice=='Y')
		 { cout<<": ";
		    gets(other_det);
		       createstrm<<"\n\n"<<other_det;
		   cout<<"\n\n  Do you wish to enter another line?(y/n)";
		     cin>>choice;
		  }
		}
		clrscr();
		 cout<<"Do you wish to create another file?(Y/N)";
		cin>>choice;
	       if(choice=='y'||choice=='Y')
		 goto rpp;
	       else
		 return 0;
	      }

 class other_employee:public basicfunctions
  {  //Variable set
      //Detail Set 1
       char filename1[20],name[40],mname[40],fname[40],dob[12],doj[12],bgroup[3],occ[15];
       //Detail Set 2
       char residence[60],licenseno[20];
       long int phone_no;
       long int aadharno;
       //Details dealing with skills and criminal record
       char education[60],crime_rec[70];
       //Salary
       float salary;
       //Other details
       char other_det[70];
       char Dchoice[4],choice;
       public:
	 int otemp_menu();
	  int otemp_createf();
      };
int other_employee::otemp_menu()
       { clrscr();
	 Dloop:
	 clrscr();
	  cout<<"<-";
	  gotoxy(24,12);
	  cout<<"OTHER EMPLOYEES MENU";
	  gotoxy(23,14);
	  cout<<"________________";
	  gotoxy(23,16);
	  cout<<"1. Create File";
	  gotoxy(23,18);
	  cout<<"2. View File";
	  gotoxy(23,20);
	  cout<<"3. Modify File";
	  gotoxy(23,22);
	  cout<<"4. Delete File";
	  gotoxy(23,24);
	  cout<<"________________";
	  gotoxy(23,26);
	  cout<<"Enter Command : ";
	   gets(Dchoice);
	 if(strcmp(Dchoice,"<-")==0)
	  return 0;
	 else if(strcmp(Dchoice,"1")==0)
	   { otemp_createf();
		goto Dloop;
	      }
	      else if(strcmp(Dchoice,"2")==0)
	       {  int rod=opentxtf(0,0);
		  if(rod==0)
		    goto Dloop;
		   else
		     otemp_createf();
		 }
	     else if(strcmp(Dchoice,"3")==0)
	      {  int mod=modifymenu();
		     if(mod==0)
			goto Dloop;
		      else
			otemp_createf();
		  }
	      else if(strcmp(Dchoice,"4")==0)
	       { deletetxtf();
		  goto Dloop;
		}
	       return 0;
	   }
int other_employee::otemp_createf()
 { rpp:
   clrscr();
    cout<<"New File\n\n\n Enter the name the with which you wish to save the file(use '.txt' extension) : ";
      gets(filename1);
   clrscr();
      cout<<filename1<<"\n________________________________________________________________________";
	ofstream createstrm(filename1,ios::out|ios::app);
	   if(createstrm)
	     { rcc:
	       clrscr();
		gotoxy(10,20);
		  cout<<"\aA file with the same name already exists";
		gotoxy(15,22);
		  cout<<"Do you wish to : ";
		gotoxy(17,24);
		  cout<<"1. View that file";
		 gotoxy(17,26);
		   cout<<"2. Replace that file";
		 gotoxy(17,28);
		   cout<<"3. Change the name of present file";
		 cout<<"\n\n\nEnter command : ";
		 cin>>choice;
		if(choice=='1')
		 {  opentxtf(filename1,20);
		     goto rcc;
		   }
	       else if(choice=='2')
		 { remove(filename1);
		     clrscr();
		     gotoxy(24,24);
		     cout<<filename1<<" was effictively removed from disk";
		     delay(3000);
		     goto rpp;
		  }
	      else if(choice=='3')
		{ clrscr();
		   cout<<"\n\nEnter new filename(usd '.txt' extension) : ";
		    strcpy(filename1,"\0");
		     gets(filename1);
		   goto rcc;
		}
	     }
	  else
	     {   cout<<"\nEnter the name of the employee : ";
		     gets(name);
		      createstrm<<" Name : "<<name;
		  cout<<"\nEnter the name of Mother of the employee : ";
		    gets(mname);
		    createstrm<<"\n\n Mother's Name : "<<mname;
		  cout<<"\nEnter the name of Father of the employee : ";
		    gets(fname);
		    createstrm<<"\n\n Father's Name : "<<fname;
		  cout<<"\nEnter date of birth of the employee : ";
		    gets(dob);
		    createstrm<<"\n\n Date of Birth : "<<dob;
		 cout<<"\nEnter blood group of the employee : ";
		   gets(bgroup);
		   createstrm<<"\n\n Blood Group : "<<bgroup;
		 cout<<"\nEnter residence address of the employee : ";
		  gets(residence);
		  createstrm<<"\n\n Residnce Address :"<<residence;
		 cout<<"\nEnter Aadhar No.of the employee :";
		  cin>>aadharno;
		  createstrm<<"\n\n Aadhar Number : "<<aadharno;
		cout<<"\nEnter License No. of the employee : ";
		  gets(licenseno);
		  createstrm<<"\n\n License Number : "<<licenseno;
		cout<<"\n Phone Number : ";
		  cin>>phone_no;
		createstrm<<"Phone Number : "<<phone_no<<"\n\n";
		cout<<"\nEnter the maximum academic qualification of the employee : ";
		  gets(education);
		  createstrm<<"\n\n Maximum academic qualification : "<<education;
		cout<<"\nEnter the date of joining of the employee : ";
		  gets(doj);
		  createstrm<<"\n\n Date of Joining : "<<doj;
	   cout<<"\nEnter the job done by employee : ";
	      gets(occ);
	      createstrm<<"\n\n Occupation : "<<occ;
		cout<<"\n Enter criminal record,if any,to which the employee was a part : ";
		  gets(crime_rec);
		  createstrm<<"\n\n Criminal Record : "<<crime_rec;
		  cout<<"\nOther details\n";
		    createstrm<<"\n\n Other Details ";
		 choice='y';
		while(choice=='y'||choice=='Y')
		 { cout<<": ";
		    gets(other_det);
		    createstrm<<"\n\n "<<other_det;
		   cout<<"\n\n  Do you wish to enter another line?(y/n)";
		     cin>>choice;
		  }
		}
		clrscr();
		 cout<<"Do you wish to create another file?(Y/N)";
		cin>>choice;
	       if(choice=='y'||choice=='Y')
		 goto rpp;
	       else
		 return 0;
	      }
 class bus: public basicfunctions
{ int busno,pascap;
   char type[10],choice,filename1[20],manufactured_by[15],manufactured_on[10],bo[10], registration_no[15];
   char permit[60],contractno[15],condition[70],otherbdet[70];
  float cost,fucap;
 public:
 int bus_createf();
 void bus_menu();
 };




  int bus::bus_createf()
{ rpp:
   clrscr();
    cout<<"New File\n\n\n Enter the name the with which you wish to save the file(use '.txt' extension) : ";
      gets(filename1);
   clrscr();
      cout<<filename1<<"\n________________________________________________________________________";
	ofstream createstrm(filename1,ios::out|ios::app);
	   if(createstrm)
	     { rcc:
	       clrscr();
		gotoxy(10,20);
		  cout<<"\aA file with the same name already exists";
		gotoxy(15,22);
		  cout<<"Do you wish to : ";
		gotoxy(17,24);
		  cout<<"1. View that file";
		 gotoxy(17,26);
		   cout<<"2. Replace that file";
		 gotoxy(17,28);
		   cout<<"3. Change the name of present file";
		 cout<<"\n\n\nEnter command : ";
		 cin>>choice;
		if(choice=='1')
		 {  opentxtf(filename1,20);
		     goto rcc;
		   }
	       else if(choice=='2')
		 { remove(filename1);
		     clrscr();
		     gotoxy(24,24);
		     remove(filename1);
		     cout<<filename1<<" was effictively removed from disk";
		     delay(3000);
		     goto rpp;
		  }
	      else if(choice=='3')
		{ clrscr();
		   cout<<"\n\nEnter new filename(usd '.txt' extension) : ";
		    strcpy(filename1,"\0");
		     gets(filename1);
		   goto rcc;
		}
	     }
	  else
	     {  cout<<"\n\n Enter Bus number : ";
		  cin>>busno;
		createstrm<<"\n\n Bus Number : "<<busno;
	      cout<<"\n\n Enter the type of bus : ";
		gets(type);
	       createstrm<<"\n\n Bus type : "<<type;
		 cout<<"\n\n Passenge capacity of bus : ";
		   cin>>pascap;
		createstrm<<"\n\n Passenger Capacity : "<<pascap;
	     cout<<"\n\n Enter the fuel capacity of bus :";
	       cin>>fucap;
	      createstrm<<"\n\n Fuel capacity : "<<fucap;
	      cout<<" \n\nManufatured by : ";
		gets(manufactured_by);
	       createstrm<<"\n\n Manufactured by : "<<manufactured_by;
	      cout<<"Manufacture completed on : ";
	       gets(manufactured_on);
		createstrm<<"\n\n Manufacture completed on : "<<manufactured_on;
	      cout<<"\n\n Bought on : ";
		gets(bo);
	      createstrm<<"\n\n Bought on : "<<bo;
	     cout<<"\n\n Cost : Rs ";
	     cin>>cost;
	       createstrm<<"\n\n Cost : Rs"<<cost;
	   cout<<" \n\n Contract number : ";
		gets(contractno);
	    createstrm<<"\n\n Contract number : "<<contractno;
	  cout<<"\n\n Permit : ";
	      gets(permit);
	    createstrm<<"\n\n Permit : "<<permit;
	  cout<<"\n\n Condition : ";
	     gets(condition);
	 createstrm<<"\n\n Condition : "<<condition;
	  clrscr();
		 cout<<"Do you wish to create another file?(Y/N)";
		cin>>choice;
	       if(choice=='y'||choice=='Y')
		 goto rpp;
	       else
		 return 0;
	      }

 void bus::bus_menu()
{ clrscr();
	 Dloop:
	 clrscr();
	  cout<<"<-";
	  gotoxy(24,12);
	  cout<<"BUS MENU";
	  gotoxy(23,14);
	  cout<<"________________";
	  gotoxy(23,16);
	  cout<<"1. Create File";
	  gotoxy(23,18);
	  cout<<"2. View File";
	  gotoxy(23,20);
	  cout<<"3. Modify File";
	  gotoxy(23,22);
	  cout<<"4. Delete File";
	  gotoxy(23,24);
	  cout<<"________________";
	  gotoxy(23,26);
	  cout<<"Enter Command : ";
	   gets(Dchoice);
	 if(strcmp(Dchoice,"<-")==0)
	  return 0;
	 else if(strcmp(Dchoice,"1")==0)
	   { otemp_createf();
		goto Dloop;
	      }
	      else if(strcmp(Dchoice,"2")==0)
	       {  int rod=opentxtf(0,0);
		  if(rod==0)
		    goto Dloop;
		   else
		     otemp_createf();
		 }
	     else if(strcmp(Dchoice,"3")==0)
	      {  int mod=modifymenu();
		     if(mod==0)
			goto Dloop;
		      else
			otemp_createf();
		  }
	      else if(strcmp(Dchoice,"4")==0)
	       { deletetxtf();
		  goto Dloop;
		}
	       return ;
	   }

//Class pcalculator:Calculate the payment as per the pre set values which can modified
class pcalculator
 { int passengers,bus_no;
   float Ldistance,Gdistance,costperp,Ecost;
   float netcost,inputdistance;
   public:
   int preset_values(int);
   float calculate();
   int return_busno();
   };


 int pcalculator::preset_values(int no)
  { clrscr();
     if(no!=0)
       { bus_no==no;
	 goto pd;
	}
     cout<<"Enter Bus number : ";
     cin>>bus_no;
     pd:
     cout<<"\nEnter the 'less than' value of distance : ";
     cin>>Ldistance;
     cout<<"\n Enter the 'greater than' value of distance : ";
     cin>>Gdistance;
     cout<<"\n Enter cost per person : ";
     cin>>costperp;
     cout<<"\n Extra charges : ";
     cin>>Ecost;
     return 0;
  }
 float pcalculator::calculate()
   { clrscr();
      cout<<"Enter number of persons : ";
      cin>>passengers;
      cout<<"\nEnter distance to be travelled : ";
      cin>>inputdistance;
      if(inputdistance>=Ldistance&&inputdistance<=Gdistance)
       netcost=costperp*passengers+Ecost;
      else if(inputdistance<=Ldistance)
	netcost=costperp*passengers;
      else if(inputdistance>=Gdistance)
	{ int difference=inputdistance-Gdistance;
	  netcost=costperp*passengers+Ecost*difference;
	 }
	return netcost;
     }
  int pcalculator::return_busno()
  { return bus_no;
  }

float Calc_op(int bsp)
{  reloop:
   clrscr();
   int bs,lpp=0;
    pcalculator obj;
    float sp;
     cout<<"<-";
    gotoxy(24,24);
     cout<<"CALCULATOR";
    gotoxy(22,26);
     cout<<"1. Enter values into file";
    gotoxy(22,30);
     cout<<"2. Calculate Net Cost";
    char chd[4];
     cout<<"Enter command : ";
    gets(chd);
       if(strcmp(chd,"1")==0)
       { clrscr();
	  fstream pcalcr("cost_file.dat",ios::in|ios::out|ios::binary|ios::app);
	     while(!pcalcr.eof())
	     { int pos=pcalcr.tellg();
	       pcalcr.read((char*)&obj,sizeof(obj));
		cout<<"Enter Bus Number : ";
		 if(bsp==0)
		   cin>>bs;
		 else
		   bs==bsp;
		  if(bs==obj.return_busno())
		   {  pcalcr.seekp(pos);
		       obj.preset_values(bs);
		       pcalcr.write((char*)&obj,sizeof(obj));
		       lpp=1;
		    }
		}
	       if(lpp!=1)
		{ obj.preset_values(bs);
		    pcalcr.write((char*)&obj,sizeof(obj));
		     }
	    }
      else if(strcmp(chd,"2")==0)
	{  clrscr();
	     ifstream pcalc("cost_file.dat",ios::in|ios::binary);
	     while(!pcalc.eof())
	      { pcalc.read((char*)&obj,sizeof(obj));
		 if(bsp==obj.return_busno())
		{ sp=obj.calculate();
		  lpp=1;
		  return sp;
		 }
	    }
	     if(lpp!=1)
		return 0;
	  }
      goto reloop;
    return 0;
   }
  //class customer_rec:Manages a basic record diary as a binary file system
 class customer_rec:public pcalculator
  { private:
    char name[25],place_from[25],place_to[25],order_date[10],orderf_date[10];
    char bus_drivern[20],prline[70],choice[4];
     int Bus_no,orderno;
     long int phone_no;
     float netp,Tpaid,Dpaid;
     char temp1[70];
      long int temp2;
      float temp3;
  public:
    int enter_details();
    void show_details();
    char return_name();
    int return_order();
    float return_Dpaid();
    int modify();
 }customer;


  int customer_rec::enter_details()
   { clrscr();
     cout<<"<-\n"
	 <<"Customer Record"
	 <<"\n___________________________________________________________\n";
    gotoxy(1,4);
    cout<<"\n Order Number : ";
      cin>>orderno;
     cout<<"\n Name of Customer : ";
      gets(name);
     cout<<"\n Phone number : ";
      cin>>phone_no;
     cout<<"\nTravel from : ";
      gets(place_from);
     cout<<"\nTravel to : ";
      gets(place_to);
     cout<<"\nBus Number used : ";
      cin>>Bus_no;
     cout<<"\n Name of bus driver hired : ";
      gets(bus_drivern);
     cout<<"\n Order placed on : ";
      gets(order_date);
     cout<<"\n Net payment : Do you wish to calculate?(Y/N)";
      char ch;
     cin>>ch;
       if(ch=='y'||ch=='Y')
	{ netp=Calc_op(Bus_no);
	  clrscr();
	   cout<<"\n\n Net payment : Rs "<<netp;
	  }
	else
	 { clrscr();
	    cout<<"\n\n Net payment : Rs ";
	     cin>>netp;
	   }
	 cout<<"\n Total amount paid : Rs";
	   cin>>Tpaid;
	    Dpaid=netp=Tpaid;
	  cout<<"\n Payment due : Rs "<<Dpaid;
	   cout<<"Fullfillment of order done on : ";
	     gets(orderf_date);
	   cout<<"\n Problem,if any, occurred during travel(y/n): ";
	     if(strcmp(choice,"y")==0||strcmp(choice,"Y")==0)
	       gets(prline);
	      else
	       { strcpy(prline,"NIL");
		  cout<<prline;
		 }
	      delay(3000);
	      ldr:
	       clrscr();
		gotoxy(22,12);
		cout<<" Do you wish to : ";
		gotoxy(22,14);
		cout<<"1. View details just filled";
		gotoxy(22,16);
		cout<<"2. Enter details of another record";
		gotoxy(22,18);
		cout<"3. Go back to the customer record menu";
		cout<<"\n\n Enter command : ";
		 int ch1;
		 cin>>ch1;
		 if(ch1==1)
		   { show_details();
		     goto ldr;
		    }
		  else if(ch1==2)
		    return 2;
		  else
		    return 0;
		 }
void customer_rec::show_details()
 { clrscr();
   cout<<"\n Order number : "<<orderno
       <<"\n\n Name of customer : "<<name
       <<"\n\n Phone number : "<<phone_no
       <<"\n\n Travel from : "<<place_from
       <<"\n\n Travel to : "<<place_to
       <<"\n\n order placed on : "<<order_date
       <<"\n\n Bus number used : "<<Bus_no
       <<"\n\n Bus driver hired : "<<bus_drivern
       <<"\n\n Net payment : Rs "<<netp
       <<"\n\n Total amount paid : Rs "<<Tpaid
       <<"\n\n Payment due : Rs "<<Dpaid
       <<"\n\n Fullfillment of order done on : "<<orderf_date
       <<"\n\n Problem,if any,occurred during travel :\n"<<prline;
   cout<<"\n\n\n\t\t\t\t\tPress any key to go back";
   }

char customer_rec::return_name()
 { return *name;
 }
int customer_rec::return_order()
 { return orderno;
 }
float customer_rec::return_Dpaid()
 { return Dpaid;
 }

int customer_rec::modify()
 { clrscr();
    cout<<"\nEnter '.' to retain old data ";
     cout<<"\n\nName of customer : "<<name<<endl;
      gets(temp1);
       if(strcmp(temp1,".")!=0)
	  strcpy(name,temp1);
       cout<<"\n\n Travel from : "<<place_from<<endl;
	 gets(temp1);
	if(strcmp(temp1,".")!=0)
	   strcpy(place_from,temp1);
	cout<<"\n\n Travel to : "<<place_to<<endl;
	  gets(temp1);
	if(strcmp(temp1,".")!=0)
	  strcpy(place_to,temp1);
	cout<<"\n\n Order placed on : "<<order_date<<endl;
	   gets(temp1);
	    if(strcmp(temp1,".")!=0)
	      strcpy(temp1,order_date);
	    cout<<"\n\n Fullfillment of order done on : "<<orderf_date<<endl;
	      gets(temp1);
		if(strcmp(temp1,".")!=0)
		   strcpy(orderf_date,temp1);
		 cout<<"\n\n Bus driver hired : "<<bus_drivern<<endl;
		   gets(temp1);
		    if(strcmp(temp1,".")!=0)
		       strcpy(bus_drivern,temp1);

	    cout<<"\n\n\n Enter '0' to retain old data";
	     cout<<"\n\n Order number : "<<orderno<<endl;
	      cin>>temp2;
	     if(temp2!=0)
	       orderno=temp2;
	      cout<<"\n\n Phone number : "<<phone_no<<endl;
	       cin>>temp2;
	       if(temp2!=0)
		 phone_no=temp2;
	       cout<<"\n\n Net payment : Rs "<<netp<<endl;
		 cin>>temp3;
		if(temp3!=0)
		  netp=temp3;
		 cout<<"\n\n Toatal amount paid : Rs "<<Tpaid<<endl;
		  cin>>temp3;
		   if(temp3!=0)
		    Tpaid=temp3;
		   cout<<"\n\n Payment due : Rs "<<Dpaid<<endl;
		     cin>>temp3;
		      if(temp3!=0)
			Dpaid=temp3;

	      return 0;
	   }


void customer_menu()
 {   back:
     clrscr();
     cout<<"<-";
     char ch[4];
     gotoxy(24,12);
     cout<<"CUSTOMER RECORD MENU ";
     gotoxy(20,13);
     cout<<"___________________________";
     gotoxy(20,15);
     cout<<"1. Enter an order in record";
     gotoxy(20,17);
     cout<<"2. View an order";
     gotoxy(20,19);
     cout<<"3. Modify an order";
     gotoxy(20,21);
     cout<<"4. Delete order";
     cout<<"\n\n\nEnter command : ";
      gets(ch);
       if(strcmp(ch,"<-")==0)
	  return ;
       else if(strcmp(ch,"1")==0)
	 { customer_enter();
	   goto back;
	   }
	else if(strcmp(ch,"2")==0)
	  { customer_view();
	     goto back;
	   }
       else if(strcmp(ch,"3")==0)
	 { customer_modify();
	    goto back;
	  }
	else if(strcmp(ch,"4" )==0)
	 { customer_delete();
	    goto back;
	   }
	}
 void customer_enter()
  { int d;
    customer_rec b;
     ofstream recdec("record.dat",ios::out|ios::binary|ios::app);
     while(d==2)
      { clrscr();
	 d=b.enter_details();
	 recdec.write((char*)&b,sizeof(b));
	 }
       recdec.close();
	 if(d==0)
	  return;
       }
 void customer_view()
  { int number,result=0;
     char ch='y';
     while(ch=='y'||ch=='Y')
     { ifstream psp("record.dat",ios::in|ios::binary);
       customer_rec bc;
       cout<<" \n\n\n Enter the order number to be viewed : ";
	cin>>number;
	while(!psp.eof())
	 { psp.read((char*)&bc,sizeof(bc));
	   int order=bc.return_order();
	      if(number==order)
		{ cout<<"\n\n\n\t\t\t\t\tFOUND!!";
		   ++result;
		   bc.show_details();
		 }
	       }
	     if(result==0)
	       cout<<"\n\n\n\t\t\t\t\tNOT FOUND!!";
	     cout<<"Do you wish to see details of another order?(y/n)";
	      cin>>ch;
	   }
	    return ;
	  }
void custoner_modify()
  {  int ch,orderi,check=0;
     char namei[25],chk,namer[25];
       retry:
      clrscr();
       cout<<"\nDo you wish to search by entering "
	   <<"\n\t1. Name of customer"
	   <<"\n\t2. Order number";
     cout<<"\n\n\nEnter command : ";
       cin>>chk;
      if(chk==1)
	{ clrscr();
	  cout<<"\n Enter name : ";
	    gets(namei);
	   }
	 else
	   { clrscr();
	     cout<<"\n Enter order number : ";
	      cin>>orderi;
	      }
	   fstream modcus("record.dat",ios::out|ios::in|ios::binary|ios::app);
	    modcus.seekg(0,ios::beg);
	    customer_rec mod;
	     while(!modcus.eof())
	      { long pos=modcus.tellg();
		modcus.read((char*)&mod,sizeof(mod));
		 int p=mod.return_order();
		 *namer=mod.return_name();
		  if(strcmp(namer,namei)==0||p==orderi)
		   { clrscr();
		     cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tFOUND!!";
		      delay(1000);
		       clrscr();
		      cout<<"Is this the order you were looking for?(Y/N)";
		       cin>>chk;
		      if(chk=='y'||chk=='Y')
			{ ++check;
			    mod.modify();
			    modcus.seekp(pos);
			    modcus.write((char*)&mod,sizeof(mod));

			  }
		     }
		  }
		 clrscr();
	       if(check==0)
		{ cout<<"It seems that the order you are looking for is"
			<<"\n\n in existence."
			<<"\n\n Do you wish to try again?(y/n)";
		    cin>>chk;
		    if(chk=='y'||chk=='Y')
		      goto retry;
		    else
		     { clrscr();
			gotoxy(24,24);
		       cout<<" Going back to CUSTOMER RECORD MENU ";
		       return ;
		    }
		}

void customer_delete()
 { redel:
   int l;
   float frs=0.0;
   char ch,cht[4];
   clrscr();
   fstream wrdel("ttts.dat",ios::in|ios::out|ios::app|ios::binary);
   fstream cdel("record.dat",ios::in|ios::out|ios::app|ios::binary);
   customer_rec objd;
    cout<<"\n\n Enter the order range to be deleted"
	<<"\n\n *Note that the upper value and the lower value of the range so entered will not be deleted";
      cout<<"\n\n Min : ";
      int min;
       cin>>min;
      cout<<"\n\n Max : ";
      int max;
       cin>>max;
      while(!cdel.eof())
       { cdel.read((char*)objd,sizeof(objd));
	  int p=objd.return_order();
	  if(p>min&&p<max)
	   { cout<<p;
	      float frs1=objd.return_Dpaid();
	      if(frs1==frs)
		cout<<" { COMPLETED } \n";
	       else
		 cout<<" { Rs. "<<frs1<<"left to be paid } \n";
	       cdel.seekg(0,ios::beg);
	       clrscr();
		gotoxy(10,24);
		 cout<<"Do you wish to continue?(y/n)";
		cin>>ch;
		  if(ch=='y'||ch=='Y')
		   { while(!cdel.eof())
		      {  cdel.read((char*)&objd,sizeof(objd));
			  int r=objd.return_order();
			   if(r>min&&r<max)
			    ++l;
			   else
			    wrdel.write((char*)&objd,sizeof(objd));
			}
		     clrscr();
		     gotoxy(18,24);
		       cout<<l<<" number of records are deleted";
		   }
		   else
		    return ;
		 clrscr();
		  cout<<"\n\n\n\t\t\tPress 1 to delete more records"
		      <<"\n\n\t\t\tEnter '<-' to go back"
		      <<"\n\n Enter command : ";
		    gets(cht);
	       if(strcmp(cht,"<-")==0)
		 return;
	       else(strcmp(cht,"1")==0)
		 goto redel;
	      }
	    }
      }
   }
 void menu()
 {  remenu_view:
   clrscr();
     int command;
     gotoxy(27,12);
      cout<<"TRAVEL X";
      gotoxy(24,14);
      cout<<"_____________";
      gotoxy(25,16);
	cout<<"1. Driver Files";
       gotoxy(25,18);
	 cout<<"2. Conductor Files";
	gotoxy(25,20);
	 cout<<"3. Other Employee's Files";
	gotoxy(25,22);
	 cout<<"4. Bus Files";
	gotoxy(25,26);
	  cout<<"5. Order's Record";
	 gotoxy(25,28);
	  cout<<"6. Payment Calculator";
	gotoxy(25,30);
	  cout<<"7. Exit";
       gotoxy(24,32);
       cout<<"______________";
	gotoxy(24,34);
	 cout<<"Enter Command : ";
	cin>>command;
	switch(command)
	 { case 1: driver dr;
		   dr.driver_menu();
		   break;
	   case 2: conductor cd;
		   cd.conductor_menu();
		   break;
	   case 3: other_employee oe;
		   oe.otemp_menu();
		   break;
	   case 4: bus bs;
		   bs.bus_menu();
		   break;
	   case 5: customer_menu();
		   break;
	   case 6: Calc_op();
		   break;
	   case 7: clrscr();
		   gotoxy(12,24);
		   cout<<"Exiting the program";
		   delay(2000);
		   exit(0);
	     default: clrscr();
		       gotoxy(28,24);
			cout<<"Command not verified";
			gotoxy(28,24);
			cout<<"Try Again";
		   }
		goto remenu_view;
	    }


void main()
   {     clrscr();
	 securityfunc();

	 getch();
   }


#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void securityfunc();
void menu();
void loadstart();
void loaderfunc();
float Calc_op(int);
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
	    delay(2000);
	   }
 class basicfunctions
 { char filename[20],choice[4],choice1,lineinput[70],pgcommand[4],newline[70];
    int lineno,linenoI,newlineno,chk;
   public:
    basicfunctions()
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
	  lineno=1;
     cout<<"\n Enter the name of the you wish to open\n(use'.txt'extension): ";
     gets(filename);
     ex:
     ifstream opentxtf(filename,ios::in|ios::app|ios::nocreate);
       if(!opentxtf)
       { clrscr();
	 gotoxy(32,24);
	 cout<<"FILE DOESN'T";
	 gotoxy(36,26);
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
       { clrscr();
	   cout<<filename
	       <<"\n_____________________________________________________________\n";
	       opentxtf.seekg(0,ios::beg);
	   while(!opentxtf.eof())
	   { ++lineno;
	      opentxtf.getline(lineinput,68);
	       cout<<lineno<<". "<<lineinput<<endl;
	    }
	    lineno=0;
	      cout<<"Press any key to go back";
	      getch();
	     opentxtf.close();
	     return 0;
	    }
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
   { MF:
    clrscr();
     cout<<"<- ->\n"
	 <<"\n Enter file name\n(Use'.txt' extension) : ";
      gets(filename);
       fstream apptxtf(filename,ios::in|ios::out|ios::app);
      apptxtf.seekg(0,ios::beg);
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
		lineno=1;
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
		   if(lineno==newlineno)
		     {  cout<<"Enter the line you wish to add : \n";
			   gets(newline);
			 newtxtf<<newline<<endl;
		  }
	      else
		newtxtf<<lineinput<<endl;
	      lineno++;
	  }
       remove(filename);
      rename("tcc.txt",filename);
	 apptxtf.close();
	    newtxtf.close();
	    lineno=0;
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
       fstream apptxtf(filename,ios::in|ios::out|ios::app);
      apptxtf.seekg(0,ios::beg);
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
		lineno=1;
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
		   if(lineno==newlineno)
		     {  cout<<"Enter the line you wish to add : \n";
			   gets(newline);
			 newtxtf<<newline<<endl;
			 newtxtf<<lineinput<<endl;
		  }
	      else
		newtxtf<<lineinput<<endl;
	      lineno++;
	  }

       remove(filename);
      rename("tcc.txt",filename);
	 apptxtf.close();
	    newtxtf.close();
	    lineno=0;
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
	ofstream createstrm(filename1,ios::out);
		cout<<"\nEnter the name of the driver : ";
		     gets(name);
		     createstrm<<" Name : "<<name;
		  cout<<"\nEnter the name of Mother of the driver : ";
		    gets(mname);
		    createstrm<<"\n Mother's name : "<<mname;
		  cout<<"\nEnter the name of Father of the driver : ";
		    gets(fname);
		    createstrm<<"\n Father's name : "<<fname;
		  cout<<"\nEnter date of birth of the driver : ";
		    gets(dob);
		    createstrm<<"\n Date of Birth : "<<dob;
		 cout<<"\nEnter blood group of the driver : ";
		   gets(bgroup);
		   createstrm<<"\n Blood Group : "<<bgroup;
		 cout<<"\nEnter residence address of the driver : ";
		  gets(residence);
		  createstrm<<"\n Residence Address : "<<residence;
		 cout<<"\nEnter Aadhar No.of the driver :";
		  cin>>aadharno;
		  createstrm<<"\n Aadhar Number : "<<aadharno;
		cout<<"\nEnter License No. of the driver : ";
		  gets(licenseno);
		  createstrm<<"\n License Number : "<<licenseno;
	       cout<<"\n Phone Number : ";
		  cin>>phone_no;
		createstrm<<"\n Phone Number : "<<phone_no;
		cout<<"\nEnter the maximum academic qualification of the driver : ";
		  gets(education);
		  createstrm<<"\n Maximum academic qualification : "<<education;
		cout<<"\nEnter the date of joining of the driver : ";
		  gets(doj);
		  createstrm<<"\n Date of Joining : "<<doj;
		cout<<"\nEnter the permit of the driver : ";
		 gets(permit);
		 createstrm<<"\n Permit : "<<permit;
		cout<<"\n Enter criminal record,if any,to which the driver was a part : ";
		  gets(crime_rec);
		  createstrm<<"\n Criminal Record : "<<crime_rec;
		  cout<<"\nOther details\n";
		  createstrm<<"\nOther details";
		 choice='y';
		while(choice=='y'||choice=='Y')
		 { cout<<": ";
		    gets(other_det);
		    createstrm<<"\n"<<other_det;
		   cout<<"\n\n  Do you wish to enter another line?(y/n)";
		     cin>>choice;
		  }
		clrscr();
		createstrm.close();
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
		cout<<"\nEnter the name of the conductor : ";
		     gets(name);
		     createstrm<<" Name : "<<name;
		  cout<<"\nEnter the name of Mother of the conductor : ";
		    gets(mname);
		    createstrm<<"\n Mother's Name : "<<mname;
		  cout<<"\nEnter the name of Father of the conductor : ";
		    gets(fname);
		    createstrm<<"\n Father's Name : "<<fname;
		  cout<<"\nEnter date of birth of the conductor : ";
		    gets(dob);
		    createstrm<<"\n Date of Birth : "<<dob;
		 cout<<"\nEnter blood group of the conductor : ";
		   gets(bgroup);
		   createstrm<<"\n Blood Group : "<<bgroup;
		 cout<<"\nEnter residence address of the conductor : ";
		  gets(residence);
		  createstrm<<"\n Residence Address : "<<residence;
		 cout<<"\nEnter Aadhar No.of the conductor :";
		  cin>>aadharno;
		  createstrm<<"\n Aadhar Number : "<<aadharno;
		cout<<"\nEnter License No. of the conductor : ";
		  gets(licenseno);
		  createstrm<<"\n License Number : "<<licenseno;
		cout<<"\n Phone Number : ";
		  cin>>phone_no;
		createstrm<<"\nPhone Number : "<<phone_no;
		cout<<"\nEnter the maximum academic qualification of the conductor : ";
		  gets(education);
		  createstrm<<"\n Maximum academic qualification : "<<education;
		cout<<"\nEnter the date of joining of the conductor : ";
		  gets(doj);
		  createstrm<<"\n Date of Joining : "<<doj;
		cout<<"\nEnter the permit of the conductor : ";
		 gets(permit);
		 createstrm<<"\n Permit : "<<permit;
		cout<<"\n Enter criminal record,if any,to which the conductor was a part : ";
		  gets(crime_rec);
		  createstrm<<"\n Criminal Record : "<<crime_rec;
		  cout<<"\nOther details\n";
		  createstrm<<"\n Other Details ";
		 choice='y';
		while(choice=='y'||choice=='Y')
		 { cout<<": ";
		    gets(other_det);
		       createstrm<<"\n"<<other_det;
		   cout<<"\n\n  Do you wish to enter another line?(y/n)";
		     cin>>choice;
		  }
		clrscr();
		createstrm.close();
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
       char residence[60],licenseno[25];
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
	     cout<<"\nEnter the name of the employee : ";
		     gets(name);
		      createstrm<<" Name : "<<name;
		  cout<<"\nEnter the name of Mother of the employee : ";
		    gets(mname);
		    createstrm<<"\n Mother's Name : "<<mname;
		  cout<<"\nEnter the name of Father of the employee : ";
		    gets(fname);
		    createstrm<<"\n Father's Name : "<<fname;
		  cout<<"\nEnter date of birth of the employee : ";
		    gets(dob);
		    createstrm<<"\n Date of Birth : "<<dob;
		 cout<<"\nEnter blood group of the employee : ";
		   gets(bgroup);
		   createstrm<<"\n Blood Group : "<<bgroup;
		 cout<<"\nEnter residence address of the employee : ";
		  gets(residence);
		  createstrm<<"\n Residnce Address :"<<residence;
		 cout<<"\nEnter Aadhar No.of the employee :";
		  cin>>aadharno;
		  createstrm<<"\n\n Aadhar Number : "<<aadharno;
		cout<<"\nEnter License No. of the employee : ";
		  gets(licenseno);
		  createstrm<<"\n License Number : "<<licenseno;
		cout<<"\n Phone Number : ";
		  cin>>phone_no;
		createstrm<<"\n Phone Number : "<<phone_no;
		cout<<"\nEnter the maximum academic qualification of the employee : ";
		  gets(education);
		  createstrm<<"\n Maximum academic qualification : "<<education;
		cout<<"\nEnter the date of joining of the employee : ";
		  gets(doj);
		  createstrm<<"\n Date of Joining : "<<doj;
	   cout<<"\nEnter the job done by employee : ";
	      gets(occ);
	      createstrm<<"\n Occupation : "<<occ;
		cout<<"\n Enter criminal record,if any,to which the employee was a part : ";
		  gets(crime_rec);
		  createstrm<<"\n Criminal Record : "<<crime_rec;
		  cout<<"\nOther details\n";
		    createstrm<<"\n Other Details ";
		 choice='y';
		while(choice=='y'||choice=='Y')
		 { cout<<": ";
		    gets(other_det);
		    createstrm<<"\n "<<other_det;
		   cout<<"\n\n  Do you wish to enter another line?(y/n)";
		     cin>>choice;
		  }
		createstrm.close();
		clrscr();
		 cout<<"Do you wish to create another file?(Y/N)";
		cin>>choice;
	       if(choice=='y'||choice=='Y')
		 goto rpp;
	       else
		 return 0;
	      }
  class bus:public basicfunctions
  { int busno,pascap;
    char type[10],choice,filename1[20],manufactured_by[15],manufactured_on[10],bo[10], registration_no[15];
     char permit[60],contractno[15],condition[70],otherbdet[70],Dchoice[4];
      float cost,fucap;
   public:
    int bus_createf();
    int bus_menu();
  };

  int bus::bus_createf()
{ rpp:
   clrscr();
    cout<<"New File\n\n\n Enter the name the with which you wish to save the file(use '.txt' extension) : ";
      gets(filename1);
   clrscr();
      cout<<filename1<<"\n________________________________________________________________________";
	ofstream createstrm(filename1,ios::out|ios::app);
	      cout<<"\n\n Enter Bus number : ";
		  cin>>busno;
		createstrm<<"\n Bus Number : "<<busno;
	      cout<<"\nEnter the type of bus : ";
		gets(type);
	       createstrm<<"\n Bus type : "<<type;
		 cout<<"\n\nPassenge capacity of bus : ";
		   cin>>pascap;
		createstrm<<"\n Passenger Capacity : "<<pascap;
	     cout<<"\n\n Enter the fuel capacity of bus( in Litres) :";
	       cin>>fucap;
	      createstrm<<"\n Fuel capacity( in Litres) : "<<fucap;
	      cout<<" \n\nManufatured by : ";
		gets(manufactured_by);
	       createstrm<<"\n Manufactured by : "<<manufactured_by;
	      cout<<"Manufacture completed on : ";
	       gets(manufactured_on);
		createstrm<<"\n Manufacture completed on : "<<manufactured_on;
	      cout<<"\n\n Bought on : ";
		gets(bo);
	      createstrm<<"\n Bought on : "<<bo;
	     cout<<"\n\n Cost : Rs ";
	     cin>>cost;
	       createstrm<<"\n Cost : Rs"<<cost;
	   cout<<" \n\n Contract number : ";
		gets(contractno);
	    createstrm<<"\n Contract number : "<<contractno;
	  cout<<"\n\n Permit : ";
	      gets(permit);
	    createstrm<<"\n Permit : "<<permit;
	  cout<<"\n\n Condition : ";
	     gets(condition);
	 createstrm<<"\n Condition : "<<condition;
	  clrscr();
	     createstrm.close();
		 cout<<"Do you wish to create another file?(Y/N)";
		cin>>choice;
	       if(choice=='y'||choice=='Y')
		 goto rpp;
	       else
		 return 0;
	   }
 int bus::bus_menu()
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
	   { bus_createf();
		goto Dloop;
	      }
	      else if(strcmp(Dchoice,"2")==0)
	       {  int rod=opentxtf(0,0);
		  if(rod==0)
		    goto Dloop;
		   else
		    bus_createf();
		 }
	     else if(strcmp(Dchoice,"3")==0)
	      {  int mod=modifymenu();
		     if(mod==0)
			goto Dloop;
		      else
			bus_createf();
		  }
	      else if(strcmp(Dchoice,"4")==0)
	       { deletetxtf();
		  goto Dloop;
		}
	       return 0;
	   }
  //class customer_rec:Manages a basic record diary as a binary file system
 class customer_rec
  { private:
    char name[35],place_from[40],place_to[40],order_date[10],orderf_date[10];
    char bus_drivern[35],prline[70],choice[4];
     int Bus_no,orderno,passno;
     long int phone_no;
     float netp,Tpaid,Dpaid;
     char temp1[70],temp4[25],temp0[12];
      long int temp2;
      float temp3;
  public:
    char found;
    customer_rec()
    { found='n';
    }
    int enter_details();
    int show_details();
    char return_found();
    int return_order();
    float return_Dpaid();
    int modify();
 };


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
      cout<<"\n Number of Passengers : ";
      cin>>passno;
     cout<<"\n Order placed on : ";
      gets(order_date);
     cout<<"\n Net payment : Rs ";
	     cin>>netp;
	 cout<<"\n Total amount paid : Rs";
	   cin>>Tpaid;
	    Dpaid=netp-Tpaid;
	  cout<<"\n Payment due : Rs "<<Dpaid;
	   cout<<"\n\nFullfillment of order done on : ";
	     gets(orderf_date);
	   cout<<"\n Problem,if any, occurred during travel : ";
	     gets(prline);
	     cout<<"\n\nPress any key to go back...";
	      getch();
	     return 0;
		 }
int customer_rec::show_details()
 { clrscr();
   cout<<"\n Order number : "<<orderno
       <<"\n\n Name of customer : "<<name
       <<"\n\n Phone number : "<<phone_no
       <<"\n\n Travel from : "<<place_from
       <<"\n\n Travel to : "<<place_to
       <<"\n\n order placed on : ";puts(order_date);
   cout<<"\n\n Bus number used : "<<Bus_no
       <<"\n\n Bus driver hired : ";puts(bus_drivern);
   cout<<"\n\n Number of Passengers : "<<passno
       <<"\n\n Net payment : Rs "<<netp
       <<"\n\n Total amount paid : Rs "<<Tpaid
       <<"\n\n Payment due : Rs "<<Dpaid
       <<"\n\n Fullfillment of order done on : "<<orderf_date
       <<"\n\n Problem,if any,occurred during travel\n : "<<prline;
   cout<<"\n\n\n\t\t\t\t\tPress any key to go back";
     getch();
     return 0;
   }

char customer_rec::return_found()
 { return found;
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
	      gets(temp0);
		if(strcmp(temp0,".")!=0)
		   strcpy(orderf_date,temp0);
		 cout<<"\n\n Bus driver hired : "<<bus_drivern<<endl;
		   gets(temp4);
		    if(strcmp(temp4,".")!=0)
		       strcpy(bus_drivern,temp4);

	    cout<<"\n\n\n Enter '0' to retain old data";
	     cout<<"\n\n Order number : "<<orderno<<endl;
	      cin>>temp2;
	     if(temp2!=0)
	       orderno=temp2;
	      cout<<"\n\n Phone number : "<<phone_no<<endl;
	       cin>>temp2;
	       if(temp2!=0)
		 phone_no=temp2;
	       cout<<"\n\n Number of passengers : "<<passno<<endl;
		cin>>temp2;
		 if(temp2!=0)
		   passno=temp2;
	       cout<<"\n\n Net payment : Rs "<<netp<<endl;
		 cin>>temp3;
		if(temp3!=0)
		  netp=temp3;
		 cout<<"\n\n Total amount paid : Rs "<<Tpaid<<endl;
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
  { customer_rec b;
     ofstream recdec("record.dat",ios::out|ios::binary|ios::app);
       clrscr();
	 b.enter_details();
	 clrscr();
	 cout<<"\nTHE DETAILS ARE : ";
	 b.show_details();
	 recdec.write((char*)&b,sizeof(b));
	  recdec.close();
	   return ;
     }
 void customer_view()
  { clrscr();
    int number,result=0;
      ifstream psp("record.dat",ios::in|ios::binary);
       customer_rec bc;
       cout<<" \n\n\n Enter the order number to be viewed : ";
	cin>>number;

	  while(psp.read((char*)&bc,sizeof(bc)))
	  { int order=bc.return_order();
	      if(order==number)
		{ cout<<"\n\n\n\t\t\t\t\tFOUND!!";
		  delay(1000);
		   ++result;
		   bc.show_details();
		 }
	       }
	     if(result==0)
	       { clrscr();
	       cout<<"\n\n\n\t\t\t\t\tNOT FOUND!!";
	       delay(1500);
	      }
	    return ;
	 }
void customer_modify()
  {  int orderi,check=0;
      char chk;
       retry:
	clrscr();
	 cout<<"\n Enter order number : ";
	  cin>>orderi;
	   fstream modcus("record.dat",ios::out|ios::in|ios::binary|ios::app);
	   ofstream modnew("TCC.dat",ios::out|ios::binary|ios::app);
	    modcus.seekg(0,ios::beg);
	    customer_rec mod;
	     while(!modcus.eof())
	      { modcus.read((char*)&mod,sizeof(mod));
		int p=mod.return_order();
		if(p==orderi&&check==0)
		 {  check=1;
		     customer_rec mof(mod);
		      mof.modify();
		      modnew.write((char*)&mof,sizeof(mof));
		   }
		   else if(p==orderi&&check==1)
		    { cout<<" REPITITIONS HAVE BEEN REMOVED";
		      }
		 else if(p!=orderi)
		 {  modnew.write((char*)&mod,sizeof(mod));
		  }
	       }
		modcus.close();
		modnew.close();
		remove("record.dat");
		rename("TCC.dat","record.dat");
	       if(check==0)
		{ cout<<"It seems that the order you are looking for is"
		      <<"\n\n not in existence."
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
	 }

void customer_delete()
 { redel:
   int l,delsize;
   char ch,cht[4];int deloptions[10];
   clrscr();
   fstream wrdel("TTC.dat",ios::in|ios::out|ios::app|ios::binary);
   fstream cdel("record.dat",ios::in|ios::out|ios::app|ios::binary);
   customer_rec objd;
   cout<<"MAXIMUM LIMIT OF ORDERS TO BE DELETED IS 10";
    cout<<"\n\n  Enter the order no.'s to be deleted."
	<<" Press Enter after entering every record number"
	<<"\n  Enter '0' to end enteries"<<"\n\n : ";
     for( delsize=0;delsize<10;delsize++)
       {  cin>>deloptions[delsize];
	 if(deloptions[delsize]==0)
	   goto Br;
	 }
       Br:
       delsize=delsize+1;
    while(!cdel.eof())
     {  cdel.read((char*)&objd,sizeof(objd));
	 l=objd.return_order();
	  for(int i=0;i<delsize;i++)
	   { if(l==deloptions[i])
	       { objd.found='y';
		 cout<<"\a\n"<<l<<" : Payment Due = Rs."<<objd.return_Dpaid();
	       }
	    }
      }
      cout<<"  CONTINUE?(Y/N)";
       cin>>ch;
    if(ch=='y'||ch=='Y')
    { l=1;
       clrscr();
       cdel.seekg(0,ios::beg);
	while(!cdel.eof())
       { cdel.read((char*)&objd,sizeof(objd));
	  if(objd.found=='n')
	 { wrdel.write((char*)&objd,sizeof(objd));
	  }
	  else if(objd.found=='y')
	   { ++l;
	     cout<<"\a";
	     delay(10);
	   }
	}
	cdel.close();
	wrdel.close();
	remove("record.dat");
	rename("TCC.dat","record.dat");
	clrscr();
	gotoxy(10,25);
	cout<<l<<" number of records deleted ";
      }
      else if(ch=='n'||ch=='N')
       { clrscr();
	 gotoxy(29,24);
	 cout<<" \aDELETION DIVERTED ";
	 delay(2000);
       }

     clrscr();
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\tPress 1 to delete more records"
     <<"\n\n\t\t\tEnter '<-' to go back"
     <<"\n\n Enter command : ";
	gets(cht);
	 if(strcmp(cht,"<-")==0)
	  return ;
	  else if(strcmp(cht,"1")==0)
	  goto redel;

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
	  cout<<"6. Exit";
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
	   case 6: clrscr();
		   gotoxy(12,24);
		   cout<<"Exiting the program";
		   delay(2000);
		   exit(0);
		   break;
	     default: clrscr();
		       gotoxy(28,24);
			cout<<"Command not verified";
			gotoxy(28,24);
			cout<<"Try Again";
			break ;
	       }
		goto remenu_view;
	    }


void main()
   {     clrscr();
	 securityfunc();

	 getch();
   }


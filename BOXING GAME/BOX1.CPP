#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
 char ch='1';
 int x=0,y=0;
 gotoxy(0,0);
 cout<<"|o|";
 while(ch!='0')
  { cin>>ch;
      switch(ch)
       {  case '1': if(x!=0&&y!=0)
		     ++y;
		     else
		     { --x;
		       ++y;
		       }
		       clrscr();
		      gotoxy(x,y);
		       cout<<"|o|";
		     break;
	  case '2':clrscr();
		   ++y;
		   gotoxy(x,y);
		   cout<<"|o|";
		   break;
	  case '3': clrscr();
		    ++y;
		    ++x;
		    gotoxy(x,y);
		    cout<<"|o|";
		    break;
	   case '4': clrscr();
		     if(x==0&&y==0)
		       {  gotoxy(32,28);
			  cout<<"\aRope a Dope!!";
			  gotoxy(x,y);
			  cout<<"|o|";
		       }
		      else
			{ --x;
			  gotoxy(x,y);
			  cout<<"|o|";
			}
			break;
	   case '7': clrscr();
		      if(x==0&&y==0)
		      { gotoxy(x,y);
			 cout<<"|o|";
			 gotoxy(32,28);
			 cout<<"\a Leaning!!";
		       }
		       else if(x==0||y==0)
			{ gotoxy(x,y);
			  cout<<"|o|";
			}
			else
			 { --x;
			   --y;
			   gotoxy(x,y);
			   cout<<"|0|";
			 }
			 break;
	    case '8': clrscr();
			 if(x==0||y==0)
			   { gotoxy(32,28);
			      cout<<"Escaping!!";
			      gotoxy(x,y);
			      cout<<"|o|";
			     }
			 else
			   {  --y;
			      gotoxy(x,y);
				cout<<"|o|";
			    }
		       break;
	    case '9': clrscr();
		       if(x==0||y==0)
			 { gotoxy(32,28);
			   cout<<" \a\aEscaping!!!!";
			   gotoxy(x,y);
			   cout<<"|o|";
			 }
			 else
			   { ++x;
			      --y;
			      gotoxy(x,y);
			      cout<<"|o|";
			    }
			break;
	    case '6': clrscr();
		       ++x;
		       gotoxy(x,y);
		       cout<<"|o|";
		       break;
	    default: gotoxy(50,32);
			 cout<<"aha!!";
			 break;
	   }
	  }
	   getch();
  }
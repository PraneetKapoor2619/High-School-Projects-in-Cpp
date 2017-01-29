#include<iostream.h>
#include<conio.h>
#include<ctype.h>
void main()
{  char ch='y';
   float t1,t2,T1,T2,tn,TN,ANSWER;
    while(ch=='y'||ch=='Y')
     { clrscr();
	char expression[100];
	  cout<<"\nCalculator"
	      <<"\n_______________________________________________________________________________";
	 cout<<"\n Enter the expression\n(To Terminate the expression,put 'E' in end)\n\n : ";
	 for(int i=0;i<100;i++)
	  {  while(expression[i-1]!='E')
		{ gotoxy(5+i,6);
		   cin>>expression[i];
		 }
	    }
	 int size=sizeof(expression);
	  for(int l=0;l<size;l++)
	   {  if(expression[l]=='*'||expression[l]=='/')
		{ int j=l, k=l;
		   while(j>=0)
		      { if(ispunct(expression[j-1])==0)
			 { t1=expression[j-1];
			     goto a;
			  }
		       --j;
		       }
		    a:
		   while(expression[k+1]!='\0')
		      { if(ispunct(expression[k+1])==0)
			 { t2=expression[k+1];
			    goto b;
			  }
			 ++k;
		       }
		     b:
		   if(expression[l]=='*')
		     {  tn=t1*t2;
			expression[j-1]=tn;
			  expression[l]='.';
			    expression[k+1]='.';
		       }
		    else if(expression[l]=='/')
		      {  tn=t1/t2;
			  expression[j-1]=tn;
			    expression[l]='.';
			     expression[k+1]='.';
			 }
		    }
		}
	 for(int r=0;r<size;r++)
	   { if(expression[r]=='+'||expression[r]=='-')
	      { int j=r,k=r;
		 while(j>=0)
		   { if(ispunct(expression[j-1]==0))
		      { T1=expression[j-1];
			 goto c;
		       }
		       --j;
		    }
		  c:
		 while(expression[k+1]!=0)
		   { if(ispunct(expression[k+1])==0)
		      { T2=expression[k+1];
			 goto d;
		      }
		      ++k;
		    }
		  d:
		 if(expression[r]=='+')
		   { TN=T1+T2;
		      expression[j-1]=TN;
		       expression[r]='.';
			expression[k+1]=='.';
		     }
		 else if(expression[r]=='-')
		   { TN=T1-T2;
		       expression[j-1]=TN;
			 expression[r]='.';
			  expression[k+1]='.';
		    }
		 }
	      }
       for(int p=0;p<50;p++)
	{  if(ispunct(expression[p]==0))
	    { ANSWER=expression[p];
	       goto e;
	       }
	}
	e:
	 cout<<"\n\n ANSWER IS : "<<ANSWER;
	  cout<<"\n\n Do you wish to calculate more expressions?(y/n)";
	   cin>>ch;
	}
	getch();
      }

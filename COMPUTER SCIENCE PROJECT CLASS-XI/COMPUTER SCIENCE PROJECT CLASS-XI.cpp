#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
void main()
{ clrscr();
 int m,n; m=n=0;
 cout<<"\t\t\tPHYSICS QUIZ\t\n\n";
char chp[25]="phyhigh";
char chpu[25],q[6],l[20]; cout<<"\n\n ENTER THE LOG IN PASSWORD PLEASE-->";
cin>>chpu;
if(strcmp(chpu,chp)==0)
{ cout<<"YOU ARE LOGGED IN";
}
else
{ cout<<"YOU ENTERED THE WRONG PASSWORD";
exit(0);
}
cout<<"\nENTER YOUR FIRST NAME CANDIDATE-->";cin>>l;
cout<<"\n\nNOW  THE QUIZ WILL START "<<l<<"\nIT HAS FIVE QUESTIONS OF 5 MARKS EACH"<<"\n FOR WRONG ANSWER NO MARKS WILL BE DEDUCTED";
cout<<"\n\n Q1:THE LIFETIME OF AN ISOLATED PROTON IS APPROXIMATELY -"<<"\n a)10^41\nb)10^47\nc)10^(-37)\nd)10^(-46)"<<"\n->  ";
cin>>q[0];
cout<<"\n Q2: THE FAMOUS TIME TRAVEL PARADOX ALMOST EQUIVALENT TO HITLER'S PARADOX IS-"
<<"\n a)FUTURE VISITOR'S PARADOX\n b)REVOLUTION PARADOX\n c)GRANDFATHER'S PARADOX\n d)INFORMATION PARADOX"<<"\n->  ";
cin>>q[1];
cout<<"\n Q3: ADJUSTMENT MADE BY SOMMERFIELD IN BOHR'S ATOMIC MODEL WAS INTRODUCTION OF-"
<<"\n a)SUBSHELLS\n b)ELLIPTICAL ORBITS OF e-\n  c)POSITRON-ELECTRON PAIRS\n  d)CONCEPT OF QUARKS"<<"\n->   ";
cin>>q[2];
cout<<"\n Q4: WHICH OF THE FOLLOWING IS TRUE ABOUT PHOTON-"
<<"\n a)THEY HAVE MOMENTUM\n b)HAVE AN ANTI-PARTICLE\n c)ARE INVOLVED IN INTERACTION OF e- BY FEYNMAN DIAGRAMS\n d)ALL OF THESE ARE CORRECT"<<"\n->  ";
cin>>q[3];
cout<<"\n Q5: FOR WHICH CONCEPT IN THEORETICAL PHYSICS RELATED TO POWER AND ENERGY IS FREEMAN DYSON FAMOUS FOR-"
<<"\n a) DYSON MATRIX\n b) DYSON LIGHT\n C) DYSON SPHERE\n d)DYSON REACTIONS"<<"\n->  ";
cin>>q[4];
char a[6]={'a','c','b','d','c','\o'};
for(int i=0;i<6;i++)
{ if(a[i]==q[i])
{ m=m+4;
n=n+1;
}
}
cout<<"\t\t\n\n**END OF TEST**"<<"\n\n NUMBER OF QUESTIONS CORRECT: "<<n<<"\n\n NUMBER OF QUESTIONS INCORRECT: "<<5-n
<<"\n\n YOU HAVE SCORED "<<m<<" POINTS OUT OF 20 POINTS";
int p=m*100/20;
if(p>30)
{ cout<<"\n\n"<<l<<"YOU PASSED THE EXAMINATION"<<"\n YOUR PERCENTAGE WAS "<<p<<"%";
}
else
{ cout<<"\n\n"<<l<< " HAVE FAILED IN THIS EXAMINATION:-("<<"\n YOUR PERCENTAGE WAS "<<p<<"%";
cout<<"\n\n\t\t **BETTER LUCK NEXT TIME**";
}
getch();
}
/*The following header files are included*/
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream.h>
#include <graphics.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>

/*This structures holds the data regarding the signup forms*/
struct medal
{
int total;
char name[50];
medal *next;
};
medal medals;

struct signups
      {
       char name[40];
       char actcode[25];
       char nation[20];
       char state[25];
       char city[25];
       char phone[25];
       char email[25];
       char password[25];
       char id[50];//Id means the random id that softaware provides you
      };

struct players_register
      {
       char p_name[50];
       char p_gender[7];
       char p_country[50];
       char p_sport[50];
       char p_birth_date[20];
       int rank;
       int total;
       }player;


class countries
      {
       public:
       char name[30];
       char continent[30];
       int total;
      }con,country_obj;

char *account;
void logo();//It draws the olympic ring logo in the screen
void loading();//It shows the loading menu
void frontpage();
void sport_shooting();
void drawgun(int x,int y,int size,int height);
void search_animate(int);
void help();//Displays the help menu and its features
void mainmenu();//The very first menu of the program
void sportriefel();
void loginmenu();//If person wants to login
void searchbyplayer();
void swimmingsport();
void gengraph();
void searchbysports();
void search();
void updaterecord(char[],char[]);
void searchtab();
void visit();
void visitplayer();
void visitcountry();
void medallist();
void loggedin();
void graph(int num[],int n);
void nologin();//Menu to Continue without login
void removeplayer();
void signup();//Generates sign up forms
void updatetopten();
void datamenu();//Only Logged in persons can edit data
void warning();
void searchmenu();//Search the old database
int getycordinate(int,int,int);//Used for getting the y cordinate in case of menus
void drawpointat(int,int);//Draws the menu pointer at a location
void deletepointat(int,int);//Deletes the menu pointer at a location
void getpassword(char []);//To get details in ****** form
void blinkstr(int,int,char[],int,int);
void flames(int,int);//Draws blinking lamps
void convert(char[],int);
void flames2(int,int);
void sportswimming();
void playerdetails();
void modify_datas();
void sportbadminton_start();
void drawlock(int,int);
void add_country();
void remove_country();
void olympic_text();
void add_remove_country();
void olympicsport();
void drawtt(int x,int y,int r1,int r2);
void singletennis();
void sport_tennis();
void searchbycountry();
void doublematch(char[],char[]);
void riefelswimmatch(char[],char[]);
void drawbadminton(int x,int y,int r1,int r2);
void doublebadminton();
void singlebadminton();
void doubletennis();
void tennissingle(char[]);
void sportbadminton();
void badmintonsingle(char[]);
void drawcourt();
void main()
     {
      /*Initialization of graphics system*/
      int graph_driver=DETECT,graph_mode,error;
      initgraph(&graph_driver,&graph_mode,"C:/TC/BGI");
      error=graphresult();
      if(error!=0)
	{
	 clrscr();
	 textcolor(GREEN);
	 cout<<"GRAPHICS ARE NOT INITIALIZED";
	 exit(0);
	}
      search_animate(60);//It accepts the millisecond parameter for delay
      cleardevice();
      settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
      /**Now designing of screens start**/
      loading();//Shows the first loading screen
      textcolor(5);
      cleardevice();//Clears screen in graphic mode
      frontpage();//Creates the Welcome page of the program
      cleardevice();
      getch();//kbhit function passes a character
      setbkcolor(BLACK);
      mainmenu();
      delete account;
      closegraph();
     }


void border(int col)
     {
      setcolor(col);
      int i=0,l=0,r=0,t=639,b=479;
      for(i=0;i<5;++i)
	 {
	 rectangle(l,r,t,b);
	 b-=1;
	 t-=1;
	 l+=1;
	 r+=1;
	 }
      b-=4;
      t-=4;
      l+=4;
      r+=4;
      setcolor(col+1);
      for(i=0;i<5;++i)
	 {
	  rectangle(l,r,t,b);
	  l+=1;
	  r+=1;
	  t-=1;
	  b-=1;
	 }
     }

void man_fig()//It draws the shape of man
     {
      setcolor(3);
      int shape[10];//Shape is a polygon array for the man's body
      circle(100,180,25);
      shape[0]=89;
      shape[1]=205;
      shape[2]=100;
      shape[3]=280;
      shape[4]=111;
      shape[5]=205;
      drawpoly(3,shape);
      //Now the same array for another parts
      shape[2]=40;
      shape[3]=240;
      shape[4]=91;
      shape[5]=220;
      drawpoly(3,shape);
      shape[0]=112;
      shape[1]=205;
      shape[2]=180;
      shape[3]=190;
      shape[4]=5;
      shape[5]=6;
      drawpoly(2,shape);
     }

void search_animate(int time)//to show animation while processing
     {
      setcolor(WHITE);
      int j,i,x,y,angle1=0,angle2=36;
      x=getmaxx()/2;
      y=getmaxy()/2;
      for(j=0;j<2;++j)
	 {
	   angle1=0;
	   angle2=30;
	   for(i=0;i<19;++i)
	     {
	      cleardevice();
	      setfillstyle(SLASH_FILL,i);
	      pieslice(x,y,angle1,angle2,200);
	      angle1+=18;
	      angle2+=18;
	      delay(time);
	     }
	 }
   }

void loading()
     {
     int r=0;
     int i=1,color=YELLOW;//Colour Index
     border(2);
     int x=180,poly[10];
     while(!kbhit())//If loading is completed successfully
     {
     flames(80,200);
     flames(560,200);
     if(x>450)
       {
	if(x==470)
	  goto endcompile;
	setcolor(BLACK);
	poly[6]=450;
	setfillstyle(SOLID_FILL,BLACK);
	settextstyle(10,HORIZ_DIR,5);
	outtextxy(170,20,"Loading.......");
	drawpoly(6,poly);
	fillpoly(6,poly);
	setcolor(9);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,0);
	outtextxy(180,340,"Successfully Loaded...");
	setcolor(6);
	outtextxy(210,400,"Press Any Key");
	x+=10;
	endcompile:
	goto end;
      }
     settextstyle(10,HORIZ_DIR,5);
     setcolor(color);
     outtextxy(170,20,"Loading.......");
     if(color==YELLOW)
       color=BLACK;
     else
       color=YELLOW;
     settextstyle(GOTHIC_FONT,HORIZ_DIR,0);
     setcolor(BLACK);
     rectangle(180,360,x-10,380);
     setcolor(YELLOW);
     poly[0]=180;
     poly[1]=360;
     poly[2]=180;
     poly[3]=380;
     poly[4]=x;
     poly[5]=380;
     poly[6]=x;
     poly[7]=360;
     poly[8]=180;
     poly[9]=360;
     setfillstyle(SOLID_FILL,GREEN);
     drawpoly(5,poly);
     fillpoly(5,poly);
     x+=10;
     end:
     if(r>100)
       {
	r=0;
       }
     setcolor(i);
     circle(319,240,r);
     r+=10;
     ++i;
     if(i==15)
       i=1;
    }
  getch();
  }

void frontpage()
     {
      int c=1;
      setbkcolor(WHITE);
      logo();
      border(4);
      outtextxy(180,320,"Olympic Data Manager");
      delay(1000);
      while(!kbhit())//Until keyboard is not hit
	{
	setcolor(c);
	while(!kbhit())
	blinkstr(180,380,"Press Enter to Continue",5,0);
	++c;//changes colour everytime
	if(c>14)
	  {
	   c=1;
	  }
       }
     }

void mainmenu()
     {
      again:
      cleardevice();
      setbkcolor(BLACK);
      char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=1,temp=1;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu
      border(5);
      setlinestyle(SOLID_LINE,1,3);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
      setcolor(2);
      outtextxy(90,80,"O");
      circle(100,100,50);
      setcolor(3);
      circle(100,100,55);
      setcolor(4);
      outtextxy(95,230,"L");
      circle(105,240,45);
      setcolor(5);
      circle(105,240,50);
      setcolor(6);
      outtextxy(140,330,"Y");
      circle(150,340,45);
      setcolor(7);
      circle(150,340,40);
      setcolor(8);
      outtextxy(260,350,"M");
      circle(270,360,40);
      setcolor(9);
      circle(270,360,35);
      setcolor(10);
      outtextxy(370,350,"P");
      circle(380,360,35);
      setcolor(11);
      circle(380,360,30);
      setcolor(12);
      outtextxy(465,305,"I");
      circle(470,320,30);
      setcolor(13);
      circle(470,320,25);
      setcolor(14);
      outtextxy(545,255,"C");
      circle(550,270,25);
      setcolor(2);
      circle(550,270,20);
      setcolor(10);
      setlinestyle(SOLID_LINE,1,1);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,50,"Select Your Choice");
      setcolor(9);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
      outtextxy(220,80,"Log In");
      //setcolor(7);
      //delay(1000);
      outtextxy(220,110,"Sign Up");
      //setcolor(9);
      //delay(1000);
      outtextxy(220,140,"Continue without Sign in");
      //setcolor(11);
      //delay(1000);
      outtextxy(220,170,"Help");
      //setcolor(12);
      //delay(1000);
      outtextxy(220,200,"Quit");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      //delay(1000);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==0)
			index=5;
		      break;
	      case 80:index=index+1;
		      if(index==6)
			index=1;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 1:loginmenu();
	       break;
	case 2:signup();
	       break;
	case 3:nologin();
	       break;
	case 4:help();
	       break;
	case 5:exit(0);
       }
    goto again;
   }

void drawpointat(int a,int b)
     {
      setcolor(11);
      while(!kbhit())
      blinkstr(a,b,"*",1,1);
     }

void deletepointat(int a,int b)
     {
      setcolor(BLACK);
      outtextxy(a,b,"*");
      setcolor(WHITE);
     }

/*cord_y refers to the  y cordinate of pointer,change refers to the
    change in two y cordinates and index refers to current index pointed*/
int getycordinate(int cord_y,int change,int index)
    {
     int y;
     --index;
     y=cord_y+(index*change);
     return(y);
    }

void loginmenu()
     {
      signups s;
      ifstream file("Signup.dat",ios::in|ios::binary);
      if(!file)
	 {
	  outtextxy(150,200,"Sorry!! No User Account Is Registered Till Now");
	  getch();
	  goto end;
	 }
      char id[20];
      char password[20];
      cleardevice();
      setbkcolor(LIGHTCYAN);
      setcolor(BLUE);
      outtextxy(150,20,"Type 0 in any field to exit Signing In Mode");
      reenter:
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      logo();
      border(DARKGRAY);
      setcolor(RED);
      outtextxy(150,282,"Enter Id:");
      gotoxy(30,19);
      gets(id);
      if(id[0]=='0')
	 goto end;
      if(id[0]=='\0')
	{
	 while(!kbhit())
	 blinkstr(200,400,"You didn't entered any thing",SANS_SERIF_FONT,1);
	 getch();
	 setcolor(BLACK);
	 outtextxy(200,400,"You didn't entered any thing");
	 setcolor(YELLOW);
	 goto reenter;
	}
      reenter2:
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      setcolor(RED);
      outtextxy(150,313,"Enter Password:");
      gotoxy(38,21);
      getpassword(password);
      if(password[0]=='0')
	 goto end;
      if(password[0]=='\0')
	{
	 while(!kbhit())
	 blinkstr(200,400,"You didn't entered any thing",SANS_SERIF_FONT,1);
	 getch();
	 setcolor(BLACK);
	 outtextxy(200,400,"You didn't entered any thing");
	 setcolor(YELLOW);
	 goto reenter2;
	}
     while(!file.eof())
	{
	 file.read((char*)&s,sizeof(s));
	 if((strcmp(s.id,id)==0)&&(strcmp(s.password,password)==0))
	   {
	    setbkcolor(BLACK);
	    account=s.id;
	    loggedin();
	    goto end;
	   }
	}
     end:
     }

/*The getpassword function helps in entering data as password or in * form*/
void getpassword(char pass[])
     {
      char ch;
      int i=0;
      do
       {
	ch=getch();
	if(ch==8&&i>0)
	  {
	   cout<<"\b \b";//here the deletion of stars takes place
	   pass[i]='\0';
	   --i;
	  }
	else
	if(ch!=13&&ch!=27&&ch!=8)
	  {
	   cout<<"*";
	   pass[i]=ch;
	   ++i;
	  }
       }while(ch!=13);
      pass[i]='\0';
  }

void signup()
     {
      char code[25],ucode[25],ucheck[25];
      int n;
      ifstream ucodes("ucode.txt");
      ifstream secret("secret.srp");
      secret.getline(code,25);//The Secret Code is Read here
      ucodes.getline(ucheck,25);
      ofstream file("Signup.dat",ios::binary|ios::app);
      fstream  tries;
      int check=0;//It checks whether all details are entered or not
      signups s;//object of signup structure to get signup information
      char choice;
      setcolor(BLUE);
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
      reenter:
      cleardevice();
      border(10);
      tries.open("tries.txt",ios::in);
      tries>>n;
      tries.close();
      if(n==0)//If the software has been locked
	{
	 cleardevice();
	 drawlock(320,240);
	 setcolor(BLUE);
	 outtextxy(260,30,"Enter 0 to Exit");
	 border(12);
	 outtextxy(180,46,"Priya Grahak Software ab locked ho chuka hai");
	 outtextxy(180,80,"Do You want to unlock sign up mode (Y/N):");
	 choice=getch();
	 /*The variable n records total available tries*/
	 if(choice=='y'||choice=='Y')
	   {
	    outtextxy(180,114,"Enter the Unlock code:");
	    tryagain:
	    gotoxy(47,5);
	    getpassword(ucode);
	    if(ucode[0]=='0')
	       goto ends;
	    if(strcmp(ucode,ucheck)==0)
	      {
	       tries.open("tries.txt",ios::out);
	       n=3;
	       tries<<n;
	       tries.close();
	      }
	    else
	      {
	       while(!kbhit())
	       blinkstr(190,260,"You Entered Wrong Code.....(Retry)",SANS_SERIF_FONT,1);
	       getch();
	       setcolor(BLACK);
	       outtextxy(190,260,"You Entered Wrong Code.....(Retry)");
	       setcolor(RED);
	       gotoxy(47,5);
	       cout<<"                             ";
	       goto tryagain;
	      }
	    cleardevice();
	    border(14);
	   }
	 else
	   {
	    cleardevice();
	    goto endofsignup;
	   }
	}
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
      outtextxy(170,30,"To get code contact Olympic Committe");
      outtextxy(490,30,"Cost:$500000");
      outtextxy(240,52,"Activation Code:");
      gotoxy(49,4);
      getpassword(s.actcode);
      if(!strcmp(s.actcode,code))
	{
	 goto contd;
	}
      else
	{
	 --n;
	 outtextxy(180,84,"You have total tries left:");
	 gotoxy(49,6);
	 cout<<n;
	 tries.open("tries.txt",ios::out);
	 tries<<n;
	 tries.close();
	 getch();
	 goto reenter;
	}
      contd:
      gotoxy(24,8);
      setcolor(YELLOW);
      rectangle(178,98,442,302);
      setcolor(GREEN);
      rectangle(182,102,438,298);
      cout<<"* Name:";
      gotoxy(24,10);
      cout<<"* Country:";
      gotoxy(24,12);
      cout<<"  State:";
      gotoxy(24,14);
      cout<<"* City:";
      gotoxy(24,16);
      cout<<"* Phone:";
      gotoxy(24,18);
      cout<<"  Email:";
      gotoxy(24,25);
      cout<<"* means important fields";
      gotoxy(31,8);
      drawpointat(150,115);
      gets(s.name);
      deletepointat(150,115);
      drawpointat(150,147);
      gotoxy(34,10);
      gets(s.nation);
      deletepointat(150,147);
      gotoxy(32,12);
      drawpointat(150,179);
      gets(s.state);
      deletepointat(150,179);
      gotoxy(31,14);
      drawpointat(150,211);
      gets(s.city);
      deletepointat(150,211);
      gotoxy(32,16);
      drawpointat(150,243);
      gets(s.phone);
      deletepointat(150,243);
      gotoxy(32,18);
      drawpointat(150,275);
      gets(s.email);
      deletepointat(150,275);
      recheck://Recheck label sends back for entering information
      if(s.name[0]=='\0')
	{
	  check=0;
	  ++check;
	  gotoxy(24,25);
	  cout<<"Please Enter your name   ";
	  gotoxy(31,8);
	  drawpointat(150,115);
	  gets(s.name);
	  deletepointat(150,115);
	  if(s.name[0]!='\0')
	    --check;
	}
      if(s.nation[0]=='\0')
	{
	  check=0;
	  ++check;
	  gotoxy(24,25);
	  cout<<"Please Enter the nation  ";
	  gotoxy(34,10);
	  drawpointat(150,147);
	  gets(s.nation);
	  deletepointat(150,147);
	  if(s.nation[0]!='\0')
	    --check;
	}
      if(s.city[0]=='\0')
	{
	  check=0;
	  ++check;
	  gotoxy(24,25);
	  cout<<"Please Enter your city   ";
	  gotoxy(31,14);
	  drawpointat(150,211);
	  gets(s.city);
	  deletepointat(150,211);
	  if(s.city[0]!='\0')
	     --check;
	}
      if(s.phone[0]=='\0')
	{
	  check=0;
	  ++check;
	  gotoxy(24,25);
	  cout<<"Please Enter the phone   ";
	  gotoxy(32,16);
	  drawpointat(150,243);
	  gets(s.phone);
	  deletepointat(150,243);
	  if(s.phone[0]!='\0')
	    --check;
	}
      if(check!=0)
	{
	  goto recheck;
	}
      gotoxy(10,20);
      cout<<"Press F1 to read the license Agreement or Enter to continue";
      again:
      choice=getch();
      if(choice==13)
	{
	 gotoxy(14,25);
	 cout<<"Do You meet the committe's license agreement (Y/N):";
	 choice=getch();
	 choice=toupper(choice);
	 cout<<choice;
	 if(choice=='Y'||choice=='y')
	   goto savepoint;
	 else
	   goto endofsignup;//Discard refers to act of not saving in file
	}
      else
      if(choice=='\0')
	{
	 choice=getch();
	 if(choice==59)
	   {
	    gotoxy(6,22);
	    cout<<"The software is protected from copyright by Apptica"
		   "Corporations.";
	    gotoxy(6,23);
	    cout<<"Any public violation of software is strictly prohibited."
		   " Misuse ";
	    gotoxy(6,24);
	    cout<<"of software by selling or any other method is"
		   " punishable by law";
	   }
	  goto again;
	}
       else
	 {
	  goto again;
	 }
      savepoint://If everything is finalized
      cleardevice();
      border(10);
      setcolor(GREEN);
      settextstyle(5,HORIZ_DIR,1);
      outtextxy(160,40,"Now You are almost to be our member");
      gotoxy(44,7);
      outtextxy(180,85,"Enter ID:");
      retry_id:
      gotoxy(34,7);
      cout<<"                     ";
      gotoxy(34,7);
      gets(s.id);
      if(s.id[0]=='0')
         goto ends;
      if(strlen(s.id)<4)
	 {
	  while(!kbhit())
	  blinkstr(160,400,"Be Careful ID Length should be >4",5,1);
	  getch();
	  setcolor(BLACK);
	  outtextxy(160,400,"Be Careful ID Length should be >4");
	  setcolor(GREEN);
	  goto retry_id;
	 }
      outtextxy(180,130,"Enter Password:");
      retry_pass:
      gotoxy(40,10);
      cout<<"                     ";
      gotoxy(40,10);
      getpassword(s.password);
       if(strlen(s.password)<8)
	 {
	  while(!kbhit())
	  blinkstr(160,400,"Be Careful Password Length should be >7",5,1);
	  getch();
	  setcolor(BLACK);
	  outtextxy(160,400,"Be Careful Password Length should be >7");
	  setcolor(GREEN);
	  goto retry_pass;
	 }
      outtextxy(180,162,"Re-Enter Password:");
      gotoxy(44,12);
      getpassword(code);
      if(strcmp(code,s.password)==0)
	{
	 cleardevice();
	}
      else
	{
	 gotoxy(44,12);
	 cout<<"                                 ";
	 while(!kbhit())
	 blinkstr(160,400,"Be Careful Password Do Not Match",5,1);
	 getch();
	 setcolor(BLACK);
	 outtextxy(160,400,"Be Careful Password Do Not Match");
	 setcolor(GREEN);
	 goto retry_pass;
	}
      cleardevice();
      border(DARKGRAY);
      while(!kbhit())
      blinkstr(160,50,"Dear User Thanks for Completing Registration",6,3);
      getch();//To retrieve extra key
      file.write((char*)&s,sizeof(s));
      file.close();
      endofsignup:
      cleardevice();
      /*while(!file.eof())
	 {
	  file.read((char*)&s,sizeof(s));
	  cout<<s.name;
	  cout<<s.password;
	}*/
      ends:
     }

void nologin()
     {
      char ch;
      int index=1,temp=1,y;
      cleardevice();
      border(7);
      setcolor(GREEN);
      settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
      setcolor(YELLOW);
      outtextxy(200,50,"Welcome to Guest Menu");
      setcolor(9);
      olympic_text();
      settextstyle(3,HORIZ_DIR,2);
      outtextxy(230,80,"Search Data");
      outtextxy(230,110,"View Graphs");
      outtextxy(230,140,"Medal Lists");
      outtextxy(230,170,"Back Menu");
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(200,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==0)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=1;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(200,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
     switch(index)
       {
	case 1:search();
	       break;
	case 2:gengraph();
	       break;
	case 3:medallist();
	       break;
	case 4:cleardevice();

       }
     }

void blinkstr(int x,int y,char s[],int font,int size)
     {
      static int i=1;
      settextstyle(font,HORIZ_DIR,size);
      if(i==14)
	i=1;
      setcolor(i);
      ++i;
      outtextxy(x,y,s);
      delay(10);
     }

void loggedin()
     {
      //the temp coordinate stores the previously pointed index menu
      int y,index=1,ch,temp=1;
      cleardevice();
      border(7);
      setlinestyle(SOLID_LINE,1,3);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
      setcolor(2);
      outtextxy(90,80,"O");
      circle(100,100,50);
      setcolor(3);
      circle(100,100,55);
      setcolor(4);
      outtextxy(95,230,"L");
      circle(105,240,45);
      setcolor(5);
      circle(105,240,50);
      setcolor(6);
      outtextxy(140,330,"Y");
      circle(150,340,45);
      setcolor(7);
      circle(150,340,40);
      setcolor(8);
      outtextxy(260,350,"M");
      circle(270,360,40);
      setcolor(9);
      circle(270,360,35);
      setcolor(10);
      outtextxy(370,350,"P");
      circle(380,360,35);
      setcolor(11);
      circle(380,360,30);
      setcolor(12);
      outtextxy(465,305,"I");
      circle(470,320,30);
      setcolor(13);
      circle(470,320,25);
      setcolor(14);
      outtextxy(545,255,"C");
      circle(550,270,25);
      setcolor(2);
      circle(550,270,20);
      setcolor(10);
      settextstyle(6,HORIZ_DIR,4);
      outtextxy(170,38,"You have Successfully Logged in");
      setcolor(CYAN);
      settextstyle(8,HORIZ_DIR,2);
      outtextxy(200,80,"Enter Player Details");
      outtextxy(200,110,"Modify Existing Datas");
      outtextxy(200,140,"Visit Database");
      outtextxy(200,170,"Log Out -");
      settextstyle(7,HORIZ_DIR,1);
      setcolor(YELLOW);
      outtextxy(310,175,account);
      settextstyle(8,HORIZ_DIR,2);
      do
      {
      y=getycordinate(80,30,index);
      setcolor(BLUE);//Sets colour of the pointer
      drawpointat(165,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==0)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=1;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(165,y+6);
       temp=index;
      }while(ch!=13);
     switch(index)
       {
	case 1:playerdetails();
	       break;
	case 2:modify_datas();
	       break;
	case 3:visit();
	       break;
	case 4:goto end;
       }
     loggedin();
     end:
     }

void flames(int a,int b)
     {
      static int n=0;
      int poly[20];
      static int x[20]={a-30,a-10,a-15,a,a+15,a+10,a+30,a+10};
      static int y[20]={b-15,b-10,b-25,b-18,b-25,b-10,b-15,b};
      static int i=1;
      setcolor(i);
      setfillstyle(SLASH_FILL,i);
      rectangle(a-10,b,a+10,b+90);
      floodfill(a,b+10,i);
      poly[0]=a-10;
      poly[1]=b;
      poly[2]=a-30;
      poly[3]=b-15;
      poly[4]=a-10;
      poly[5]=b-10;
      poly[6]=a-15;
      poly[7]=b-25;
      poly[8]=a;
      poly[9]=b-18;
      poly[10]=a+15;
      poly[11]=b-25;
      poly[12]=a+10;
      poly[13]=b-10;
      poly[14]=a+30;
      poly[15]=b-15;
      poly[16]=a+10;
      poly[17]=b;
      drawpoly(9,poly);
      setfillstyle(CLOSE_DOT_FILL,i);
      fillpoly(9,poly);
      ++i;
      if(i==15)
	i=1;
      setcolor(YELLOW);
      circle(x[0]-2,y[0]-3,1);
      circle(x[1]-2,y[1]-3,1);
      circle(x[2]-2,y[2]-3,1);
      circle(x[3]-2,y[3]-3,1);
      circle(x[4]-2,y[4]-3,1);
      circle(x[5]-2,y[5]-3,1);
      delay(50);
      setcolor(BLACK);
      circle(x[0]-2,y[0]-3,1);
      circle(x[1]-2,y[1]-3,1);
      circle(x[2]-2,y[2]-3,1);
      circle(x[3]-2,y[3]-3,1);
      circle(x[4]-2,y[4]-3,1);
      circle(x[5]-2,y[5]-3,1);
      x[0]-=4;
      x[1]-=4;
      x[2]-=4;
      x[4]+=4;
      x[5]+=4;
      y[0]-=4;
      y[1]-=4;
      y[2]-=4;
      y[3]-=4;
      y[4]-=4;
      y[5]-=4;
      ++n;
      if(n==5)
	{
	 x[0]=a-30;
	 x[1]=a-10;
	 x[2]=a-15;
	 x[3]=a;
	 x[4]=a+15;
	 x[5]=a+10;
	 x[6]=a+30;
	 x[7]=a+10;
	 y[0]=b-15;
	 y[1]=b-10;
	 y[2]=b-25;
	 y[3]=b-18;
	 y[4]=b-25;
	 y[5]=b-10;
	 y[6]=b-15;
	 y[7]=b;
	 n=0;
       }
     }

void flames2(int a,int b)
     {
      static int n=0;
      int poly[20];
      static int x[20]={a-30,a-10,a-15,a,a+15,a+10,a+30,a+10};
      static int y[20]={b-15,b-10,b-25,b-18,b-25,b-10,b-15,b};
      static int i=1;
      setcolor(i);
      setfillstyle(SLASH_FILL,i);
      rectangle(a-10,b,a+10,b+90);
      floodfill(a,b+10,i);
      poly[0]=a-10;
      poly[1]=b;
      poly[2]=a-30;
      poly[3]=b-15;
      poly[4]=a-10;
      poly[5]=b-10;
      poly[6]=a-15;
      poly[7]=b-25;
      poly[8]=a;
      poly[9]=b-18;
      poly[10]=a+15;
      poly[11]=b-25;
      poly[12]=a+10;
      poly[13]=b-10;
      poly[14]=a+30;
      poly[15]=b-15;
      poly[16]=a+10;
      poly[17]=b;
      drawpoly(9,poly);
      setfillstyle(CLOSE_DOT_FILL,i);
      fillpoly(9,poly);
      ++i;
      if(i==15)
	i=1;
      setcolor(YELLOW);
      circle(x[0]-2,y[0]-3,1);
      circle(x[1]-2,y[1]-3,1);
      circle(x[2]-2,y[2]-3,1);
      circle(x[3]-2,y[3]-3,1);
      circle(x[4]-2,y[4]-3,1);
      circle(x[5]-2,y[5]-3,1);
      delay(50);
      setcolor(BLACK);
      circle(x[0]-2,y[0]-3,1);
      circle(x[1]-2,y[1]-3,1);
      circle(x[2]-2,y[2]-3,1);
      circle(x[3]-2,y[3]-3,1);
      circle(x[4]-2,y[4]-3,1);
      circle(x[5]-2,y[5]-3,1);
      x[0]-=4;
      x[1]-=4;
      x[2]-=4;
      x[4]+=4;
      x[5]+=4;
      y[0]-=4;
      y[1]-=4;
      y[2]-=4;
      y[3]-=4;
      y[4]-=4;
      y[5]-=4;
      ++n;
      if(n==5)
	{
	 x[0]=a-30;
	 x[1]=a-10;
	 x[2]=a-15;
	 x[3]=a;
	 x[4]=a+15;
	 x[5]=a+10;
	 x[6]=a+30;
	 x[7]=a+10;
	 y[0]=b-15;
	 y[1]=b-10;
	 y[2]=b-25;
	 y[3]=b-18;
	 y[4]=b-25;
	 y[5]=b-10;
	 y[6]=b-15;
	 y[7]=b;
	 n=0;
       }
     }

void draw_ring(int x,int y,int radius,int width)
     {
       for(int i=0;i<width;++i)
	  {
	   circle(x,y,radius+i);
	  }
    }

void logo()
     {
       setlinestyle(SOLID_LINE,1,THICK_WIDTH);
       setcolor(BLUE);
       draw_ring(210,150,50,5);
       setcolor(DARKGRAY);
       draw_ring(320,150,50,5);
       setcolor(RED);
       draw_ring(430,150,50,5);
       setcolor(YELLOW);
       draw_ring(265,200,50,5);
       setcolor(GREEN);
       draw_ring(375,200,50,5);
       setlinestyle(SOLID_LINE,1,NORM_WIDTH);
     }


void sport_badminton()
     {
      int y1=100;
      setbkcolor(BLACK);
      border(RED);
      while(!kbhit())
	{
	  if(y1==160)
	   {
	    drawbadminton(100,y1,25,50);
	    drawbadminton(540,y1,25,50);
	    setlinestyle(SOLID_LINE,1,THICK_WIDTH);
	    drawcourt();
	    y1=161;
	   }
	   if(y1==161)
	   {
	   delay(100);
	   goto donotmove;
	   }
	  setcolor(DARKGRAY);
	  drawbadminton(100,y1,25,50);
	  drawbadminton(540,y1,25,50);
	  delay(50);
	  setcolor(BLACK);
	  drawbadminton(100,y1,25,50);
	  drawbadminton(540,y1,25,50);
	  y1++;
	  if(y1!=160)
	  continue;
	  donotmove:
	  blinkstr(135,220,"......................",10,5);
	  blinkstr(135,280,"BADMINTON",10,5);
	  blinkstr(135,295,"......................",10,5);
	  blinkstr(120,385,"Press enter to continue",5,5);
	  }
      getch();
    }

void drawbadminton(int x,int y,int r1,int r2)
     {
      setfillstyle(HATCH_FILL,GREEN);
      ellipse(x,y,0,360,r1,r2);
      fillellipse(x,y,r1,r2);
      rectangle(x-2,y+50,x+2,y+130);
     }

void drawtt(int x,int y,int r1,int r2)
     {
      setfillstyle(SOLID_FILL,BLUE);
      ellipse(x,y,0,360,r1,r2);
      fillellipse(x,y,r1,r2);
      rectangle(x-4,y+70,x+4,y+170);
     }

void playerdetails()
     {
      players_register player={" "," "," "," "," ",0,0};
      char dd[5],mm[5],yy[5];
      char choice;
      ifstream country_file;
      int continues=0;
      /*The above variable is used in the case of editing which tells
      whether the compiling should be continued or not*/
      char sport,gender;
      //Player.dat contains details of different players who are registered
      cleardevice();
      settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
      setcolor(YELLOW);
      outtextxy(150,40,"Type 0 in any field to exit registration");
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
      setcolor(GREEN);
      outtextxy(160,50,"New Player Registration Form");
      border(YELLOW);
      setcolor(YELLOW);
      rectangle(178,98,442,389);
      setcolor(BLUE);
      rectangle(180,100,440,387);
      gotoxy(24,8);
      cout<<"1* Name:";
      gotoxy(24,10);
      delay(500);
      cout<<"2* Country:";
      gotoxy(24,12);
      delay(500);
      cout<<"3* Select Gender:";
      gotoxy(24,13);
      delay(500);
      cout<<"   Press 1 for male";
      gotoxy(24,14);
      cout<<"   Press 2 for Female";
      gotoxy(24,16);
      delay(500);
      cout<<"4* Choose Sport:";
      gotoxy(24,17);
      cout<<"   Press 1 for Badminton";
      gotoxy(24,18);
      cout<<"   Press 2 for Shooting (Gun)";
      gotoxy(24,19);
      cout<<"   Press 3 Tennis";
      gotoxy(24,20);
      cout<<"   Press 4 for Swimming";
      gotoxy(24,23);
      delay(500);
      cout<<"5* Birth Date:";
      cout<<"____/__/__";
      gotoxy(24,22);
      cout<<"   (yy/mm/dd)";
      /*Player details are entered here*/
      names:
      drawpointat(150,115);
      gotoxy(32,8);
      cout<<"                    ";
      gotoxy(32,8);
      gets(player.p_name);
      deletepointat(150,115);
      if(player.p_name[0]=='\0')
	{
	  gotoxy(24,28);
	  cout<<"Please Enter player's name   ";
	  getch();
	  gotoxy(24,28);
	  cout<<"                             ";
	  gotoxy(32,8);
	  cout<<"                ";
	  goto names;
	}
      else
	 if(player.p_name[0]=='0')
	    goto endofthefunction;

      if(continues==1)
	{
	 goto edit;
	}
      /**************Country***************/
      countries:
      country_file.open("Country.dat",ios::binary|ios::in);
      drawpointat(150,147);
      gotoxy(35,10);
      cout<<"                    ";
      gotoxy(35,10);
      gets(player.p_country);
      deletepointat(150,147);
      if(player.p_country[0]=='\0')
	{
	  gotoxy(24,28);
	  cout<<"Please Enter Country's Name";
	  getch();
	  gotoxy(24,28);
	  cout<<"                            ";
	  gotoxy(35,10);
	  cout<<"                  ";
	  goto countries;
	}
      else
	 if(player.p_country[0]=='0')
	    goto endofthefunction;
      country_file.seekg(0);
      while(country_file)
	   {
	   country_file.read((char*)&country_obj,sizeof(country_obj));
	   if(strcmpi(country_obj.name,player.p_country)==0)
		{
		 goto endofsearch;
		}
	   }
	  country_file.close();
	  gotoxy(15,28);
	  gotoxy(13,26);
	  cout<<"Dear User The Entered Country Does Not Exist in The Database." ;
	  gotoxy(17,27);
	  cout<<"Please Retry or Refer to the Country Database.";
	  getch();
	  gotoxy(13,26);
	  cout<<"                                                             " ;
	  gotoxy(17,27);
	  cout<<"                                              ";
	  goto countries;
      endofsearch:
      country_file.close();
      if(continues==1)
	{
	 goto edit;
	}
      /**************Gender***************/
      checkgender:
      gotoxy(41,12);
      drawpointat(150,179);
      gender=getch();
      cout<<gender;
      if(gender=='1')
	{
	 strcpy(player.p_gender,"Male");
	 gotoxy(41,12);
	 cout<<player.p_gender;
	}
      else
      if(gender=='2')
	{
	 strcpy(player.p_gender,"Female");
	 gotoxy(41,12);
	 cout<<player.p_gender;
	}
      else
      if(gender=='0')
	goto endofthefunction;
      else
	 {
	  gotoxy(24,28);
	  cout<<"Sorry.....Wrong Gender Choice!!!!!";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  gotoxy(41,12);
	  cout<<" ";
	  goto checkgender;
	}
      deletepointat(150,179);
      if(continues==1)
	{
	 goto edit;
	}
      /*********************************/
      checksport:/*Used for checking sport consistency*/
      gotoxy(40,16);
      drawpointat(150,245);
      sport=getch();
      cout<<sport;
      if(sport=='1')
	 {
	  gotoxy(40,16);
	  strcpy(player.p_sport,"Badminton");
	  cout<<player.p_sport;
	 }
      else
      if(sport=='2')
	 {
	  gotoxy(40,16);
	  strcpy(player.p_sport,"Riefel");
	  cout<<player.p_sport;
	 }
      else
      if(sport=='3')
	 {
	  gotoxy(40,16);
	  strcpy(player.p_sport,"Tennis");
	  cout<<player.p_sport;
	 }
      else
      if(sport=='4')
	 {
	  gotoxy(40,16);
	  strcpy(player.p_sport,"Archery");
	  cout<<player.p_sport;
	 }
      else
      if(sport=='5')
	 {
	  gotoxy(40,16);
	  strcpy(player.p_sport,"Swimming");
	  cout<<player.p_sport;
	 }
      else
      if(sport=='0')
	    goto endofthefunction;
      else
	 {
	  gotoxy(24,28);
	  cout<<"Sorry.....Wrong Sport Choice!!!!!";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  gotoxy(40,16);
	  cout<<" ";
	  goto checksport;
	 }
      deletepointat(150,245);
      if(continues==1)
	{
	 goto edit;
	}
      /**********Date of Birth**********/
      dob:
      gotoxy(38,23);
      cout<<"____/__/__";
      drawpointat(150,350);
      year:/***********/
      gotoxy(38,23);
      cout<<"____";
      gotoxy(38,23);
      yy[0]=getch();
      if(!isdigit(yy[0]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto year;
	 }
      cout<<yy[0];
      yy[1]=getch();
      if(!isdigit(yy[1]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto year;
	 }
      cout<<yy[1];
      yy[2]=getch();
      if(!isdigit(yy[1]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto year;
	 }
      cout<<yy[2];
      yy[3]=getch();
      if(!isdigit(yy[1]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto year;
	 }
      cout<<yy[3];
      yy[4]='\0';
      if(strcmp(yy,"0000")==0)
	 {
	   gotoxy(24,28);
	   cout<<"Please Enter Valid Year (Press any key)";
	   getch();
	   gotoxy(24,28);
	   cout<<"                                        ";
	   goto year;
	  }
      month:/***********/
      gotoxy(43,23);
      cout<<"__";
      gotoxy(43,23);
      mm[0]=getch();
      if(!isdigit(mm[0]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto month;
	 }
      yy[4]='\0';
      cout<<mm[0];
      mm[1]=getch();
      if(!isdigit(mm[1]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto month;
	 }
      cout<<mm[1];
      mm[2]='\0';
      if(strcmp(mm,"00")==0)
	 {
	   gotoxy(24,28);
	   cout<<"Please Enter A valid Month (Press any key)";
	   getch();
	   gotoxy(24,28);
	   cout<<"                                          ";
	   goto month;
	 }
      if(strcmp(mm,"12")>0)
	{
	 gotoxy(24,28);
	 cout<<"Please Enter A valid Month (Press any key)";
	 getch();
	 gotoxy(24,28);
	 cout<<"                                          ";
	 goto month;
	}

      date:/***********/
      gotoxy(46,23);
      cout<<"__";
      gotoxy(46,23);
      dd[0]=getch();
      if(!isdigit(dd[0]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto date;
	 }
      cout<<dd[0];
      dd[1]=getch();
      if(!isdigit(dd[1]))
	 {
	  gotoxy(24,28);
	  cout<<"Please Enter Digit (Press any key)";
	  getch();
	  gotoxy(24,28);
	  cout<<"                                  ";
	  goto date;
	 }
      cout<<dd[1];
      dd[2]='\0';
      if(strcmp(dd,"00")==0)
	 {
	   gotoxy(24,28);
	   cout<<"Please Enter Valid Date (Press any key)";
	   getch();
	   gotoxy(24,28);
	   cout<<"                                       ";
	   goto date;
	  }
      if(strcmp(mm,"01")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
      else
      if(strcmp(mm,"02")==0)
	 {
	  if(strcmp(dd,"28")>0)
	   {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"03")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"04")==0)
	 {
	  if(strcmp(dd,"30")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"05")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"06")==0)
	 {
	  if(strcmp(dd,"30")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"07")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	  }
       else
      if(strcmp(mm,"08")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"09")==0)
	 {
	  if(strcmp(dd,"30")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"10")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"11")==0)
	 {
	  if(strcmp(dd,"30")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
       else
      if(strcmp(mm,"12")==0)
	 {
	  if(strcmp(dd,"31")>0)
	    {
	     gotoxy(24,28);
	     cout<<"Please Enter valid date (Press any key)";
	     getch();
	     gotoxy(24,28);
	     cout<<"                                       ";
	     goto date;
	    }
	 }
      strcat(player.p_birth_date,yy);
      strcat(player.p_birth_date,"/");
      strcat(player.p_birth_date,mm);
      strcat(player.p_birth_date,"/");
      strcat(player.p_birth_date,dd);
      deletepointat(150,350);
      /*********************************/
      saving_starts_here:
      gotoxy(22,26);
      cout<<"Are the Following Details Correct (Y/N):";
      choice=getch();
      gotoxy(22,26);
      cout<<"                                        ";
      if(choice=='Y'||choice=='y')
	{
	 gotoxy(22,27);
	 cout<<"Do You Want to Save.....(Y/N):";
	 choice=getch();
	 if(choice=='Y'||choice=='y')
	    {
	     cout<<"Yes";
	     gotoxy(32,28);
	     cout<<"Saving";
	     delay(500);
	     cout<<".";
	     delay(500);
	     cout<<".";
	     delay(500);
	     cout<<".";
	     delay(500);
	     cout<<".";
	     delay(500);
	     cout<<".";
	     delay(500);
	     cout<<".";
	     gotoxy(20,28);
	     cout<<"Finally This Player is Registered in the Database";
	     fstream file("Players.dat",ios::binary|ios::app);
	     file.write((char*)&player,sizeof(player));
	     file.close();
	     getch();
	    }
	 else
	    {
	     goto endofthefunction;
	    }
	}
     else
	if(choice=='N'||choice=='n')
	  {
	   continues=1;
	   edit:
	   gotoxy(18,27);
	   cout<<"Enter the Index Number (1,2,3,4,5) you wanna edit:";
	   choice=getche();
	   gotoxy(18,27);
	   cout<<"                                                  ";
	   switch(choice)
	      {
	       case '0':gotoxy(21,27);
			cout<<"End the Editor Mode (Y/N):";
			choice=getche();
			gotoxy(21,27);
			cout<<"                          ";
			if(choice=='y'||choice=='Y')
			   goto saving_starts_here;
			else
			   goto edit;
	       case '1':gotoxy(21,27);
			cout<<"Sure to Edit Name (Y/N): ";
			choice=getche();
			gotoxy(21,27);
			cout<<"                         ";
			if(choice=='y'||choice=='Y')
			   {
			    goto names;
			   }
			else
			   {
			    goto edit;
			   }
	       case '2':gotoxy(21,27);
			cout<<"Sure to Edit Country (Y/N):";
			choice=getche();
			gotoxy(21,27);
			cout<<"                           ";
			if(choice=='y'||choice=='Y')
			   {
			    goto countries;
			   }
			else
			   {
			    goto edit;
			   }
	       case '3':gotoxy(21,27);
			cout<<"Sure to Edit Gender (Y/N):";
			choice=getch();
			gotoxy(21,27);
			cout<<"                          ";
			if(choice=='y'||choice=='Y')
			   {
			    goto checkgender;
			   }
			else
			   {
			    goto edit;
			   }
	       case '4':gotoxy(21,27);
			cout<<"Sure to Edit Sport (Y/N):";
			choice=getche();
			gotoxy(21,27);
			cout<<"                         ";
			if(choice=='y'||choice=='Y')
			   {
			    goto checksport;
			   }
			else
			   {
			    goto edit;
			   }
	       case '5':gotoxy(21,27);
			cout<<"Sure to Edit Date (Y/N):";
			choice=getche();
			gotoxy(21,27);
			cout<<"                         ";
			if(choice=='y'||choice=='Y')
			   {
			    goto dob;
			   }
			else
			   {
			    goto edit;
			   }
	     };
	  }
    endofthefunction:
    }

void drawlock(int x,int y)
     {
      setcolor(DARKGRAY);
      rectangle(x-35,y,x+35,y+60);
      setfillstyle(CLOSE_DOT_FILL,DARKGRAY);
      floodfill(x-34,y+1,DARKGRAY);
      setcolor(DARKGRAY);
      rectangle(x-30,y-30,x-20,y);
      setfillstyle(SOLID_FILL,DARKGRAY);
      floodfill(x-29,y-29,DARKGRAY);
      rectangle(x+30,y-30,x+20,y);
      setfillstyle(SOLID_FILL,DARKGRAY);
      floodfill(x+29,y-29,DARKGRAY);
      arc(x,y,47,133,43);
      arc(x,y,55,125,36);
      }

void modify_datas()
     {
      cleardevice();
      int y,index=1,temp=1;
      char ch;
      border(4);
      setcolor(YELLOW);
      settextstyle(6,HORIZ_DIR,3);
      outtextxy(208,40,"Welcome to Database Modifier");
      settextstyle(8,HORIZ_DIR,1);
      setcolor(11);
      outtextxy(250,80,"Add/Remove Countries");
      outtextxy(250,110,"Olympic Sports");
      outtextxy(250,140,"Remove Players");
      outtextxy(250,170,"GO Back");
      do
      {
      y=getycordinate(80,30,index);
      setcolor(BLUE);//Sets colour of the pointer
      drawpointat(225,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==0)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=1;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(225,y+6);
       temp=index;
      }while(ch!=13);
      switch(index)
	{
	 case 1:add_remove_country();
		break;
	 case 2:olympicsport();
		break;
	 case 3:removeplayer();
		break;
	 case 4:;
	}
     }


void add_remove_country()
{
     again:
     cleardevice();
     char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu
     border(5);
     olympic_text();
     setcolor(LIGHTBLUE);
     settextstyle(10,HORIZ_DIR,1);

     outtextxy(80,10,"WELCOME TO COUNTRY MANAGER");
	setcolor(CYAN);
      setlinestyle(SOLID_LINE,1,1);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
   outtextxy(200,60,"Select From Menu");
      setcolor(5);
      settextstyle(3,HORIZ_DIR,2);
     delay(150);
     outtextxy(220,110,"To add a country");

    delay(150);
      outtextxy(220,140,"To remove a country");
       delay(150);
       delay(150);
      outtextxy(220,170,"Back");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      delay(150);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:add_country();
	       break;
	case 3:remove_country();
	       break;
	case 4:goto ends;
       }
   goto again;
   ends:
  }
void remove_country()
     {
      char ans='y',choice;
      /******************************************/
      int y=60,flag=0;
      char name[50];
      setlinestyle(SOLID_LINE, 1, 3);
      border(1);
      /******************************************/
      //getch();
      cleardevice();
      border(1);
      ifstream conf;
      setcolor(GREEN);
      settextstyle(3,HORIZ_DIR,5);
	  cleardevice();
	  border(DARKGRAY);
	  man_fig();
	  setcolor(LIGHTBLUE);
	  settextstyle(1,HORIZ_DIR,3);
	  outtextxy(180,195,"WANNA DELETE ANY COUNTRY NAMES");
	  outtextxy(340,225,"Y/N");
	  setcolor(YELLOW);
	  while(!kbhit())
	  {
	  ellipse(265,73,0,360,150,50);
	  setfillstyle(CLOSE_DOT_FILL,RED);
	  fillellipse(265,73,150,50);
	  blinkstr(160,40,"WELCOME TO",1,3);
	  blinkstr(160,65,"COUNTRY DELETER",1,3);
	  settextstyle(3,HORIZ_DIR,3);
	  delay(100);
	  }
	  ans=getch();
	  if(ans=='n'||ans=='N')
	     goto END;
	  else
	  if(ans!='y'||ans!='Y')
	     {
      /******Deletion starts here********/

      cleardevice();
      border(1);
      man_fig();
      settextstyle(10,HORIZ_DIR,2);
      setcolor(YELLOW);
      conf.open("country.dat");
      outtextxy(200,40,"Countries till now");
      conf.read((char*)&con,sizeof(con));
      settextstyle(7,HORIZ_DIR,1);

      while(conf)
	  {
	  settextstyle(7,HORIZ_DIR,1);
	  setcolor(5);
	  outtextxy(250,y+24,con.name);
	  outtextxy(240,y+26,"*");
	  cout<<endl;
	  conf.read((char*)&con,sizeof(con));
	  y+=20;
	  }
	  y=60;
	  conf.close();
       setcolor(GREEN);
      settextstyle(3,HORIZ_DIR,1);
      outtextxy(180,332,"1*ENTER THE NAME OF COUNTRY TO BE DELETED:");
      gotoxy(30,20);
      gets(name);
      setcolor(YELLOW);
      conf.open("country.dat");
      ofstream delc ;
      delc.open("countrytemp.dat");
      conf.read((char*)&con,sizeof(con));
      while(conf)
      { 	if(strcmpi(con.name,name)==0)
	  flag=1;

	else
	{
	delc.write((char*)&con,sizeof(con));
	}
	conf.read((char*)&con,sizeof(con));

     }
     if(flag==1)
	 outtextxy(240,420,"Country is deleted");
	 else
	 outtextxy(240,420,"No country deleted");
	 getch();
     conf.close();
      delc.close();
     remove("country.dat");
       rename("countrytemp.dat","country.dat");


      }
     END:
     cleardevice();
      border(12);
      setcolor(YELLOW);
      conf.open("country.dat",ios::in);
      settextstyle(10,HORIZ_DIR,2);
      setcolor(YELLOW);
      outtextxy(200,40,"Countries till now");
      conf.read((char*)&con,sizeof(con));
      settextstyle(7,HORIZ_DIR,1);
      y=60;
      while(conf)
      {
       settextstyle(7,HORIZ_DIR,1);
       setcolor(5);
       outtextxy(100,y+24,con.name);
       outtextxy(90,y+26,"*");
       cout<<endl;
       conf.read((char*)&con,sizeof(con));
       y+=20;
       }

      conf.close();
      getch();
      }



void add_country()
     {
      int continues=0;
      char ans='y',anss='y',choice;
      /******************************************/
      int y=60;
      countries con={" "," ",0};
      setlinestyle(SOLID_LINE, 1, 3);
      border(1);
      /******************************************/
      //getch();
      cleardevice();
      border(1);
      fstream conf;
      conf.open("country.dat",ios::binary|ios::app);
      setcolor(GREEN);
      settextstyle(3,HORIZ_DIR,5);
      while(ans=='y')
	 {
	  START:
	  cleardevice();
	  border(DARKGRAY);
	  man_fig();
	  setcolor(LIGHTBLUE);
	  settextstyle(1,HORIZ_DIR,3);
	  outtextxy(180,195,"WANNA ENTER ANY COUNTRY NAMES");
	  outtextxy(340,225,"Y/N");
	  setcolor(YELLOW);
	  while(!kbhit())
	  {
	  ellipse(265,73,0,360,150,50);
	  setfillstyle(CLOSE_DOT_FILL,RED);
	  fillellipse(265,73,150,50);
	  blinkstr(160,40,"WELCOME TO",1,3);
	  blinkstr(160,65,"COUNTRY MANAGER",1,3);
	  settextstyle(3,HORIZ_DIR,3);
	  delay(100);
	  }
	  enter1:
	  gotoxy(34,20);
	  ans=getch();
	  if(ans=='n'||ans=='N')
	     goto END;
	  else
	  if(ans=='Y'||ans=='y')
	     goto ENTERAGAIN;
	  else
	  goto enter1;
	}

      setcolor(BLACK);
      delay(50);
      setcolor(YELLOW);
      ENTERAGAIN:
      continues=0;
      cleardevice();
      border(1);
      man_fig();
      setcolor(GREEN);
      settextstyle(3,HORIZ_DIR,1);
      outtextxy(190,152,"1*ENTER THE NAME OF COUNTRY:");
      setcolor(GREEN);
      outtextxy(190,185,"2*CHOOSE NAME OF THE CONTINENT:");
      settextstyle(7,HORIZ_DIR,1);
      setcolor(5);
      outtextxy(190,210,"   Press 1 for Africa....");
      outtextxy(190,230,"   Press 2 for Antarctica....");
      outtextxy(190,250,"   Press 3 for Asia....");
      outtextxy(190,270,"   Press 4 for Australia....");
      outtextxy(190,290,"   Press 5 for Europe....");
      outtextxy(190,310,"   Press 6 for North America....");
      outtextxy(190,330,"   Press 7 for South America....");
      while(!kbhit())
	  {
	  ellipse(265,73,0,360,150,50);
	  setfillstyle(CLOSE_DOT_FILL,RED);
	  fillellipse(265,73,150,50);
	  blinkstr(160,40,"WELCOME TO",1,3);
	  blinkstr(160,65,"COUNTRY MANAGER",1,3);
	  settextstyle(3,HORIZ_DIR,3);
	  delay(100);
	  }
      NAME:
      gotoxy(61,11);
      cout<<"                 ";
      gotoxy(61,11);
      gets(con.name);
      if(con.name[0]=='\0')
	 {
	  setcolor(13);
	  outtextxy(140,370,"HEY YOU ENTERED NOTHING....");
	  getch();
	  setcolor(BLACK);
	  outtextxy(140,370,"HEY YOU ENTERED NOTHING");
	  goto NAME;
	 }
      if(continues==1)//Initially 0
	goto edit;
      /***************Continent**************/
      CONTINENT:
      setcolor(13);
      gotoxy(65,13);
      choice=getch();
      switch(choice)
	    {
	     case '1':strcpy(con.continent,"Africa");
		      break;
	     case '2':strcpy(con.continent,"Antarctica");
		      break;
	     case '3':strcpy(con.continent,"Asia");
		      break;
	     case '4':strcpy(con.continent,"Australia");
		      break;
	     case '5':strcpy(con.continent,"Europe");
		      break;
	     case '6':strcpy(con.continent,"North America");
		      break;
	     case '7':strcpy(con.continent,"South America");
		      break;
	   }
      cout<<con.continent;
      if(continues==1)//Initially 0
	goto edit;
      setcolor(13);
      outtextxy(140,390,"Are the Following Details Correct (Y/N):");
      ans=getch();
      setcolor(0);
      outtextxy(140,390,"Are the Following Details Correct (Y/N):");
      setcolor(13);
      gotoxy(22,26);
      cout<<"                                  ";
      saving_point:
      if(ans=='Y'||ans=='y')
	{
	 gotoxy(22,27);
	 setcolor(13);
	 outtextxy(140,410,"Do You Want to Save.....(Y/N):");
	 ans=getch();
	 setcolor(BLACK);
	 outtextxy(140,410,"Do You Want to Save.....(Y/N):");
	 if(ans=='Y'||ans=='y')
	    {
	     setcolor(13);
	     outtextxy(140,410,"A New Country has been Added");
	     conf.write((char*)&con,sizeof(con));
	     getch();
	    }
	 else
	    {
	     goto endofthefunction;
	    }
	}
     else
	if(ans=='N'||ans=='n')
	  {
	   continues=1;
	   edit:
	   gotoxy(18,27);
	   cout<<"Enter the Index Numbe(1,2) you wanna edit:";
	   ans=getch();
	   gotoxy(18,27);
	   cout<<"                                                ";
	   switch(ans)
	      {
	       case '0':gotoxy(21,27);
			cout<<"End the Editor Mode (Y/N):";
			ans=getch();
			gotoxy(21,27);
			cout<<"                          ";
			if(ans=='y'||ans=='Y')
			   goto saving_point;
			else
			   goto edit;
	       case '1':gotoxy(21,27);
			cout<<"Sure to Edit Country Name (Y/N): ";
			ans=getch();
			gotoxy(21,27);
			cout<<"                         ";
			if(ans=='y'||ans=='Y')
			   {
			    goto NAME;
			   }
			else
			   {
			    goto edit;
			   }
	       case '2':gotoxy(21,27);
			cout<<"Sure to Edit Country (Y/N):";
			ans=getche();
			gotoxy(21,27);
			cout<<"                           ";
			if(ans=='y'||ans=='Y')
			   {
			    goto CONTINENT;
			   }
			else
			   {
			    goto edit;
			   }
	  }
	   }
      endofthefunction:
      goto START;
      END:
      cleardevice();
      gotoxy(40,15);
      setcolor(5);
      settextstyle(3,HORIZ_DIR,4);
      outtextxy(120,102,"THANK YOU FOR YOUR SUPPORT");
      setcolor(2);
      settextstyle(3,HORIZ_DIR,1);
      border(9);
      outtextxy(40,282,"TO ENTER MORE COUNTRIES PRESS----<<<<<-Y/y->>>>>----");
      setcolor(RED);
      outtextxy(80,322,"OTHERWISE PRESS----<<<<<----N/n---->>>>>----");
      enter2:
      anss=getch();
      if(anss=='n'||anss=='N')
      {
      cleardevice();
      border(12);
      conf.close();
      setcolor(YELLOW);
      ifstream conf("country.dat",ios::in);
      settextstyle(10,HORIZ_DIR,2);
      setcolor(YELLOW);
      outtextxy(200,40,"Countries till now");
      conf.read((char*)&con,sizeof(con));
      settextstyle(7,HORIZ_DIR,1);
      while(conf)
      {
       settextstyle(7,HORIZ_DIR,1);
       setcolor(5);
       outtextxy(100,y+24,con.name);
       outtextxy(90,y+26,"*");
       cout<<endl;
       conf.read((char*)&con,sizeof(con));
       y+=20;
	   }
      conf.close();
      }
      else
      if(anss=='y'||anss=='Y')
	goto ENTERAGAIN;
      else
	goto enter2;
      getch();
      }
      void olympic_text()
     {
      setlinestyle(SOLID_LINE,1,3);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
      setcolor(2);
      outtextxy(95,110,"O");
      circle(100,125,50);
      setcolor(3);
      circle(100,125,55);
      setcolor(4);
      outtextxy(92,230,"L");
      circle(100,240,45);
      setcolor(5);
      circle(100,240,50);
      setcolor(6);
      outtextxy(140,330,"Y");
      circle(150,340,45);
      setcolor(7);
      circle(150,340,40);
      setcolor(8);
      outtextxy(260,350,"M");
      circle(270,360,40);
      setcolor(9);
      circle(270,360,35);
      setcolor(10);
      outtextxy(370,350,"P");
      circle(380,360,35);
      setcolor(11);
      circle(380,360,30);
      setcolor(12);
      outtextxy(465,305,"I");
      circle(470,320,30);
      setcolor(13);
      circle(470,320,25);
      setcolor(14);
      outtextxy(545,255,"C");
      circle(550,270,25);
      setcolor(2);
      circle(550,270,20);
   }


void olympicsport()
   {
    againmenu:
    cleardevice();
     char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu
     border(5);
     olympic_text();
     setcolor(YELLOW);
     settextstyle(10,HORIZ_DIR,1);

     outtextxy(100
     ,10,"WELCOME TO SPORTS ARENA");
	setcolor(3);
      setlinestyle(SOLID_LINE,1,1);
      settextstyle(4,HORIZ_DIR,3);
   outtextxy(200,60,"Select From Menu");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
     delay(150);
     outtextxy(220,110,"BADMINTON");

    delay(150);
       outtextxy(220,140,"SWIMMING");
       delay(150);
      outtextxy(220,170,"TENNIS");
      delay(150);
      outtextxy(220,200,"RIEFEL SHOOTING");
      delay(150);
      outtextxy(220,230,"QUIT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      delay(150);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=6;
		      break;
	      case 80:index=index+1;
		      if(index==7)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:sportbadminton_start();
	       break;
	case 3:sportswimming();
	       break;
	case 4:sport_tennis();
	       break;
	case 5:sport_shooting();
	       break;
	case 6:goto endofsports;
       }
   goto againmenu;
   endofsports:
   }
void sportbadminton_start()
     {
      cleardevice();
      setlinestyle(SOLID_LINE,1,NORM_WIDTH);
      drawcourt();
      /******************************************/
      sport_badminton();
      /******************************************/
      setcolor(GREEN);
      sportbadminton();
    }
void sportbadminton()
   {
     cleardevice();
     char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu
      drawbadminton(500,120,25,50);
      border(5);
      olympic_text();
      setcolor(YELLOW);
      settextstyle(10,HORIZ_DIR,1);
      outtextxy(80,10,"WELCOME TO BADMINTON ARENA");
      setcolor(3);
      //setlinestyle(SOLID_LINE,1,1);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,60,"Select From Menu");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
      outtextxy(220,110,"DOUBLE'S GAME");
      //delay(1000);
      outtextxy(220,140,"SINGLE'S GAME");
      //delay(1000);
      outtextxy(220,170,"Quit The Sport");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:doublebadminton();
	       break;
	case 3:singlebadminton();
	       break;
	case 4:;

       }
   }


void singlebadminton()
     {
      restart:
      cleardevice();
      char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 2 as it points to first menu
      drawbadminton(500,120,25,50);
      border(5);
      olympic_text();
      drawbadminton(500,120,25,50);
      setcolor(YELLOW);
      settextstyle(10,HORIZ_DIR,1);
      outtextxy(220,10,"BADMINTON ARENA");
      setcolor(3);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,60,"Select For Single's game");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
      outtextxy(220,110,"MALE GAME");
      //delay(1000);
      outtextxy(220,140,"FEMALE GAME");
      //delay(1000);
      outtextxy(220,170,"BACK TO SPORT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:badmintonsingle("male");
	       break;
	case 3:badmintonsingle("female");
	       break;
	case 4:goto endit;
       }
   goto restart;
   endit:
 }

 void badmintonsingle(char gender[])
{
  char check_con[40];

  players_register pp;
  int flag=0;

  char name1[20],name2[30],name11[20],name22[30];
  ifstream file;
  fstream temp2;
  cleardevice();
  drawbadminton(500,120,25,50);
  border(5);
     olympic_text();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,170,"ENTER 1st player name :");
  delay(1000);
  cleardevice();
  {
  int i=0;
  ifstream file("players.dat");
  ofstream temp1("temp1.dat");
  ofstream temp2("temp2.dat");
   file.read((char*) &player,sizeof(player));
  while(file)
  {
   temp2.write((char*) &player,sizeof(player));
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp2.close();
   ENTER:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,"badminton")==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
   outtextxy(150,15,"Type 0 in any field to exit this window");
   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name1);
   if(name1[0]=='0')
      goto end;
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name1,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
      cleardevice();
      goto ENTER;
      }

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name1,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");
  }
  flag=0;
  cleardevice();
  drawbadminton(500,120,25,50);
  border(5);
     olympic_text();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,170,"ENTER 1st player name :");
  gotoxy(50,12);
   setcolor(YELLOW);
  outtextxy(380,170,name1);
  setcolor(3);
  outtextxy(150,202,"ENTER 2nd player name :");
  delay(3000);
  cleardevice();
  {
  players_register pp;int i=0;
    ENTER1:
    file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,"badminton")==0)
   {
   settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);

   i+=15;
   }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
   outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name2);
   if(name2[0]=='0')
      goto end;

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name2,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
   getch();
      cleardevice();
      goto ENTER1;
      }
   file.close();

  }


   cleardevice();
  drawbadminton(500,120,25,50);
  border(5);
     olympic_text();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,170,"ENTER 1st player name :");
  outtextxy(150,202,"ENTER 2nd player name :");
  gotoxy(50,14);
  setcolor(YELLOW);
  outtextxy(380,170,name1);
  outtextxy(380,202,name2);
  getch();
  cleardevice();
  border(5);
     olympic_text();
  remove("players.dat");
  rename("temp2.dat","players.dat");
  outtextxy(180,97,"MATCH HAS STARTED....");
  while(!kbhit())
  outtextxy(180,147,"PRESS ANY KEY TO START");
  getch();
  cleardevice();
  border(5);
  setcolor(9);
  char choice;
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(145,97,"Following Players Took Part in the Match");
      setcolor(YELLOW);
      outtextxy(195,147,"1.");
      outtextxy(215,147,name1);
      outtextxy(195,197,"2.");
      outtextxy(215,197,name2);
      setcolor(9);
      outtextxy(135,237,"Enter Player INDEX Number Who Won:");
      choices:
      choice=getch();
      switch(choice)
	 {
	  case '1':updaterecord(name1,"badminton");
	   break;
	  case '2':updaterecord(name2,"badminton");
	   break;
	  default :goto choices;
	 }
  goto end2;
  end:
  remove("players.dat");
  rename("temp2.dat","players.dat");
  end2:
 }


 void doublebadminton()

 {
   again:
   cleardevice();
   setcolor(GREEN);
   drawbadminton(500,120,25,50);
   char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu

     border(5);
     olympic_text();

     setcolor(YELLOW);
     settextstyle(10,HORIZ_DIR,1);
     outtextxy(220,10,"BADMINTON ARENA");
	setcolor(3);
      //setlinestyle(SOLID_LINE,1,1);
      settextstyle(4,HORIZ_DIR,3);
   outtextxy(200,60,"Select For Double's game");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
     outtextxy(220,110,"MALE GAME");
      //setcolor(7);
      //delay(1000);
      outtextxy(220,140,"FEMALE GAME");
      outtextxy(220,170,"BACK TO SPORT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:doublematch("Badminton","Male");
	       break;
	case 3:doublematch("Badminton","Female");
	       break;
	case 4:goto endofthis;;

      }
   goto again;
   endofthis:
 }



void drawcourt()
     {
      setcolor(WHITE);
      int poly[25];
      /******Main Court Design Starts Here*******/
      poly[0]=129;
      poly[1]=140;
      poly[2]=219;
      poly[3]=230;
      poly[4]=511;
      poly[5]=230;
      poly[6]=421;
      poly[7]=140;
      poly[8]=129;
      poly[9]=140;
      drawpoly(5,poly);
      setfillstyle(SOLID_FILL,GREEN);
      fillpoly(5,poly);

      /******Badminton Net*******/
      poly[0]=275;
      poly[1]=140;
      poly[2]=365;
      poly[3]=230;
      poly[4]=365;
      poly[5]=195;
      poly[6]=275;
      poly[7]=105;
      poly[8]=275;
      poly[9]=140;
      drawpoly(5,poly);
      setfillstyle(HATCH_FILL,GREEN);
      fillpoly(5,poly);
      line(159,140,249,230);
      line(391,140,481,230);
     }

void help()
     {
      cleardevice();
      char choice;
      border(5);
      setbkcolor(WHITE);
      settextstyle(7,HORIZ_DIR,1);
      setcolor(RED);
      outtextxy(490,15,"Esc.<-(Back)");
      setcolor(BLUE);
      outtextxy(100,20,"Welcome to the ODMP help menu");
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      setcolor(LIGHTRED);
      outtextxy(80,80,"Our Application involves only use of simple keyboard"
      " features.");
      outtextxy(80,100,"Here You Learn How to use them all.....");
      setcolor(MAGENTA);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      outtextxy(80,140,"To Move up and down in any menus use the"
      " keyboard up");
      outtextxy(80,160,"and down buttons");
      setcolor(GREEN);
      outtextxy(80,200,"If you wanna select any option simply"
      " press the enter key");
      setcolor(DARKGRAY);
      outtextxy(80,260,"If you have registered yourself then you "
      "should choose the");
      outtextxy(80,280,"login mode");
      setcolor(LIGHTBLUE);
      outtextxy(80,320,"If you want to buy registration you can choose the"
      " signup");
      outtextxy(80,340,"feature");
      setcolor(LIGHTMAGENTA);
      outtextxy(80,380,"If you just want to know records and do not want"
      " above");
      outtextxy(80,400,"options,choose the guest mode from the main menu");
      getchoice:
      choice=getch();
      if(choice!=27)
	goto getchoice;
    }

/*
void warning()
     {
      cleardevice();
      setbkcolor(RED);
      struct date date_obj;
      getdate(&date_obj);
      int yy=date_obj.da_year;
      if(yy%4!=0)
	{
	 border(WHITE);
	 setcolor(YELLOW);
	 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	 outtextxy(100,300,"ODMP HAS DETECTED THAT THIS YEAR IS ");
	 outtextxy(100,350,"NOT MEANT FOR MANAGING ANY DATABASE.");
	 outtextxy(100,400,"ANY MISTAKES CAN CORRUPT THE DATABASE");
	 while(!kbhit())
	    {
	      //blinkstr(140,50,"WARNING!",10,6);
	      settextstyle(10,VERT_DIR,3);
	      outtextxy(30,100,"BE CAREFUL");
	    }
	 getch();
	}
      setbkcolor(BLACK);
     }
  */
void removeplayer()
{
  char ans='y';
      /******************************************/
      int y=60,x=0;
      char name[50];
      /******************************************/
      cleardevice();
      setlinestyle(SOLID_LINE, 1, 3);
      border(1);
      ifstream file;
      setcolor(GREEN);
      settextstyle(3,HORIZ_DIR,5);
	 man_fig();
	  setcolor(LIGHTBLUE);
	  settextstyle(1,HORIZ_DIR,3);
	  outtextxy(180,195,"WANNA DELETE ANY PALYER");
	  outtextxy(340,225,"Y/N");
	  setcolor(YELLOW);
	  while(!kbhit())
	  {
	  ellipse(265,73,0,360,150,50);
	  setfillstyle(CLOSE_DOT_FILL,RED);
	  fillellipse(265,73,150,50);
	  blinkstr(160,40,"WELCOME TO",1,3);
	  blinkstr(160,65,"PLAYER REMOVER",1,3);
	  settextstyle(3,HORIZ_DIR,3);
	  delay(100);
	  }
	  ans=getch();
	  if(ans=='n'||ans=='N')
	     goto END;
	  else
	  if(ans!='y'||ans!='Y')
	     {
      /******Deletion starts here********/

      cleardevice();

	  border(12);
      setcolor(YELLOW);
      file.open("players.dat",ios::in);
      settextstyle(10,HORIZ_DIR,2);
      setcolor(YELLOW);
      outtextxy(200,40,"Players till now");
      file.read((char*)&player,sizeof(player));
      settextstyle(7,HORIZ_DIR,1);
      y=60;
      while(file)
      {
       settextstyle(7,HORIZ_DIR,1);
       setcolor(5);
       outtextxy(x+100,y+24,player.p_name);
       outtextxy(x+90,y+26,"*");
       if(y>=300)
       {
       y=40;
       x=120;
       }
       file.read((char*)&player,sizeof(player));
       y+=20;
	   }
	   y=60;
      file.close();

	     int flag=0;
       setcolor(GREEN);
      settextstyle(3,HORIZ_DIR,1);
      outtextxy(140,352,"1*ENTER THE NAME OF PLAYER TO BE DELETED:");
      gotoxy(40,25);
      gets(name);
      setcolor(YELLOW);
      file.open("players.dat");
      ofstream delp ;
      delp.open("playertemp.dat");
      file.read((char*)&player,sizeof(player));
      while(file)
      { 	if(strcmpi(player.p_name,name)==0)
	   {
	     flag=1;
	     }
	else
	{
	delp.write((char*)&player,sizeof(player));
	}
	file.read((char*)&player,sizeof(player));

     }
     if(flag==1)
	 outtextxy(240,420,"Player is deleted");
	 else
	 outtextxy(240,420,"No player deleted");
	 getch();
     remove("players.dat");
       rename("playertemp.dat","players.dat");
      file.close();
      delp.close();

      }
     END:
     cleardevice();
      x=0;
      border(12);
      setcolor(YELLOW);
      file.open("players.dat",ios::in);
      settextstyle(10,HORIZ_DIR,2);
      setcolor(YELLOW);
      outtextxy(200,40,"Playerss till now");
      file.read((char*)&player,sizeof(player));
      settextstyle(7,HORIZ_DIR,1);
      y=60;
      while(file)
      {
       settextstyle(7,HORIZ_DIR,1);
       setcolor(5);
       outtextxy(x+100,y+24,player.p_name);
       outtextxy(x+90,y+26,"*");
       if(y>=300)
       {
       y=40;
       x=120;
       }
       file.read((char*)&player,sizeof(player));
       y+=20;
       }
       y=60;
      file.close();
      getch();
}
void visit()
     {
      again:
      cleardevice();
      int i=2;
      settextstyle(10,HORIZ_DIR,2);
      setcolor(i);
      ++i;
      outtextxy(75,70,"W");
      setcolor(i);
      ++i;
      outtextxy(80,110,"E");
      setcolor(i);
      ++i;
      outtextxy(80,150,"L");
      setcolor(i);
      ++i;
      outtextxy(80,190,"C");
      setcolor(i);
      ++i;
      outtextxy(80,230,"O");
      setcolor(i);
      ++i;
      outtextxy(80,270,"M");
      setcolor(i);
      ++i;
      outtextxy(80,310,"E");
      setcolor(YELLOW);
      delay(1000);
      outtextxy(150,150,"T");
      setcolor(MAGENTA);
      outtextxy(150,190,"O");
      i=5;
      delay(1000);
      setcolor(i);
      ++i;
      outtextxy(220,50,"D");
      setcolor(i);
      ++i;
      outtextxy(220,90,"A");
      setcolor(i);
      ++i;
      outtextxy(220,130,"T");
      setcolor(i);
      ++i;
      outtextxy(220,170,"A");
      setcolor(i);
      ++i;
      outtextxy(220,210,"B");
      setcolor(i);
      ++i;
      outtextxy(220,250,"A");
      setcolor(i);
      ++i;
      outtextxy(220,290,"S");
      setcolor(i);
      ++i;
      outtextxy(220,330,"E");
      /******************************************************/
      int y,index=1,temp=1;
      char ch;
      /******************************************************/
      setlinestyle(SOLID_LINE,1,3);
      border(DARKGRAY);
      setcolor(RED);
      rectangle(300,140,600,190);
      setcolor(GREEN);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      outtextxy(375,150,"Players Database");
      setcolor(YELLOW);
      rectangle(300,200,600,250);
      setcolor(CYAN);
      outtextxy(375,210,"Country Database");
      rectangle(300,260,600,310);
      setcolor(BROWN);
      outtextxy(375,270,"Back To Main Menu");
      do
      {
      y=getycordinate(150,58,index);
      drawpointat(350,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==0)
			index=3;
		      break;
	      case 80:index=index+1;
		      if(index==4)
			index=1;
	     }
	}
       y=getycordinate(150,58,temp);
       deletepointat(350,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
      setbkcolor(BLACK);
     /************INDEX READING**************/
     switch(index)
	 {
	  case 1:visitplayer();
		 break;
	  case 2:visitcountry();
		 break;
	  case 3:goto ends;
	}
     goto again;
     ends:
    }

void visitplayer()
     {
       char totals[50];
       cleardevice();
       ifstream file;
       border(6);
       int y=80;
       cleardevice();
       border(8);
       setcolor(GREEN);
       settextstyle(7,HORIZ_DIR,2);
       outtextxy(70,40,"Name");
       outtextxy(190,40,"Gender");
       outtextxy(290,40,"Country");
       outtextxy(420,40,"Sport");
       setcolor(YELLOW);
       outtextxy(550,40,"Total");
       file.open("players.dat",ios::in);
       file.read((char*)&player,sizeof(player));
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
       int total=0;
       char choice;
       while(file)
          {
            setcolor(9);
            outtextxy(80,y,player.p_name);
            setcolor(8);
            outtextxy(200,y,player.p_gender);
            setcolor(10);
            outtextxy(300,y,player.p_country);
            outtextxy(430,y,player.p_sport);
            convert(totals,player.total);
            outtextxy(550,y,totals);
            file.read((char*)&player,sizeof(player));
            y+=20;
            ++total;
            if(total==18)
              {
               getchoice:
               choice=getch();
               if(choice=='\0')
	 choice=getch();
               if(choice==27)
	  {
	   goto end;
	  }
               else
               if(choice==81)
	 {
	  y=80;
	  total=0;
	  cleardevice();
	  border(8);
	  settextstyle(7,HORIZ_DIR,2);
	  outtextxy(70,40,"Name");
	  outtextxy(190,40,"Gender");
	  outtextxy(290,40,"Country");
	  outtextxy(420,40,"Sport");
	  setcolor(YELLOW);
	  outtextxy(550,40,"Total");
	  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	 }
               else
	 {
	  goto getchoice;
	 }
              }
          }
       getch();
       end:
       file.close();
     }

void visitcountry()
     {
      cleardevice();
      int y=80;
      char totals[50];
      ifstream file;
      border(8);
      setcolor(GREEN);
      settextstyle(7,HORIZ_DIR,2);
      outtextxy(90,40,"Country");
      outtextxy(250,40,"Continent");
      setcolor(YELLOW);
      outtextxy(390,40,"Total Medals");
      file.open("country.dat",ios::in);
      file.read((char*)&country_obj,sizeof(country_obj));
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      while(file)
          {
            setcolor(9);
            outtextxy(100,y,country_obj.name);
            setcolor(8);
            outtextxy(250,y,country_obj.continent);
            convert(totals,country_obj.total);
            outtextxy(390,y,totals);
            file.read((char*)&country_obj,sizeof(country_obj));
            y+=20;
          }
      file.close();
      getch();
     }

void search()
     {
      again:
      char ch;
      int poly[15],index=1,temp=1,y;
      cleardevice();
      /************************************************************/
      setbkcolor(WHITE);
      border(MAGENTA);
      setlinestyle(SOLID_LINE,1,3);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
      setcolor(GREEN);
      circle(100,130,30);
      poly[0]=110;
      poly[1]=160;
      poly[2]=125;
      poly[3]=200;
      poly[4]=132;
      poly[5]=197;
      poly[6]=115;
      poly[7]=155;
      drawpoly(4,poly);
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
      setcolor(RED);
      outtextxy(78,120,"Search");
      outtextxy(80,135,"Tools");
      settextstyle(7,HORIZ_DIR,4);
      setcolor(LIGHTRED);
      outtextxy(85,30,"WELCOME TO SEARCH MENU");
      setcolor(BLUE);
      outtextxy(85,40,".................................................."
      "..............................................");
      outtextxy(85,5,".................................................."
      "..............................................");
      gotoxy(23,7);
      setcolor(DARKGRAY);
      rectangle(300,100,600,150);
      setcolor(BROWN);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      outtextxy(375,110,"Search By Players");
      rectangle(300,160,600,210);
      setcolor(CYAN);
      outtextxy(375,170,"Search By Country");
      rectangle(300,220,600,270);
      setcolor(GREEN);
      outtextxy(375,230,"Search By Sports");
      setcolor(BLUE);
      rectangle(300,280,600,330);
      setcolor(BROWN);
      outtextxy(375,290,"Back To Main Menu");
      do
      {
      y=getycordinate(110,58,index);
      drawpointat(350,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==0)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=1;
	     }
	}
       y=getycordinate(110,58,temp);
       deletepointat(350,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
      setbkcolor(BLACK);
     /************INDEX READING**************/
     switch(index)
	 {
	  case 1:searchbyplayer();
		 break;
	  case 2:searchbycountry();
		 break;
	  case 3:searchbysports();
		 break;
	  case 4:goto ends;

	 }
      goto again;
      ends:
    }



void searchbyplayer()
     {
      ifstream file;
      int length=0;
      char playername[50];
      cleardevice();
      border(RED);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      outtextxy(210,40,"Player Search Menu");
      searchtab();//Search Box
      gotoxy(23,7);
      gets(playername);
      file.open("players.dat",ios::in|ios::binary);
      file.read((char*)&player,sizeof(player));
      while(!file.eof())
	  {
	   if(strcmpi(player.p_name,playername)==0)
	     {
	      outtextxy(80,200,"Name");
	      outtextxy(160,200,"Gender");
	      outtextxy(260,200,"Sport");
	      outtextxy(360,200,"Country");
	      outtextxy(460,200,"Birth Date");
	      length=strlen(player.p_name);
	      setcolor(BROWN);
	      outtextxy(80,240,player.p_name);
	      setcolor(LIGHTBLUE);
	      outtextxy(length+160,240,player.p_gender);
	      setcolor(BROWN);
	      outtextxy(length+220,240,player.p_sport);
	      setcolor(LIGHTBLUE);
	      outtextxy(length+340,240,player.p_country);
	      setcolor(BROWN);
	      outtextxy(length+420,240,player.p_birth_date);
	      goto endsearch;
	     }
	   file.read((char*)&player,sizeof(player));
      }
      setcolor(RED);
      outtextxy(250,285,".........................");
      outtextxy(250,300,"NAME NOT FOUND");
      outtextxy(250,305,".........................");
      endsearch:
      getch();
     }

void searchbysports()
      {
       ifstream file;
       int y=80;
       char sport[50];
       cleardevice();
       border(RED);
       outtextxy(210,40,"Sports Search Menu");
       searchtab();//Search Box
       gotoxy(23,7);
       gets(sport);
       cleardevice();
       setbkcolor(BLACK);
       border(RED);
       setcolor(GREEN);
       settextstyle(7,HORIZ_DIR,2);
       outtextxy(150,40,"Name");
       outtextxy(320,40,"Country");
       outtextxy(490,40,"Sport");
       char found='N';
       file.open("players.dat",ios::in);
       file.read((char*)&player,sizeof(player));
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
       int total=0;
       char choice;
       while(file)
          {
          if(strcmpi(player.p_sport,sport)==0)
           {
            setcolor(9);
            outtextxy(150,y,player.p_name);
            setcolor(8);
            outtextxy(320,y,player.p_country);
            outtextxy(490,y,player.p_sport);
            y+=20;
            ++total;
            found='y';
            }
          file.read((char*)&player,sizeof(player));
          }
      if(found=='N')
      {
      setcolor(RED);
      outtextxy(250,285,".........................");
      outtextxy(250,300,"NO SUCH SPORT");
      outtextxy(250,305,".........................");
      }
       getch();
       end:
       file.close();
     }

void searchtab()
     {
      setbkcolor(WHITE);
      setlinestyle(SOLID_LINE,1,3);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
      setcolor(BLUE);
      rectangle(155,85,545,125);
      rectangle(160,90,450,120);
      rectangle(460,90,540,120);
      setcolor(BLUE);
      outtextxy(470,90,"Search");
      gotoxy(23,7);
      setlinestyle(SOLID_LINE,1,1);
    }

void sportswimming()
     {
      cleardevice();
      logo();
      border(13);
      int y=51,color=LIGHTBLUE;
      setcolor(LIGHTBLUE);
      settextstyle(10,HORIZ_DIR,3);
      outtextxy(100,300,"WELCOME TO SWIMMING");
      settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
      while(!kbhit())
      {
      for(int i=0;i<24;++i)
      {
      setcolor(color);
      rectangle(120,50,519,170);
      outtextxy(120,y,"--------------------------------------------------");
      outtextxy(100,300,"----------------------------"
      "-----------------------------");
      outtextxy(100,350,"----------------------------"
      "-----------------------------");
      y+=5;
      }
      y=51;
      i=0;
      if(color==LIGHTBLUE)
	color=LIGHTCYAN;
      else
	color=LIGHTBLUE;
      }
     getch();
     swimmingsport();
     }

void sport_shooting()
     {
      cleardevice();
      border(RED);
      setlinestyle(SOLID_LINE,1,THICK_WIDTH);
      arc(500,240,90,270,40);
      setcolor(YELLOW);
      arc(490,240,90,270,45);
      setcolor(BLUE);
      arc(510,240,90,270,35);
      setcolor(RED);
      arc(520,240,90,270,30);
      while(!kbhit())
	 {
	  blinkstr(130,50,"SHOOTING",7,8);
	  blinkstr(130,70,"...................................",7,8);
	  //delay();
	  drawgun(140,240,170,60);
	 }
     getch();
     sportriefel();
     }

void drawgun(int x,int y,int size,int height)
     {
      /*****Declaration of distance*********/
      static int distance=8;
      setfillstyle(SOLID_FILL,BLACK);
      pieslice(x,y,0,270,12);
      rectangle(x,y,x+size,y+20);
      rectangle(x+2,y+2,x+size-2,y+20-2);
      line(x+10,y+20,x-5,y+height);
      line(x-5,y+height,x+15,y+height);
      line(x+15,y+height,x+30,y+20);
      line(x+60,y+20,x+25,y+35);
      line(x+10+1,y+20+1,x-5-1,y+height-1);
      line(x-5+1,y+height+1,x+15-1,y+height-1);
      line(x+15+1,y+height+1,x+30-1,y+20-1);
      line(x+60+1,y+20+1,x+25-1,y+35-1);
      setcolor(GREEN);
      circle(x+size+distance+5,y+8,8);
      delay(15);
      setcolor(BLACK);
      circle(x+size+distance+5,y+8,8);
      ++distance;
      if(distance==100)
	distance=1;
     }

void doublematch(char sport[],char gender[])
     {
      char choice;
      char found='n';
      fstream playerfile;
      fstream countryfile;
      int counts=0;
      char c_name1[50],c_name2[50],name1[20],name2[30],name11[20],name22[30];
      cleardevice();
      border(5);
      setlinestyle(SOLID_LINE,1,3);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
      settextstyle(3,HORIZ_DIR,1);
      setcolor(5);
      /**************************************/
      logo();
      int y=50;
      countryfile.open("country.dat",ios::in|ios::binary);
      if(!countryfile)
        {
         outtextxy(150,400,"SORRY INSUFFICIENT COUNTRIES IN DATABASE");
         getch();
         goto end;
        }
      countryfile.read((char*)&country_obj,sizeof(country_obj));
      setcolor(YELLOW);
      while(!countryfile.eof())
	   {
	    ++counts;
	    outtextxy(500,y,country_obj.name);
	    y+=20;
	    countryfile.read((char*)&country_obj,sizeof(country_obj));
	   }
      countryfile.close();
      if(counts<2)
        {
         outtextxy(150,400,"SORRY INSUFFICIENT COUNTRIES IN DATABASE");
         getch();
         goto end;
        }
      setcolor(GREEN);
      outtextxy(50,297,"TEAM 1:");
      gotoxy(17,20);
      gets(c_name1);
      gotoxy(17,20);
      cout<<"            "  ;
      setcolor(YELLOW);
      outtextxy(270,297,c_name1);
      /***************Checking*****************/
      countryfile.open("country.dat",ios::in|ios::binary);
      countryfile.read((char*)&country_obj,sizeof(country_obj));
      while(!countryfile.eof())
	   {
	    if(strcmpi(country_obj.name,c_name1)==0)
	      {
	       found='y';
	      }
	    countryfile.read((char*)&country_obj,sizeof(country_obj));
	   }
      countryfile.close();
      if(found=='n')
	 {
	  outtextxy(10,20,"NO SUCH COUNTRY EXISTS");
	  getch();
	  setcolor(BLACK);
	  outtextxy(10,20,"NO SUCH COUNTRY EXISTS");
	  goto end;
	 }
      /***********Checking Ends***************/
      /***************************************/
      cleardevice();
      //logo();
      border(5);
      settextstyle(3,HORIZ_DIR,1);
      setcolor(3);
      outtextxy(150,300,"ENTER 1st player name :");
      /************Displaying available names************/
      y=50;
      playerfile.open("players.dat",ios::in|ios::binary);
      if(!playerfile)
        {
         outtextxy(150,400,"SORRY INSUFFICIENT PLAYERS IN DATABASE");
         getch();
         goto end;
        }
      playerfile.read((char*)&player,sizeof(player));
      counts=0;
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_gender,gender)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_country,c_name1)==0))
	      {
	       outtextxy(500,y,player.p_name);
	       y+=20;
	       ++counts;
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      if(counts<2)
        {
         outtextxy(150,400,"SORRY INSUFFICIENT PLAYERS IN DATABASE");
         getch();
         goto end;
        }
      again:
      gotoxy(50,20);
      cout<<"                    ";
      gotoxy(50,20);
      gets(name1);
      gotoxy(50,20);
      cout<<"            ";
      setcolor(YELLOW);
      outtextxy(380,300,name1);
      /***************Checking*****************/
      found='n';
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_name,name1)==0)&&
	      (strcmpi(player.p_country,c_name1)==0)&&
	      (strcmpi(player.p_sport,sport)==0))
	      {
	       found='y';
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      if(found=='n')
	 {
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(BLACK);
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(YELLOW);
	  getch();
	  goto again;
	 }
      /***********Checking Ends***************/
      /***************************************/
      cleardevice();
      //logo();
      border(5);
      settextstyle(3,HORIZ_DIR,1);
      setcolor(3);
      outtextxy(150,300,"ENTER IInd player name :");
      /************Displaying available names************/
      y=50;
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_gender,gender)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_name,name1)!=0)&&
	      (strcmpi(player.p_country,c_name1)==0))
	      {
	       outtextxy(500,y,player.p_name);
	       y+=20;
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      gotoxy(50,20);
      gets(name2);
      gotoxy(50,20);
      cout<<"            ";
      setcolor(YELLOW);
      outtextxy(380,300,name2);
      /***************Checking*****************/
      found='n';
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_name,name2)==0)&&
	      (strcmpi(player.p_country,c_name1)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_name,name1)!=0))
	      {
	       found='y';
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      if(found=='n')
	 {
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(BLACK);
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(YELLOW);
	  getch();
	  goto end;
	 }
      /**************************************/
      cleardevice();
      //logo();
      border(5);
      found='n';
      /***************TEAM B****************/
      y=50;
      countryfile.open("country.dat",ios::in|ios::binary);
      countryfile.read((char*)&country_obj,sizeof(country_obj));
      setcolor(YELLOW);
      while(!countryfile.eof())
	   {
	    if(strcmpi(country_obj.name,c_name1)!=0)
	       outtextxy(500,y,country_obj.name);
	    y+=20;
	    countryfile.read((char*)&country_obj,sizeof(country_obj));
	   }
      countryfile.close();
      setcolor(GREEN);
      outtextxy(50,297,"TEAM 2:");
      gotoxy(17,20);
      gets(c_name2);
      gotoxy(17,20);
      cout<<"            "  ;
      setcolor(YELLOW);
      outtextxy(270,297,c_name2);
      /***************Checking*****************/
      countryfile.open("country.dat",ios::in|ios::binary);
      countryfile.read((char*)&country_obj,sizeof(country_obj));
      while(!countryfile.eof())
	   {
	    if((strcmpi(country_obj.name,c_name2)==0)&&
	       (strcmpi(c_name2,c_name1)!=0))
	      {
	       found='y';
	       goto xx;
	      }
	    countryfile.read((char*)&country_obj,sizeof(country_obj));
	   }
      xx:
      countryfile.close();
      if(found=='n')
	 {
	  outtextxy(10,20,"NO SUCH COUNTRY EXISTS");
	  getch();
	  setcolor(BLACK);
	  outtextxy(10,20,"NO SUCH COUNTRY EXISTS");
	  goto end;
	 }
      /***********Checking Ends***************/
      /***************************************/
      cleardevice();
      border(GREEN);
      border(5);
      settextstyle(3,HORIZ_DIR,1);
      setcolor(3);
      outtextxy(150,300,"ENTER 1st player name :");
      /************Displaying available names************/
      y=50;
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_gender,gender)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_country,c_name2)==0)&&
	      (strcmpi(player.p_name,c_name1)!=0)&&
	      (strcmpi(player.p_name,c_name2)!=0))
	      {
	       outtextxy(500,y,player.p_name);
	       y+=20;
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      again2:
      gotoxy(50,20);
      cout<<"                    ";
      gotoxy(50,20);
      gets(name11);
      gotoxy(50,20);
      cout<<"            ";
      setcolor(YELLOW);
      outtextxy(380,300,name11);
      /***************Checking*****************/
      found='n';
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_name,name11)==0)&&
	      (strcmpi(player.p_country,c_name2)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_name,c_name1)!=0)&&
	      (strcmpi(player.p_name,c_name2)!=0))
	      {
	       found='y';
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      if(found=='n')
	 {
	  gotoxy(0,0);
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(BLACK);
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(YELLOW);
	  getch();
	  goto end;
	 }
      /***********Checking Ends***************/
      /***************************************/
      cleardevice();
      //logo();
      border(5);
      settextstyle(3,HORIZ_DIR,1);
      setcolor(3);
      outtextxy(150,300,"ENTER IInd player name :");
      /************Displaying available names************/
      y=50;
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_gender,gender)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_name,name11)!=0)&&
	      (strcmpi(player.p_country,c_name2)==0)&&
	      (strcmpi(name22,name1)!=0)&&
	      (strcmpi(name22,name2)!=0))
	      {
	       outtextxy(500,y,player.p_name);
	       y+=20;
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      gotoxy(50,20);
      gets(name22);
      gotoxy(50,20);
      cout<<"            ";
      setcolor(YELLOW);
      outtextxy(380,300,name22);
      /***************Checking*****************/
      found='n';
      playerfile.open("players.dat",ios::in|ios::binary);
      playerfile.read((char*)&player,sizeof(player));
      while(!playerfile.eof())
	   {
	    if((strcmpi(player.p_name,name22)==0)&&
	      (strcmpi(player.p_country,c_name2)==0)&&
	      (strcmpi(player.p_sport,sport)==0)&&
	      (strcmpi(player.p_name,name11)!=0)&&
	      (strcmpi(name22,name1)!=0)&&
	      (strcmpi(name22,name2)!=0))
	      {
	       found='y';
	      }
	    playerfile.read((char*)&player,sizeof(player));
	   }
      playerfile.close();
      if(found=='n')
	 {
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(BLACK);
	  outtextxy(10,20,"NO SUCH PLAYER EXISTS");
	  setcolor(YELLOW);
	  getch();
	  goto end;
	 }/***********Checking Ends***************/
      cleardevice();
      logo();
      outtextxy(180,40,"MATCH HAS STARTED....");
      getch();
      cleardevice();
      outtextxy(145,50,"Following Players Took Part in the Match");
      setcolor(YELLOW);
      outtextxy(120,90,"1..TEAM A");
      outtextxy(195,100,"I.");
      outtextxy(215,100,name1);
      outtextxy(195,130,"II.");
      outtextxy(215,130,name2);
      outtextxy(120,140,"2..TEAM B");
      outtextxy(195,150,"I.");
      outtextxy(215,150,name11);
      outtextxy(195,170,"II.");
      outtextxy(215,170,name22);
      outtextxy(135,230,"Enter TEAM INDEX Number Who Won:");
      choices:
      choice=getch();
      switch(choice)
         {
          case '1':updaterecord(name1,sport);
	   updaterecord(name2,sport);
	   break;
          case '2':updaterecord(name11,sport);
	   updaterecord(name22,sport);
	   break;
          default :goto choices;
         }
      end:
     }

void sportriefel()
     {
      again:
      cleardevice();
      char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 2 as it points to first menu
      border(5);
      olympic_text();
      setcolor(YELLOW);
      settextstyle(10,HORIZ_DIR,1);
      outtextxy(220,10,"RIEFEL SHOOTING ARENA");
      setcolor(3);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,60,"Select For Single's game");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);

      outtextxy(220,110,"MALE GAME");

      outtextxy(220,140,"FEMALE GAME");

      outtextxy(220,170,"BACK TO SPORT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:riefelswimmatch("male","riefel");
	       break;
	case 3:riefelswimmatch("female","riefel");
	       break;
	case 4:goto ends;
       }
    goto again;
    ends:
 }

void riefelswimmatch(char gender[],char sport[])
{

  char check_con[40];

  int flag=0,a=11;;
   char name1[20],name2[30],name3[20],name4[30],name5[20],name6[30];
  ifstream file("players.dat");
  cleardevice();
  border(5);
   settextstyle(3,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(370,370,"Press any key to fill");
  //getch();
  cleardevice();

 int i=0;
 // ifstream file("players.dat");
  ofstream temp1("temp1.dat");

  ofstream temp2("temp2.dat");
   file.read((char*) &player,sizeof(player));
  while(file)
  {
   temp2.write((char*) &player,sizeof(player));
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp2.close();
   ENTER:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,sport)==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name1);
   if(name1[0]=='0')
      goto end;

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name1,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
      cleardevice();
      goto ENTER;
   }

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name1,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");

  flag=0;
  cleardevice();
  border(5);
  settextstyle(3,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(80,90,"ENTER 2nd player name :");
  settextstyle(0,HORIZ_DIR,1);
  setcolor(YELLOW);
  outtextxy(320,70+a,name1);


  //////////////////////////222222222//////////////////////////////////

  settextstyle(3,HORIZ_DIR,1);
  outtextxy(370,370,"Press any key to fill");
  getch();
  cleardevice();

  //ifstream file("players.dat");
  //ofstream temp1("temp1.dat");

   ENTER2:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,sport)==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name2);
   if(name2[0]=='0')
      goto end;

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name2,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
      cleardevice();
      goto ENTER2;
     }

   temp1.open("temp1.dat");
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name2,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");



  flag=0;
  cleardevice();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(80,90,"ENTER 2nd player name :");
  outtextxy(80,110,"ENTER 3rd player name :");

    settextstyle(0,HORIZ_DIR,1);
  setcolor(YELLOW);
  outtextxy(320,70+a,name1);
  outtextxy(320,90+a,name2);

   ///////////////////////////////////////3////////////////////////

   settextstyle(3,HORIZ_DIR,1);
  outtextxy(370,370,"Press any key to fill");
  getch();
  cleardevice();


//  ifstream file("players.dat");
  //ofstream temp1("temp1.dat");

   ENTER3:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,sport)==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name3);
   if(name3[0]=='0')
      goto end;
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name3,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
      cleardevice();
      goto ENTER3;

	  }
   temp1.open("temp1.dat");
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name3,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");


   flag=0;
  cleardevice();
  border(5);
  settextstyle(3,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(80,90,"ENTER 2nd player name :");
  outtextxy(80,110,"ENTER 3rd player name :");
  outtextxy(80,130,"ENTER 4th player name :");

    settextstyle(0,HORIZ_DIR,1);
  setcolor(YELLOW);
  outtextxy(320,70+a,name1);
  outtextxy(320,90+a,name2);
  outtextxy(320,110+a,name3);



    //////////////////////////////////4///////////////////////////////
    settextstyle(3,HORIZ_DIR,1);
  outtextxy(370,370,"Press any key to fill");

  getch();
  cleardevice();


  //ifstream file("players.dat");
 // ofstream temp1("temp1.dat");

   ENTER4:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,sport)==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name4);
   if(name4[0]=='0')
      goto end;

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name4,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
       cleardevice();
      goto ENTER4;
     }

   temp1.open("temp1.dat");
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name4,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");


   flag=0;
   cleardevice();
  border(5);
  settextstyle(3,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(80,90,"ENTER 2nd player name :");
  outtextxy(80,110,"ENTER 3rd player name :");
  outtextxy(80,130,"ENTER 4th player name :");
  outtextxy(80,150,"ENTER 5th player name :");

    settextstyle(0,HORIZ_DIR,1);
  setcolor(YELLOW);
  outtextxy(320,70+a,name1);
  outtextxy(320,90+a,name2);
  outtextxy(320,110+a,name3);
  outtextxy(320,130+a,name4);


       //////////////////////////////5///////////////////////////
       settextstyle(3,HORIZ_DIR,1);
  outtextxy(370,370,"Press any key to fill");
  getch();
  cleardevice();


 // ifstream file("players.dat");
  //ofstream temp1("temp1.dat");

   ENTER5:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,sport)==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name5);
   if(name5[0]=='0')
      goto end;

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name5,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
       cleardevice();
      goto ENTER5;

	     }
   temp1.open("temp1.dat");
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name5,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");

   flag=0;
  cleardevice();
  border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(80,90,"ENTER 2nd player name :");
  outtextxy(80,110,"ENTER 3rd player name :");
  outtextxy(80,130,"ENTER 4th player name :");
  outtextxy(80,150,"ENTER 5th player name :");
  outtextxy(80,170,"ENTER 6th player name :");
  settextstyle(0,HORIZ_DIR,1);
  setcolor(YELLOW);
  outtextxy(320,70+a,name1);
  outtextxy(320,90+a,name2);
  outtextxy(320,110+a,name3);
  outtextxy(320,130+a,name4);
  outtextxy(320,150+a,name5);
  ///////////////////////////6/////////////////////////


  settextstyle(3,HORIZ_DIR,1);
  outtextxy(370,370,"Press any key to fill");
	getch();
  cleardevice();


    ENTER6:
    file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,sport)==0)
   {
    settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);

   i+=15;
   }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,15,"Type 0 in any field to exit this window");

   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name6);
   if(name6[0]=='0')
      goto end;

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name6,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
   getch();
       cleardevice();
      goto ENTER6;
       }
   file.close();

 flag=0;
  cleardevice();
  border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(15);
  outtextxy(80,70,"ENTER 1st player name :");
  outtextxy(80,90,"ENTER 2nd player name :");
  outtextxy(80,110,"ENTER 3rd player name :");
  outtextxy(80,130,"ENTER 4th player name :");
  outtextxy(80,150,"ENTER 5th player name :");
  outtextxy(80,170,"ENTER 6th player name :");
  settextstyle(0,HORIZ_DIR,1);
  setcolor(YELLOW);
  outtextxy(320,70+a,name1);
  outtextxy(320,90+a,name2);
  outtextxy(320,110+a,name3);
  outtextxy(320,130+a,name4);
  outtextxy(320,150+a,name5);
  outtextxy(320,170+a,name6);
  getch();
  cleardevice();
  border(5);
  char choice;
   remove("players.dat");
   rename("temp2.dat","players.dat");
  outtextxy(180,97,"MATCH HAS STARTED....");
  while(!kbhit())
  outtextxy(180,147,"PRESS ANY KEY TO START");
  getch();
     outtextxy(135,337,"Enter Player INDEX Number Who Won:");
      choices:
      choice=getch();
      switch(choice)
	 {
	  case '1':updaterecord(name1,sport);
	   break;
	  case '2':updaterecord(name2,sport);
	   break;
	  case '3':updaterecord(name3,sport);
	   break;
	  case '4':updaterecord(name4,sport);
	   break;
	  case '5':updaterecord(name5,sport);
	   break;
	  case '6':updaterecord(name6,sport);
	   break;
          default :goto choices;
	 }
  goto end2;
  end:
  remove("players.dat");
   rename("temp2.dat","players.dat");
  end2:
 }

void swimmingsport()
     {
      cleardevice();
      char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 2 as it points to first menu
      border(5);
      olympic_text();
      setcolor(YELLOW);
      settextstyle(10,HORIZ_DIR,1);
      outtextxy(220,10,"SWIMMING ARENA");
      setcolor(3);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,60,"Select For Single's game");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      outtextxy(220,110,"MALE GAME");

      outtextxy(220,140,"FEMALE GAME");

      outtextxy(220,170,"BACK TO SPORT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:riefelswimmatch("male","swimming");
	       break;
	case 3:riefelswimmatch("female","swimming");
	       break;
	case 4:;
       }

 }

void sport_tennis()
   {
     cleardevice();
     border(BROWN);
     setcolor(15);
     setlinestyle(SOLID_LINE,1,THICK_WIDTH);
     rectangle(100, 100, 400, 300);
     setfillstyle(1, 2);
     floodfill(200,200,15);
     rectangle(100, 150, 400, 250);
     rectangle(175, 150, 325, 250);
     setlinestyle(SOLID_LINE,1,NORM_WIDTH);
     setfillstyle(1,BROWN);
     circle(500,200,10);
     floodfill(500,200,15);
     bar(452,185,458,230);
     setfillstyle(8, 14);
     ellipse(455,160,0,360,25,25);
     floodfill(455,160,15);
     while(!kbhit())
	{
	 blinkstr(170,350,"THE TENNIS ARENA",10,3);
	 delay(100);
	}
     getch();
     cleardevice();
     char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu
      border(5);
      olympic_text();
      setcolor(YELLOW);
      settextstyle(10,HORIZ_DIR,1);
      outtextxy(80,10,"WELCOME TO TENNIS ARENA");
      setcolor(3);
      //setlinestyle(SOLID_LINE,1,1);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,60,"Select From Menu");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
      outtextxy(220,110,"DOUBLE'S GAME");
      //delay(1000);
      outtextxy(220,140,"SINGLE'S GAME");
      //delay(1000);
      outtextxy(220,170,"Quit The Sport");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:doubletennis();
	       break;
	case 3:singletennis();
	       break;
	case 4:;

       }
   }


 void doubletennis()

 {
   again:
   cleardevice();
   char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 1 as it points to first menu

     border(5);
     olympic_text();

     setcolor(YELLOW);
     settextstyle(10,HORIZ_DIR,1);
     outtextxy(220,10,"TENNIS ARENA");
	setcolor(3);
      //setlinestyle(SOLID_LINE,1,1);
      settextstyle(4,HORIZ_DIR,3);
   outtextxy(200,60,"Select For Double's game");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
     outtextxy(220,110,"MALE GAME");
      //setcolor(7);
      //delay(1000);
      outtextxy(220,140,"FEMALE GAME");
      outtextxy(220,170,"BACK TO SPORT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:doublematch("Tennis","Male");
	       break;
	case 3:doublematch("Tennis","Female");
	       break;
	case 4:goto endofthis;;

      }
   goto again;
   endofthis:
 }


void singletennis()
     {
      restart:
      cleardevice();
      char ch;//For accepting a character for desired choice
      int y;//y cordinate of the menu pointer
      int index=2,temp=2;//Both stores index of the current pointed menu
      //Index is initialized with 2 as it points to first menu
      drawbadminton(500,120,25,50);
      border(5);
      olympic_text();
      drawbadminton(500,120,25,50);
      setcolor(YELLOW);
      settextstyle(10,HORIZ_DIR,1);
      outtextxy(220,10,"TENNIS ARENA");
      setcolor(3);
      settextstyle(4,HORIZ_DIR,3);
      outtextxy(200,60,"Select For Single's game");
      setcolor(6);
      settextstyle(3,HORIZ_DIR,2);
      //delay(1000);
      outtextxy(220,110,"MALE GAME");
      //delay(1000);
      outtextxy(220,140,"FEMALE GAME");
      //delay(1000);
      outtextxy(220,170,"BACK TO SPORT");
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      setcolor(BLUE);
      do
      {
      y=getycordinate(80,30,index);
      drawpointat(185,y+6);
      ch=getch();
      if(ch=='\0')
	{
	 ch=getch();
	 switch(ch)
	     {
	      case 72:index=index-1;
		      if(index==1)
			index=4;
		      break;
	      case 80:index=index+1;
		      if(index==5)
			index=2;
	     }
	}
       y=getycordinate(80,30,temp);
       deletepointat(185,y+6);
       temp=index;
      }
     while(ch!=13);//Until Enter is pressed
    switch(index)
       {
	case 2:tennissingle("male");
	       break;
	case 3:tennissingle("female");
	       break;
	case 4:goto endit;
       }
   goto restart;
   endit:
 }

void tennissingle(char gender[])
{
  fstream temp2;
  players_register pp;
  int flag=0;
  char check_con[40];

  char name1[20],name2[30];
  ifstream file;
  cleardevice();
  drawbadminton(500,120,25,50);
  border(5);
     olympic_text();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,170,"ENTER 1st player name :");
  delay(1000);
  cleardevice();
  {
  int i=0;
  ifstream file("players.dat");
  ofstream temp1("temp1.dat");
  ofstream temp2("temp2.dat");
   file.read((char*) &player,sizeof(player));
  while(file)
  {
   temp2.write((char*) &player,sizeof(player));
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp2.close();
   ENTER:
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
    if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,"tennis")==0)
     {
     settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);
     i+=15;
     }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
   outtextxy(150,15,"Type 0 in any field to exit this window");
   setcolor(4);
   outtextxy(150,15,"Type 0 in any field to exit this window");
   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name1);
   if(name1[0]=='0')
     goto end;
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name1,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
      getch();
      cleardevice();
      goto ENTER;
      }

   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name1,player.p_name)!=0)
    {
    temp1.write((char*) &player,sizeof(player));
      }
   file.read((char*) &player,sizeof(player));
   }
   file.close();
   temp1.close();
   remove("players.dat");
   rename("temp1.dat","players.dat");
  }
  flag=0;
  cleardevice();
  drawbadminton(500,120,25,50);
  border(5);
     olympic_text();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,170,"ENTER 1st player name :");
  gotoxy(50,12);
   setcolor(YELLOW);
  outtextxy(380,170,name1);
  setcolor(3);
  outtextxy(150,202,"ENTER 2nd player name :");
  delay(3000);
  cleardevice();
  {
  players_register pp;int i=0;
    ENTER1:
    file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(player.p_gender,gender)==0&&strcmpi(player.p_sport,"tennis")==0)
   {
   settextstyle(5,HORIZ_DIR,3);
     setcolor(CYAN);
     outtextxy(70,30,"Players in database");
     settextstyle(0,HORIZ_DIR,1);
     setcolor(CYAN);
     outtextxy(90,75+i,player.p_name);

   i+=15;
   }
   file.read((char*) &player,sizeof(player));
  }
   i=0;
   file.close();
   border(5);
  settextstyle(1,HORIZ_DIR,1);
  setcolor(3);
   outtextxy(150,15,"Type 0 in any field to exit this window");
   outtextxy(350,280,"Enter name of player");
   gotoxy(50,20);
   gets(name2);
   if(name2[0]=='0')
      goto end;
   file.open("players.dat");
   file.read((char*) &player,sizeof(player));
   while(file)
  {
   if(strcmpi(name2,player.p_name)==0)
    flag=1;
   file.read((char*) &player,sizeof(player));
   }
   file.close();
      if(flag!=1)
      {
     gotoxy(50,22);
   cout<<"Enter a valid player";
   getch();
      cleardevice();
      goto ENTER1;
      }
   file.close();

  }


   cleardevice();
  drawbadminton(500,120,25,50);
  border(5);
     olympic_text();
  settextstyle(3,HORIZ_DIR,1);
  setcolor(3);
  outtextxy(150,170,"ENTER 1st player name :");
  outtextxy(150,202,"ENTER 2nd player name :");
  gotoxy(50,14);
  setcolor(YELLOW);
  outtextxy(380,170,name1);
  outtextxy(380,202,name2);
  getch();
  cleardevice();
  border(5);
     olympic_text();
  outtextxy(180,97,"MATCH HAS STARTED....");
  while(!kbhit())
  outtextxy(180,147,"PRESS ANY KEY TO END");
  getch();
  cleardevice();
  border(5);
  setcolor(9);
  char choice;
      settextstyle(1,HORIZ_DIR,1);
      outtextxy(145,97,"Following Players Took Part in the Match");
      setcolor(YELLOW);
      outtextxy(195,147,"1.");
      outtextxy(215,147,name1);
      outtextxy(195,197,"2.");
      outtextxy(215,197,name2);
      setcolor(9);
      outtextxy(135,237,"Enter Player INDEX Number Who Won:");
      choices:
      choice=getch();
      switch(choice)
	 {
	  case '1':updaterecord(name1,"tennis");
	   break;
	  case '2':updaterecord(name2,"tennis");
	   break;
	  default :goto choices;
	 }
  end:
 remove("players.dat");
   rename("temp2.dat","players.dat");
 }


void updaterecord(char name[],char sport[])
     {
       medal *p1,*p2;
       int small,temp;
       char ch,temp3[50];
       ifstream file;
       char check_con[50],change='n';
       fstream temp2;
       file.open("players.dat",ios::binary);
       temp2.open("newtemp.dat",ios::binary|ios::out);
       file.read((char*) &player,sizeof(player));
       while(file)
	{
        if((strcmpi(name,player.p_name)==0)&&(strcmpi(sport,player.p_sport)==0))
           {
            player.total+=1;
            strcpy(check_con,player.p_country);
            change='y';
           }
        temp2.write((char*)&player,sizeof(player));
        file.read((char*)&player,sizeof(player));
        }
       file.close();
       temp2.close();
       remove("players.dat");
       rename("newtemp.dat","players.dat");
       if(change=='y')
       {
       /*************************************/
       file.open("country.dat");
       temp2.open("newtemp.dat",ios::out);
       file.read((char*) &country_obj,sizeof(country_obj));
       while(file)
        {
         if(strcmpi(check_con,country_obj.name)==0)
            {
             country_obj.total+=1;
            }
	 temp2.write((char*)&country_obj,sizeof(country_obj));
         file.read((char*) &country_obj,sizeof(country_obj));
        }
         file.close();
         temp2.close();
         remove("country.dat");
         rename("newtemp.dat","country.dat");
       }

     }

void updatetopten()
    {
     ifstream file;
     setlinestyle(SOLID_LINE,1,NORM_WIDTH);
     int temp;
     char temp3[50];
     medal *f,*l,*x;
     medal *p2,*p1;
      /****************Editing of the top10 file*************/
      file.open("country.dat",ios::binary);
      file.read((char*)&country_obj,sizeof(country_obj));
         f=l=x=NULL;
         while(file)
             {
               if(f==NULL)
	      {
	       f=new medal;
	       f->total=country_obj.total;
	       strcpy(f->name,country_obj.name);
	       f->next=NULL;
	       l=f;
	      }
	   else
	      {
	       x=new medal;
	       strcpy(x->name,country_obj.name);
	       x->total=country_obj.total;
	       x->next=NULL;
	       l->next=x;
	       l=x;
	       }
	      file.read((char*)&country_obj,sizeof(country_obj));
	     }
	 file.close();
	 p1=f;
	 for(p1=f;p1!=NULL;p1=p1->next)
	 {
	  for(p2=p1->next;p2!=NULL;p2=p2->next)
	     {
	      if(p2->total<=p1->total)
		{
		 temp=p2->total;
		 p2->total=p1->total;
		 p1->total=temp;
		 strcpy(temp3,p2->name);
		 strcpy(p2->name,p1->name);
		 strcpy(p1->name,temp3);
		}
	     }
	 }
     ofstream filewrite;
     filewrite.open("top.dat",ios::trunc);
     while(f!=NULL)
	  {
	   if(f->total>0)
	   {
	   medals.total=f->total;
	   strcpy(medals.name,f->name);
	   medals.next=NULL;
	   filewrite.write((char*)&medals,sizeof(medals));
	   }
	   f=f->next;
	   }
     delete p1;
     delete p2;
     delete x;
     delete f,l;
     filewrite.close();
    }

void gengraph()
     {
      cleardevice();
      updatetopten();
      border(GREEN);
      ifstream file;
      int value[12];
      int i=0;
      file.open("top.dat",ios::in|ios::binary);
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
      if(!file)
	{
	 outtextxy(150,400,"THIS DATABASE IS UNDER CONSTRUCTION");
	 getch();
	 goto end;
	}
      file.read((char*)&medals,sizeof(medals));
      i=0;
      while(file)
	 {
	  value[i]=medals.total;
	  file.read((char*)&medals,sizeof(medals));
	  ++i;
	 }
      graph(value,i);
      getch();
      end:
      file.close();
    }

void graph(int num[],int n)
     {
      fstream file;
      char total[4];
      int width=40,count=1,height;
      setcolor(GREEN);
      settextstyle(SANS_SERIF_FONT,VERT_DIR,2);
      setcolor(YELLOW);
      outtextxy(30,150,"Country Names------->");
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
      outtextxy(300,430,"Total Medals--------->");
      setcolor(RED);
      line(80,400,80,50);
      line(80,400,580,400);
      file.open("top.dat",ios::in);
      file.read((char*)&medals,sizeof(medals));
      for(int i=0;i<n;++i)
	{
	setfillstyle(SLASH_FILL,i+1);
	setcolor(i+1);
	if(num[n-1]<5)
	   {
	    height=60;
	    rectangle(80+width,400-height-num[i],80+20+width,400);
	    floodfill(80+width+2,400-height-num[i]+1,i+1);
	    convert(total,num[i]);
	    outtextxy(80+width,400-height-num[i]-50,total);
	    settextstyle(SANS_SERIF_FONT,VERT_DIR,1);
	    outtextxy(80+width-40,300,medals.name);
	    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	   }
	else
	   {
	    rectangle(80+width,400-num[i]-30,80+20+width,400);
	    floodfill(80+width+2,400-num[i]-30+1,i+1);
	    convert(total,num[i]);
	    outtextxy(80+width,400-num[i]-70,total);
	    settextstyle(SANS_SERIF_FONT,VERT_DIR,1);
	    outtextxy(80+width-40,300,medals.name);
	    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	   }
	width+=60;
	++count;
	file.read((char*)&medals,sizeof(medals));
	}
     }

void searchbycountry()
     {
      ifstream file;
      char totals[50];
      char countryname[50];
      cleardevice();
      border(RED);
      searchtab();//Search Box
      gotoxy(23,7);
      gets(countryname);
      file.open("country.dat",ios::in|ios::binary);
      file.read((char*)&country_obj,sizeof(country_obj));
      while(!file.eof())
	  {
	   if(strcmpi(country_obj.name,countryname)==0)
	     {
	      outtextxy(120,210,"Name");
	      outtextxy(240,210,"Continent");
	      outtextxy(360,210,"Total Medals");
	      setcolor(BROWN);
	      outtextxy(120,240,country_obj.name);
	      setcolor(LIGHTBLUE);
	      outtextxy(240,240,country_obj.continent);
	      setcolor(BROWN);
	      convert(totals,country_obj.total);
	      outtextxy(360,240,totals);
	      goto endsearch;
	     }
	   file.read((char*)&country_obj,sizeof(country_obj));
              }
      setcolor(RED);
      outtextxy(250,285,".........................");
      outtextxy(250,300,"NAME NOT FOUND");
      outtextxy(250,305,".........................");
      endsearch:
      getch();
    }

void convert(char str[],int num)
     {
      int digit;
      int i=0;
      if(num==0)
         {
          str[i]='0';
          ++i;
         }
      while(num!=0)
         {
          digit=num%10;
          str[i]=(digit)+48;
          ++i;
          num=num/10;
         }
      str[i]='\0';
      strrev(str);
     }

void medallist()
     {
       char totals[50];
       cleardevice();
       ifstream file;
       border(6);
       int y=80;
       cleardevice();
       border(8);
       setcolor(GREEN);
       //drawmedal();
       settextstyle(7,HORIZ_DIR,2);
       outtextxy(100,40,"Name");
       outtextxy(200,40,"Country");
       setcolor(YELLOW);
       outtextxy(350,40,"Total");
       file.open("players.dat",ios::in);
       file.read((char*)&player,sizeof(player));
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
       int total=0;
       char choice;
       while(file)
          {
            setcolor(9);
            outtextxy(100,y,player.p_name);
            setcolor(8);
            outtextxy(200,y,player.p_country);
            convert(totals,player.total);
	    outtextxy(350,y,totals);
            file.read((char*)&player,sizeof(player));
            y+=20;
            ++total;
            if(total==18)
              {
               getchoice:
               choice=getch();
               if(choice=='\0')
	 choice=getch();
               if(choice==27)
	  {
	   goto end;
	  }
               else
               if(choice==81)
	 {
	  y=80;
	  total=0;
	  cleardevice();
	  border(8);
	  settextstyle(7,HORIZ_DIR,2);
	  outtextxy(100,40,"Name");
	  outtextxy(200,40,"Country");
	  setcolor(YELLOW);
	  outtextxy(350,40,"Total Medals");
	  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
	 }
	       else
	 {
	  goto getchoice;
	 }
	      }
	  }
       choice=getch();
       if(choice=='\0')
	 choice=getch();
       end:
       file.close();
     }

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>
struct player
{
char *Player_Name;
char *Key;
long int High_Score;
int Flage;
}Player;
long int high;
int a[100][3];
char name[10];
int queu(int *p,int j)
{
 int i=0;
 for(i=0;i<j*3;i++)
 {
 p[0+i]=p[3+i];
 }
 return 0;
 }
class s
{
public:
  int x,y;
  int box();
  int move(int z);
  int delet(int*,int);
  int food(int ,int );
  s()
  {
    x=5;
    y=5;
  }
};
int s::box()
{
 int p=0,i,j;
 for(i=5,j=5;i<=75&&j<=25; )
  {
    gotoxy(i,j);
    textcolor(CYAN);
    cprintf("#");
    if(i!=75&&j!=25&&p==0)
    {i++;}
    if(i==75&&j!=25&&p==0)
    {
    j++;
    if(j==25)
    {p=1;i=5;j=5;}
    }
    if(i==5&&j!=25&&p==1)
    {j++;}
    if(i!=75&&j==25&&p==1)
    {i++;
    if(i==75)
    break;}
  }
  return 0;
}

void logout()
{
	FILE*f=fopen("data.txt","r");
	FILE*g=fopen("data1.txt","w");
	int n;
	if(Player.Flage==0)
	{
		fscanf(f,"%d",&n);
		fprintf(g,"%d\n%d %d %s %s %ld\n",n+1,strlen(Player.Player_Name),strlen(Player.Key),Player.Player_Name,Player.Key,Player.High_Score);
		for(int i=0;i<n;i++)
		{
			int l,m;
			fscanf(f,"%d %d ",&l,&m);
			Player.Player_Name=(char*)malloc((sizeof(char)*l)+1);
			Player.Key=(char*)malloc((sizeof(char)*m)+1);
			fscanf(f,"%s %s %ld",Player.Player_Name,Player.Key,&high);
			fprintf(g,"%d %d %s %s %ld\n",l,m,Player.Player_Name,Player.Key,high);

		}
	}
	else
	{
		if(high>Player.High_Score)
			Player.High_Score=high;
		fscanf(f,"%d",&n);
		fprintf(g,"%d\n%d %d %s %s %ld\n",n,strlen(Player.Player_Name),strlen(Player.Key),Player.Player_Name,Player.Key,Player.High_Score);
		for(int i=0;i<n;i++)
		{
			int l,m;
			char *na,*k;
			fscanf(f,"%d %d ",&l,&m);
			na=(char*)malloc((sizeof(char)*l)+1);
			k=(char*)malloc((sizeof(char)*m)+1);
			fscanf(f,"%s %s %ld",na,k,&high);
			if(strcmp(na,Player.Player_Name)!=0)
			{
				fprintf(g,"%d %d %s %s %ld\n",l,m,na,k,high);
			}
		}
	}
	fclose(f);
	fclose(g);
	remove("data.txt");
	rename("data1.txt","data.txt");

}
int s::move(int z)
{
  switch(z)
  {
  case 72:
	y--;
	break;
  case 77:
	x++;
	break;
  case 75:
	x--;
	break;
  case 80:
	y++;
	break;
  }
 gotoxy(x,y);
 textcolor(GREEN);
 cprintf("*");
 if(((x==5||x==75)&&(y>=5&&y<=25))||((y==5||y==25)&&(x>=5||x<=75)))
 {
  textcolor(RED);
  gotoxy(35,15);
  cprintf("game over");
  logout();
  delay(1500);
  exit(1);
 }
 return 0;
}
int s::delet(int *p,int j)
{
  static int m=x-6,n=y,r=1,t=0;
  m+=r;
  n+=t;
  gotoxy(m,n);
  cout<<" ";
  if(p[0]-m==0&&p[1]-n==0)
  {
  switch(p[2])
  {
  case 72:
       t=-1;
       r=0;
       break;
  case 77:
       t=0;
       r=1;
       break;
  case 75:
       t=0;
       r=-1;
       break;
  case 80:
       t=1;
       r=0;
       break;
  }
  queu(p,j);
  j--;
  }
  gotoxy(x,y);
  return j;
}
int s::food(int r1,int r2)
{
 gotoxy(r1,r2);
 textcolor(140);
 cprintf("@");
 gotoxy(x,y);
 if(x-r1==0&&y-r2==0)
 {
 high+=5;                        //?
 return 1;
 }
 else
 return 0;
}
void login()
{
	int repet=2;
do{
	repet=2;
	gotoxy(20,13);
	textcolor(RED);
	cprintf("Enter Player Name : ");
	char*name;
	gets(name);
	FILE *f=fopen("data.txt","r");
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++)
	{        //intiliztion again then what happen of pointer
		int l,m;
		fscanf(f,"%d %d",&l,&m);
		char *Name=(char*)malloc((sizeof(char)*l)+1);
		char *Key =(char*)malloc((sizeof(char)*m)+1);
		long int High_Score;
		fscanf(f,"%s %s %ld",Name,Key,&High_Score);
		if(strcmp(Name,name)==0)
		{
			textcolor(RED);
			gotoxy(20,15);
			cprintf("This name is already taken ! ");
			gotoxy(20,16);
			cprintf("Enter 1 For Try again ");
			gotoxy(20,17);
			cprintf("Enter 2 For Enter key ");
			int ans;
			cin>>ans;
			if(ans==2)
			{
				clrscr();
				textcolor(6);
				gotoxy(20,13);
				cprintf("Enter key : ");
				char *key;
				gets(key);
				if(strcmp(key,Key)==0)
				{
					Player.Player_Name=(char*)malloc((sizeof(char)*l)+1);
					Player.Key=(char*)malloc((sizeof(char)*m)+1);
					Player.Player_Name=Name;
					Player.Key=Key;
					Player.High_Score=High_Score;
					repet=0;
					Player.Flage=1;
				}
				else
				{
					textcolor(RED);
					gotoxy(20,14);
					cprintf("Key is not matched ! Try again !!");
					delay(1000);
					clrscr();
					repet=1;
				}
			}
			else
			{
				clrscr();
				repet=1;
			}
		}
	}
	fclose(f);
	if(repet==2)
	{
		clrscr();
		Player.Player_Name=name;
		textcolor(RED);
		gotoxy(20,12);
		cprintf("Key use for play again same name! so reamber !");
		gotoxy(20,13);
		cprintf("Enter key : ");
		char*key;
		gets(key);
		Player.Key=key;
		Player.High_Score=0;
		repet=0;
		Player.Flage=0;
	}
}while(repet);
textcolor(6);
gotoxy(20,14);
  cprintf("We hope,You will enjoy this Game.");
  delay(1000);
}
int main()
{
  clrscr();
  textcolor(RED);
  gotoxy(36,13);
  cprintf("Snack game");
  delay(2000);
  clrscr();
  int an=1,y,x,g=77,i=0,j=-1,r1,r2;
  char a1[10];
  login();
  clrscr();
  textcolor(RED);
  gotoxy(2,2);
  cout<<"Player Name : ";
  cout<<Player.Player_Name;
  gotoxy(60,2);
  cout<<"Score : "<<high;
  gotoxy(60,4);
  cout<<"High Score :"<<Player.High_Score;
  time_t t;
  s o;
  o.box();
  for(i=0;i<5;i++)
  {
  gotoxy(36+i,15);
  textcolor(GREEN);
  cprintf("*");
  }
  o.x=40;
  o.y=15;
  srand((unsigned)time(&t));
  for(i=0;;i++)
  {
  if(an==1)
  do
  {
  r1=rand()%75;
  r2=rand()%25;
  }while(r1<=5||r2<=5);
  an=o.food(r1,r2);
  y=getch();
  x=getch();
  if(g!=x)
  { j++;
  a[j][0]=o.x;
  a[j][1]=o.y;
  a[j][2]=x;
  }
  g=x;
  while(!kbhit())
  {
   if(an==1)
   do
   {
     r1=rand()%75;
     r2=rand()%25;
   } while(r1<=5||r2<=5);
   an=o.food(r1,r2);
   gotoxy(60,2);
   cout<<"Score : "<<high;
   if(an==0)
   j=o.delet(&a[0][0],j);
   o.move(x);
   delay(100);
  }
  }
}

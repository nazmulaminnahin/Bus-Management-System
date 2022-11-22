#include <stdio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int main(){
login();
}
void login()

{
	int a=0,i=0;
    char uname[20],c;
    char pword[20];
    char user[20]="nahin";
    char pass[20]="nahin";
    do
{
	system("cls");
    printf("\n\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t BUS RESERVATION SYSTEM");
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  LOGIN FORM  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd  ");
    printf("\n\n   ENTER USERNAME: ");
	scanf("%s", &uname);
	printf(" \n   ENTER PASSWORD: ");
	while(i<10)
	{
	    c=getch();
	    pword[i]=c;
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
	printf("  \n\n   WELCOME USER !!!!");
	printf("\n\n\n   Press any key to continue...");
	getch();
	break;
	}
	else
	{
	    printf("\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd");
		printf("\n\n   LOGIN IS UNSUCESSFUL...PLEASE TRY AGAIN...");
		a++;

		getch();
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

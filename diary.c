#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//function prototype
int menu();
int	password(char *n,char*p);
int write();
int read();
int exit1();
//main function
int main() {
	int c;// c=condition
	char n[20],p[20];// n=name, p=password
	printf("\n\n	**   Welcome To The Personal Diary   **\n\n");
	printf("Lets Verify Your Identity\n\n\n");
	system("pause");
	printf("Username : ");
	scanf("%s",n);
	printf("Password : ");
	scanf("%s",p);
	c=password(n,p);
	if (c==1)//checking if password typed is correct using passowrd function
	{
		printf("\"Verification Successful\"\n");
		system("pause");
		menu();
	}
	else 
	{
		printf("\"Verification Error, Please Try Again\"\n");//if incorrect print this statement
		system("pause");
		system("cls");
		main();
	}
}

// Menu Function
int menu(){
	
	fflush(stdin);
	system("cls");
	int s; //s=switch
	printf("\n\n	**   Welcome To The Main Menu   **\n\n");
	printf("1: Write\n2: Read\n3: Exit\n\nSelect An Option : ");
	scanf("%d",&s);
		switch(s)
		{
			case   1:
			{
						write();
						break;
			}
		
			case   2:
			{
						read();
						break;
			}
			case   3:
			{
						exit1();
						break;
			}
			default :
			{
				printf("Error Selection, Please Try Again\n");
				system("pause");
				system("cls");
				menu();
				break;
			}
				
		}
	}
	
// Password Function
int	password(char*n1,char *p1)
{
	int a1,b1,c1;
	a1=strcmp(n1,"user");
	b1=strcmp(p1,"password");
	c1=((a1==0)&&(b1==0));//if username and password match then we can display the meny function

	return c1;
}

// Read Function
int read(){
	fflush(stdin);
		

	
	//Input
	FILE *input;
	char diary[12]; //diary is diary name 
	char text[500];
	char text2[500];
	printf("Diary's Date [dd-mm-yyyy]: ");
	gets(diary);
	input=fopen(diary,"r");
	fflush(stdin);
	
	//Loop For Reading different rows	
	while(fgets(text,500,input)!=NULL)
	{
		sscanf(text,"%[^\n]",text2);
		printf("%s",text);
	}
	fclose(input);
	system("pause");
	int i;
	printf("Continue Reading ?\n\n1 :Yes\n2: No\nChoice : ");
	scanf("%d",&i);
	switch (i)
	{
	
		case 1 :
		{
			read();
			break;
		}
	
		case 2 :
		{
			printf("Okay, Returning To The Main Menu\n");
			system("pause");
			menu();
			break;
		}
		
		default :
		{
			printf("Error Selection, Lets Go To The Main Menu\n");
			system("pause");
			menu();
			break;
		}
	}
		
}

// Write function
int write(){ 
	
//Time
	fflush(stdin);
	printf("Write Function Is Activated\n\n\n");

	time_t rawtime;
	struct tm*timeinfo;
	time(&rawtime);
	timeinfo=localtime (&rawtime);
	printf("\nLocal Date And Time: %s\n",asctime(timeinfo));
	fflush(stdin); //clear the buffered data
	
//Output
	FILE *output;
	char diary[12]; //diary is diary name 
	char *text[500];
	printf("Today\'s Date [dd-mm-yyyy]: ");
	gets(diary);
	output=fopen(diary,"a");	
	fflush(stdin);
	printf("\nToday\'s Content : ");
	scanf("%[^\n]",text);
	printf("\nWritten Content : %s\n",text);	
	fprintf(output,"%s\nContent : %s\n\n",asctime(timeinfo),text);
	fclose(output);
	system("pause");
	
	//Back to Main Menu
	printf("\nWritting Saved, Returning To The Main Menu\n\n");
	system("pause");
	menu();
	return 0;
}

// Exit Function
int exit1(){
	fflush(stdin);
	printf("Exit Function Is Activated\n\n\n");
	
	printf("The System Will Be Closing Now\n");
	system("exit");
}

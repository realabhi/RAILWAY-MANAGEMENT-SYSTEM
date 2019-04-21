
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>





void book()
{system("cls");
int pnr=rand();
int ch2;
	char name[30],from[80],to[80],date[30];
c:
	
	printf("\nWelcome to the booking centre.Please fill in the following details(USE UNDERSCORE AS SPACE)");
	
	printf("\n1.NAME::");
	scanf("%s",&name);
	printf("\n2.FROM::");
	scanf("%s",&from);
	printf("\n3.TO::");
	scanf("%s",&to);
	printf("\n4.DATE::");
	scanf("%s",&date);
	
	printf("Congratulations your ticket has been booked. PNR NO: %d",pnr);

	
    FILE *fptr;

    char filename[15];
    
    char ch;
    
 

   
    fptr = fopen("booked.txt", "a");

   	fprintf(fptr,"\n");
    fprintf(fptr, name);
    fprintf(fptr, "   ");
    fprintf(fptr,"%d ",pnr);
    fprintf(fptr,"\n");
    
  
    fclose(fptr);
    
    	printf("\n5.BACK");
	printf("\n6.Exit");
	
	scanf("%d",&ch2);

   if(ch2==5)
   user();
   else if(ch2==6)
   exit(0);
   else
   {
   printf("Please enter the correct key!");
   book();}

}
void checkReserv(){
	system("cls");
	printf("\n\t\tThese are all the Reservations stored in the database(Name of passenger,PNR number)\n\n");
	char ch,ch2;
	FILE *fptr;
	fptr=fopen("booked.txt","r");
    ch=fgetc(fptr);
    while(ch!=EOF)
    {
    	printf("%c",ch);
    	ch=fgetc(fptr);
	}
	fclose(fptr);
    
    	printf("\n5.BACK");
	printf("\n6.Exit");
	
	scanf("%d",&ch2);

   if(ch2==5)
   adminlogged();
   
   else if(ch2==6)
   exit(0);
   else
   {
   printf("Please enter the correct key!");
   checkReserv();}
	
	
}


void adminlogged()
{ system("cls"); 
 int ch;
 printf("\n\t\t\t\t\t\tSucessfully Logged in");
		printf("\n---------------------------------------------------------------------------------------------------------------------");
		printf("\n\nWhat do you want to do?");
		printf("\n1.Check Reservations");
		printf("\n2.Set train schedule");
		printf("\n3.BACK");
		printf("\n4.Exit");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: checkReserv();
		break;
		case 2: setSchedule();
		break;
		case 3:main();
		break;
		case 4:exit(0);
		break;	
		default:printf("Please enter the correct key!");
		adminlogged();
}
}





void admin()
{   char username[30];
int ch;
char pass[30];
system("cls");
	printf("\n\t\t\t\tWelcome administrator.Please login to contiue");
	printf("\nEnter your username");
	scanf("%s",&username);
	printf("\nEnter your password");
	scanf("%s",&pass);
	
	if(strcmp(username,"abhishek")==0&&strcmp(pass,"123")==0)
	
		
	adminlogged();
		
		
	
	
	
	else
	{
		printf("Wrong combination");
	}
	
}
void setSchedule()
{   char name[80],from[80],to[80];int ch2,i;
	FILE *fptr;
	fptr=fopen("train_schedule.txt","a");
    printf("Enter the train name(USE UNDERSCORE AS SPACE)");
    scanf("%s",&name);  
	printf("Enter the FROM station");
    scanf("%s",&from);  
	printf("Enter the TO station");
    scanf("%s",&to);   
   
        fprintf(fptr,"\n");
        
    	fprintf(fptr,name);
    	
    	fprintf(fptr," ");
    	
    	fprintf(fptr,from);
    	
    	fprintf(fptr," ");
    	
    	fprintf(fptr,to);
    	
    	fprintf(fptr," ");
		
    	fprintf(fptr,"\n");
    	
	
	fclose(fptr);
	printf("\n---------------------------------------------------------------------------------------------------------------------");
	printf("\nSchedule sucessfully submitted.");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
    	printf("\n5.BACK");
	printf("\n6.Exit");
	
	scanf("%d",&ch2);

   if(ch2==5)
   adminlogged();
   else if(ch2==6)
   exit(0);
   else
   {
   printf("Please enter the correct key!");
   setSchedule();}
}


void train()
{int ch2;   
system("cls");
int train_no;
char ch;
	printf("\n\tALL THE TRAINS WITH THEIR PROPER SCHEDULE ARE GIVEN BELOW(train name,FROM station->TO station)::\n\n");
	
	FILE *fptr;
	fptr=fopen("train_schedule.txt","r");
	ch=fgetc(fptr);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fptr);
		
	}
	fclose(fptr);
		printf("\n5.BACK");
	printf("\n6.Exit");
	
	scanf("%d",&ch2);
	 if(ch2==5)
   user();
   else if(ch2==6)
   exit(0);
   else
   {
   printf("Please enter the correct key!");
   train();}
}




int user()
{   system("cls");
	int ch;
   
	printf("\nWelcome user. What do you want to do");
	printf("\n1.BOOK A TICKET");
	printf("\n2.CHECK TRAIN SCHEDULE");
	printf("\n3.Back");
	printf("\n4.Exit");
	scanf("%d",&ch);
	
	switch(ch)
	{
		 case 1:book();
		 break;
		 case 2:train();
		 break;
		 case 3:main();
		 break;
		 case 4:exit(0);
		default: printf("Please Enter the correct key");
		user();
		 
	}
	return 0;
}



aboutus()
{   int ch2;
	printf("\n\nThis project has been developed by ABHISHEK MISHRA student of GURUKUL KANGRI UNIVERSITY, as a project for 'C PROJECT EXPO' under the guidance of MR. MAYANK AGARWAL SIR.");
	printf("\n\n\n5.BACK");
	printf("\n6.Exit");
	
	scanf("%d",&ch2);
	 if(ch2==5)
   adminlogged();
   else if(ch2==6)
   exit(0);
   else
   {
   printf("Please enter the correct key!");
   aboutus();}
}















int main()
{   system("cls");
	int ch;
	printf("\t\t\t\t\tWelcome to the Railway application.");
	printf("\n\n\nLogin to continue");
	printf("\n1.Admin");
	printf("\n2.User");
	printf("\n3.About Us");
	printf("\n4.Exit");
	
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:admin();
		break;
	    case 2:user();
	    break;
		case 3:aboutus();
		break;
		case 4:exit(0);
		break;
		default: printf("Please Enter the correct key");
		main();
		
	
		
	}
	
	
	return 0;
	
}

// this code is being developed by  RINKI
// MCA-1 MORNING
// ROLLNO 33
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define _GNU_SOURCE
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define QNO 30
#define totques 10
#define size 200
struct employee
{
	char name[20];
	int score;

}emp[200];
void firstscreen();
void show_record();
void reset_score();
void help();
void edit_score(float score, char plnm[20]);
void second_screen();
void sorting();
void asked(char option[size], const char option1[size], const char option2[size],
const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,int *);
int score1=0, score2=0, score3=0;
char playername[20];
int finalscore=0;	
int main()
{
	firstscreen();
	
	system("cls");
	second_screen();
	
}
void firstscreen()// first screen to be displayed
{
	system("COLOR 3f");// it is used to give the color the output screen
	printf("\n\n");
	printf("\n\t\t\t\t________________________________________");
	printf("\n\t\t\t\t________________________________________");
    printf("\n\t\t\t\t\t        WELCOME ");
    printf("\n\t\t\t\t\t          TO ");
    printf("\n\t\t\t\t\t       QUIZ GAME ");
    printf("\n\n");
    printf("\n\t\t\t\t\tSubmitted By : Rinki");
    printf("\n\t\t\t\t\tSubmitted To : Dr Syamala Devi");
    printf("\n\t\t\t\t________________________________________");
    printf("\n\t\t\t\t________________________________________\n");
    system("pause");
    system("cls");
    
}
void second_screen()// it is the main menu bar
{
	//char playername[20];
	printf("\n\t\t\t\t_________________________________________________");
	printf("\n\t\t\t\t_________________________________________________");
    printf("\n\t\t\t\t -> Press S to start the game");
    printf("\n\t\t\t\t -> Press V to view the highest score  ");
    printf("\n\t\t\t\t -> Press R to reset score");
    printf("\n\t\t\t\t -> Press H for help            ");
    printf("\n\t\t\t\t -> Press Z to display all game player list");
    printf("\n\t\t\t\t -> Press Q to quit             ");
    printf("\n\t\t\t\t_________________________________________________");
    printf("\n\t\t\t\t_________________________________________________\n\n");
	printf("\n\t\t\t\tEnter your choice::  ");
    char choice;
    choice=toupper(getch());
    printf("%c \n",choice);
    printf("\n\t\t");
    getch();
    
    if (choice=='V')
	{
		show_record();
	}
     else if (choice=='H')
	{
	help();getch();
	
	}
	else if (choice=='R')
	{reset_score();
	getch();
	}
	else if (choice=='Q')
	exit(1);
	else if (choice=='Z')
	display();
    else if(choice=='S')
    {
    	score1=0;
    	score2=0;
    	score3=0;
     system("cls");
     trial:
	printf("\n\t\t\t________________________________________");
     printf("\n\t\t\tRegister your name:"); // first function to be used to start the game
     gets(playername);
     printf("\t\t\t________________________________________");
     if(strlen(playername)==0)
     {
     	system("cls");
     	printf("\n\n\n\n\t\t\t Please enter your name to play game");// IT IS USED FOR ERROR CONTROL
     	goto trial;
	 }
	 printf("\n");
     system("pause");
     system("cls");
    printf("\n\n\n\n\t\t\t***************************************\n");
	printf("\t\t\t\t WELCOME %s to Quiz game      \n",playername);
	printf("\t\t\t***************************************\n");
	getch();
	system("cls");
     RANDOM3();
 	}
 	else
 	{	
 		printf("\t   Please enter the correct choice to start the game");
 		getch();
	 	system("cls");
 		second_screen();
	 }
}
void show_record()
    {
    sorting();// here the sorting function is called
	system("cls");
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%d",&playername,&finalscore);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %d",playername,finalscore);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();
	system("cls");
	second_screen();
	}

void reset_score()
    {
	system("cls");
    float sc;
	char nm[20];
	FILE *f;
	f=fclose(fopen("marks.txt", "w"));// it used to remove the data from the file
    fclose(f);
    
    system("cls");
		printf("\n\n\n\n\t\t\t***************************************\n");
		printf("\t\t\t*    Ohh!! NO DATA TO SHOW            *\n");
		printf("\t\t\t***************************************\n");
	
    getch();
    system("cls");
	second_screen();
	}

void help()
	{
	system("cls");
    printf("\n\n\t                                   HELP");
    printf("\n\t --------------------------------------------------------------------------------------");
    printf("\n\t ......................... C program Quiz Game............................");
    printf("\n\t >> There are three rounds in the game, EASY LEVEL , MEDIUM  LEVEL AND DIFFICULT LEVEL");
    printf("\n\t >> In warmup round you will be asked a total of 10 questions to test your general");
    printf("\n\t    knowledge. You will be eligible to play the game if you can give atleast 7");
    printf("\n\t    right answers otherwise you can't play the Game...........");
    printf("\n\t >> Your game starts with the EASY LEVEL. In this lEVEL you will be asked");
    printf("\n\t    total 10 questions 7 right answer will be take you to next level .");
    printf("\n\t >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n\t    right option");
    printf("\n\t >> You will be asked questions continuously if you keep giving the right answers.");
    printf("\n\t >> No negative marking for wrong answers");
	printf("\n\t --------------------------------------------------------------------------------------");
	printf("\n\n\t*******************************BEST OF LUCK******************************************");
	printf("\n\n\t\t\t*****C PROGRAM QUIZ GAME is developed by RINKI ********");
	getch();
	system("cls");
	second_screen();
	
	}

void edit_score(float score, char plnm[20])
	{
	system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	  {
	   sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);
		}
		getch();
		second_screen();
	}
RANDOM3(){
	 char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	char empty[256][256];
	int i,j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];
    FILE * fp;
    FILE * output;
     int trialscore1=0;
    fp = fopen("Quiz2.txt","r");
    output = fopen("NewText2.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}
	
		printf("\n\n\n\n\t\t\t***************************************\n");
		printf("\t\t\t*\t    WELCOME TO LEVEL ONE      *\n");
		printf("\t\t\t***************************************\n");
		getch();
		system("cls");


	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}
		asked(option, option1, option2, option3, option4, correct, category,output,&score1);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	
	fputs(playername,output);
	fprintf( output," got total %d out of 40 ",score1);
	fclose(fp);
	
	fclose(output);
	
	output = fopen("Newtext2.txt","r");
	
	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}
	
	fclose(output);
	system("pause");
	system("cls");
	printf("\n\n\t\t\t***************************************\n");
	printf( "\t\t\t %s  got total %d out of 40 ",playername,score1);
	printf("\n\t\t\t***************************************\n");
		getch();
		system("cls");
	
	if(score1>28)
	{
		system("cls");
		printf("\n\n\t\t\t***************************************\n");
		printf("\t\t\t* CONGRATS!!! YOU REACHED TO LEVEL 2   *\n");
		printf("\t\t\t***************************************\n");
		system("pause");
		system("cls");
		RANDOM();
	}
	else
	{
		system("cls");
		printf("\n\n\t\t\t***************************************\n");
		printf("\t\t\t* STUDY HARD!!! BETTER LUCK NEXT TIME  *\n");
		printf("\t\t\t***************************************\n");
		ff();
		add_file();
		
		getch();
		system("cls");
		second_screen();
	}
}
void asked3(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,int *score1)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);
		
			char correctanswer[size];
			char wronganswer[size];
			
			fprintf(fp,"%s \n",category);
			
		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);
				
				*score1 += 4;
				
			fprintf(fp," \n You are awarded 4 marks for this correct answer \n ");
		}
		else
		{
		
			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);
			
			correctanswer[100] = '\0';
		
			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[100] = '\0';
			
			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
			fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
		}
		
			fprintf(fp," -----------------------------------------------------------------------------\n");		
			fprintf(fp," -----------------------------------------------------------------------------\n");		
	}
RANDOM(){
	 char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	char empty[256][256];
	int i,j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];

    FILE * fp;
    FILE * output;
    fp = fopen("Quiz.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}



	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		
		asked(option, option1, option2, option3, option4, correct, category,output,&score2);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	//fprintf(output,"nice to meeet u\n");
	fputs(playername,output);
	fprintf( output,"  got total %d out of 40 ",score2);
	fclose(fp);
	
	fclose(output);
	
	
	output = fopen("Newtext.txt","r");
	
	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}
	
	fclose(output);
	system("pause");
	system("cls");
	printf("\n\n\t\t\t***************************************\n");
	printf( "\t\t\t %s  got total %d out of 40 ",playername,score2);
	printf("\n\t\t\t***************************************\n");
	getch();
		system("cls");
	if(score2>28)
	{
		system("cls");
		printf("\n\n\t\t\t***************************************\n");
		printf("\t\t\t* CONGRATS!!! YOU REACHED TO LEVEL 3   *\n");
		printf("\t\t\t***************************************\n");
		system("pause");
		system("cls");
		Random1();
	}
	else
	{
		system("cls");
		printf("\n\n\t\t\t***************************************\n");
		printf("\t\t\t* STUDY HARD!!! BETTER LUCK NEXT TIME \t *\n");
		printf("\t\t\t***************************************\n");
		ff();
		add_file();
		getch();
		second_screen();
	}
	
}
void asked(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,int *score2)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);
		
			char correctanswer[size];
			char wronganswer[size];
			
			fprintf(fp,"%s \n",category);
			
		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);
				
				*score2 += 4;
				
			fprintf(fp," \n You are awarded 4 marks for this correct answer \n ");
		}
		else
		{
		
			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);
			
			correctanswer[24] = '\0';
		
			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[24] = '\0';
			
			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
			fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
		}
		
			fprintf(fp," -----------------------------------------------------------------------------\n");		
			fprintf(fp," -----------------------------------------------------------------------------\n");				
	}
	Random1(){
	 char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	char empty[256][256];
	int i,j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];

	
    FILE * fp;
    FILE * output;
    fp = fopen("Quiz1.txt","r");
    output = fopen("NewText1.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}



	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		
		asked(option, option1, option2, option3, option4, correct, category,output,&score3);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	
	fputs(playername,output);
	fprintf( output,"  got total %d out of 40 ",score3);
	fclose(fp);
	
	fclose(output);
	
	output = fopen("Newtext1.txt","r");
	
	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}
	
	fclose(output);
	
	system("pause");
	system("cls");
	printf("\n\n\t\t\t***************************************\n");
	printf( "\t\t\t %s  got total %d out of 40 ",playername,score3);
	printf("\n\t\t\t***************************************\n");
	getch();
	system("cls");
	printf("\n\n\t\t\t********************************************\n");
	printf("\t\t\t*    YOU HAVE A VERY GOOD IQ KEEP IT UP    *\n");	
	printf("\t\t\t*********************************************\n");
	ff();
	add_file();
	getch();
	system("cls");
	printf("\n\n\t\t\t********************************************\n");
	printf("\t\t\t %s you got %d for 120       \n",playername,finalscore);	
	printf("\t\t\t*********************************************\n");
	getch();
	system("cls");
	second_screen();
		
}
void asked1(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,int *score3)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);
		
			char correctanswer[size];
			char wronganswer[size];
			
			fprintf(fp,"%s \n",category);
			
		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);
				
				*score3 += 4;
				
			fprintf(fp," \n You are awarded 4 marks for this correct answer \n ");
		}
		else
		{
		
			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);
			
			correctanswer[24] = '\0';
		
			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[24] = '\0';
			
			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
			fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
		}
		
			fprintf(fp," -----------------------------------------------------------------------------\n");		
			fprintf(fp," -----------------------------------------------------------------------------\n");			
	}
	add_file()
	{
		FILE *fp;
 
    fp = fopen("marks.txt", "a+");
 
    if(fp == NULL) {
        printf("file can't be opened\n");
        exit(1);
    }
        fflush(stdin);
        fprintf(fp, " %s\t  %d  \n", playername, finalscore);
 
 
    fclose(fp);
 	
    return 0;
    
}
ff()
{
	finalscore=score1+score2+score3;
}
void sorting()
{
	struct employee temp;
	FILE *fp;
	int i=0,size1,j;
	char ch; 
 
	fp=fopen("marks.txt","r");
	if(fp==NULL)
	{ 
	printf("\n Cannot open the file \n");
	exit(0);
	}
	while(ch!=EOF)
	{
	fscanf(fp,"%s%d",&emp[i].name,&emp[i].score);  
	ch=fgetc(fp); 
	i++;  
	} 
	size1=i-1;
	for(i=1;i<size1;++i)
	for(j=0;j<size1-i;j++)
	if(emp[j+1].score>emp[j].score)
	{
	temp=emp[j];
	emp[j]=emp[j+1];
	emp[j+1]=temp;
	}
	fp=fopen("score.txt","w");
	for(i=0;i<size1;i++)
	fprintf(fp,"%s\t\t %d\n",emp[i].name,emp[i].score);
	fclose(fp);
	fclose(fp);

}
display()
{
	sorting();
	system("cls");
   char ch;
   FILE *fp;
   printf("Name           Score\n");
   printf("********************\n");
   
   fp=fopen("score.txt","r");
   
   while ((ch=getc(fp))!=EOF){
      if(ch == '\t')
         printf("\t");
      else
         printf("%c",ch);
   }
   fclose(fp);
   getch();
   system("cls");
   second_screen();
}
	



	

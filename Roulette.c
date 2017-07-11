/*
Emily Morford
Cis 170-03
March 23,2017
Roulette Game
*/
 
//function prototypes
void showInstructions();
float getBetAmount();
void makeBet(char*, int*, char*, char*);
int spinWheel();
float figureWinnings(float, float, char*, int*, int, char*, char*);  
char makeChoice();

#include <string.h> //do I need this for strcmp?
#include  <stdlib.h>  //  see below  in spinwheel function   //for abs value too?
#include  <time.h>   //  see below
#include <math.h>   //needed for fmod
#include <stdio.h>


int main ()
{
//to try absolute value function	
//float pig = (fabs(-2.1));
//printf("%f\n", pig);

	
float bet;
int spin;
char decision; //local variable :/
//char *type;  //adding the * makes it a string??
char type[4];
int number;
float currentbalance;   //local if set =0??
char iichoice;
char iiichoice;
srand (time(0));   //  see above #include


//do while loop to continue playing --uses local variable :/
do {
		showInstructions();
		bet=getBetAmount();
		makeBet(type, &number, &iichoice, &iiichoice);
		spin=spinWheel();
	//	printf  (" this is the spin: %d\n", spin);
	//	printf  (" this is what you bet: $%.02f\n", bet);
	//	printf ("This is your number: %d\n", number);
	//		printf ("This is your choice: %s\n", iichoice);
	//		printf ("This is your choice: %s\n", iiichoice);
	//	printf("We are in the main function before entering the figurewinnings function:This is the choice received i , ii or iii:   %s\n", type);
	//printf("\n**NOTE--We are in the figurewinnings function:This is the choice received i , ii or iii:   %s\n", type);
		currentbalance = figureWinnings ( bet, currentbalance, type,  &number,  spin, &iichoice, &iiichoice);  //currentbalance??

		printf("Enter C to continue or Q to quit \n" );
		scanf(" %c",&decision);
	}
		while ((decision=='C')||(decision=='c'));

return 0;
}

void showInstructions(){
printf (" You can place your bet in one of three ways:\n");
printf ("\ti.	bet on a number(payout is 36 times the bet amount)\n");
printf ("\tii.	bet on an odd or even (payout is 2 times the bet)\n");
printf ("\tiii.	bet on a dozen~first 1-12, second 13-24, third 25-36 (payout is 3 times the bet )\n");
}

float getBetAmount(){
float bet;
	printf ("How much would you like to bet?\n");	//what if user enters a $ sign
	scanf("%f", &bet );
	printf (" You would like to bet $%.2f\n", bet);	
return bet;	
}


void makeBet(char type[4], int* number, char* iichoice, char* iiichoice) {
	
//char iichoice="";
do		{
	printf ("What type of bet would you like to make? i? ii? or iii? \n");
	getchar();
	gets(type);
		//scanf("%c", &type );  //  \n???
		//scanf("%s", type );  //  \n???
		//getchar();
		}
while (!( (strcmp(type,"i")==0) || (strcmp(type,"ii")==0)||(strcmp(type,"iii")==0)));

printf ("You would like to bet on bet choice \"%s\".\n", type);


		if(strcmp(type,"i")==0){
		//	do{
				printf ("What number would you like to bet on? Choose from 0 to 36:\n");
				//getchar();
				scanf("%d", &*number );  //note you need &*
		//			}
		//		while (!(*number>=0)&&(*number<=36));   //should it be *number??
				printf ("You are betting on number %d.\n", *number);
		}
		
		else if (strcmp(type,"ii")==0)	{
			   do  {
					printf ("What group of numbers would you like bet on? Please enter even or odd.\n");
					//	getchar();
					gets(iichoice);
					printf ("You are betting on \"%s\" numbers.\n", iichoice);
					}
					while (!( (strcmp(iichoice,"even")==0) || (strcmp(iichoice,"odd")==0)));
		}
		
		else { // (strcmp(type,"iii")==0)
				do{
					printf ("What group of numbers would you like bet on? first or second or third?\n");
				//	getchar();
					gets(iiichoice);
					printf ("You are betting on the \"%s\" set of numbers.\n", iiichoice);
					}			
				while (!( (strcmp(iiichoice,"first")==0) || (strcmp(iiichoice,"second")==0) || (strcmp(iiichoice,"third")==0) ));
		}
	
}

int spinWheel()
{
	int spin;

	//srand(spin);
	spin= ((rand() % 37));  // x=(rand() %(max-min+1)) + min
 	printf("The number on the wheel is........%d\n", spin);  // x=(rand() %(max-min+1)) + min
 	return spin;		
}

float figureWinnings(float bet, float currentbalance, char type[4], int* number, int spin, char* iichoice, char* iiichoice )  //did have char* type
{
float earnings, negcurrentbalance;
int remainder;
 
 //if (!(spin==number)){

// printf("\n**NOTE--We are in the figurewinnings function:This is the choice received i , ii or iii:   %s\n", type);

if(strcmp(type,"i")==0){
	
//	printf("**\nnote----We have entered into the figurewinnings function type i\n");
	
 	if(!(*number==spin)){     //argh- I had strcmp here! don't use with integers
  			printf("This was not a winning spin :( \n");
 			currentbalance=currentbalance - bet;
 			 }
 	else{
 			earnings= bet*36;
 			printf ("You won $%.02f\n", earnings);
 			currentbalance=currentbalance+earnings-bet;
 		 }	 
 	}
 
else if(strcmp(type,"ii")==0){
	
	//	printf("**\nnote----We have entered into the figurewinnings function type ii\n");
	
	//printf(" This is the winning spin number: %d\n", spin);
	remainder=(fmod(spin,2));
//	printf ("This is the remainder: %d\n", remainder);
 	//printf ("This is your number: %d\n", *number);
 //	printf ("This is your choice: %s\n", iichoice);
	
	
 	if((strcmp(iichoice,"even")==0)&&(remainder==0)){     
  			earnings= bet*2;
 			printf ("You won $%.02f\n", earnings);
 			currentbalance=currentbalance+earnings-bet;
 			 }
 	else if ((strcmp(iichoice,"odd")==0)&&(remainder==1)){     
  			earnings= bet*2;
 			printf ("You won $%.02f\n", earnings);
 			currentbalance=currentbalance+earnings-bet;
 			 }
 	else {
	 	printf("This was not a winning spin :( \n");
 			currentbalance=currentbalance - bet;
	 	 }		
 	 }	 
  	
else{			//else unnecessary??    (strcmp(type,"iii")==0)		
//	printf("\n**note----We have entered into the figurewinnings function type iii\n");	
 		if((strcmp(iiichoice,"first")==0)&&((spin>=1)&&(spin<=12))){     
  			earnings= bet*3;
 			printf ("You won $%.02f\n", earnings);
 			currentbalance=currentbalance+earnings-bet;
 			 }
 		else if ((strcmp(iiichoice,"second")==0)&&((spin>=13)&&(spin<=24))){   
  			earnings= bet*3;
 			printf ("You won $%.02f\n", earnings);
 			currentbalance=currentbalance+earnings-bet;
 			 }
 		else if ((strcmp(iiichoice,"third")==0)&&((spin>=25)&&(spin<=36))){   
  			earnings= bet*3;
 			printf ("You won $%.02f\n", earnings);
 			currentbalance=currentbalance+earnings-bet;
 			 }
 		else {
	 		printf("This was not a winning spin :( \n");
 			currentbalance=currentbalance - bet;
	 		 }		
  	}
 		
 	//print current balance
		if (currentbalance==0){
		 	printf("Your winnings and losses cancel each other out.\n\n");}
 		else if (currentbalance <0){		
		 			negcurrentbalance=fabs(currentbalance);
		 	printf ("Your total losses are $%.2f\n\n",negcurrentbalance);}
 		else  {						//(currentbalance >0)  unnecessary??
	 		printf ("Your total winnings are $%.2f\n\n", currentbalance);}
	 		
 	return currentbalance;
}





/*Yusuf Can Kan - 161044007*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu();
int getInt(int mini, int maxi);
int numberGeneratorBetweenRange(int min, int max);
void horseRacingGame();
void countOccurrence();
void triangleOfSequences();

int main(){
	srand(time(NULL));
	menu();
	return 0;	
}
/*It displays the menu and checks the menu inputs.*/
void menu(){  
	
	int choice;
	printf("\n1.Horse Racing Game\n");
	printf("2.Occurence Counter\n");
	printf("3.Triangle of Sequence\n");
	printf("0.Exit\n");
	do{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				horseRacingGame();
				printf("\n\n1.Horse Racing Game\n");
				printf("2.Occurence Counter\n");
				printf("3.Triangle of Sequence\n");
				printf("0.Exit\n");
				break;
			case 2:
				countOccurrence();
				printf("\n\n1.Horse Racing Game\n");
				printf("2.Occurence Counter\n");
				printf("3.Triangle of Sequence\n");
				printf("0.Exit\n");
				break;
			case 3:
				triangleOfSequences();
				printf("\n1.Horse Racing Game\n");
				printf("2.Occurence Counter\n");
				printf("3.Triangle of Sequence\n");
				printf("0.Exit\n");
				break;
			case 0:
				break;
			default:  			/*When the wrong input entered,menu displays again.*/
				printf("\n\nInvalid input");
				printf("\n\n\n1.Horse Racing Game\n");
				printf("2.Occurence Counter\n");
				printf("3.Triangle of Sequence\n");
				printf("0.Exit\n");
				
		}	
	}while(choice!=0);
}
/*It gets an integer input between two values from user.*/
int getInt(int mini, int maxi){
	
	int number;
	scanf("%d",&number);
	/*If input not in charge then function gets again.*/
	while(number<mini || number>maxi){
		printf("\nNot in Range! Try Again:");
		scanf("%d",&number);
	}
	return number;					
}
/*It generates integer between min and max values.*/
int numberGeneratorBetweenRange(int min, int max){
	
	int number;
	
	number=(rand()%(max-min+1));
	number+=min;	
	
	return number;
}

void horseRacingGame(){
	int horse_number;
	int myhorse,i=0,j=0;
	int run,winner_run=20,winner_index=0,tie=0;
	int control,tie_index;
	/*Generates horse number between 2 and 5 with numberGeneratorBetweenRange function.*/
	horse_number=numberGeneratorBetweenRange(3,5);
		
	printf("Number of Horses:%d",horse_number);
	printf("\nHorse Number:");
	/*Takes horse number forum number between 1 and number of horse.*/
	myhorse=getInt(1,horse_number);
	printf("Racing starts...\n");
	
	for(i=1;i<=horse_number;i++){
	
		/*Generates how much run for i th horse.*/
		run=numberGeneratorBetweenRange(10,20);
		/*Calculates winner horse and saves it.When the horse become new winner horse it resets all tie values.*/
		if(run<winner_run){
			winner_run=run;
			winner_index=i;
			tie=0;
			control=0;
		}
		/*If the winner horses tie then it saves that.*/
		else if(run == winner_run){
			tie++;
			tie_index=i;
				if(tie_index==myhorse){	/*It is for 3 horses tie and one of that horses is my horse.*/
					control++;
				}
		}
		/*It prints horses runs.*/
		printf("Horse %d:",i);
		for(j=0;j<run;j++){
			printf("-");
		}
		printf("\n");
	}
	/*Calculates the situations.*/
	if(myhorse==winner_index && tie==0){
		printf("You Win! Winner is Horse %d",myhorse);
	}
	else if(myhorse!=winner_index && tie==0){
		printf("You lose! Winner is Horse %d",winner_index);
	}
	else if(tie!=0 && (myhorse==winner_index || myhorse== tie_index || control!=0)){	
		printf("You Win! Winner is Horse %d",myhorse);
	}
	else{
		printf("You Lose! Winner is Horse %d",winner_index);
	}
}

void countOccurrence(){

	int big_number,search_number,search_number_temp;
	int occurance=0,i;
	int ten=0;
	int ten1=1;
	
	printf("\nBig Number=");
	scanf("%d",&big_number);	
	printf("Search Number=");
	scanf("%d",&search_number);
	
	search_number_temp=search_number;
	/*It calculates how many digit has search number.*/
	while(search_number_temp>0){
		search_number_temp/=10;
		ten++;
	}
	/*It generates a number which is tenth times. It continues from 1 digit to search number digits.*/
	for(i=1;i<=ten;i++){
		ten1*=10;
	}
	/*
	 *It searchs occurence.
	 *It looks every digit until big number become smaller then 1.
	*/
	while(big_number>0){
		/*ten1 (We generate that above. Tenth times number helps us looks numbers digits.)*/
		if(big_number % ten1 == search_number){
			occurance++;
		}
		/*It decreases big number 1 digit every times.*/
		big_number = big_number / 10;
	}
	printf("Occurance=%d",occurance);
	
}

void triangleOfSequences(){
	int random=0;
	int i=0,j=0;
	/*It generates random number between 2 - 10.*/
	random=numberGeneratorBetweenRange(2,10);
	printf("\n");
	/*It prints the shape.*/
	for(i=1;i<=random;i++){
		
		for(j=1;j<=i;j++){
			
			printf("%d ",i*j);
			
		}
		printf("\n");
	}
}


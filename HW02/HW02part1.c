/*Yusuf Can Kan - 161044007*/
#include<stdio.h>
#include<stdlib.h>

void menu(int most_succesful,int most_unsuccesful,int most_succesful_index,int most_unsuccesful_index,
		 int A,int B,int C,int D,int F,double average,int student_count);
void most_succesfull(int most_succesful,int most_succesful_index);
void most_unsuccesfull(int most_unsuccesful,int most_unsuccesful_index);
char letter_grade(int grade);
void letter_grade_statistic(int A,int B,int C,int D,int F);
void average(int average);
void print_menu(int student_count);

int main(){
		
	int grade=0;
	int student_count,i;
	int most_succesful=0,most_unsuccesful=101;
	int most_succesful_index=0,most_unsuccesful_index=0;
	int A=0,B=0,C=0,D=0,F=0;
	int sum=0,condition=0;
	double average=0;
	srand(40);
	
	/*It iterates until user enters a valid input*/
	while(condition==0){							
	
		printf("\nEnter student count=");
		scanf("%d",&student_count);
		printf("\n");
		if(student_count>=3 && student_count <=50){
			condition++;
			 /*
			 *It generates random values for grades.
			 *Finds succesful and unsuccesful students grades and all letter grades counts.
			 */
			for(i=0;i<student_count;i++){ 
				/*Generates and prints grades.*/
				grade=rand()%101;
				printf("%3d ",grade);
			
				sum+=grade;
				/*For new lines.*/
				if((i+1)%10==0){
						printf("\n");
				}
				/*Calculates most succesfull students grades.*/
				if(grade>most_succesful){
					most_succesful=grade;
					most_succesful_index=i+1;
				}
				/*Calculates most unsuccesfull students grades.*/
				if(grade<most_unsuccesful){
					most_unsuccesful=grade;
					most_unsuccesful_index=i+1;
				}

				if(letter_grade(grade)=='A'){
					A++;
				}
				else if(letter_grade(grade)=='B'){
					B++;
				}
				else if(letter_grade(grade)=='C'){
					C++;
				}
				else if(letter_grade(grade)=='D'){
					D++;
				}
				else{
					F++;	
				}
			}
		}
		else{
			printf("Not in Range!!!");
		}		
	}
	average=(double)sum/(double)i;
		
	menu(most_succesful,most_unsuccesful,most_succesful_index,most_unsuccesful_index,
		 A,B,C,D,F,average,student_count);
		 
	return 0;
}
/*Prints menu on the screen.*/
void print_menu(int student_count){
	printf("\n----------------------------------------------------------------------------\n\n");
	printf("Student Score Calculator Menu for %d Student.",student_count);
	
	printf("\n\n1)Most Succesful Student\n");
	printf("2)Most Unsuccesful Student\n");
	printf("3)Letter Grade Statics\n");
	printf("4)Calculate Average\n");
	printf("5)Show All Data\n");
	printf("                   Make Selection: ");	
}
/*
 *It shows menu until users enters -1.
 *Shows answers.
*/
void menu(int most_succesful,int most_unsuccesful,int most_succesful_index,int most_unsuccesful_index,
		 int A,int B,int C,int D,int F,double average,int student_count){
	print_menu(student_count);
	
	int choose;
	scanf("%d",&choose);
	while(choose != -1){
		switch(choose){
			case 1:
				most_succesfull(most_succesful,most_succesful_index);
				break;
			case 2:
				most_unsuccesfull(most_unsuccesful,most_unsuccesful_index);
				break;
			case 3:
				letter_grade_statistic(A,B,C,D,F);
				break;
			case 4:
				printf("\nThe average Score of %d student is %.2lf",student_count,average);
				break;
			case 5:
				most_succesfull(most_succesful,most_succesful_index);
				most_unsuccesfull(most_unsuccesful,most_unsuccesful_index);
				letter_grade_statistic(A,B,C,D,F);
				printf("\nThe average Score of %d student is %.2lf",student_count,average);
				break;
			default:
				printf("\nFalse Selection");
		}
		print_menu(student_count);   /*Prints the menu.*/
		scanf("%d",&choose);
	}
}
/*
 *It prints most succesfull students grades,index,letter grade
*/	 
void most_succesfull(int most_succesful,int most_succesful_index){
	printf("\n\nMost Succesful Student:\n");
	printf("Index:%d",most_succesful_index);
	printf("\nScore:%d",most_succesful);
	printf("\nLetter Grade=%c",letter_grade(most_succesful));
}
/*
 *It prints most unsuccesfull students grades,index,letter grade
*/
void most_unsuccesfull(int most_unsuccesful,int most_unsuccesful_index){
	printf("\n\nMost Unsuccesful Student:\n");
	printf("Index:%d",most_unsuccesful_index);
	printf("\nScore:%d",most_unsuccesful);
	printf("\nLetter Grade=%c",letter_grade(most_unsuccesful));
}
/*
 *It returns grades letter.
*/
char letter_grade(int grade){
	if(grade>=90 && grade<=100){
		return 'A';
	}
	else if(grade>=80 && grade<=89){
		return 'B';
	}
	else if(grade>=70 && grade<=79){
		return 'C';
	}

	else if(grade>=60 && grade<=69){
		return 'D';
	}

	else{
		return 'F';
	}
} 
/*
 *It prints letter grades counts on the screen.
*/	 
void letter_grade_statistic(int A,int B,int C,int D,int F){

	printf("\n\n%d student got letter grade 'A'\n",A);
	printf("%d student got letter grade 'B'\n",B);
	printf("%d student got letter grade 'C'\n",C);
	printf("%d student got letter grade 'D'\n",D);
	printf("%d student got letter grade 'F'\n",F);

}	 

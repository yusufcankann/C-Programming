/*Yusuf Can Kan - 161044007*/

/*
 *I write question 2-3 and question 4 differently.
 *So it writes the answer to files and deletes the other values.
 *For example if you run the answer of 2-3 and the file has answer of 4 it deletes the answer 4 and writes 2-3.
 *I did not use append mode because it may looks bad for couple of time working.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct p{	/*For linked list.*/
	
	int a;
	struct p *next;
	
}p_t;

int read_each_line();		/******************ANSWER OF QUESTION 1 FUNCTİON******************/
void show_prime_linked();	/******************ANSWER OF QUESTION 2-3 FUNCTİON****************/
void write_prime_linked();	/******************ANSWER OF QUESTION 4 FUNCTİON******************/
p_t *create_linked();		/*It creates the linked list.*/
void show_prime_array();	/******************ANSWER OF QUESTION 2-3 FUNCTİON****************/
void write_prime_array();	/******************ANSWER OF QUESTION 4 FUNCTİON******************/
int *create_array(int *counter);	/*It creates the dynamic array*/
int isprime(int n);			/*Prime or not function*/

int main(){
	/*I create the menu for all questions and all calculations.*/
	char choose;
	printf("\n1.Show Prime (Linked List)");
	printf("\n2.Show Prime (Array)");
	printf("\n3.Write Prime (Linked List)");
	printf("\n4.Write Prime (Array)");
	printf("\n         Choose:");
	scanf("%c",&choose);
	
	switch(choose){
		case '1':
			show_prime_linked();
			break;
		case '2':
			show_prime_array();
			break;
		case '3':
			printf("\n\nCalculating and writing, Please Wait\n\n");
			write_prime_linked();
			break;
		case '4':
			printf("\n\nCalculating and writing, Please Wait\n\n");
			write_prime_array();
			break;
		default:
			printf("Invalid Input\n");
	}
	return 0;
}
/******************ANSWER OF QUESTION 1 FUNCTİON******************/
int read_each_line(FILE *fPtr){		/*It reads a line and returns the value.*/
	
	int number;

	if(fscanf(fPtr,"%d,00",&number) != EOF)
		return number;
	else 
		return -1;
}
/*
 * Creates the linked list and it filles it. Than it calculates the time for
 * finding prime numbers between 1-500.000 , 1-750.000 and 1-1.000.000.It writes that time on the
 * ‘output_even_LinkedList.txt’ files.
*/
/******************ANSWER OF QUESTION 2-3 FUNCTİON******************/
void show_prime_linked(){
	
	int i;
	int number=0;
	FILE *fPtr1;
	p_t *head;
	p_t *ptr;
	clock_t start;
	clock_t one,two,three;
	
	fPtr1=fopen("output_prime_LiknedList.txt","w");	/*It opens the file for writing the answers(times).*/
	
	head = create_linked(); /*It creates the linked list.*/

	ptr=head;
	start=clock();	/*It stores the time for starting.*/
	
	/*It looks all values inside the linked list.*/
	while(ptr->next!=NULL){
		number=ptr->a;	
		
		if(number == 500000)/*It stores the nessesary times.*/
			one = clock();
		else if(number == 750000)
			two = clock();
		else if(number == 1000000)
			three=clock();
		
		if(isprime(number)==1)	/*If number is prime it prints it on the screen.*/
			printf("\n %d",number);
		ptr = ptr->next;
	}
	
	/*It frees the memory.*/
	while(head!=NULL){
		ptr=head;
		head=head->next;
		free(ptr);
	}

	/*It writes the times on the files.*/
	fprintf(fPtr1,"\n\nQuestion 2 / 3-a-b-c:\n1 - 500.000 : %.2lf ms   \n1 - 750.000 : %.2lf ms   \n1 - 1.000.000 : %.2lf ms", ( (double)(one-start)/(CLOCKS_PER_SEC))*1000.0 , ((double)(two-start) / (CLOCKS_PER_SEC) )*1000.0,((double)(three-start) / (CLOCKS_PER_SEC) )*1000.0);
	
	fclose(fPtr1);
	printf("\n\nThe prime numbers has showed.\n");
	printf("The calculating times has written in the file.\n");
}

/*
 *Creates the linked list and it filled it. Than it calculates the time for
 *writing time.It writes that time on the ‘output_even_LinkedList.txt’ files.
*/
/******************ANSWER OF QUESTION 4 FUNCTİON******************/
void write_prime_linked(){
	int i;
	int number=0;
	FILE *fPtr1;
	p_t *head;
	p_t *ptr;
	clock_t start;
	clock_t one;
	
	fPtr1=fopen("output_prime_LiknedList.txt","w"); /*It opens the file for writing the answers(times).*/
	
	head = create_linked();				/*It creates the linked list.*/

	ptr=head;	
	start=clock();						/*It stores the time for starting.*/
	
	/*It looks all values inside the linked list.*/
	while(ptr->next!=NULL){
		number=ptr->a;	
		/*If number is prime it writes it on the file.*/
		if(isprime(number)==1)
			fprintf(fPtr1,"%d\n",number);
		ptr = ptr->next;
	}
	one=clock();
	/*It frees the memory.*/
	while(head!=NULL){
		ptr=head;
		head=head->next;
		free(ptr);
	}
	/*It writes the times on the files.*/
	fprintf(fPtr1,"\nQuestion 4 : %lf",( (double)(one-start)/(CLOCKS_PER_SEC))*1000.0);
	fclose(fPtr1);
	printf("\n\nThe prime numbers has written in the file.\n");
	printf("The written time has written in the file.\n");
}

/******************ANSWER OF QUESTION 2-3 FUNCTİON******************/
void show_prime_array(){

	int *ptr;
	int i;
	int counter=1;
	clock_t start;
	clock_t one,two,three;
	FILE *fPtr1;
	
	ptr = create_array(&counter); /*It creates the dynamic array*/
	
	start=clock();				  /*It stores the time for starting.*/
	
	for(i=0;i<counter-1;i++){	  /*It stores the nessesary times.*/
	
		if(ptr[i] == 500000)
			one = clock();
		else if(ptr[i] == 750000)
			two = clock();
		else if(ptr[i] == 1000000)
			three=clock();
			
		if(isprime(ptr[i])==1)		/*If number is prime it prints it on the screen.*/
			printf("%d\n",ptr[i]);	
	}
	fPtr1=fopen("output_prime_dynamic_array.txt","w");	/*It opens the file for writing the answers(times).*/
	
	/*It writes the times on the files.*/
	fprintf(fPtr1,"\n\nQuestion 2 / 3-a-b-c:\n1 - 500.000 : %.2lf ms   \n1 - 750.000 : %.2lf ms   \n1 - 1.000.000 : %.2lf ms", ( (double)(one-start)/(CLOCKS_PER_SEC))*1000.0 , ((double)(two-start) / (CLOCKS_PER_SEC) )*1000.0,((double)(three-start) / (CLOCKS_PER_SEC) )*1000.0);
	
	free(ptr);
	fclose(fPtr1);
	printf("\n\nThe prime numbers has showed.\n");
	printf("The calculating times has written in the file.\n");

}
/******************ANSWER OF QUESTION 4 FUNCTİON******************/
void write_prime_array(){

	int *ptr;
	int i;
	int counter=1;
	clock_t start;
	clock_t one;
	
	FILE *fPtr1;
	
	fPtr1=fopen("output_prime_dynamic_array.txt","w");		/*It opens the file for writing the answers(times).*/
	
	ptr = create_array(&counter);
	
	start=clock();
	for(i=0;i<counter-1;i++){
		if(isprime(ptr[i])==1)		/*If it is prime it writes the value to the file.*/
			fprintf(fPtr1,"\n %d",ptr[i]);
	}
	one=clock();
	/*It writes the times ( answer ) on the txt files.*/
	fprintf(fPtr1,"\nQuestion 4 : %lf",( (double)(one-start)/(CLOCKS_PER_SEC))*1000.0);
	
	free(ptr);
	fclose(fPtr1);
	printf("\n\nThe prime numbers has written in the file.\n");
	printf("The written time has written in the file.\n");
}

/*It creates the linked list and returns the pointer.*/
p_t *create_linked(){

	int number=0;
	FILE *fPtr;
	p_t *head;
	p_t *ptr;

	fPtr=fopen("data.txt","r");
	head=(p_t *)malloc(sizeof(p_t));
	ptr=head;
	
	while(number!=-1){
		number=read_each_line(fPtr);
		/*It extends the linked list until file ends.*/
		if(number!=-1){
			ptr->a=number;
			ptr->next = (p_t *)malloc(1*sizeof(p_t));
			ptr=ptr->next;
		}
		ptr->next = NULL;
	}
	fclose(fPtr);
	return head;
}

/*It creates the dynamic array and it returns the pointer.*/
int *create_array(int *counter){
	
	int index=0;
	int *ptr;
	FILE *fPtr;
	int number=0;
	fPtr=fopen("data.txt","r");
	ptr=(int *)malloc(sizeof(int)*1);

	number = read_each_line(fPtr);
	/*It extends the array until file ends.*/
	while(number!=-1){
		ptr[index]=number;
		(*counter)++;
		index++;
		ptr=(int*)realloc(ptr,sizeof(int) * (*counter));
		number = read_each_line(fPtr);
	}
	fclose(fPtr);
	return ptr;
	
}
/*
 *It check if the number is prime or not.
 *If it is prime it returns the number.
*/
int isprime(int n){
	int i,condition=0;
	
	if(n==1)
		return -1;
	for(i=2;(i<=n/2) && (condition==0) ;i++){
		if(n%i==0)
			condition++;
	}
	if(condition == 0)
		return 1;
	else 
		return -1;
}



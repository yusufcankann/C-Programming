/*Yusuf Can Kan - 161044007*/
#include<stdio.h>
void menu();										/*It displays menu..*/
void encrypt_open_msg();							/*It encrypts the txt.*/
int find_size_of_line(char line[]); 				/*It calculates the size of line.*/
void decrypt_secret_msg(); 							/*It decrypts the txt.*/
void reverse_line(char line[],int line_lenght); 	/* It reverses the all line. */
int main(){
		menu();
		return 0;
}
void menu(){
		char choice[10];             				/*
													 *It takes an string for choice and it looks just first character. In that way when the users 
													 *enters a invalid input it controls just first character and just does first input.
													*/
	do{
		printf("\n\n1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("0. Exit\n");
		printf("Choice:");
		scanf(" %s",choice);
		if(find_size_of_line(choice) > 0)			/*It checks the string size!*/
			printf("\nInvalid input.!!!!");
		else{
			switch(choice[0]){
				case '0':
					break;
				case '1':
					encrypt_open_msg();	
					break;
				case '2':
					decrypt_secret_msg();
					break;
				default:
					printf("\nInvalid input.!!!!");
			}
		}
	}while(choice[0] !='0');
}
void encrypt_open_msg(){
	char line[1024];
	int key,line_lenght;
	int i;
	printf("\nEnter A Key Value=");						/*It takes a key value from the user.*/
	scanf("%d",&key);
	printf("\n");
	FILE *FIPtr=fopen("open_msg.txt","r");				/*It opens the txt files.*/
	FILE *FOPtr=fopen("secret_msg.txt","w");
	
	while(fgets(line,1024,FIPtr) != NULL){				/*It takes every time 1 line until there is no line.*/
		line_lenght=find_size_of_line(line);			/*Takes the line lenght.*/
		reverse_line(line,line_lenght);					/*Reverses the line.*/
		for(i=0;i<=line_lenght;i++){					/*It encryptes the line with the key value.*/
			if(line[i] == '.')
				line[i] = '*';
			else if(line[i] == ' ')
				line[i] = '_';
			else{
				line[i]-=key;
				if(line[i]<'a')							/*When the character become smaller than 'a' it goes the 'z' and continue there.*/
					line[i]=('z'+1)-('a'-line[i]);
			}
		}
		fprintf(FOPtr,"%s",line);						/*It writes the answer to txt.*/
		printf("%s",line);								/*It writes the line to the screen.*/
	}
	fclose(FIPtr);
	fclose(FOPtr);
}
void decrypt_secret_msg(){
	char line[1024];
	int key,line_lenght;
	int i;
	printf("\nEnter A Key Value=");						/*It takes a key value from the user.*/
	scanf("%d",&key);
	printf("\n");
	FILE *FIPtr=fopen("open_msg.txt","w");				/*It opens the txt files.*/
	FILE *FOPtr=fopen("secret_msg.txt","r");
	while(fgets(line,1024,FOPtr) != NULL){				/*It takes every time 1 line until there is no line.*/
		line_lenght=find_size_of_line(line);			/*Takes the line lenght.*/
		reverse_line(line,line_lenght);					/*Reverses the line.*/
		for(i=0;i<=line_lenght;i++){
			if(line[i] == '*')
				line[i] = '.';
			else if(line[i] == '_')
				line[i] = ' ';
			else{
				line[i]+=key;
				if(line[i]>'z')
					line[i]=('a'-1)+(line[i]-'z');		/*When the character become bigger than 'z' it goes the 'a' and continue there.*/
			}	
		}
		fprintf(FIPtr,"%s",line);						/*It writes the answer to txt.*/
		printf("%s",line);								/*It writes the line to the screen.*/
	}
	fclose(FIPtr);
	fclose(FOPtr);
}
int find_size_of_line(char line[]){
	int i=0;
	while(line[i]!='\n' && line[i]!='\0')				/*It calculates the line size.*/
		i++;
	return i-1;	
}
void reverse_line(char line[],int line_lenght){			/*It reverses the line.*/
	int i=0;
	char temp[1];
	for(i=0;i<(line_lenght/2)+1;i++){
		temp[0]=line[line_lenght-i];
		line[line_lenght-i]=line[i];
		line[i]=temp[0];	
	}
}







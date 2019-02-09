/*Yusuf Can Kan - 161044007*/

/*  !!!!IMPORTANT NOTE!!!!  */
/*
	If you are using windows (DEV-C++) you must delete the line 81.
	The line is:
	fscanf(fPtr,"%c",&comma);
	
	This is nessesary because fscanf function does note take '\n' character in linux.
	But in windows it taken otomatically.

	If you are using linux you don't have to change anything.
*/

#include<stdio.h>
#include<stdlib.h>	/*For malloc calloc and random function.*/
#include<time.h>	/*For random function.*/

typedef struct{
	
	char **Map;
	int Width;		/*rows of the map.*/
	int Height;		/*column of the map.*/
	int Flower_X;	/*X coordinates of flower.*/
	int Flower_Y;	/*Y coordinates of flower.*/

}Forest;

typedef struct{
	
	int Coord_X;	/*X coordinates of botanist.*/
	int Coord_Y;	/*X coordinates of botanist.*/
	int Water_Bottle_Size;

}Botanist;

void init_game (Forest *forest, Botanist *botanist);			/*It initiliazes the game.*/
void print_map (Forest forest);									/*It prints he map.*/
void search (Forest *forest, Botanist *botanist,int *condition);/*It searchs the flower.*/

int main(){
	
	int i,j;
	int condition=0;	/*
						 *This condition value needs for that when the game finishes 
						 *the function writes the situation only 1 time.
						 */
	srand(time(NULL));
	
	Forest forest;
	Botanist botanist;
	
	init_game (&forest,&botanist);
	print_map (forest);
	printf("\nSearching...\n\n");
	search(&forest,&botanist,&condition);
	
	
	for(i=0 ; i < forest.Height ; i++)		/*At the end of everything it frees the memory which we takes with calloc inside the init_game function.*/
			free(forest.Map[i]);

	free(forest.Map);

	return 0;
}
void init_game (Forest *forest, Botanist *botanist){

	int i,j;
	char comma;		/*We use that when we takes the map from the csv file. It takes the ',' characters. */
	FILE *fPtr;
	fPtr=fopen("init.csv","r");		/*It opens the file.*/
		
	fscanf(fPtr,"%d",&botanist->Water_Bottle_Size);			/*It takes width , height and water size from the file.*/
	fscanf(fPtr,"%d,%d",&forest->Height,&forest->Width);
	forest->Map=(char **)calloc(forest->Height,sizeof(char*));	/*It creates memory with calloc.*/

	for(i=0 ; i < forest->Height ; i++)
		forest->Map[i]=(char*)calloc(forest->Width,sizeof(char));	/*It creates memory with calloc.*/
	
	for(i=0 ; i < forest->Height ; i++){		/*It takes the map from file.*/
		fscanf(fPtr,"%c",&comma);
		fscanf(fPtr,"%c",&comma);
		for(j=0;j<forest->Width;j++){
			
			if(j==forest->Width-1)
				fscanf(fPtr,"%c",&forest->Map[i][j]);
			else
				fscanf(fPtr,"%c,",&forest->Map[i][j]);
			
			if(forest->Map[i][j]=='F'){	/*It stores the coordinate which 'F' and 'B' place.*/
				forest->Flower_X=i;
				forest->Flower_Y=j;
			}
			
			if(forest->Map[i][j]=='B'){
				botanist->Coord_X=i;
				botanist->Coord_Y=j;
			}
		}
	}
	fclose(fPtr);	/*It closes the file.*/
}

void print_map (Forest forest){	/*It prints the map.*/
	
	int i,j;
	for(i=0 ; i < forest.Height ; i++){
		for(j=0;j<forest.Width;j++)
			printf(" %c",forest.Map[i][j]);
		printf("\n");
	}
}

void search(Forest *forest, Botanist *botanist,int *condition){
	int dice;
	dice=rand()%4;		/*It rolls the dice.*/
	if(dice==0)dice=4;
	
	if(botanist->Water_Bottle_Size<=0)	/*If water ended it leaves the function.*/
		return;
	
	if(forest->Map[botanist->Coord_X][botanist->Coord_Y] == 'B')	/*First it deletes the botanist from the map since botanist is moving.*/
		forest->Map[botanist->Coord_X][botanist->Coord_Y] = ' ';

	if(dice==1 && botanist->Coord_Y+1 < 10 && botanist->Water_Bottle_Size>0 && forest->Map[botanist->Coord_X][botanist->Coord_Y+1] != '#'){	/*If botanist goes to right.*/
		botanist->Coord_Y++;			/*It increases the Coord_Y.*/
		botanist->Water_Bottle_Size--;	/*İt decreases the Water_Bottle_Size.*/
		
		if(forest->Map[botanist->Coord_X][botanist->Coord_Y] == 'F'){/*If it founded the flower.*/
			print_map (*forest);
			
			/*
			 *If it did not printed the "I have found..", it prints and increases the condition. 
			 *If I don't use the condition it prints a lot time.
			 */
			if(*condition==0)	
				printf("\nI have found it on (%d,%d)!\n",botanist->Coord_X,botanist->Coord_Y);
			(*condition)++;
			return;
		}
		/*RECURSIVE*/
		if(botanist->Water_Bottle_Size>0 && *condition==0)	/*If it didn't found the flower and it has water the function calls itself again.*/  
			search (forest,botanist,condition);	
		else{
			/*If the water is end it prints the help and increases the condition..*/
			if(*condition==0){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				print_map (*forest);
				printf("\nHelp! I am on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
			}
			(*condition)++;
		}		
	}
	/*If botanist goes to left.*/
	if(dice==2 && botanist->Coord_Y-1 > 0 && botanist->Water_Bottle_Size>0 && forest->Map[botanist->Coord_X][botanist->Coord_Y-1] != '#'){
		botanist->Coord_Y--;			/*It decreases the Coord_Y.*/
		botanist->Water_Bottle_Size--;  /*It decreases the Water_Bottle_Size.*/
		
		if(forest->Map[botanist->Coord_X][botanist->Coord_Y] == 'F'){ /*If it founded the flower.*/
			print_map (*forest);
			/*
			 *If it did not printed the "I have found..", it prints and increases the condition. 
			 *If I don't use the condition it prints a lot time.
			 */
			if( (*condition) ==0)
				printf("\nI have found it on (%d,%d)!\n",botanist->Coord_X,botanist->Coord_Y);
			(*condition)++;
			return;
		}
		/*RECURSIVE*/
		if(botanist->Water_Bottle_Size>0 && *condition==0)/*If it didn't found the flower and it has water the function calls itself again.*/  
			search (forest,botanist,condition);	
		else{
			/*If the water is end it prints the help and increases the condition..*/
			if(*condition==0){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				print_map (*forest);
				printf("\nHelp! I am on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
			}
			(*condition)++;
		}
	}
	/*If botanist goes to down.*/
	if(dice==3 && botanist->Coord_X + 1 <10 && botanist->Water_Bottle_Size>0 && forest->Map[botanist->Coord_X+1][botanist->Coord_Y] != '#'){
		botanist->Coord_X++;		   /*It increases the Coord_X.*/
		botanist->Water_Bottle_Size--; /*It decreases the Water_Bottle_Size.*/
		
		if(forest->Map[botanist->Coord_X][botanist->Coord_Y] == 'F'){/*If it founded the flower.*/
			print_map (*forest);
			/*
			 *If it did not printed the "I have found..", it prints and increases the condition. 
			 *If I don't use the condition it prints a lot time.
			 */
			if(*condition==0)
				printf("\nI have found it on (%d,%d)!\n",botanist->Coord_X,botanist->Coord_Y);
			(*condition)++;
			return;
		}
		/*RECURSIVE*/
		if(botanist->Water_Bottle_Size>0 && *condition==0)
			search (forest,botanist,condition);	
		else{
			/*If the water is end it prints the help and increases the condition..*/
			if(*condition==0){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				print_map (*forest);
				printf("\nHelp! I am on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
			}
			(*condition)++;
		}
	}
	/*If botanist goes to up.*/
	if(dice==4 && botanist->Coord_X - 1 >0 && botanist->Water_Bottle_Size>0 && forest->Map[botanist->Coord_X-1][botanist->Coord_Y] != '#'){
		botanist->Coord_X--;		   /*It decreases the Coord_X.*/
		botanist->Water_Bottle_Size--; /*It decreases the Water_Bottle_Size.*/
		
		if(forest->Map[botanist->Coord_X][botanist->Coord_Y] == 'F'){
			print_map (*forest);
			if(*condition==0)
				printf("\nI have found it on (%d,%d)!\n",botanist->Coord_X,botanist->Coord_Y);
			(*condition)++;
			return;
		}	
		if(botanist->Water_Bottle_Size>0 && *condition==0)
			search (forest,botanist,condition);	
		else{
			/*If the water is end it prints the help and increases the condition..*/
			if(*condition==0){
				forest->Map[botanist->Coord_X][botanist->Coord_Y]='B';
				print_map (*forest);
				printf("\nHelp! I am on (%d,%d)\n",botanist->Coord_X,botanist->Coord_Y);
			}
			(*condition)++;
		}
	}
		/*If it do the move and still it did not find the flower it calls itself again.*/
	if(*condition==0)
		search (forest,botanist,condition);
}


/*Yusuf Can Kan - 161044007*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef enum{						
	S,P,T,B,M,START,FINISH,E	/*E = for empty blocks.*/
}block_type;

typedef struct{			/*Struct for every block.*/
	
	char text[20];
	int data;
	block_type type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
	
}block;

void display_board(block board[][10]);				/*It displays the board.*/
void init_board(block board[][10]);					/*It initializes the board.*/
int single_player(block board[][10],int x,int y);	/*Single player function.*/
int control(block board[][10],int *x,int *y);		/*It controls that when the game is playing player comes any special blocks.(S,P,T,B,M)*/
void two_player();								/*2 Player function.*/
void menu();									/*When the program runs first time menu fuction stars and ask that single player or 2 player.*/

int main(){

	menu();
	
	return 0;
}
/*When the program runs first time menu fuction stars and ask that single player or 2 player.*/
void menu(){

	int choice=0;
	srand(time(NULL));
	block board[10][10];
	init_board(board);
	
	printf("  1. Single Player\n  2. 2 Player\n\n   Choice:");		/*It takes the choice for menu from the user.*/
	scanf("%d",&choice);
	
	switch(choice){
		case 1:printf("  Move Count=%d \n\n",single_player(board,9,9));
			   break;
		case 2:two_player();
			   break;
		default:printf("  Invalid Input!!\n\n");
				break;
		
	}
}
void display_board(block board[][10]){				/*It displays the game boards.*/
	int i,j;
	
	printf("\n    ------------------------------------------------------------------------------\n");
	for(i=0;i<10;i++){
		printf("    ");
		for(j=0;j<10;j++){
			if(board[i][j].text[0] != '-')			/*If the block is not empty (S,P,T,B,M) it prints that.*/
				printf("%s",board[i][j].text);
			else{
				if(board[i][j].data < 10)
					printf("|   %d  " ,board[i][j].data);
				else 
					printf("|  %.2d  ",board[i][j].data);
			}
		}
		printf("|");
		printf("\n    -----------------------------------------------------------------------");
		printf("\n");
	}
}

void init_board(block board[][10]){	/*It initializes the board.*/
	int i,j;
	char a[2]="--";
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){								/*At first it gaves the structures spesific values.*/
			
			board[i][j].text[0] = a[0];	
			
			if(i%2==1)	
				board[i][j].data = (100-10*i-j);
			else
				board[i][j].data =(100-10*(i)-(9-j));
				
			board[i][j].type=E;
			
			board[i][j].pos_x = i;
			board[i][j].pos_y = j;
			board[i][j].jump_x= -1;			/*At first it gaves the structures spesific values.*/
			board[i][j].jump_y= -1;
		}
	}
											/*Then it gaves the valid values to valid struts.*/
	sprintf(board[9][9].text,"| 1 (Start)");
	board[9][9].type=START;
	sprintf(board[9][4].text,"| S{1} ");
	board[9][4].type=S;
	board[9][4].jump_x= 9;			
	board[9][4].jump_y= 9;
	sprintf(board[9][3].text,"|M{11} ");
	board[9][3].type=M;
	board[9][3].jump_x= 8;		
	board[9][3].jump_y= 0;
	sprintf(board[8][6].text,"|M{28} ");
	board[8][6].type=M;
	board[8][6].jump_x= 7;		
	board[8][6].jump_y= 2;
	sprintf(board[8][2].text,"|   P  ");
	board[8][2].type=P;
	sprintf(board[7][5].text,"|S{12} ");
	board[7][5].type=S;
	board[7][5].jump_x= 8;		
	board[7][5].jump_y= 1;
	sprintf(board[7][1].text,"|   B  ");
	board[7][1].type=B;
	board[7][1].jump_x= 6;			
	board[7][1].jump_y= 3;
	sprintf(board[6][9].text,"|   T  ");
	board[6][9].type=T;
	board[6][9].jump_x= 6;		
	board[6][9].jump_y= 4;
	sprintf(board[6][5].text,"|   B  ");
	board[6][5].type=B;
	board[6][5].jump_x= 5;		
	board[6][5].jump_y= 9;
	sprintf(board[6][1].text,"|M{52} ");
	board[6][1].type=M;
	board[6][1].jump_x= 4;			
	board[6][1].jump_y= 1;
	sprintf(board[5][5].text,"|S{22} ");
	board[5][5].type=S;
	board[5][5].jump_x= 7;		
	board[5][5].jump_y= 8;
	sprintf(board[5][2].text,"|   P  ");
	board[5][2].type=P;
	sprintf(board[5][0].text,"|   B  ");
	board[5][0].type=B;
	board[5][0].jump_x= 4;
	board[5][0].jump_y= 4;
	sprintf(board[4][9].text,"|S{44} ");
	board[4][9].type=S;
	board[4][9].jump_x= 5;	
	board[4][9].jump_y= 6;
	sprintf(board[4][6].text,"|M{77} ");
	board[4][6].type=M;
	board[4][6].jump_x= 2;		
	board[4][6].jump_y= 6;
	sprintf(board[4][3].text,"|   T  ");
	board[4][3].type=T;
	board[4][3].jump_x= 5;		
	board[4][3].jump_y= 1;
	sprintf(board[3][7].text,"|S{52} ");
	board[3][7].type=S;
	board[3][7].jump_x= 4;	
	board[3][7].jump_y= 1;
	sprintf(board[3][4].text,"|   B  ");
	board[3][4].type=B;
	board[3][4].jump_x= 2;		
	board[3][4].jump_y= 0;
	sprintf(board[3][1].text,"|M{77} ");
	board[3][1].type=M;
	board[3][1].jump_x= 2;		
	board[3][1].jump_y= 6;
	sprintf(board[2][8].text,"|   T  ");
	board[2][8].type=T;
	board[2][8].jump_x= 2;		
	board[2][8].jump_y= 3;
	sprintf(board[2][5].text,"|M{83} ");
	board[2][5].type=M;
	board[2][5].jump_x= 1;		
	board[2][5].jump_y= 7;
	sprintf(board[2][2].text,"|S{68} ");
	board[2][2].type=S;
	board[2][2].jump_x= 3;		
	board[2][2].jump_y= 2;
	sprintf(board[1][8].text,"|   B  ");
	board[1][8].type=B;
	board[1][8].jump_x= 1;		
	board[1][8].jump_y= 3;
	sprintf(board[1][5].text,"|   P  ");
	board[1][5].type=P;
	sprintf(board[1][1].text,"|M{94} ");
	board[1][1].type=M;
	board[1][1].jump_x= 0;		
	board[1][1].jump_y= 3;
	sprintf(board[0][2].text,"|   T  ");
	board[0][2].type=T;
	board[0][2].jump_x= 1;		
	board[0][2].jump_y= 2;
	sprintf(board[0][7].text,"|S{72} ");
	board[0][7].type=S;
	board[0][7].jump_x= 2;		
	board[0][7].jump_y= 1;
	sprintf(board[0][8].text,"|S{56} ");
	board[0][8].type=S;
	board[0][8].jump_x= 4;		
	board[0][8].jump_y= 5;
	sprintf(board[0][9].text,"| 100 (Finish)");
	board[0][9].type=FINISH;
}

/*Single player function.*/
int single_player(block board[][10],int x,int y){
	int count=0;
	int dice=0;
	int y_temp;
	char temp[100];
	
	dice=rand()%6;			/*It rolls the rice.*/
	if(dice==0) dice=6;
	
	/*It makes the different calculations for colum is odd or even.*/
	if(x%2==1){			/* If colum is odd.*/			
		y_temp=y;
		y=y-dice;		/*Player goes to left on the board.*/
		if(y<0){		/*If it comes to end of the rows (line) it passes other row(line).*/
			x--;
			y=(-1)*y -1;
			if(board[x][y].type == P){ 	/*If the block is P it doesn't move so gets back to old places.*/
				x++;
				y=y_temp;
			}
		}
		if(board[x][y].type == P) /*If the block is P it doesn't move.*/
			y=y_temp;
		count++;					/*Move count increases 1.*/
	}
	else{
		y_temp=y;
		y=y+dice;				/*Player goes to right on the board.*/
		if(x==0 && y>9)			/*If it passes the 100 it doesn't move.*/
			y=y_temp;
		else if(x!=0 && y>9){	/*If it comes to end of the rows (line) it passes other row(line).*/
			x--;
			y=10-(y-9);
		}
		if(board[x][y].type == P){ /*If the block is P it doesn't move so gets back to old places.*/
			x++;
			y=y_temp;
		}
		count++;						/*Move count increases 1.*/
	}
 	control(board,&x,&y);				/*It checks the block if it is special block.(S,P,T,B,M)*/
 	
	if(board[x][y].data == 100){		/*The block is last block*/
		printf("\n\n");
		sprintf(temp,"%s",board[x][y].text);
		sprintf(board[x][y].text,"|Player");	/*Writes the players places.*/
		display_board(board);
		printf("\n    Dice:%d    x:%d   y:%d      Block Number:%d\n\n",dice,x,y,board[x][y].data);		/*It prints the dice.*/
		sprintf(board[x][y].text,"%s"	,temp);
		printf("\n\n");
		return count;
	}
   if(x!=0 || y!=9)					/*Recursion condition. If the block is not last block it calls the same function.*/
		count+=single_player(board,x,y);

	printf("\n\n");
	sprintf(temp,"%s",board[x][y].text);		/*It prints the playes location.*/
	sprintf(board[x][y].text,"|Player");
	display_board(board);
	printf("\n    Dice:%d    x:%d   y:%d      Block Number:%d\n\n",dice,x,y,board[x][y].data);
	sprintf(board[x][y].text,"%s",temp);
	printf("\n\n");
	return count;
}
/*It controls that when the game is playing player comes any special blocks.(S,P,T,B,M)*/
int control(block board[][10],int *x,int *y){
	
	int x_t=*x, y_t=*y;
	/*If it is special block it takes the jump_x and jump_y values from struct and changes the location.*/
	if(board[*x][*y].type == S || board[*x][*y].type == M || board[*x][*y].type == T || board[*x][*y].type == B ){	
		*x=board[x_t][y_t].jump_x;
		*y=board[x_t][y_t].jump_y;
		return 1;
	}
	else 
		return 0;
}

/*2 Player function.*/
/*It calles the single_player function for 2 players and at end it compares that.*/
void two_player(){
	int p1,p2;
	block board[10][10];
	init_board(board);
	printf("\n     *************************************************************************************************");
	printf("\n                                               Player 1");
	p1=single_player(board,9,9);
	init_board(board);
	printf("\n     *************************************************************************************************");
	printf("\n                                               Player 2");
	p2=single_player(board,9,9);
	
	printf("\n\n  Player1 move count: %d",p1);
	printf("\n  Player2 move count: %d",p2);
	
	if(p1<p2)
		printf("\n\n  Winner is Player1 !!!\n\n");
	else if(p2<p1)
		printf("\n\n  Winner is Player2 !!!\n\n");
	else
		printf("\n\n  No Winner.\n\n");
}




	
	
	





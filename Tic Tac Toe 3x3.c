#include<stdio.h>
#include<stdlib.h>

char a=' ',b=' ',c=' ',d=' ',e=' ',f=' ',g=' ',h=' ',z=' ',j=' ';
char check[9] = {'1','2','3','4','5','6','7','8','9'};

void Board(){

	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",a,b,c);
	printf("--------|-------|--------\n");
	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",d,e,f);
	printf("--------|-------|--------\n");
	printf("\t|\t|\n   %c    |   %c   |   %c   \n\t|\t|\n",g,h,z);

}

char Position(int pos, int p, char cp1 , char cp2);

void main(){
	int pos,p,i;
	char win = 'D',cp1,cp2;
	
	printf("Player 1: Enter Your Marker X/O\n");
	scanf("%c",&cp1);
	
	while(cp1 != 'X')
	{
		if(cp1 == 'O')
		{
			break;
		}
		printf("ERROR Enter again\nPlayer 1: Enter Your Marker X/O\n");
		scanf(" %c",&cp1);
	}
	
	system("cls");
	
	if (cp1 == 'X'){
		cp2 = 'O';
	}
	else cp2 = 'X';
	
	Board();
	
	for (i=1;i<=9;i++){
				if (i%2 == 0){
					printf("\n\nPLAYER 2 TURN (%c)\n",cp2);
					p = 2;
				}
				else
				{
					printf("\n\nPLAYER 1 TURN (%c)\n",cp1);
					p = 1;
				}
				printf("At Which Position (1-9) Do You Want To Place Your Marker.\n");
			    scanf("%d",&pos);
			    while(pos < 1 || pos > 9)
			    {
			    	printf("ERROR, position number must be between 1 & 9 inclusive.\n");
					printf("At Which Position (1-9) Do You Want To Place Your Marker.\n");	    	
			   	 	scanf("%d",&pos);	    	
				}
				while (check[pos-1] == 'X' || check[pos-1] == 'O') 
				{
					printf("The position %d is already taken.\nPlease enter again.\n", pos);  	
			   	 	scanf("%d",&pos);
				}
			    
				Position(pos,p,cp1,cp2);
			    
				if (check[0] == check[1] && check[0] == check[2]){
			    	win = check[0];
			    	break;
				}
				else if (check[0] == check[3] && check[0] == check[6]){
					win = check[0];
			    	break;
				}
				else if (check[2] == check[5] && check[2] == check[8]){
					win = check[2];
			    	break;
				}
				else if (check[6] == check[7] && check[6] == check[8]){
					win = check[6];
			    	break;
				}
				else if (check[0] == check[3] && check[0] == check[6]){
					win = check[0];
			    	break;
				}
				else if (check[2] == check[4] && check[2] == check[6]){
					win = check[2];
			    	break;
				}
				else if (check[0] == check[4] && check[0] == check[8]){
					win = check[0];
			    	break;
				}
				else if (check[3] == check[4] && check[3] == check[5]){
					win = check[3];
			    	break;
				}
				else if (check[1] == check[4] && check[1] == check[7]){
					win = check[1];
			    	break;
				}
	}
	
	if (win == cp1){
		printf("\n\n\nPLAYER 1 WINS !!!");
	}
	else if (win == cp2){
		printf("\n\n\nPLAYER 2 WINS !!!");
	}
	else printf("IT'S A DRAW !!!");
}

char Position(int pos, int p, char cp1 , char cp2){
	char temp;
	switch (pos){
		case 1:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			a = temp;
			check[0] = temp;
			system("cls");
			Board();
		break;
		case 2:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			b = temp;
			check[1] = temp;
			system("cls");
			Board();
		break;
		case 3:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			c = temp;
			check[2] = temp;
			system("cls");
			Board();
		break;
		case 4:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			d = temp;
			check[3] = temp;
			system("cls");
			Board();
		break;
		case 5:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			e = temp;
			check[4] = temp;
			system("cls");
			Board();
		break;
		case 6:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			f = temp;
			check[5] = temp;
			system("cls");
			Board();
		break;
		case 7:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			g = temp;
			check[6] = temp;
			system("cls");
			Board();
		break;
		case 8:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			h = temp;
			check[7] = temp;
			system("cls");
			Board();
		break;
		case 9:
			if (p == 1){
				temp = cp1;
			}
			else temp = cp2;
			z = temp;
			check[8] = temp;
			system("cls");
			Board();
		break;
	
	}
}

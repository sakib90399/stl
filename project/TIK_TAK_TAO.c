#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char player='X';
const char  computer='0';

void resetBoard();
void printBoard();
int checkFreespaces();
void playerMove();
char checkwinner();
void computerMove();
void printWinner(char);
int main()
{
    char winner=' ';
    char response=' ';
    do{
        winner =' ';
        response =' ';
        resetBoard();
    

    while(winner ==' '&&checkFreespaces() !=0)
    {
        printBoard();
        playerMove();
        winner = checkwinner();
        if (winner!= ' '|| checkFreespaces()==0)
        {
            break;
        }
    computerMove();
    winner=checkwinner();
    if(winner!= ' '||checkFreespaces()==0)
    {
        break;
    } 
}
    printBoard();
    printWinner(winner);

    printf("\n Would you like to play again?(Y/N):");
    scanf("%c");
    scanf("%c",&response);
    response=toupper(response); 

} while(response=='Y');

printf("Thanks for playing!");

return 0; 
} 
void resetBoard(){
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++){
        board[i][j]=' ';
      }
    }
}
void printBoard()
{
    printf("%c | %c | %c",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
     printf("%c | %c | %c",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
     printf("%c | %c | %c",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int checkFreespaces()
{
    int freespaces=9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if (board[i][j]!=' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playerMove()
{
    int x;
    int y;
    do
    {
     printf("Enter row #(1-3): ");
      scanf("%d",&x);
     x--;
     printf("Enter column #(1-3): ");
      scanf("%d",&y);
     y--;
     if(board[x][y]!=' ')
     {
        printf("Invalid move!\n");
      }
       else
       {
        board[x][y]=player;
        break;
     }
    } while (board[x][y]!=' ');
    
}
void computerMove()
{
    srand(time(0));
    int x;
    int y;

    if (checkFreespaces()>0)
    {
        do
        {
            x=rand()%3;
            y=rand()%3;
        } while (board[x][y]!=' ');

        board[x][y]=computer;
        
    }
     else{
            printWinner(' ');
         }
        
}

char checkwinner()
{
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&& board[i][0]==board[i][2])
        {
            return board[i][0];
        }
    }
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==board[1][i]&& board[0][i]==board[2][i])
        {
            return board[0][i];
        }
    }

    if(board[0][0]==board[1][1]&& board[0][0]==board[2][2])
    {
            return board[0][0];
     }
      if(board[0][2]==board[1][1]&& board[0][2]==board[2][0])
      {
            return board[0][2];
     }
     return ' ';



}
void printWinner(char winner)
{
    if (winner==player)
    {
        printf ("You Win!");

    }
    else if(winner==computer) 
    {
        printf ("You Lose!");

    } else {
        printf ("It's a tie");
    }

    
    

}



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char player = 'X';
const char computer = 'O';
void resetBord();
void printBord();
int checkFreeSpace();
void playermove();
void computermove();
char checkwinner();
void printwinner(char winner);

int main(){
    char check;
    do{   
    char winner = ' ';
    resetBord();
   while (winner==' ' && checkFreeSpace() !=0)
   {
    printBord();
    playermove();
    winner = checkwinner();
   
    if (winner != ' ' || checkFreeSpace==0 )
    {
        break;
    }
    computermove();
    if (winner != ' ' || checkFreeSpace == 0 )
    {
        break;
    }
    }
    printBord();
    printwinner(winner);
    printf("\n Do u wanna play again?(Y/N): ");
    scanf("%c");//to clear buffer
    scanf("%c",&check);
    }
    while(check=='Y');
}
void resetBord(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=' ';

        }
        
    }
    
}
void printBord(){
    
    printf("%c | %c | %c",board[0][0],board[0][1],board[0][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c",board[1][0],board[1][1],board[1][2]);
    printf("\n--|---|--\n");
    printf("%c | %c | %c",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int checkFreeSpace(){
    int freeSpace = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]!=' ')
            {
                freeSpace--;
            }
            
        }
        
    }
    return freeSpace;
}
void playermove(){
    int x,y;
    do
    {
    printf("put da ro(1-3): ");
    scanf("%d",&x);
    printf("put da kolam(1-3): ");
    scanf("%d",&y);
    x--;
    y--;
    if (board[x][y]==' ')
    {
        board[x][y]= player;
        break;
    }
     else if(board[x][y]!=' ') 
        
        printf("Invalid number\n");

        
    } while (board[x][y] !=' ');
    

}
void computermove(){
    srand(time(0));
    int x;
    int y;
    if (checkFreeSpace()>0)
    {
       do
       {
        x = rand() %3;
        y = rand() %3;
       } while (board[x][y] != ' ');
       board[x][y]= computer;
    }
    else
        printwinner(' ');


}
char checkwinner(){
    //rows
    for (int i = 0; i < 3; i++)
    {
       if (board[i][0]==board[i][1]&&board[i][2]==board[i][0])
       {
        return board[i][0];
       }
       
    }
    //column
    for (int i = 0; i < 3; i++)
    {
       if (board[0][i]==board[1][i]&&board[2][i]==board[0][i])
       {
        return board[0][i];
       }
       
    }
    //diagonal
    if (board[0][0]==board[1][1]&&board[2][2]==board[0][0])
       {
        return board[0][0];
       }
    if (board[0][2]==board[1][1]&&board[2][0]==board[0][2])
       {
        return board[0][2];
       }
    
    return ' ';
}
void printwinner(char winner){
    
    if (winner == player)
    {
        printf("YOU WIN");
    }
    else if (winner == computer)
    {
        printf("YOU WIN");
    }
    else{
        printf("tie");
    }
}
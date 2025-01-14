/*
A tic-tac-toe game written in C to help me refresh
and learn a bit more syntax (because I really don't know anything)
*/

#include <stdio.h>
#include <stdlib.h>

/*
p1 (x) p2 (o)
Each player has their own game board - 3 arrays which correspond to columns, rows, or diagonals

Q: How do we alternate moves? 
A: We keep a while loop and we break when a winner occurs.

Q: How do we verify moves?
A: Check the full game board to see it position is occupied

Q: How do we check winner?
A: At the end of each turn, we will run a checkWin function which will read player data to see if a win has been achieved
*/

/*
   a     b     c
      |     |     
1  -  |  -  |  -  
 _____|_____|_____
      |     |     
2  -  |  -  |  -  
 _____|_____|_____
      |     |     
3  -  |  -  |  -  
      |     |     
*/


typedef struct {
// num in [a, b, c]
    int cols[3];
// num in [1, 2, 3]
    int rows[3];
// num in [top left to bottom right, bottom left to top right]
    int diag[2];
} player;


// We don't need to label who is who, because this is only used to check occupied spots
typedef struct {
    int board[3][3];
} game;

int checkTurn() {
    return 0;
}

int checkWin(player p1, player p2)
{
    for(int i = 0; i < 3; i++) {
        if (p1.cols[i] == 3) return 1;
        if (p1.rows[i] == 3) return 1;
        if (p2.cols[i] == 3) return 2;
        if (p2.rows[i] == 3) return 2;
    }
    if ((p1.diag[0]||p1.diag[1]) == 2) return 1;
    if ((p2.diag[0]||p2.diag[1]) == 2) return 2;
    return 0;
}

int main() 
{
    player p1 = { {0,0,0}, {0,0,0}, {0,0} };
    player p2 = { {0,0,0}, {0,0,0}, {0,0} };
    
    int winner = 0;
    do {
        puts("Hello");
        
        winner = checkWin(p1, p2);
    } while (!winner);
    printf("Player %i Wins!");
    return 0;
}
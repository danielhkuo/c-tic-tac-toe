/*
A tic-tac-toe game written in C to help me refresh
and learn a bit more syntax (because I really don't know anything)
*/

#include <stdio.h>
#include <stdbool.h>
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

typedef struct Player {
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

// num in [a, b, c]
    int cols[3];
// num in [1, 2, 3]
    int rows[3];
// num in [top left to bottom right, bottom left to top right]
    int diag[2];
} player;


// We don't need to label who is who, because this is only used to check occupied spots
typedef struct game {
    int board[3][3];
} game;

int checkWin()
{
    return 0;
}

int main()
{
    do {
        puts("Hello");
    } while (checkWin());
    return 0;
}
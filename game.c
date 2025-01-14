/*
A tic-tac-toe game written in C to help me refresh
and learn a bit more syntax (because I really don't know anything)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
p1 (x) p2 (o), represented as -1, 0, and 1

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


// This board is not used to check winner. Only used to render the board and check valid turns!
typedef struct {
    int board[3][3];
} game;

typedef struct {
    int r;
    int c;
} pair;

int checkTurn(char c, int col) {
    col = col--;
    int row;
    if (c == ('A' || 'a')) row = 0;
    if (c == ('B' || 'B')) row = 1;

}

int checkWin(player p1, player p2)
{
    for(int i = 0; i < 3; i++) {
        if ((p1.cols[i] || p1.rows[i]) == 3) return 1;
        if ((p2.cols[i] || p2.rows[i]) == 3) return 2;
    }
    if ((p1.diag[0]||p1.diag[1]) == 2) return 1;
    if ((p2.diag[0]||p2.diag[1]) == 2) return 2;
    return 0;
}

void renderBoard(game g)
{

}

int main()
{
    // Better initialization with clear structure
    game g = {{0,0,0}, {0,0,0}, {0,0,0}};
    player p1 = {{0,0,0}, {0,0,0}, {0,0,0}};
    player p2 = {{0,0,0}, {0,0,0}, {0,0,0}};
    int winner = 0;
    int count = 0;
    const char* set = "abcABC";  // Made const for safety
    char buffer;  // For handling newline characters

    do {
        // Default to player 2, if it is an even turn, player 1
        int curr = (count % 2 == 0) ? 1 : 2;  // Simplified player selection
        char row;
        int col;

        // Display current game state (assuming you have a displayGame function)
        // displayGame(g);

        // Get row input
        printf("Player %i's Turn. Enter Row (a-c): ", curr);
        while (scanf(" %c", &row) != 1 || strchr(set, row) == NULL) {
            printf("Invalid input, please enter a valid row (a-c): ");
            while ((buffer = getchar()) != '\n' && buffer != EOF); // Clear input buffer
        }

        // Get column input
        printf("Enter Column (0-2): ");
        while (scanf("%d", &col) != 1 || col < 0 || col > 2) {
            printf("Invalid input, please enter a valid column (0-2): ");
            while ((buffer = getchar()) != '\n' && buffer != EOF); // Clear input buffer
        }

        // Check if position is already taken (assuming 0 means empty)
        int row_idx = (row >= 'a' && row <= 'c') ? row - 'a' : row - 'A';
        if (g.board[row_idx][col] != 0) {  // Assuming g has a board member
            printf("Position already taken! Try again.\n");
            continue;  // Skip turn if position is taken
        }

        // Update game state here
        // updateGame(&g, &p1, &p2, row_idx, col, curr);

        count++;
        winner = checkWin(p1, p2);

        // Check for draw condition
        if (count == 9 && !winner) {
            printf("Game ends in a draw!\n");
            return 0;
        }

    } while (!winner);

    printf("Player %i Wins!\n", winner);  // Fixed printf format
    return 0;
}
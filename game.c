/*
A tic-tac-toe game written in C to help me refresh
and learn a bit more syntax (because I really don't know anything)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ASCII Art Board Layout:
   0     1     2
      |     |     
a  -  |  -  |  -  
 _____|_____|_____
      |     |     
b  -  |  -  |  -  
 _____|_____|_____
      |     |     
c  -  |  -  |  -  
      |     |     
*/

typedef struct {
    int board[3][3];
} game;

/*
 Check if there's a winner
 Returns: 1 if Player 1 wins, 2 if Player 2 wins, 0 if no winner
*/
int checkWin(game g)
{
    // Check rows
    if (g.board[0][0] + g.board[0][1] + g.board[0][2] == 3) return 1;
    if (g.board[0][0] + g.board[0][1] + g.board[0][2] == -3) return 2;
    if (g.board[1][0] + g.board[1][1] + g.board[1][2] == 3) return 1;
    if (g.board[1][0] + g.board[1][1] + g.board[1][2] == -3) return 2;
    if (g.board[2][0] + g.board[2][1] + g.board[2][2] == 3) return 1;
    if (g.board[2][0] + g.board[2][1] + g.board[2][2] == -3) return 2;
    
    // Check columns
    if (g.board[0][0] + g.board[1][0] + g.board[2][0] == 3) return 1;
    if (g.board[0][0] + g.board[1][0] + g.board[2][0] == -3) return 2;
    if (g.board[0][1] + g.board[1][1] + g.board[2][1] == 3) return 1;
    if (g.board[0][1] + g.board[1][1] + g.board[2][1] == -3) return 2;
    if (g.board[0][2] + g.board[1][2] + g.board[2][2] == 3) return 1;
    if (g.board[0][2] + g.board[1][2] + g.board[2][2] == -3) return 2;
    
    // Check diagonals
    if (g.board[0][0] + g.board[1][1] + g.board[2][2] == 3) return 1;
    if (g.board[0][0] + g.board[1][1] + g.board[2][2] == -3) return 2;
    if (g.board[2][0] + g.board[1][1] + g.board[0][2] == 3) return 1;
    if (g.board[2][0] + g.board[1][1] + g.board[0][2] == -3) return 2;
    
    return 0;
}

void displayGame(game g)
{
    printf("   0     1     2\n      |     |     \n");
    char line[3];
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (g.board[r][c] == 0) {
                line[c] = '-';
            }
            else if (g.board[r][c] == -1)
            {
                line[c] = 'O';
            } else {
                line[c] = 'X';
            }
        }
        char rowLabel;
        if (r == 0) {
            rowLabel = 'a';
        }
        else if (r == 1)
        {
            rowLabel = 'b';
        } else {
            rowLabel = 'c';
        }
        printf("%c  %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n",rowLabel, line[0],line[1],line[2]);
    }
}

int main()
{
    // Better initialization with clear structure
    game g = {{{0,0,0}, {0,0,0}, {0,0,0}}};
    int winner = 0;
    int count = 0;
    const char* set = "abcABC";  // Made const for safety
    char buffer;  // For handling newline characters

    do {
        // Default to player 2, if it is an even turn, player 1
        int curr = (count % 2 == 0) ? 1 : 2;  // Simplified player selection
        char row;
        int col;

        displayGame(g);

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

        // Player 1 = 1 = X, Player 2 = -1 = O
        g.board[row_idx][col] = (curr == 1) ? 1 : -1;

        count++;
        winner = checkWin(g);

        // Check for draw condition
        if (count == 9 && !winner) {
            printf("Game ends in a draw!\n");
            return 0;
        }

    } while (!winner);

    printf("Player %i Wins!\n", winner);  // Fixed printf format
    displayGame(g);
    return 0;
}
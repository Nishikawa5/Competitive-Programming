#include <stdlib.h>
#include <stdio.h>

#define usi unsigned short int

// (scanf("%c", &guess) == 1 && guess != '\n')

bool* iniGuesses(int *dif) {
    bool *temp = (bool *) malloc(sizeof(bool) * 26);
    for (int i = 0; i < 26; i++) temp[i] = false;

    char guess;
    int tempdif = 0;
    getchar(); // read newline after the int
    while ((guess = getchar()) && guess != '\n') {
        if (!temp[guess - 'a']) {
            tempdif++;
            temp[guess - 'a'] = true;
        }
    }

    *dif = tempdif;
    return temp;
}

bool *copyBool(bool *vec) {
    bool *temp = (bool *) malloc(sizeof(bool) * 26);
    for (int i = 0; i < 26; i++) temp[i] = vec[i];

    return temp;
}

int guessChars(bool **guesses, int *difguess) {
    bool *temp = copyBool(*guesses);
    char guess;
    int tot = 0;
    
    while ((guess = getchar()) && guess != '\n') {
        if (temp[guess - 'a']) {
            if ((*guesses)[guess - 'a']) {
                (*guesses)[guess - 'a'] = false;
                (*difguess)--;
            }
        } else {
            if (*difguess != 0) tot++;
            temp[guess - 'a'] = true;
        }
    }
    return tot;
}

// UVa 00489 - Hangman Judge
/* Input error and corner case that we can win before using all the other guess characters made me waste a lot of time
  in this problem. 
  
  Maybe after getting an integer as input, after this integer there's a newline character, then if we get a char as input
  we get this newline character after the integer input.
  Its something like that, i tested it wrong at first time

  when reading the integer from the buffer, it consumes the integer value, but leaves the newline character in it
  so we have to read another character (the newline character) to read the subsequent characters that we want to read
  */
int main(void) {
    int round;
    int dif;

    scanf("%d", &round);
    while(round != -1) {
        bool *match = iniGuesses(&dif);
        int tries = guessChars(&match, &dif);

        printf("Round %d\n", round);

        if (tries >= 7) {
            printf("You lose.\n");
        } else {
            if (dif == 0) printf("You win.\n");
            else printf("You chickened out.\n");
        }

        scanf("%d", &round);
    }
}















void checkSteps(char **board, usi m, usi n, usi i, usi j) {
    short steps[3] = {-1, 0, 1};

    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            short curi = i + steps[a];
            short curj = j + steps[b];
            if (curi >= 0 && curi < m && curj >= 0 && curj < n && 
                board[curi][curj] != '*') {
                board[curi][curj]++;
            }
        }
    }
}

// have done this type of problem before
int minesweeper(void) {
    usi m, n;
    usi field = 1;

    scanf("%hu %hu", &m, &n);

    while (m != 0 && n != 0) {
        if (field > 1) printf("\n");

        // initialize the board
        char **board = (char **) malloc(sizeof(char *) * m);
        for (int i = 0; i < m; i++) {
            board[i] = (char *) malloc(sizeof(char) * n);
            for (int j = 0; j < n; j++) {
                scanf(" %c", &board[i][j]);
                if (board[i][j] == '.') board[i][j] = '0';
            }
        }

        // change the board counting mines
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '*') {
                    checkSteps(board, m, n, i, j);
                }
            }
        }

        // print the board
        printf("Field #%d:\n", field++);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }

        scanf("%hu %hu", &m, &n);
    }
}
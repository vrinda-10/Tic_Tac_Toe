#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Initialize the board with numbers 1-9
void initializeBoard() {
    char val = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = val++;
}

// Display the current state of the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Check if current player has won
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer) return true;
    }
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer) return true;

    return false;
}

// Check if all cells are filled (draw)
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Switch player from X to O or O to X
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Ask the current player to make a move
void getMove() {
    int move;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken. Try again.\n";
        } else {
            board[row][col] = currentPlayer;
            break;
        }
    }
}

// Main game loop
void playGame() {
    initializeBoard();
    currentPlayer = 'X';

    while (true) {
        displayBoard();
        getMove();

        if (checkWin()) {
            displayBoard();
            cout << " Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

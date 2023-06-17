
#include <iostream>
using namespace std;

bool p1checkWin(char board[][3]) {
    if (board[0][0] == 'X') {
        if (board[0][1] == 'X' && board[0][2] == 'X') {
            return true;
        }
    }
    if (board[1][0] == 'X') {
        if (board[1][1] == 'X' && board[1][2] == 'X') {
            return true;
        }
    }
    if (board[2][0] == 'X') {
        if (board[2][1] == 'X' && board[2][2] == 'X') {
            return true;
        }
    }
    if (board[0][0] == 'X') {
        if (board[1][0] == 'X' && board[2][0] == 'X') {
            return true;
        }
    }
    if (board[0][1] == 'X') {
        if (board[1][1] == 'X' && board[2][1] == 'X') {
            return true;
        }
    }
    if (board[0][2] == 'X') {
        if (board[1][2] == 'X' && board[2][2] == 'X') {
            return true;
        }
    }
    if (board[0][0] == 'X') {
        if (board[1][1] == 'X' && board[2][2] == 'X') {
            return true;
        }
    }
    if (board[0][2] == 'X') {
        if (board[1][1] == 'X' && board[2][0] == 'X') {
            return true;
        }
    }
    return false;
}

bool p2checkWin(char board[][3]) {
    if (board[0][0] == 'O') {
        if (board[0][1] == 'O' && board[0][2] == 'O') {
            return true;
        }
    }
    if (board[1][0] == 'O') {
        if (board[1][1] == 'O' && board[1][2] == 'O') {
            return true;
        }
    }
    if (board[2][0] == 'O') {
        if (board[2][1] == 'O' && board[2][2] == 'O') {
            return true;
        }
    }
    if (board[0][0] == 'O') {
        if (board[1][0] == 'O' && board[2][0] == 'O') {
            return true;
        }
    }
    if (board[0][1] == 'O') {
        if (board[1][1] == 'O' && board[2][1] == 'O') {
            return true;
        }
    }
    if (board[0][2] == 'O') {
        if (board[1][2] == 'O' && board[2][2] == 'O') {
            return true;
        }
    }
    if (board[0][0] == 'O') {
        if (board[1][1] == 'O' && board[2][2] == 'O') {
            return true;
        }
    }
    if (board[0][2] == 'O') {
        if (board[1][1] == 'O' && board[2][0] == 'O') {
            return true;
        }
    }
    return false;
}

bool isValidMove(char board[][3], int mark) {
    int row = (mark - 1) / 3;
    int col = (mark - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

void printBoard(char board[][3]) {
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
    cout << " --- --- ---" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << " --- --- ---" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << " --- --- ---" << endl;
}

void playGame() {
    char board[][3] = { {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'} };

    char player1 = 'X';
    char player2 = 'O';
    bool turn = true;
    bool p1win = false;
    bool p2win = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;
    cout << "Let's start the game!" << endl;

    int turns = 9;
    int turnCounter = 0;
    while (turnCounter < turns && p1win == false && p2win == false) {
        printBoard(board);
        cout << endl;

        int mark = 0;
        if (turn) {
            cout << "Player 1 Turn" << endl;
            cin >> mark;
            if (!isValidMove(board, mark)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            int row = (mark - 1) / 3;
            int col = (mark - 1) % 3;
            board[row][col] = player1;
            p1win = p1checkWin(board);
        }
        else {
            cout << "Player 2 Turn" << endl;
            cin >> mark;
            if (!isValidMove(board, mark)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            int row = (mark - 1) / 3;
            int col = (mark - 1) % 3;
            board[row][col] = player2;
            p2win = p2checkWin(board);
        }

        turnCounter++;
        turn = !turn;
    }

    printBoard(board);
    cout << endl;

    if (p1win) {
        cout << "Player 1 wins!" << endl;
    }
    else if (p2win) {
        cout << "Player 2 wins!" << endl;
    }
    else {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    playGame();
    return 0;
}

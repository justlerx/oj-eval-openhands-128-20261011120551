#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkWin(const vector<string>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

int main() {
    vector<string> board(3);
    for (int i = 0; i < 3; i++) {
        cin >> board[i];
    }
    
    int countX = 0, countO = 0, countEmpty = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x') countX++;
            else if (board[i][j] == 'o') countO++;
            else if (board[i][j] == '-') countEmpty++;
        }
    }
    
    bool xWins = checkWin(board, 'x');
    bool oWins = checkWin(board, 'o');
    
    // Check for invalid states
    bool invalid = false;
    
    // Both players can't win simultaneously
    if (xWins && oWins) {
        invalid = true;
    }
    // If X wins, X should have exactly one more piece than O
    else if (xWins && countX != countO + 1) {
        invalid = true;
    }
    // If O wins, X and O should have equal pieces
    else if (oWins && countX != countO) {
        invalid = true;
    }
    // If neither wins, the difference should be at most 1 (X goes first)
    else if (!xWins && !oWins && (countX < countO || countX > countO + 1)) {
        invalid = true;
    }
    
    if (invalid) {
        cout << "invalid" << endl;
    } else if (xWins) {
        cout << "win" << endl;
    } else if (oWins) {
        cout << "lose" << endl;
    } else if (countEmpty == 0) {
        cout << "tie" << endl;
    } else {
        cout << "ongoing" << endl;
    }
    
    return 0;
}
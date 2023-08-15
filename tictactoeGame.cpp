#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << " " << board[i][j] << " ";
            if (j != board[i].size() - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i != board.size() - 1) {
            for (int j = 0; j < board[i].size(); ++j) {
                cout << "---";
                if (j != board[i].size() - 1) {
                    cout << "|";
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}


// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const char& cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the Tic Tac Toe board

    char currentPlayer = 'X';
    int row, col;

    while (true) {
        // Print the current state of the board
        printBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the board is full (draw)
        if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    printBoard(board);

    return 0;
}

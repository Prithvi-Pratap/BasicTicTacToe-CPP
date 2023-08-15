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

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Create the Tic Tac Toe board

    // Print the initial state of the board
    printBoard(board);

    return 0;
}

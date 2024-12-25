#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check lanes
        for (int i = 0; i < board.size(); ++i) {
            bool check[9] = { false };
            for (int j = 0; j < board[i].size(); ++j) {
                char c = board[i][j];
                if (c != '.') {
                    if (!check[c - '1']) check[c - '1'] = true;
                    else return false;
                }
            }
        }

        // Check columns
        for(int i=0; i < board.size(); i++){
            bool check[9] = { false };
            for (vector<char> row:board) {
                char c = row[i];
                if (c != '.') {
                    if (!check[c - '1']) check[c - '1'] = true;
                    else return false;
                }
            }
        }

        // Check squares
        for(int i=0; i < 9; i++){
            bool check[9] = { false };
            for (int j = (i%3)*3; j < (i%3)*3+3; ++j) {
                for (int k = (i/3)*3; k < (i/3)*3+3; ++k) {
                    char c = board[j][k];
                    if (c != '.') {
                        if (!check[c - '1']) check[c - '1'] = true;
                        else return false;
                    }
                }
            }
//            printf("i %i mod3 %i div3 %i", i, i%3, i/3);
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector <vector<char>> board1 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << (solution.isValidSudoku(board1) ? "true" : "false") << endl;
    // Expected output: true

    // Test Case 2
    vector <vector<char>> board2 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '2', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    cout << (solution.isValidSudoku(board2) ? "true" : "false") << endl;
    // Expected output: false
    return 0;
}
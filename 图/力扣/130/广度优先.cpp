#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        vector<pair<int, int> > queue;
        int height = board.size();
        int weight = board[0].size();
        // 遍历边界并将'O'换成'#'
        for (int i = 0; i < weight; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '#';
                queue.emplace_back(0, i);
            }
            if (board[height - 1][i] == 'O') {
                board[height - 1][i] = '#';
                queue.emplace_back(height - 1, i);
            }
        }
        for (int i = 0; i < height; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                queue.emplace_back(i, 0);
            }
            if (board[i][weight - 1] == 'O') {
                board[i][weight - 1] = '#';
                queue.emplace_back(i, weight - 1);
            }
        }
        // 如果上下左右有'O'，将其转化为'#':
        while (!queue.empty()) {
            int x = queue.back().first;
            int y = queue.back().second;
            queue.pop_back();
            board[x][y] = '#';
            // up
            if (x - 1 >= 0){
                if(board[x - 1][y] == 'O') {
                    queue.emplace_back(make_pair(x - 1, y));
                }
            }
            // down
            if (x + 1 < height){
                if(board[x + 1][y] == 'O') {
                    queue.emplace_back(make_pair(x + 1, y));
                }
            }
            // right
            if (y + 1 < weight){
                if(board[x][y + 1] == 'O') {
                    queue.emplace_back(make_pair(x, y + 1));
                }
            }
            // left
            if (y - 1 >= 0){
                if(board[x][y - 1] == 'O') {
                    queue.emplace_back(make_pair(x, y - 1));
                }
            }
        }
        // 将所有的'#'转化为'O'，将所有的'O'转化为'X'
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < weight; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

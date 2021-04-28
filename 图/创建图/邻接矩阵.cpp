/**
 * 邻接矩阵构建图
 */
#include<iostream>
#include<vector>
using namespace std;
const int H = 5;
const int W = 5;

void display(int Graph[H][W]){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cout << Graph[i][j] << " ";
        cout << endl;
    }
}

int main(){
    int Graph[H][W] = {0};
    Graph[0][2] = 1;
    Graph[1][4] = 1;
    Graph[3][4] = 1;
    Graph[4][3] = 1;
    display(Graph);
    return 0;
}
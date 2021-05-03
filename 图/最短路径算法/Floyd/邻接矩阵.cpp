#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#define INF 0x7fffffff
using namespace std;
char V[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

vector<vector<int> >& floyd(vector<vector<int> >& matrix, int v0)
{
    vector<vector<int> > path(matrix.size(), vector<int>(matrix.size(), 0));
    static vector<vector<int> > dist(matrix.size(), vector<int>(matrix.size(), 0));
    int i,j,k;
    int tmp;
    int n = matrix.size();

    // 初始化
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            dist[i][j] = matrix[i][j];    // "顶点i"到"顶点j"的路径长度为"i到j的权值"。
            path[i][j] = j;                // "顶点i"到"顶点j"的最短路径是经过顶点j。
        }
    }

    // 计算最短路径
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                // 如果经过下标为k顶点路径比原两点间路径更短，则更新dist[i][j]和path[i][j]
                tmp = (dist[i][k]==INF || dist[k][j]==INF) ? INF : (dist[i][k] + dist[k][j]);  // 防止多个INF相加越界
                if (dist[i][j] > tmp){
                    // "i到j最短路径"对应的值设，为更小的一个(即经过k)
                    dist[i][j] = tmp;
                    // "i到j最短路径"对应的路径，经过k
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    // 打印
    for(int i = 0; i < n; i++){
        cout << " v0(" << V[v0] << ")-->";
        cout << V[i] << ": ";
        if(dist[v0][i] == INF) cout << "INF";
        else cout << dist[v0][i];
        cout << "(" << V[path[v0][i]] << ")" << endl;
    }
    return dist;
}

int main() {
    ifstream readfile("D:\\Desktop\\practice\\weights.txt");  // 这里要绝对路径
    int n;
    int v0 = 0;
    readfile >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    if (readfile.is_open()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                readfile >> matrix[i][j];
                if(matrix[i][j] == 0 && i != j) matrix[i][j] = INF;
//                cout << matrix[i][j] << ' ';
            }
//            cout << endl;
        }
        readfile.close();
    }
    floyd(matrix, v0);
    return 0;
}
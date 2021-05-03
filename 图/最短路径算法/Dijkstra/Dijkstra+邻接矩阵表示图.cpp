#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define INF 0x7fffffff
//#pragma warning(disable:4996)

void Dijkstra(vector<vector<int>> &vec, vector<int> &result, int v0) {
    vector<int> visited(vec.size(), 0); // 表示顶点是否被选中，0：顶点未被选中；1：顶点已被选中
    int last_visited = 0;
    visited[v0] = 1; // 选中起始顶点
    result[0] = 0;

    for (int i = 0; i < vec.size() - 1; ++i) { // N 个顶点需要做 N - 1 次循环
        // 查看顶点周围的所有点
        for (int j = 0; j < vec.size(); ++j) { // 循环遍历所有顶点
            if (visited[j] == 0) { // 保证被查看的新顶点没有被访问到
                if (vec[v0][j] != 0) { // 保证当前顶点（V0）与新顶点（j）之间有路径
                    int dist = vec[v0][j] + last_visited; // 计算 V0 到 J 的路径距离
                    if (dist < result[j])result[j] = dist; // 用新路径代替原来的路径
                }
            }
        }
        // 找出最小值
        int minIndex = 0;
        while (visited[minIndex] == 1) minIndex++; // 找第一个没有被选中的节点
        for (int j = minIndex; j < vec.size(); ++j) {
            if (visited[j] == 0 && result[j] < result[minIndex]) {
                minIndex = j;
            }
        }

        last_visited = result[minIndex]; // 更新最小值
        visited[minIndex] = 1; // 将最小值顶点选中
        v0 = minIndex; // 下次查找从最限制顶点开始
    }
}

int main() {
    ifstream readfile("D:\\Desktop\\practice\\weights.txt");  // 这里要绝对路径
    int n;
    readfile >> n;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    if (readfile.is_open()) {
        cout << 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                readfile >> vec[i][j];
//                cout << vec[i][j] << " ";
            }
//            cout << endl;
        }
        readfile.close();
    }
    vector<int> result(n, INF); // 把输出结果全部初始化为无穷大
    Dijkstra(vec, result, 0);

    for (int i = 0; i < n; ++i) {
        if (result[i] == INF)printf("INF\n");
        else printf("%d\n", result[i]);
    }
    return 0;
}
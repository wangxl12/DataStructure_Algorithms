/**
 * 邻接表构建图
 */
#include<iostream>
#include<vector>
using namespace std;
const int MAX = 5;

struct GraphNode{
    int label;  // 存储当前节点的标签
    vector<GraphNode* > neighbors;  // 存储相邻节点
    GraphNode(int x): label(x){};  // 初始化节点的标签
};

void display(GraphNode* Graph[]){
    cout << "Graph:" << endl;
    for(int i = 0; i < MAX; i++){
        cout << "Label: " << Graph[i]->label;
        for(int j = 0; j < Graph[i]->neighbors.size(); j++) cout << " " << Graph[i]->neighbors[j]->label;
        cout << endl;
    }
}

void del(GraphNode* Graph[]){
    for(int i = 0; i < MAX; i++){
        delete Graph[i];
    }
}
int main(){
    GraphNode* Graph[MAX];  // MAX个结点
    for(int i = 0; i < MAX; i++) Graph[i] = new GraphNode(i);
    // 添加边
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);

    display(Graph);
    del(Graph);
    return 0;
}
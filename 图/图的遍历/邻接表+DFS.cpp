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

void DFS_graph(GraphNode* Graph[], int v0){
    // 为了防止死循环，需要标记一下已经被访问的结点
    vector<bool> visited(MAX, false);
    vector<GraphNode* > stack;
    // 起点入栈
    stack.push_back(Graph[v0]);
    // DFS
    while(!stack.empty()){
        GraphNode* tmp = stack[stack.size() - 1];
        stack.pop_back();
        // visit
        cout << tmp->label << " ";
        visited[tmp->label] = true;
        // push neighbors
        for(int i = 0; i < tmp->neighbors.size(); i++){
            if(!visited[tmp->neighbors[i]->label]) {  // 如果没有遍历过
                stack.push_back(tmp->neighbors[i]);  // 将邻接点压栈
                visited[tmp->neighbors[i]->label] = true; // 防止出现邻结点暂未被访问，但是已经处于队列中，这样容易重复入队
            }
        }
    }
    cout << endl;
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
    Graph[3]->neighbors.push_back(Graph[2]);
    Graph[4]->neighbors.push_back(Graph[3]);
    display(Graph);
    DFS_graph(Graph, 1);
    DFS_graph(Graph, 0);
    del(Graph);
    return 0;
}
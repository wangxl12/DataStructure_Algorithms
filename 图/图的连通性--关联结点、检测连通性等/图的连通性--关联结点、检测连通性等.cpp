#include <iostream>

#define Elem int
using namespace std;

/*...
 * 使用一维数组存储父节点，可能会说一维数组的长度无法确定，思考一下图的连通性的用处，
 * 在大型社交软件中创建用户ID可以是连续的，这样的话就保证了一维数组的每一个节点都有值
 */
class UnionFind {
private:
    int count = 0;  // 记录连同分支个数
    Elem *parent;  // 记录根结点
    int *size;  // 记录每一个节点的子结点个数

public:
    UnionFind(int N) {
        count = N;  // 初始化连通分支数
        parent = new Elem[N];
        size = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;  // 初始化父节点(为本身)
            size[i] = 0;  // 初始化子结点个数
        }
    }

    void Union(Elem p, Elem q) {
        /*...
         * 连接图中的连个节点p, q
         */
        // 判断两个结点是否连通
        Elem root_p = find(p);
        Elem root_q = find(q);
        if (root_q == root_p) return;  // 连通
        else {  // 不连通
            if (size[p] >= size[q]) parent[q] = parent[p];
            else parent[p] = parent[q];
            count--;
        }
    }

    bool connected(Elem p, Elem q) {
        return find(p) == find(q);
    }

    Elem getCount() {
        /*...
         * 返回连通分支数
         */
        return count;
    }

    Elem find(Elem node) {
        while (parent[node] != node) {
            node = parent[node];  // 不断向上找自己的根节点
            parent[node] = parent[parent[node]];  // 减少树的高度，从而减少find函数的时间复杂度
        }
        return node;
    }

};

int main() {
    UnionFind obj(8);
    cout << "at the start: " << obj.getCount() << endl;
    obj.Union(1, 2);
    cout << "after 1---2: " << obj.getCount() << endl;
    obj.Union(1, 3);
    cout << "after 1---3: " << obj.getCount() << endl;
    obj.Union(2, 3);
    cout << "after 2---3: " << obj.getCount() << endl;
    obj.Union(4, 5);
    cout << "after 4---5: " << obj.getCount() << endl;
    obj.Union(4, 6);
    cout << "after 4---6: " << obj.getCount() << endl;
    obj.Union(3, 5);
    cout << "after 3---5: " << obj.getCount() << endl;
    return 0;
}


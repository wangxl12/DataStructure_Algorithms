#include <iostream>

#define Elem int
using namespace std;

/*...
 * ʹ��һά����洢���ڵ㣬���ܻ�˵һά����ĳ����޷�ȷ����˼��һ��ͼ����ͨ�Ե��ô���
 * �ڴ����罻����д����û�ID�����������ģ������Ļ��ͱ�֤��һά�����ÿһ���ڵ㶼��ֵ
 */
class UnionFind {
private:
    int count = 0;  // ��¼��ͬ��֧����
    Elem *parent;  // ��¼�����
    int *size;  // ��¼ÿһ���ڵ���ӽ�����

public:
    UnionFind(int N) {
        count = N;  // ��ʼ����ͨ��֧��
        parent = new Elem[N];
        size = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;  // ��ʼ�����ڵ�(Ϊ����)
            size[i] = 0;  // ��ʼ���ӽ�����
        }
    }

    void Union(Elem p, Elem q) {
        /*...
         * ����ͼ�е������ڵ�p, q
         */
        // �ж���������Ƿ���ͨ
        Elem root_p = find(p);
        Elem root_q = find(q);
        if (root_q == root_p) return;  // ��ͨ
        else {  // ����ͨ
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
         * ������ͨ��֧��
         */
        return count;
    }

    Elem find(Elem node) {
        while (parent[node] != node) {
            node = parent[node];  // �����������Լ��ĸ��ڵ�
            parent[node] = parent[parent[node]];  // �������ĸ߶ȣ��Ӷ�����find������ʱ�临�Ӷ�
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


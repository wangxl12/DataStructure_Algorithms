#include<iostream>
#include<vector>

using namespace std;
int map[10][3] = {{0, 1, 2}, {0, 1, 3}, {0, 1, 4}, {0, 2, 3}, {0, 2, 4},
                  {0, 3, 4}, {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}};  // 因为一共有10种取值的方法，可以穷举

void getResult(vector<int> &array) {
    for(int i = 0; i < 10; i++){
        if((array[map[i][0]] + array[map[i][1]] + array[map[i][2]]) % 10 == 0){
            int s = 0;
            for(int j = 0; j < 5; j++){
                if(j != map[i][0] && j != map[i][1] && j != map[i][2]) s += array[j];
            }
            cout << s % 10 << endl;
            return ;
        }
    }
    cout << -1 << endl;
}

int main() {
    vector<int> array(5, 0);
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 5; i++) cin >> array[i];  // 将5个数存在array里
        getResult(array);
    }
    return 0;
}

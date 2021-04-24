#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b){
    return a < b? b: a;
}

int max_index(vector<int>& dp){
    int m = dp[0];
    for(int i = 1; i < dp.size(); i++){
        if(m < dp[i]) m = dp[i];
    }
    return m;
}

int result(vector<int>& list){
    vector<int> dp(list.size(), 1);  // dp[i]表示以list[i]结尾的序列最大长度值，初始化为1
    for(int i = 0; i < list.size(); i++){
        for(int j = 0; j < i; j++){
            if(list[j] < list[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return max_index(dp);
}

int main(){
    vector<int> list = {0,1,0,3,2,3};
    cout << result(list);
    return 0;
}

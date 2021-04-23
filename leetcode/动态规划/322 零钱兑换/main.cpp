#include<iostream>
#include<vector>
using namespace std;

int result(vector<int>& coins, int amount){
    // 这里将初始值设定为amount + 1，非常巧妙，可能一开始会设置为-1，但是到下面的min函数使用的时候就会回来更改了。
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 0; i < dp.size(); i++){
        for(int coin: coins){
            if(i - coin < 0) continue;
            // why还要加一个min比较？因为可能多个coin都可以，但是min就决定了初始化dp不能是-1，因为-1永远最小
            // 那么可以初始化一个比较大的数，不一定要非常大，amount + 1即可，因为dp[i]永远不可能大于i。
            // 这样的话最后return 就可以判断，如果dp[amount]=amount+1，说明不可能，就应该返回-1;否则就是dp[i];
            dp[i] = min(dp[i - coin] + 1, dp[i]);
        }
    }
    for(int i: dp) cout << i << " ";
    cout << endl;
    return (dp[amount] == amount + 1)? -1: dp[amount];
}

int main(){
    vector<int> coins = {1, 2, 5};
    cout << result(coins, 11);
    return 0;
}
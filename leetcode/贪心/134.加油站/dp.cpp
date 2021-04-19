/**
 * 下面代码使用dp实现的，逻辑正确但是超时了，主要先看看逻辑，再优化
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 创建一个n行n列的数组，第i行表示从i号加油站出发
        // 第j列表示通过j个加油站之后剩余的油量
        int n = gas.size();
        vector<vector<int> >dp(n, vector<int>(n, 0));
        // 从每一个加油站出发的初始油量
        for(int i = 0; i < n; i++) dp[i][i] = gas[i];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j - i < n + 1; j++){
                // 处于当前加油站的总油量为前一个状态减去cost[i-1]
                // 但是需要判断汽车能否到达加油站
                if(dp[i][(j - 1) % n] < cost[(j - 1) % n]) dp[i][j%n] = -1;  // 如果到达不了，将油量设为-1
                else dp[i][j%n] = dp[i][(j - 1) % n] - cost[(j - 1) % n] + gas[j%n];
            }
        }
        for(int i = 0; i < n; i++){
            // 看起点的油量是否大于等于0
            if(dp[i][i] >= 0) return i;
        }
        return -1;
    }
};
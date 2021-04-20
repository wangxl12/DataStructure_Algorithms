/**
 * 在优化中，考虑到当前状态只与前一个状态有关，所以与优化之前的dp算法相比，减少了存储空间的消耗
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 创建一个n行n列的数组，第i行表示从i号加油站出发
        // 第j列表示通过j个加油站之后剩余的油量
        int n = gas.size();
        vector<int>dp(n, 0);
        // 从每一个加油站出发的初始油量
        for(int i = 0; i < n; i++) dp[i] = gas[i];
        // 对每一个起点开始，都进行测试一遍
        for(int i = 0; i < n; i++){
            // 从i号加油站开始
            for(int j = i + 1; j - i < n + 1; j++){
                // 处于当前加油站的总油量为前一个状态减去cost[i]
                // 但是需要判断汽车能否到达加油站
                if(dp[i] < cost[(j - 1)%n]) {
                    dp[i] = -1;
                    break;
                }
                dp[i] = dp[i] - cost[(j - 1)%n] + gas[j%n];
            }
        }

        for(int i = 0; i < n; i++){
            if(dp[i] >= 0) return i;
        }
        return -1;
    }
};
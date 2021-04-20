/**
 * 当数据规模巨大的时候，如果将gas值复制到一个新的dp数组中将花费大量时间，可以省去这一步
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 创建一个n行n列的数组，第i行表示从i号加油站出发
        // 第j列表示通过j个加油站之后剩余的油量
        int n = gas.size();
        int res = 0;
        // 对每一个起点开始，都进行测试一遍
        for(int i = 0; i < n; i++){
            // 从i号加油站开始
            res = gas[i];
            for(int j = i + 1; j - i < n + 1; j++){
                // 处于当前加油站的总油量为前一个状态减去cost[i]
                // 但是需要判断汽车能否到达加油站
                if(res < cost[(j - 1)%n]) {
                    res = -1;
                    break;
                }
                res = res - cost[(j - 1)%n] + gas[j%n];
            }
            if(res >= 0) return i;
        }
        return -1;
    }
};
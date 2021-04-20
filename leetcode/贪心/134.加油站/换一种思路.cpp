/**
/* 官方给的思路是直接拿个变量来存储所有的cost和gas，每走一个车站比较一下，cost大于gas就换起点。
/* 这种方法如果单从小数据量来看，其实和之前的方法差不多，但是数据量大了，这个只用累加的方法就更高效了。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};

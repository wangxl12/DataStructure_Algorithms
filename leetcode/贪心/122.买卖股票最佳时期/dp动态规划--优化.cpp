class Solution {
public:
    int max(int a, int b){
        return a > b? a: b;
    }
    int maxProfit(vector<int>& prices) {
        // dp0表示第i天不持有股票, dp1表示第i天持有股票
        int dp0 = 0;
        int dp1 = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            // 今天无股票：可能是前一天有的卖了，也可能是前一天的也没买
            int today0 = max(dp0, dp1 + prices[i]);
            // 今天有股票：可能是前一天没了买的，也可能是前一天有的没卖
            int today1 = max(dp0 - prices[i], dp1);

            dp0 = today0;
            dp1 = today1;
        }
        return max(dp0, dp1);
    }
};
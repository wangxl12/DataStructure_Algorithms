class Solution {
public:
    int max(int a, int b){
        return a > b? a: b;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int> >dp(prices.size(), vector<int>(2, 0));
        // dp[i][0]表示第i天不持有股票, dp[i][1]表示第i天持有股票
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            // 今天无股票：可能是前一天有的卖了，也可能是前一天的也没买
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 今天有股票：可能是前一天没了买的，也可能是前一天有的没卖
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};
class Solution {
public:

    int dpp(vector<int>& prices, int i, int count,
            vector<vector<int>>& dp, int fee) {

        if(i >= prices.size())
            return 0;

        if(dp[i][count] != -1)
            return dp[i][count];

        // We currently have a stock
        if(count == 1) {

            // Sell
            int sellP = prices[i] +
                        dpp(prices, i + 1, 0, dp, fee);

            // Don't sell
            int dontSell =
                dpp(prices, i + 1, 1, dp, fee);

            return dp[i][count] = max(sellP, dontSell);
        }

        // We don't have a stock
        else {

            // Buy
            int buy = -prices[i] - fee +
                      dpp(prices, i + 1, 1, dp, fee);

            // Don't buy
            int dontBuy =
                dpp(prices, i + 1, 0, dp, fee);

            return dp[i][count] = max(buy, dontBuy);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {

        if(prices.size() == 1)
            return 0;

        vector<vector<int>> dp(
            prices.size(),
            vector<int>(2, -1)
        );

        return dpp(prices, 0, 0, dp, fee);
    }
};
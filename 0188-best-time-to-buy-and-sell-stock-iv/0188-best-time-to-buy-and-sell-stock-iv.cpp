class Solution {
public:

    int dpp(vector<int>& prices, int i, int count,
            int transactions, vector<vector<vector<int>>>& dp) {

        if(i >= prices.size() || transactions == 0)
            return 0;

        if(dp[i][count][transactions] != -1)
            return dp[i][count][transactions];

        if(count == 1) {

            // Sell
            int sellP = prices[i] +
                dpp(prices, i + 1, 0,
                    transactions - 1, dp);

            // Don't sell
            int dontSell =
                dpp(prices, i + 1, 1,
                    transactions, dp);

            return dp[i][count][transactions] =
                max(sellP, dontSell);
        }

        else {

            // Buy
            int buy = -prices[i] +
                dpp(prices, i + 1, 1,
                    transactions, dp);

            // Don't buy
            int dontBuy =
                dpp(prices, i + 1, 0,
                    transactions, dp);

            return dp[i][count][transactions] =
                max(buy, dontBuy);
        }
    }

    int maxProfit(int k, vector<int>& prices) {

        if(prices.size() <= 1 || k == 0)
            return 0;

        vector<vector<vector<int>>> dp(
            prices.size(),
            vector<vector<int>>(
                2,
                vector<int>(k + 1, -1)
            )
        );

        return dpp(prices, 0, 0, k, dp);
    }
};
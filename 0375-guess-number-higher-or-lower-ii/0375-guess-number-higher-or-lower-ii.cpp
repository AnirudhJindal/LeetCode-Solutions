class Solution {
public:

    int pDp(int n, int i, int j, vector<vector<int>>& dp) {

        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k = i; k <= j; k++) {

            int left = pDp(n, i, k - 1, dp);
            int right = pDp(n, k + 1, j, dp);

            int cost = k + max(left, right);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return pDp(n, 1, n, dp);
    }
};
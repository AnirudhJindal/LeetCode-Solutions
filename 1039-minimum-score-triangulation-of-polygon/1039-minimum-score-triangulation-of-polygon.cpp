class Solution {
public:

    int dp(vector<int>& values, int i, int j,
           vector<vector<int>>& memo) {

        if(j - i < 2)
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        int ans = INT_MAX;

        for(int k = i + 1; k < j; k++) {

            int sum =
                dp(values, i, k, memo) +
                dp(values, k, j, memo) +
                values[i] * values[k] * values[j];

            ans = min(ans, sum);
        }

        return memo[i][j] = ans;
    }


    int minScoreTriangulation(vector<int>& values) {

        int n = values.size();

        vector<vector<int>> memo(
            n,
            vector<int>(n, -1)
        );

        return dp(values, 0, n - 1, memo);
    }
};
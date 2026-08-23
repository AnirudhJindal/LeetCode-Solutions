class Solution {
public:

    int dpp(int target, int curr, int clip,
            vector<vector<int>>& dp) {

        if(curr == target)
            return 0;

        if(curr > target)
            return 1e9;

        if(dp[curr][clip] != -1)
            return dp[curr][clip];

        int ans = 1e9;

        // Copy All
        if(curr != clip) {
            ans = min(ans, 1 + dpp(target, curr, curr, dp));
        }

        // Paste
        if(clip > 0 && curr + clip <= target) {
            ans = min(ans, 1 + dpp(target, curr + clip, clip, dp));
        }

        return dp[curr][clip] = ans;
    }

    int minSteps(int n) {

        if(n == 1)
            return 0;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, -1)
        );

        return dpp(n, 1, 0, dp);
    }
};
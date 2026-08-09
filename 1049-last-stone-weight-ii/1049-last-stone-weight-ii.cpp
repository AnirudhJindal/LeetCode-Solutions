
class Solution {
public:

    int solve(vector<int>& stones,
              int i,
              int currentSum,
              int target,
              vector<vector<int>>& dp) {

        // We considered all stones
        if(i == stones.size())
            return currentSum;

        // Already calculated
        if(dp[i][currentSum] != -1)
            return dp[i][currentSum];

        // Don't take current stone
        int skip = solve(
            stones,
            i + 1,
            currentSum,
            target,
            dp
        );

        // Take current stone
        int take = 0;

        if(currentSum + stones[i] <= target) {

            take = solve(
                stones,
                i + 1,
                currentSum + stones[i],
                target,
                dp
            );
        }

        return dp[i][currentSum] = max(take, skip);
    }


    int lastStoneWeightII(vector<int>& stones) {

        int total = 0;

        for(int x : stones)
            total += x;

        int target = total / 2;

        vector<vector<int>> dp(
            stones.size(),
            vector<int>(target + 1, -1)
        );

        int best = solve(
            stones,
            0,
            0,
            target,
            dp
        );

        return total - 2 * best;
    }
};


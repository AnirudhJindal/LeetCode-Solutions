class Solution {
public:

    bool recurse(vector<int>& nums, int target, int curr, int i,
                 vector<vector<int>>& dp) {

        if (curr == target)
            return true;

        if (i >= nums.size() || curr > target)
            return false;

        if (dp[i][curr] != -1)
            return dp[i][curr];

        return dp[i][curr] =
            recurse(nums, target, curr + nums[i], i + 1, dp) ||
            recurse(nums, target, curr, i + 1, dp);
    }

    bool canPartition(vector<int>& nums) {

        int total = 0;
        for (int x : nums)
            total += x;

        if (total % 2 != 0)
            return false;

        int target = total / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return recurse(nums, target, 0, 0, dp);
    }
};
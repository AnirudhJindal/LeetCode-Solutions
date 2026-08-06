class Solution {
public:
    int robHouse(vector<int>& nums, int start, int end) {

        int n = end - start + 1;

        vector<int> dp(n);

        dp[0] = nums[start];

        if (n == 1)
            return dp[0];

        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: Rob from house 0 to n-2
        int case1 = robHouse(nums, 0, n - 2);

        // Case 2: Rob from house 1 to n-1
        int case2 = robHouse(nums, 1, n - 1);

        return max(case1, case2);
    }
};
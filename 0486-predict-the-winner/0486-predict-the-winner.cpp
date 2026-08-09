class Solution {
public:

    int dp(vector<int>& nums, int i, int j,
           vector<vector<int>>& memo) {

        if(i == j)
            return nums[i];

        if(memo[i][j] != INT_MIN)
            return memo[i][j];

        int left = nums[i] - dp(nums, i + 1, j, memo);

        int right = nums[j] - dp(nums, i, j - 1, memo);

        return memo[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> memo(
            n, vector<int>(n, INT_MIN)
        );

        int difference = dp(nums, 0, n - 1, memo);

        return difference >= 0;
    }
};
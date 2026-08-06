class Solution {
public:

    int solve(vector<int>& nums, int target, int i,
              vector<vector<int>>& dp , int sum) {

        // base cases

        if(i == nums.size()){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if (target > sum || target < -sum)
    return 0;

        if (dp[i][target+sum] != -1)
            return dp[i][target+sum];

        // take (+)
          int add = solve(nums, target-nums[i], i+1, dp , sum);


        // take (-)
          int sub = solve(nums, target+nums[i], i+1, dp,sum);

        // return dp[i][target]
        return dp[i][target+sum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        // declare dp
        int sum  = 0;
        for(int x : nums){
            sum+=x;
        }

        vector<vector<int>>dp(nums.size()+1 , vector<int>(2*sum+1 , -1));


        return solve(nums, target, 0, dp ,  sum);
    }
};
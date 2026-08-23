class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k %= n;

        vector<int> ans(n);

        int count = 0;

        for(int i = k; count < n; i = (i + 1) % n) {
            ans[i] = nums[count];
            count++;
        }

        nums = ans;
    }
};
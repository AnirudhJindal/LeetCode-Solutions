class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int sum  = 0 ;
        for(int x : nums){
            sum+=x;
        }
        int ans = 0;

       int lsum = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            lsum += nums[i];
            if(abs(sum - 2*lsum)%2 == 0) ans++;
        }

        return ans;
        
    }
};
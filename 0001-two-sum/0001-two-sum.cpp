class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       unordered_map<int , int> map;

     for(int i = 0 ; i<nums.size() ; i++){

        int remain = target - nums[i];
        if(map.find(remain) != map.end()){
            return {i , map[remain]};
        }
        map[nums[i]] = i;

        
     }
        return {-1 ,-1 };
    }
};
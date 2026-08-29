class Solution {
public:
    bool checkIfPangram(string sentence) {

        unordered_set<int>ans;

        for(auto x : sentence){
            if(!ans.count(x)){
                ans.insert(x);
            }
        }

        if(ans.size() == 26) return true;
        return false;
        
    }
};
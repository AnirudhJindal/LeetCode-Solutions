class Solution { 
public: 
    int firstUniqChar(string s) { 
        unordered_map<char, int> mp; 
        unordered_map<char, int> idx; 

        for(auto x : s) { 
            mp[x]++; 
        } 

        for(int i = 0; i < s.size(); i++) { 
            idx[s[i]] = i; 
        } 

        int ans = INT_MAX; 

        for(auto [key, count] : mp) { 
            if(count == 1) { 
                ans = min(idx[key], ans); 
            } 
        } 

        if(ans == INT_MAX) return -1;

        return ans; 
    } 
};
class Solution {
public:

    bool solve(string &s,
               unordered_set<string> &seen,
               int start,
               vector<int> &dp) {

        if (start == s.size())
            return true;

        if (dp[start] != -1)
            return dp[start];

        string word = "";

        for (int i = start; i < s.size(); i++) {

            word += s[i];

            if (seen.count(word)) {

                if (solve(s, seen, i + 1, dp))
                    return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> seen;

        for (string word : wordDict)
            seen.insert(word);

        vector<int> dp(s.size(), -1);

        return solve(s, seen, 0, dp);
    }
};
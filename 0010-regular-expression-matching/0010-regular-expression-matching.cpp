class Solution {
public:

    bool solve(int i, int j, string& s, string& p,
               vector<vector<int>>& dp) {

        // Both strings finished
        if (i == s.size() && j == p.size())
            return true;

        // Pattern finished but string is not
        if (j == p.size())
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = (i < s.size() &&
                     (s[i] == p[j] || p[j] == '.'));

        // Next character is *
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Don't use x*
            bool notTake = solve(i, j + 2, s, p, dp);

            // Use x* if current character matches
            bool take = match && solve(i + 1, j, s, p, dp);

            return dp[i][j] = take || notTake;
        }

        // Normal character
        if (match)
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        vector<vector<int>> dp(
            s.size() + 1,
            vector<int>(p.size() + 1, -1)
        );

        return solve(0, 0, s, p, dp);
    }
};
class Solution {
public:

    int help(vector<string>& digits,
             string &s,
             int index,
             bool tight,
             vector<vector<int>>& dp) {

        if (index == s.size())
            return 1;

        if (dp[index][tight] != -1)
            return dp[index][tight];

        int limit = tight ? s[index] - '0' : 9;

        int ans = 0;

        for (int i = 0; i < digits.size(); i++) {

            int digit = stoi(digits[i]);

            if (digit > limit)
                break;

            bool newTight = tight && (digit == s[index] - '0');

            ans += help(
                digits,
                s,
                index + 1,
                newTight,
                dp
            );
        }

        return dp[index][tight] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {

        string s = to_string(n);

        int nlen = s.size();
        int t = digits.size();

        int ans = 0;

        // Count all numbers having fewer digits
        for (int i = 1; i < nlen; i++) {
            ans += pow(t, i);
        }

        // Count numbers having same number of digits
        vector<vector<int>> dp(
            nlen,
            vector<int>(2, -1)
        );

        ans += help(digits, s, 0, true, dp);

        return ans;
    }
};
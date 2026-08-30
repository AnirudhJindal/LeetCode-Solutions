class Solution {
public:

    int f(string &s, int idx, bool tight, bool repetition, bool lz, int mask,
          vector<vector<vector<vector<vector<int>>>>>& dp) {

        // base case
        if(idx == s.size())
            return repetition;

        // already calculated
        if(dp[idx][tight][repetition][lz][mask] != -1)
            return dp[idx][tight][repetition][lz][mask];

        int lb = 0;
        int ub = tight ? s[idx] - '0' : 9;

        int res = 0;

        for(int dig = lb; dig <= ub; dig++) {

            if(lz && dig == 0) {

                res += f(
                    s,
                    idx + 1,
                    tight && dig == ub,
                    repetition,
                    1,
                    mask,
                    dp
                );

            }
            else {

                bool isDigitUsed = 1 & (mask >> dig);

                res += f(
                    s,
                    idx + 1,
                    tight && dig == ub,
                    repetition || isDigitUsed,
                    0,
                    mask | (1 << dig),
                    dp
                );
            }
        }

        return dp[idx][tight][repetition][lz][mask] = res;
    }

    int numDupDigitsAtMostN(int n) {

        string s = to_string(n);

        vector<vector<vector<vector<vector<int>>>>> dp(
            s.size(),
            vector<vector<vector<vector<int>>>>
            (2,
                vector<vector<vector<int>>>
                (2,
                    vector<vector<int>>
                    (2,
                        vector<int>(1 << 10, -1)
                    )
                )
            )
        );

        return f(s, 0, 1, 0, 1, 0, dp);
    }
};
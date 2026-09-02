class Solution {
public:

    long long recurse(
        string &s,
        int idx,
        bool tight,
        bool lz,
        int sum,
        int min_sum,
        int max_sum,
        vector<vector<vector<vector<long long>>>> &dp
    ) {

        // base case
        if (idx == s.size()) {
            return (sum >= min_sum && sum <= max_sum);
        }

        if (dp[idx][tight][lz][sum] != -1)
            return dp[idx][tight][lz][sum];

        int digit = s[idx] - '0';

        int limit;

        if (tight)
            limit = digit;
        else
            limit = 9;

        long long ans = 0;

        for (int d = 0; d <= limit; d++) {

            // leading zero
            if (d == 0 && lz) {

                ans += recurse(
                    s,
                    idx + 1,
                    tight && (d == digit),
                    true,
                    sum,
                    min_sum,
                    max_sum,
                    dp
                );

            }
            else {

                // no need to continue if sum already too large
                if (sum + d > max_sum)
                    continue;

                ans += recurse(
                    s,
                    idx + 1,
                    tight && (d == digit),
                    false,
                    sum + d,
                    min_sum,
                    max_sum,
                    dp
                );
            }

            ans %= 1000000007;
        }

        return dp[idx][tight][lz][sum] = ans;
    }


    long long solve(
        string s,
        int min_sum,
        int max_sum
    ) {

        vector<vector<vector<vector<long long>>>> dp(
            s.size(),
            vector<vector<vector<long long>>>(
                2,
                vector<vector<long long>>(
                    2,
                    vector<long long>(410, -1)
                )
            )
        );

        return recurse(
            s,
            0,
            true,
            true,
            0,
            min_sum,
            max_sum,
            dp
        );
    }


    int count(
        string num1,
        string num2,
        int min_sum,
        int max_sum
    ) {

        // f(num2)
        long long ans = solve(
            num2,
            min_sum,
            max_sum
        );

        // num1 - 1
        int i = num1.size() - 1;

        while (i >= 0 && num1[i] == '0') {
            num1[i] = '9';
            i--;
        }

        if (i >= 0)
            num1[i]--;

        // f(num1 - 1)
        ans -= solve(
            num1,
            min_sum,
            max_sum
        );

        ans %= 1000000007;

        if (ans < 0)
            ans += 1000000007;

        return ans;
    }
};
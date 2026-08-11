class Solution {
public:

    int MOD = 1e9 + 7;

    long long recurse(int n, int i, int j,
                      vector<vector<vector<long long>>>& dp,
                      vector<vector<int>>& cell) {

        // Invalid cell
        if(i < 0 || i >= 4 || j < 0 || j >= 3 || cell[i][j] == -2)
            return 0;

        // One digit remaining
        if(n == 1)
            return 1;

        // Already calculated
        if(dp[n][i][j] != -1)
            return dp[n][i][j];

        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, 2, -2, -1, 1};

        long long ans = 0;

        for(int move = 0; move < 8; move++) {

            int nx = i + dx[move];
            int ny = j + dy[move];

            ans += recurse(n - 1, nx, ny, dp, cell);

            ans %= MOD;
        }

        return dp[n][i][j] = ans;
    }


    int knightDialer(int n) {

        vector<vector<int>> cell(
            4,
            vector<int>(3, 0)
        );

        // Invalid positions
        cell[3][0] = -2;
        cell[3][2] = -2;

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(
                4,
                vector<long long>(3, -1)
            )
        );

        long long ans = 0;

        // Start from every valid digit
        for(int i = 0; i < 4; i++) {

            for(int j = 0; j < 3; j++) {

                if(cell[i][j] != -2) {

                    ans += recurse(n, i, j, dp, cell);

                    ans %= MOD;
                }
            }
        }

        return ans;
    }
};
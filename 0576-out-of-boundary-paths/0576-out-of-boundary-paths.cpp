class Solution {
public:

    int MOD = 1e9 + 7;

    int recurse(int m, int n,
                int i, int j,
                int moves,
                vector<vector<vector<int>>>& dp) {

        // We went outside the grid
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;

        // No moves left, but still inside
        if(moves == 0)
            return 0;

        // Already calculated
        if(dp[moves][i][j] != -1)
            return dp[moves][i][j];

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        long long ans = 0;

        for(int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            ans += recurse(
                m,
                n,
                ni,
                nj,
                moves - 1,
                dp
            );

            ans %= MOD;
        }

        return dp[moves][i][j] = ans;
    }


    int findPaths(int m, int n,
                  int maxMove,
                  int startRow,
                  int startColumn) {

        vector<vector<vector<int>>> dp(
            maxMove + 1,
            vector<vector<int>>(
                m,
                vector<int>(n, -1)
            )
        );

        return recurse(
            m,
            n,
            startRow,
            startColumn,
            maxMove,
            dp
        );
    }
};
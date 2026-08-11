class Solution {
public:

    double recurse(int n,
                   int k,
                   int row,
                   int column,
                   vector<vector<vector<double>>>& dp) {

        // Knight went outside the board
        if(row < 0 || row >= n || column < 0 || column >= n)
            return 0;

        // No moves remaining and knight is still on board
        if(k == 0)
            return 1;

        // Already calculated
        if(dp[k][row][column] != -1)
            return dp[k][row][column];

        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, 2, -2, -1, 1};

        double ans = 0;

        for(int move = 0; move < 8; move++) {

            int nx = row + dx[move];
            int ny = column + dy[move];

            double prob = 1.0 / 8.0;

            ans += prob * recurse(
                n,
                k - 1,
                nx,
                ny,
                dp
            );
        }

        return dp[k][row][column] = ans;
    }


    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>> dp(
            k + 1,
            vector<vector<double>>(
                n,
                vector<double>(n, -1)
            )
        );

        return recurse(
            n,
            k,
            row,
            column,
            dp
        );
    }
};
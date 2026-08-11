class Solution {
public:

    int transverse(vector<vector<int>>& graph,
                   vector<vector<int>>& dp,
                   int i,
                   int j) {

        int n = graph.size();
        int m = graph[0].size();

        // Destination cell
        if(i == n - 1 && j == m - 1) {
            return max(1, 1 - graph[i][j]);
        }

        // Already calculated
        if(dp[i][j] != INT_MIN)
            return dp[i][j];

        int right = INT_MAX;
        int down = INT_MAX;

        // Move right
        if(j + 1 < m) {
            right = transverse(graph, dp, i, j + 1);
        }

        // Move down
        if(i + 1 < n) {
            down = transverse(graph, dp, i + 1, j);
        }

        // Choose the path requiring less HP
        int need = min(right, down);

        // Account for current cell
        dp[i][j] = max(1, need - graph[i][j]);

        return dp[i][j];
    }


    int calculateMinimumHP(vector<vector<int>>& graph) {

        int n = graph.size();
        int m = graph[0].size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, INT_MIN)
        );

        return transverse(graph, dp, 0, 0);
    }
};
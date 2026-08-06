class Solution {
public:
    vector<int> boxes;
    vector<vector<vector<int>>> dp;

   int dfs(int l, int r, int k) {

    if (l > r) return 0;

    if (dp[l][r][k] != -1)
        return dp[l][r][k];

    int L = l, K = k;   // save original state

    while (l + 1 <= r && boxes[l] == boxes[l + 1]) {
        l++;
        k++;
    }

    int ans = (k + 1) * (k + 1) + dfs(l + 1, r, 0);

    for (int m = l + 1; m <= r; m++) {
        if (boxes[m] == boxes[l] && boxes[m - 1] != boxes[m]) {
            ans = max(ans,
                      dfs(l + 1, m - 1, 0) +
                      dfs(m, r, k + 1));
        }
    }

    return dp[L][r][K] = ans;
}

    int removeBoxes(vector<int>& b) {

        boxes = b;

        int n = boxes.size();

        dp = vector<vector<vector<int>>>(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );

        return dfs(0, n - 1, 0);
    }
};
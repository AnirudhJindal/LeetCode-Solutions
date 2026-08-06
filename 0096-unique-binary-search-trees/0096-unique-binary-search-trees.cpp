class Solution {
public:
    int numTrees(int n) {

        // catalan tree

        // so basically its like if u have 5 modes for bst what type of tress u
        // can maek one can be like one on one side and three on the other side
        // then two and two and then again three on left side and one on right
        // adn tehn add oall o it mostly a one d dp question

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
      if (n >= 1) dp[1] = 1;
if (n >= 2) dp[2] = 2;
if (n >= 3) dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int> friends(n, 0);   // 0 = alive, -1 = eliminated
        int eliminated = 0;
        int i = 0;

        while (eliminated < n - 1) {

            int steps = 0;

            // Move until we reach the k-th alive friend
            while (steps < k) {
                if (friends[i] == 0)
                    steps++;

                if (steps == k)
                    break;

                i = (i + 1) % n;
            }

            // Eliminate that friend
            friends[i] = -1;
            eliminated++;

            // Move to the next alive friend
            while (friends[i] == -1)
                i = (i + 1) % n;
        }

        // Find the last remaining friend
        for (int j = 0; j < n; j++) {
            if (friends[j] == 0)
                return j + 1;
        }

        return -1;
    }
};
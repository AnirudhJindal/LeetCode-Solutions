class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [distance, xcd, ycd] = pq.top(); pq.pop();

            if (distance > dist[xcd][ycd]) continue;

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int nx = xcd + dr[i];
                int ny = ycd + dc[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int effort = max(distance, abs(heights[nx][ny] - heights[xcd][ycd]));

                if (effort < dist[nx][ny]) {
                    dist[nx][ny] = effort;
                    pq.push({effort, nx, ny});
                }
            }
        }

        return dist[n-1][m-1];
    }
};
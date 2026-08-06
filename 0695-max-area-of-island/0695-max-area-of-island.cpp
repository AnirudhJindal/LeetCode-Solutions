class Solution {
public:

    int bfs(vector<vector<int>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        q.push({r, c});

        grid[r][c] = 0;

        int area = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()) {

            auto front = q.front();
            q.pop();

            int x = front.first;
            int y = front.second;

            for(int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if(
                    nx >= 0 &&
                    ny >= 0 &&
                    nx < rows &&
                    ny < cols &&
                    grid[nx][ny] == 1
                ) {

                    grid[nx][ny] = 0;

                    q.push({nx, ny});

                    area++;
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        for(int r = 0; r < rows; r++) {

            for(int c = 0; c < cols; c++) {

                if(grid[r][c] == 1) {

                    int currentArea = bfs(grid, r, c);

                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};
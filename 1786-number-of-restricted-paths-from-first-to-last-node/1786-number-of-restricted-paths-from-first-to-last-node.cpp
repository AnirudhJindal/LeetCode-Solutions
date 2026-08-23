class Solution {
public:

    const int MOD = 1e9 + 7;

    int dfs(int cur,
            int n,
            vector<vector<pair<int, int>>>& graph,
            vector<int>& minDist,
            vector<int>& dp) {

        // Reached destination
        if(cur == n)
            return 1;

        // Already calculated
        if(dp[cur] != -1)
            return dp[cur];

        int ways = 0;

        for(auto& [nei, cost] : graph[cur]) {

            // Restricted path condition
            if(minDist[nei] < minDist[cur]) {

                ways = (ways + dfs(nei, n, graph, minDist, dp)) % MOD;
            }
        }

        return dp[cur] = ways;
    }


    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        // Build graph
        vector<vector<pair<int, int>>> graph(n + 1);

        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }


        // ---------------- Dijkstra ----------------

        vector<int> minDist(n + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        minDist[n] = 0;
        pq.push({0, n});

        while(!pq.empty()) {

            int dist = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if(dist != minDist[cur])
                continue;

            for(auto& [nei, cost] : graph[cur]) {

                if(minDist[nei] > dist + cost) {

                    minDist[nei] = dist + cost;

                    pq.push({minDist[nei], nei});
                }
            }
        }


        // ---------------- DP + Memoisation ----------------

        vector<int> dp(n + 1, -1);

        return dfs(1, n, graph, minDist, dp);
    }
};
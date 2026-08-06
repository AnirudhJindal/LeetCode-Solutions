class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        vector<int> dist(n ,INT_MAX);
        dist[src] = 0;

        for(int i =0 ; i<k+1 ; i++){
            vector<int> temp = dist;

            for(auto x : flights){
                int from = x[0];
                int to = x[1];
                int effort = x[2];



                if( dist[from] != INT_MAX && dist[from] + effort <temp[to]){
                    temp[to] = dist[from] + effort;
                }
            }

             dist = temp;



        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];







        
    }
};
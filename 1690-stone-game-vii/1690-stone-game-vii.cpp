class Solution {
public:



   int diffrence(int i  , int  j ,vector<int>& stones , int sum , vector<vector<int>>&dp ){
  if(i>=j) return 0;

  if(dp[i][j] != -1) return dp[i][j];

int left = (sum-stones[i]) - diffrence(i+1 , j , stones,sum-stones[i] , dp);
int right = (sum-stones[j]) - diffrence(i , j-1 , stones, sum-stones[j],dp);

return dp[i][j] =  max(left, right);


   }


    int stoneGameVII(vector<int>& stones) {


        vector<vector<int>>dp(stones.size() , vector<int>(stones.size() ,-1));


    int SUM = 0;

    for(int x : stones){
        SUM+=x;
    }

    return diffrence(0,stones.size()-1 , stones ,  SUM , dp );

    







        
    }
};
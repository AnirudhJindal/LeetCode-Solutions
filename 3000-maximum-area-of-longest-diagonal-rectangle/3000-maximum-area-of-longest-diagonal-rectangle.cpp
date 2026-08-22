class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        pair<double, int> maxi;
        maxi.first = 0;
        maxi.second = 0;

        for (auto c : dimensions) {

            int len = c[0];
            int wid = c[1];

            double diag = pow(len * len + wid * wid, 0.5);

            if (maxi.first < diag) {
                maxi.first = diag;
                maxi.second = len * wid;
            }
            else if (maxi.first == diag) {

                if (maxi.second < len * wid) {
                    maxi.second = len * wid;
                }
            }
        }

        return maxi.second;
    }
};
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;

        for(auto s : sentences) {
            int spaces = 0;

            for(auto c : s) {
                if(c == ' ') {
                    spaces++;
                }
            }

            ans = max(ans, spaces + 1);
        }

        return ans;
    }
};
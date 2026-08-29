class Solution {
public:
    int countDigits(int num) {
        string s = to_string(num);
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            int n = s[i] - '0';

            if(num % n == 0) {
                ans++;
            }
        }

        return ans;
    }
};
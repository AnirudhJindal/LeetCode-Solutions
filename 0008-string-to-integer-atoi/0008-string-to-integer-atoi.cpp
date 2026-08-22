class Solution {
public:
    int myAtoi(string s) {

        long long ans = 0;
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        bool negative = false;

        // Sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-')
                negative = true;
            i++;
        }

        // Read digits
        while (i < n && isdigit(s[i])) {

            ans = ans * 10 + (s[i] - '0');

            // Prevent overflow
            if (!negative && ans > INT_MAX)
                return INT_MAX;

            if (negative && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        if (negative)
            ans = -ans;

        return ans;
    }
};
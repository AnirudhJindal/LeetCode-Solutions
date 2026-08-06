class Solution {
public:
    vector<string> ans;

    void dp(string &s,
            unordered_set<string> &seen,
            int start,
            string sentence) {

        // Base case
        if (start == s.size()) {
            sentence.pop_back();      // remove last space
            ans.push_back(sentence);
            return;
        }

        string word = "";

        for (int i = start; i < s.size(); i++) {

            word += s[i];

            if (seen.count(word)) {

                dp(s,
                   seen,
                   i + 1,
                   sentence + word + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> seen(wordDict.begin(), wordDict.end());

        dp(s, seen, 0, "");

        return ans;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> reCalling(s.length(), -1);
        return dfs(s, dict, 0, reCalling);
    }

private:
    bool dfs(const string& s, const unordered_set<string>& dict, int i, vector<int>& reCalling) {
        if (i == s.length()) return true;
        if (reCalling[i] != -1) return reCalling[i];
        
        for (int j = i; j < s.length(); ++j) {
            string word = s.substr(i, j - i + 1);
            if (dict.count(word) && dfs(s, dict, j + 1, reCalling)) {
                return reCalling[i] = true;
            }
        }
        
        return reCalling[i] = false;
    }
};
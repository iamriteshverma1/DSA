class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                depth++;
            else {
                depth--;

                if(s[i - 1] == '(')
                    ans += pow(2, depth);
            }
        }
        return ans;
    }
};
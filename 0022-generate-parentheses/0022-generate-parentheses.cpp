class Solution {

    vector<string> res;
    string s;

    void backtrack(int open, int close, int n) {

        if(open == n && close == n) {
            res.push_back(s);
            return;
        }

        if(open < n) {
            s.push_back('(');
            backtrack(open + 1, close, n);
            s.pop_back();
        }

        if(close < open) {
            s.push_back(')');
            backtrack(open , close + 1, n);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;         
    }
};
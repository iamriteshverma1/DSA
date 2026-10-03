/*
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int>st; // used to save the index
        st.push(-1); // that will tell from where the valid paranthesis starts
        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(')
                st.push(i); //opewnnign then push th eindex inside stack
            else {

                st.pop(); // if closing then pop it up
                if(st.empty()) 
                    st.push(i); // if the stack is mempty that mean there is invalid paranthesis so let initialize with new index fro mthere the new valid paranthesis start.
                else{
                    ans = max(ans, i - st.top());
                 }
            }
        }
        return ans;
    }
};

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        int open = 0;
        int close = 0;

        // Left to Right
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                longest = max(longest, close * 2);
            }
            else if (close > open) {
                open = 0;
                close = 0;
            }
        }

        open = 0;
        close = 0;

        // Right to Left
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                longest = max(longest, open * 2);
            }
            else if (open > close) {
                open = 0;
                close = 0;
            }
        }

        return longest;
    }
};
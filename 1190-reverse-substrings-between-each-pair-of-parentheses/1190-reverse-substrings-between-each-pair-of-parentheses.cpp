class Solution {
    stack<int> st;
    void reverse(string& s, int j) {
        int i = st.top();
        st.pop();
        while(i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

public:
    string reverseParentheses(string s) {
        int n = s.size();
        for(int j = 0; j < n; j++) {
            if(s[j] == '(') {
                st.push(j);
            }
            if(s[j] == ')') {
                reverse(s, j);
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == ')' || s[i] == '(')
                continue;
            ans +=s[i];

        }
        return ans;
    }
};
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
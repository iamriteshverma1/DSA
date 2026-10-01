class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c : s) {
            if(mp.find(c) != mp.end()) {
                if(st.empty() || st.top() != mp[c]) {
                    return false;
                }
                st.pop();
            } 
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
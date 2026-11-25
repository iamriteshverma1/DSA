
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int x : asteroids) {
            if(st.empty()) {
                st.push(x);
                continue;
            }
            bool check = true;
            while(!st.empty()) {
                if((st.top() > 0 && x > 0) || (st.top() < 0 && x < 0) || st.top() < 0 && x > 0) {
                    check = true;
                    break;
                }
                else if((st.top() > 0 && x < 0) || (st.top() < 0 && x > 0)) {
                    if(abs(st.top()) == abs(x)) { 
                        st.pop();
                        check = false;
                        break;
                    }
                    else if(abs(st.top()) > abs(x)){
                        check = false;
                        break;
                    }
                    else {
                        st.pop();
                        check = true;
                    }
                }
            }
            if(check)
                st.push(x);

        }

        int n = st.size();
        vector<int> ans(n);
        int i = n - 1;
        while(!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }

        return ans;
    }
};
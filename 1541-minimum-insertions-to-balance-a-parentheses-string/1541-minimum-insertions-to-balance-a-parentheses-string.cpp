class Solution {
public:
    int minInsertions(string s) {
        int totalOpen = 0;
        int ans = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {

            if(s[i] ==  '(')
                totalOpen++;
            
            else {
                if( i + 1 < n && s[i + 1] == ')')
                    i++;
                
                else
                    ans++;
                
                if(totalOpen > 0)
                    totalOpen--;
                else
                    ans++;
            }
        }
        return ans  + 2 * totalOpen;
    }
}; 
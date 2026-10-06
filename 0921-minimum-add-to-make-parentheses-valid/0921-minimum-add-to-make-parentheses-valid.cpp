class Solution {
public:
    int minAddToMakeValid(string s) {
        int totalClose = 0;
        int totalOpen = 0;
        for(char c: s) {
            if(c == '(')
                totalOpen++;
            else {
                if(totalOpen) {
                    totalOpen--;
                    totalClose--;
                }
                totalClose++;
            }
        }

        return totalClose + totalOpen;
    }
};
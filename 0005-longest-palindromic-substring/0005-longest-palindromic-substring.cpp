// ==================   brute force ====================

/*
class Solution {
public:

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string temp = s.substr(i, j - i + 1);
                if (isPalindrome(temp)) {
                    if (temp.length() > ans.length()) {
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        
        int start = 0;
        int maxLength  = 0;
        for(int i = 0; i < s.length(); i++) {
            int len1 = centerCheck(s, i, i);
            int len2 = centerCheck(s, i, i + 1);
            int len = max(len1, len2);
            if(len > maxLength) {
                maxLength = len;
                start = i - (len - 1)/2;
            }
        }
        return s.substr(start, maxLength);
        
    }
private:
    int centerCheck(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
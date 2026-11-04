class Solution {
public:

    int LCS(string& text1, int i, string& text2, int j, vector<vector<int>>& L) {
        if(i == 0 || j == 0) {
            L[i][j] = 0;
            return 0;
        }

        if(L[i][j] != -1)
            return L[i][j];

        if(text1[i] == text2[j]) {
            L[i][j] = 1 + LCS(text1, i - 1, text2, j - 1, L);
        }
        else {
            L[i][j] = max(LCS(text1, i - 1, text2, j, L), LCS(text1, i, text2, j - 1, L));
        }

        return L[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        text1 = '#' + text1;
        text2 = '#' + text2;
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>L(n, vector<int>(m, -1));

        int ans = LCS(text1, n - 1, text2, m - 1, L);

        return ans;
    }
};
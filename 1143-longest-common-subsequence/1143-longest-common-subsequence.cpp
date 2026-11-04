class Solution {
public :
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        int L[m + 1][n + 1];
        for(int i = 0; i <= n; i++){
            L[0][i] = 0; 
        }
        for(int i = 0; i <= m; i++){
            L[i][0] = 0; 
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <=n; j++) {
                if(text1[i - 1] == text2[j - 1])
                    L[i][j] = L[i -1][j -1] + 1;
                else
                    L[i][j] = max(L[i -1][j], L[i][j - 1]);
            }
        }
        return L[m][n];
    }
};

//Recursion
class Solution1a {
public:

    int LCS(string& text1, int i, string& text2, int j) {
        if(i < 0 || j < 0) {
            return 0;
        }

        if(text1[i] == text2[j]) {
            return 1 + LCS(text1, i - 1, text2, j - 1);
        }
        else {
            return max(LCS(text1, i - 1, text2, j), LCS(text1, i, text2, j - 1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        int ans = LCS(text1, n - 1, text2, m - 1);

        return ans;
    }
};


// Memoization
class Solution1b {
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
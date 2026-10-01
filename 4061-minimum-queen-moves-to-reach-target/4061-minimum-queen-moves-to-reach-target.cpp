class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int i = source[0];
        int j = source[1];

        int k = target[0];
        int l = target[1];

        if(i == k && j == l)
            return 0;
        else if(i == k || j == l)
            return 1;
        else if(abs(i - k) == abs(j - l))
            return 1;
        return 2;
    }
};
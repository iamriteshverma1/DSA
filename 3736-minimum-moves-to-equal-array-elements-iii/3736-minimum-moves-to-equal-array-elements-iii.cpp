class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int maxV = *max_element(nums.begin(), nums.end());

        int moves = 0;
        for(int x : nums) {
            moves += maxV - x;
        }

        return moves;
    }
};
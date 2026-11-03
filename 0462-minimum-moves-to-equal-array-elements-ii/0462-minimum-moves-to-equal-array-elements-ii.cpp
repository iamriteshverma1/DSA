class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int median = nums[n/2];

        int moves = 0;
        for(int x : nums) {
            if(x > median)
                moves += x - median;
            else if(x < median) {
                moves += median - x;
            }
        }

        return moves;
    }
};
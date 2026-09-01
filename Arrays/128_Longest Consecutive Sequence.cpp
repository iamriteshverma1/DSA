
// ===================== BRUTE FORCE ==========================
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int longest = 1;
        int localLarge = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            if(nums[i - 1] == nums[i])  
                continue;

            else if(nums[i - 1] + 1 == nums[i])
                localLarge += 1;

            else{
                longest = max(longest, localLarge);
                localLarge = 1;
            }
        }
        return max(longest, localLarge);
    }
};

/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1)
            return false;
        for(int i = 0;  i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size() && j <= i + k; j++) {
                if(nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i]) && i - seen[nums[i]] <= k) {
                return true;
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};;
// ======================= BRUTE FORCE SOLUTION ===========================
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];  // yaah compleemnt nikalinge or check karinge map me hai ya nhi pahle se agar hua toh uske sath return kara dainge index ko

            if (mp.find(complement) != mp.end()) { //check for element
                return {mp[complement], i}; // if found return the answer
            }
            mp[nums[i]] = i; // if nto found then add the element to the map
        }
        return {};
    }
};
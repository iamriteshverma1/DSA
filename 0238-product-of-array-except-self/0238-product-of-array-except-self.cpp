class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        int  pre = 1;
        int post = 1;
        int i = 0;
        int j = nums.size() - 1;
        while(i < nums.size()) {
            pre *= nums[i];
            post *= nums[j];
            prefix[i++] = pre;
            suffix[j--] = post;
            

        }

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0){
                nums[i] = suffix[i + 1];
            }
            else if(i == nums.size() - 1) {
                nums[i] = prefix[i -1];
            }
            else
                nums[i] = prefix[i - 1] * suffix[i + 1];
        }

        return nums;
        
    }
};
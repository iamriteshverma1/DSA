class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(count == 3)
                return nums[i + 1];
            if(i == n- 1)
                count = 1;
            else if(nums[i] != nums[i + 1])
                count +=1;
        }
        if(count == 3)
            return nums[0];
        
        return nums[n - 1];
        
    }

};
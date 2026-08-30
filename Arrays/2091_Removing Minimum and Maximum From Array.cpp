class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN; 
        int n = nums.size();
        int index1;
        int index2;
        for(int i = 0; i < n; i++){
            if(minValue > nums[i]){
                index1 = i;
                minValue = nums[i];
            }
            if(maxValue < nums[i]){
                index2 = i;
                maxValue = nums[i];
            }
        }
        int left = min(index1, index2);
        int right = max(index1, index2);

        int ans1 = right + 1;
        int ans2 = left + 1 + n - right;
        int ans3 = n - left;

        return ans1 < ans2 && ans1 < ans3 ? ans1 : ans2 < ans3 ? ans2 : ans3;  

        
    }
};

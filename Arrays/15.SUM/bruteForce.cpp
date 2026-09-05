class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    if( nums[i] + nums[j] + nums[k] == 0)   
                        st.insert({nums[i], nums[j] , nums[k]});
                }
            }
        }
        for(auto x : st)
            ans.push_back(x);
        return ans;
    }
};

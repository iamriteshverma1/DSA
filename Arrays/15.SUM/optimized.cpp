class Solution { 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            set<int> st;
            for(int j = i + 1; j < n; j++){
                int third = - (nums[i] + nums[j]);
                if(st.find(third) != st.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                st.insert(nums[j]);
            }
        }

        vector<vector<int>> result(ans.begin(), ans.end());
        return result ;
    }
};

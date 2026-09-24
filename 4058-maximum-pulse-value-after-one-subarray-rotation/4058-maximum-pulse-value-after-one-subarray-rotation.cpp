class Solution {
public:
    long long maxValue(vector<int>& nums) {
        long long prefix = 0;
        long long original = 0;
        long long mn[2] = {0, LLONG_MIN};
        long long minSum = LLONG_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                prefix += nums[i];
            else 
                prefix -= nums[i];
            
            int parity = (i + 1) % 2;
            
            if(mn[parity] != LLONG_MIN) {
                minSum = min(minSum, prefix - mn[parity]);
            }
            mn[parity] = max(mn[parity], prefix);

        }
        original = prefix;
        long long ans = original;
        if(minSum != LLONG_MAX)
            ans = max(ans, original - 2*minSum);
        return ans;
    }
};
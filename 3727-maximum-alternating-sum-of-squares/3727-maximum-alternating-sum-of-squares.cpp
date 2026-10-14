class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sqr;

        for (int x : nums) {
            sqr.push_back(x * x);
        }

        sort(sqr.begin(), sqr.end());

        int n = sqr.size();
        int mid = n / 2;
        long long ans = 0;

        for (int i = 0; i < mid; i++) {
            ans -= sqr[i];
        }

        for (int i = mid; i < n; i++) {
            ans += sqr[i];
        }

        return ans;
    }
};
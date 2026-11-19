/*
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return 0;

        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;

        ans = min(ans, nums[n - 1] - nums[2]);
        ans = min(ans, nums[n - 2] - nums[1]);
        ans = min(ans, nums[n - 3] - nums[0]);
        return ans;
    }
};

*/


class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size() < 4)
            return 0;

        int smallest1 = INT_MAX, smallest2 = INT_MAX, smallest3 = INT_MAX;
        int largest1 = 0, largest2 = 0, largest3 = 0;

        for(int x: nums) {
            if(smallest1 > x) {
                smallest3 = smallest2;
                smallest2 = smallest1;
                smallest1 = x;
            }
            else if(smallest2 > x) {
                smallest3 = smallest2;
                smallest2 = x;
            }
            else if( smallest3 > x)
                smallest3 = x;

            
            if(largest1 < x) {
                largest3 = largest2;
                largest2 = largest1;
                largest1 = x;
            }
            else if(largest2 < x) {
                largest3 = largest2;
                largest2 = x;
            }
            else if(largest3 < x)
                largest3 = x;
        }

        return min({
            largest1 - smallest3,
            largest2 - smallest2,
            largest3 - smallest1
        });
    }
};
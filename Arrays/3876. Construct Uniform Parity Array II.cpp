class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];
        bool hasOdd = false;

        for(int x : nums1){
            if(mn > x)
                mn = x;
            if(x & 1)
                hasOdd = true;
        }
        if(mn & 1)
            return true;

        return !hasOdd;
    }
};

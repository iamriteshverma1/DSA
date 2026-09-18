class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1.begin(), nums1.begin() + m);

        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n && j < m) {
            if(nums2[i] < nums3[j]) {
                nums1[k++] = nums2[i];
                i++;
            }
            else {
                nums1[k++] = nums3[j];
                j++;
            }
        }
        while(i < n) {
            nums1[k++] = nums2[i++];
        }

        while(j < m) {
            nums1[k++] = nums3[j++];
        }
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m; //i pointer ko last element pe bhej diya nums1 ke
        for(int j=0 ; j<n ; j++){
            nums1[i] = nums2[j]; //i ke baad nums2 ke elements ko allocate kardiya
            i++;
        }
        sort(nums1.begin() , nums1.end());
    }
};
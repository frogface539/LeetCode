class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int maxi = INT_MIN;
        int n = arr.size();
        int max1 = arr[n-1] * arr[n-2] * arr[n-3];
        int max2 = arr[0] * arr[1] * arr[n-1];
        return max(max1,max2);
    }
};

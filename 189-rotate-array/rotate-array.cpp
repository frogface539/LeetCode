class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return;
        k = k % n;
        if (k == 0) return;
        // Reverse the first n-k elements
        reverse(arr.begin(), arr.begin() + (n - k));
        // Reverse the last k elements
        reverse(arr.begin() + (n - k), arr.end());
        // Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
};

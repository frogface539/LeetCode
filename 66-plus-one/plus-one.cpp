class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            } else {
                digits[i] = 0;
            }
        }
        
        // If all digits are 9, we need to add a leading 1
        vector<int> res(n + 1, 0);
        res[0] = 1;
        return res;
    }
};

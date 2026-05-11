class Solution {
public:
    int alternateDigitSum(int n) {
        int reversed = 0;
        while (n > 0) {
            reversed = reversed * 10 + (n % 10);
            n = n / 10;
        }

        int res = 0;
        int count = 1;
        while (reversed > 0) {
            int num = reversed % 10;
            if (count % 2 == 0) {
                res -= num;
            } else {
                res += num;
            }
            count++;
            reversed = reversed / 10;
        }
        return res;
    }
};
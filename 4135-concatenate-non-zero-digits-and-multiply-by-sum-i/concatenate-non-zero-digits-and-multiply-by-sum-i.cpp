class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        int sum = 0;
        while(n > 0){
            digits.push_back(n % 10);
            sum += n % 10;
            n /= 10;
        }

        reverse(digits.begin(), digits.end());
        long long num = 0;

        for(int d : digits){
            if(d != 0){
                num = num * 10 + d;
            }
        }

        return num * sum;
    }
};
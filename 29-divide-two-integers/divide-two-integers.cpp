class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long s = 0;
        long long e = dvd;
        long long mid = s + ((e - s) >> 1);
        long long ans = 0;

        while(s <= e){
            if(dvs * mid <= dvd){
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = s + ((e - s) >> 1);
        }

        if((dividend < 0) ^ (divisor < 0)) ans = -ans;
        return (int)ans;
    }
};

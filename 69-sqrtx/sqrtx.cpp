class Solution {
public:
    int mySqrt(int num) {
        int s = 0;
        int e = num;
        long long int mid = s+(e-s)/2;
        int ans = -1;

        while(s <= e){
            mid = s+(e-s)/2;
            long long int prod = mid*mid;
            if(prod < num){
                ans = mid;
                s = mid + 1;
            }

            else if(prod == num){
                return mid;
            }

            else{
                e = mid - 1;
            }
        }
        return ans;
    }
};
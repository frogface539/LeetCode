class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false; 
        }

        if(n == 1){
            return true;
        }

        else{
            if(n % 2 == 0 && isPowerOfTwo(n/2)){
                return true;
            }
        }
        return false;
    }
};
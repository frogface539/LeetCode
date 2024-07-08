class Solution {
public:
    int countPrimes(int n) {
        if(n == 0){
            return 0;
        }
        vector<bool>primes(n , true);
        primes[0] = primes[1] = false;
        int count = 0;
        for(int i=2 ; i<n ; i++){
            if(primes[i] == true){
                count++;

                int j=2*i;
                while(j<n){
                    primes[j] = false;
                    j = j + i;
                }
            }
        }
        return count;
    }
};
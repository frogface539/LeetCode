class Solution {
public:
    int numberOfDivisors(int n){
        int count = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(i * i == n){
                    count++;
                }
                else{
                    count += 2;
                }
            }
        }
        return count;
    }

    int sumOfDivisors(int n){
        int sum = 0;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                if(i * i == n){
                    sum += i;
                }
                else{
                    sum += i + (n / i);
                }
            }
        }
        return sum;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(numberOfDivisors(nums[i]) == 4){
                totalSum += sumOfDivisors(nums[i]);
            }
        }

        return totalSum;
    }
};
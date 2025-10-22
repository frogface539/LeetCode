class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Brute Force
        // int i=0;
        // int j=k-1;
        // int maxSum = INT_MIN;
        // while(j<nums.size()){
        //     int sum = 0;
        //     for(int t=i ; t<=j ; t++){
        //         sum = sum+nums[t];
        //     }
        //     i++;
        //     j++;
        //     maxSum = max(maxSum,sum);
        // }
        // double avg = maxSum/(double)k;
        // return avg;

        // optimal approach
        int i=0;
        int j=k-1;
        int sum = 0;

        for(int t=i; t<=j; t++){
            sum = sum + nums[t];
        }
        j++;
        int maxSum = sum;
        while(j<nums.size()){
            sum = sum - nums[i];
            i++;
            sum = sum + nums[j];
            j++;
            maxSum = max(sum,maxSum);
        }
        return maxSum/(double)k;

    }
};
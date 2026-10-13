class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int n = nums.size();
        vector<int> arr(n);
        int i = n - 1;

        for(int j = 0; j < n; j += 2) {
            arr[j] = nums[i--];
        }

        for(int j = 1; j < n; j += 2) {
            arr[j] = nums[i--];
        }

        long long sum = 0;

        for(int j = 0; j < n; j++) {
            long long square = 1LL * arr[j] * arr[j];

            if(j % 2 == 0) {
                sum += square;
            } else {
                sum -= square;
            }
        }

        return sum;
    }
};
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int j=0;
        int n=arr.size();
        int sum=0;
        int ans=0;

        while(j<n){
            sum += arr[j];

            if(j-i+1 < k){
                j++;
            }

            else if(j-i+1 == k){
                if(sum/k >= threshold){
                    ans++;
                }
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
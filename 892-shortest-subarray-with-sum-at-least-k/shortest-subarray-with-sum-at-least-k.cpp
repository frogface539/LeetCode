class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<long long>prefixSum(n+1,0);

        for(int i=0 ; i<n ; i++){
            prefixSum[i+1] = prefixSum[i] + arr[i];
        }

        deque<int>dq;
        int minLen = INT_MAX;

        for(int j=0 ; j<=n ; j++){
            while(!dq.empty() && prefixSum[j] - prefixSum[dq.front()] >= k){
                minLen = min(minLen, j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefixSum[j] <= prefixSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        return minLen == INT_MAX ? -1:minLen;
    }
};
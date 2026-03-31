class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        vector<pair<int,int>> vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }

        sort(vp.rbegin(), vp.rend()); 

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, ans = 0;

        for(auto &p : vp) {
            int n2 = p.first;
            int n1 = p.second;

            minHeap.push(n1);
            sum += n1;

            if(minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == k) {
                ans = max(ans, sum * n2);
            }
        }

        return ans;
    }
};
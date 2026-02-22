class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;

        //process one window
        for(int i=0 ; i<k ; i++){
            int element = nums[i];
            while(!q.empty() && nums[q.back()] < element){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        //process remaining windows
        for(int i=k ; i<nums.size() ; i++){

            //remove out of window
            if(q.front() < i-k+1){
                q.pop_front();
            }

            // add logic
            int element = nums[i];
            while(!q.empty() && nums[q.back()] < element){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
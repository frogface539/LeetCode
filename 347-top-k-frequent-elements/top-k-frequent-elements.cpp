class compare{
    public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
};


class Solution {
public:
       vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq; 
        vector<pair<int,int>> arr;
        map<int,int> mapp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            mapp[nums[i]]++;
        }

        for(auto i:mapp){
            arr.push_back(i);
        }
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);

            if(pq.size()>k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
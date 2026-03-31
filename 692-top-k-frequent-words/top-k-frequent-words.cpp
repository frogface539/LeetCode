class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto &w : words) {
            mp[w]++;
        }

        auto comp = [](pair<string,int>& a, pair<string,int>& b) {
            if (a.second == b.second)
                return a.first > b.first; 
            return a.second < b.second;   
        };

        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)> pq(comp);

        for(auto &p : mp) {
            pq.push(p);
        }

        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};
class Solution {
public:
    int beautySum(string s) {
        int beautySum = 0;
        map<char,int>mp;

        for(int i=0 ; i<s.size() ; i++){
            mp.clear();
            for(int j=i ; j<s.size() ; j++){
                char ch = s[j];
                mp[ch]++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for(auto element:mp){
                    mini = min(mini,element.second);
                    maxi = max(maxi,element.second);
                }
                beautySum = (maxi - mini) + beautySum;
            }
        }
        return beautySum;
    }
};
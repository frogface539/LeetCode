class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>temp;
        string ans;

        for(int i=0 ; i<s.length() ; i++){
            char currChar = s[i];

            if(!temp.empty() && currChar == temp.back().first){
                temp.back().second++;

                if(temp.back().second == k){
                    temp.pop_back();
                }
            }

            else{
                temp.push_back({currChar,1});
            }
        }

        for(int i=0 ; i<temp.size() ; i++){
            ans.append(temp[i].second, temp[i].first);
        }
        return ans;
    }
};
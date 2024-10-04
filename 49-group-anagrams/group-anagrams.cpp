class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>map;

        for(int i = 0 ; i<strs.size() ; i++){
            string originalString = strs[i];
            string copyString = strs[i];

            sort(copyString.begin() , copyString.end());
            map[copyString].push_back(originalString);  //m[abt] = ["nat" , "tan"]
        }

        vector<vector<string>>ans;
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
    }
};
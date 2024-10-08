class Solution {
public:
    string solver(string s){
        int i = 'a';
        char map[250] = {0};
        for(auto ch:s){
            if(map[ch] == 0){
                map[ch] = i;
                i++;
            }
        }

        for(int j = 0 ; j<s.length() ; j++){
            char ch = s[j];
            s[j] = map[ch];
        }
        return s;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string pattern2 = solver(pattern);
        vector<string>ans;
        for(auto value : words){
            string temp = value;
            string a = solver(temp);
            if(a == pattern2){
                ans.push_back(value);
            }
        }
        return ans;
    }
};
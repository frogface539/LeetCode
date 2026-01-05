class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mapping;
        mapping[' '] = ' ';
        int i=0;
        int start = 'a';

        while(start <= 'z' && i < key.length()){
            char currentKeyIndex = key[i];
            if(mapping.find(currentKeyIndex) != mapping.end()){
                i++;
            }
            else{
                mapping[currentKeyIndex] = start;
                start++;
                i++;
            }
        }

        string ans = "";
        for(int i=0 ; i<message.length() ; i++){
            ans.push_back(mapping[message[i]]);
        }
        return ans;
    }
};
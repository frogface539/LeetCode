class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26);
        //calculate frequencies of all characters
        for(int i = 0 ; i<s.size() ; i++){
            freq[s[i]-'a']++;
        }

        int length = 0;
        for(int i=0 ; i<freq.size() ; i++){
            if(freq[i] % 2 != 0){                 //odd frequencies
                length++;
            }
            else{
                length = length + min(2 , freq[i]);   //even frequencies
            }
        }
        return length;
    }
};
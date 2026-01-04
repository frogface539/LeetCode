class Solution {
public:
    string removeOccurrences(string s, string pattern) {
        while(s.find(pattern) != string::npos){
            s.erase(s.find(pattern),pattern.length());
        }
        return s;
    }
};
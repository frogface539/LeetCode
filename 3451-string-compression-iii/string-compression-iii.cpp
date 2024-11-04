#include <sstream>

class Solution {
public:
    string compressedString(string word) {
        int start = 0;
        ostringstream out; 
        
        for (int i = 1; i <= word.length(); i++) {
            if (i == word.length() || word[i] != word[i - 1]) {
                int count = i - start;

                while (count > 9) {
                    out << "9" << word[start];
                    count = count - 9;
                }
                
                out << count << word[start];
                
                start = i;
            }
        }
        
        return out.str();
    }
};

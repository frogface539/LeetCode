class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {
            bool small = false;
            bool capital = false;

            for(char c : word) {
                if(c == ch)
                    small = true;

                if(c == toupper(ch))
                    capital = true;
            }

            if(small && capital)
                count++;
        }

        return count;
    }
};
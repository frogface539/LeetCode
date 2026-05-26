class Solution {
public:
    string greatestLetter(string s) {

        for(char ch = 'Z'; ch >= 'A'; ch--) {

            bool upper = false;
            bool lower = false;

            for(char c : s) {

                if(c == ch)
                    upper = true;

                if(c == tolower(ch))
                    lower = true;
            }

            if(upper && lower)
                return string(1, ch);
        }

        return "";
    }
};
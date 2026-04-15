class Solution {
public:
    bool halvesAreAlike(string s) {
        for(char& c:s){
            c = tolower(c);
        }

        int ans1 = 0;
        int ans2 = 0;

        for(int i=0 ; i<s.length()/2 ; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                ans1++;
            }
        }

        for(int i=s.length()/2 ; i<s.length() ; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                ans2++;
            }
        }

        return ans1==ans2;
    }
};
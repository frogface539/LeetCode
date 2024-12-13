class Solution {
public:
    //static custom comparator
    static bool myComp(string& s1 , string& s2){
        return (s1+s2) > (s2+s1);
    }

    string largestNumber(vector<int>& arr) {
        vector<string>s;
        for(auto i : arr){
            s.push_back(to_string(i));
        }

        sort(s.begin() , s.end() , myComp);

        if(s[0] == "0"){
            return "0";
        }

        string result = "";
        for(auto i : s){
            result = result + i;
        }
        return result;
    }
};
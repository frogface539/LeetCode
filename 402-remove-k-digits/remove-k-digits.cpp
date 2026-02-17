class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;

        for(int i=0 ; i<num.length() ; i++){
            while(!result.empty() && k>0 && result.back() > num[i]){
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }

        while(k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        int i = 0;
        while(i < result.size() && result[i] == '0') {
            i++;
        }

        string ans = result.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
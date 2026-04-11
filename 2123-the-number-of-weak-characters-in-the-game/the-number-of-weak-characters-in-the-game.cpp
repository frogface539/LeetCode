class Solution {
public:
    static bool isGreater(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), isGreater);
        int maxDef = INT_MIN;
        int weak = 0;

        for(auto&p : properties){
            if(p[1] < maxDef){
                weak++;
            }
            else{
                maxDef = p[1];
            }
        }
        return weak;
    }
};
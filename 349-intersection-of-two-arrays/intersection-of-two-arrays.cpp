class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        set<int>st;
        for(int i = 0 ; i<arr1.size();i++){
            for(int j = 0 ; j<arr2.size();j++){
                if(arr1[i] == arr2[j]){
                    st.insert(arr1[i]);
                }
            }
        }
        return vector<int>(st.begin(),st.end());
    }
};
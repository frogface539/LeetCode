class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        int m = mat.size();
        int n = mat[0].size();
        int ans = INT_MAX;

        for(int i = 0 ; i<arr.size() ; i++){
            mp[arr[i]] = i; //array ki values ko map pe mark kardiya
        }

        for(int i=0 ; i<m ; i++){
            int k = 0;
            for(int j=0 ; j<n ; j++){
                k = max(mp[mat[i][j]] , k);
            }
            ans = min(k,ans);
        }

        for(int i=0 ; i<n ; i++){
            int k = 0;
            for(int j=0 ; j<m ; j++){
                k = max(mp[mat[j][i]] , k);
            }
            ans = min(k,ans);
        }
        return ans;
    }
};
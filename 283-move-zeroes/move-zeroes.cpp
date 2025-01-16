class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        vector<int>res1;
        vector<int>res2;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] == 0){
                res1.push_back(arr[i]);
            }

            else{
                res2.push_back(arr[i]);
            }
        }

        for(int i=0 ; i<res2.size() ; i++){
            arr[i] = res2[i];
        }

        for(int i=res2.size(); i<arr.size() ; i++){
            arr[i] = 0;
        }
    }
};
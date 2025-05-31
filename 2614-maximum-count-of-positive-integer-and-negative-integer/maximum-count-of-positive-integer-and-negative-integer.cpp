class Solution {
public:
    int maximumCount(vector<int>& arr) {
        int cp = 0;
        int cn = 0;

        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i] < 0){
                cn++;
            }


            if(arr[i] > 0){
                cp++;
            }
        }
        return max(cp,cn);
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>output;
        for(int i=0 ; i<A.size() ; i++){
            int count = 0;
            for(int j=0 ; j<=i ; j++){
                for(int k=0 ; k<=i; k++){
                    if(A[j] == B[k]){
                        count++;
                        break;
                    }
                }
            }
            output.push_back(count);
        }
        return output;
    }
};
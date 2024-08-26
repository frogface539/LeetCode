class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        
        int n = mat.size();
        stack<int>st;
        
        for(int i = 0 ; i<n ; i++){
            st.push(i);
        }
        while(st.size() != 1){
            int a = st.top() ; st.pop();
            int b = st.top() ; st.pop();
        
            if(mat[a][b]){
                st.push(b);
            }
        
           else{
                st.push(a);
            }
        }
        
        int celebrity = st.top() ; st.pop();
        
        for(int i=0 ; i<n ; i++){
            if(mat[celebrity][i] != 0){
                return -1;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            if(mat[i][celebrity] == 0 && i != celebrity){
                return -1;
            }
        }
        return celebrity;
        
    }
};

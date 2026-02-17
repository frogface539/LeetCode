class Solution {
public:
    vector<int>nextSmallerElement(vector<int>& arr, int n){
        vector<int>ans;
        stack<int>st;
        st.push(-1);

        for(int i=arr.size()-1 ; i>=0 ; i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i); //index
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int>prevSmallerElement(vector<int>& arr, int n){
        vector<int>ans;
        stack<int>st;
        st.push(-1);

        for(int i=0 ; i<arr.size() ; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i); //index
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        vector<int>next(arr.size());
        vector<int>prev(arr.size());

        next = nextSmallerElement(arr,arr.size());
        prev = prevSmallerElement(arr,arr.size());

        int area = INT_MIN;
        for(int i=0 ; i<arr.size() ; i++){
            int l = arr[i];
            if(next[i] == -1){
                next[i] = arr.size();
            }

            int b = next[i] - prev[i] - 1;

            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
};
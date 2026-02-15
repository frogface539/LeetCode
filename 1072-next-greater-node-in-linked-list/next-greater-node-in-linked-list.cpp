/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(stack<int>& st, vector<int>& arr, vector<int>& ans){
        // st.push(0);
        for(int i=arr.size()-1 ; i>=0 ; i--){
            int element = arr[i];
            while(!st.empty() && st.top() <= element){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(element);
        }
        reverse(ans.begin(),ans.end());
    }

    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        stack<int>st;
        vector<int>ans;
        solve(st,arr,ans);
        return ans;
    }
};
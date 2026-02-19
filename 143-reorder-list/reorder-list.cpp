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
    ListNode* front;
    void solve(ListNode* curr){
        if(curr==NULL){
            return;
        }
        solve(curr->next);

        if(front==NULL){
            return;
        }

        if(front==curr||front->next==curr){
            curr->next=NULL;
            front=NULL;
            return;
        }
        
        ListNode* temp=front->next;
        front->next=curr;
        curr->next=temp;
        front=temp;
    }

    void reorderList(ListNode* head){
        front=head;
        solve(head);
    }
};

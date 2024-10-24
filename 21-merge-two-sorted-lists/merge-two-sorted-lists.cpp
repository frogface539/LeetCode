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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(list1 && list2){
            if(list1->val <= list2->val){
                mptr->next = list1;  
                list1 = list1->next;  
            } else {
                mptr->next = list2; 
                list2 = list2->next;  
            }
            mptr = mptr->next;  
        }


        if(list1){
            mptr->next = list1;
        }
        if(list2){
            mptr->next = list2;
        }

        return ans->next;  // The first node is dummy, so return the next node
    }
};

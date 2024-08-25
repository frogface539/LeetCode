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
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        for(int i=0 ; i < k-1 ; i++){    
            //loop K tak chalega (if k=3 loop 2 baar chalega) (if k=2 loop 1 baar chalega)
            fast = fast -> next;
        }

        ListNode* first = fast;
        ListNode* slow = head;
        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }

        swap(first -> val , slow -> val);
        return head;
    }
};
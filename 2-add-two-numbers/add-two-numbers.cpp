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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        int carry = 0;
        ListNode* head = l3;

        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10; //carry is sum ka /10
            l3 -> next = new ListNode(sum % 10); //last digit push karne ke liye
            l1 = l1 -> next;
            l2 = l2 -> next;
            l3 = l3 -> next;
        }

        while(l1){
            int sum = l1->val + carry;
            carry = sum/10; //carry is sum ka /10
            l3 -> next = new ListNode(sum % 10); //last digit push karne ke liye
            l1 = l1 -> next;
            l3 = l3 -> next;
        }

        while(l2){
            int sum = l2->val + carry;
            carry = sum/10; //carry is sum ka /10
            l3 -> next = new ListNode(sum % 10); //last digit push karne ke liye
            l2 = l2 -> next;
            l3 = l3 -> next;
        }

        if(carry){
            l3 -> next = new ListNode(carry);
        }

        return head -> next;
    }
};
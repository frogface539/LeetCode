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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length = 0;
    ListNode* temp = head;

    while(temp != NULL){
        length++;
        temp = temp -> next;
    }

    if (n == length) {
            ListNode* newHead = head->next;
            delete head; 
            return newHead;
        }

    int position = length - n;
    ListNode* prev = head;
    for(int i=0 ; i < position -1 ; i++){
        prev = prev -> next;
    }

    ListNode* deleteNode = prev -> next;
    prev -> next = deleteNode -> next;

    delete deleteNode;

    return head;
    }
};
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;

        vector<int> v;

        while(temp != NULL)
        {
            v.push_back(temp-> val);
            temp = temp-> next;
        }

        sort(v.begin(),v.end());

        ListNode* newHead = new ListNode(0);
        temp = newHead;

        for(int num : v)
        {
            temp-> next = new ListNode(num);
            temp = temp-> next;
        }
        ListNode* result = newHead-> next;
        delete newHead;

        return result;
    }
};
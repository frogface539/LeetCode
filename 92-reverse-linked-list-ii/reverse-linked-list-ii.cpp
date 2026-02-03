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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left == right) return head;

        vector<int> arr;
        ListNode* temp = head;

        int pos = 1;
        while(pos < left){
            temp = temp->next;
            pos++;
        }

        ListNode* start = temp;

        int count = right - left + 1;
        while(count--){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        reverse(arr.begin(), arr.end());

        temp = start;
        for(int x : arr){
            temp->val = x;
            temp = temp->next;
        }

        return head;
    }
};
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        set<int>s(nums.begin(),nums.end());
            ListNode *temp=&dummy;
            while(temp->next!=NULL){
                if(s.count(temp->next->val)){
                    temp->next=temp->next->next; 
                }
                else temp=temp->next;
            }
        return dummy.next;
    }
};
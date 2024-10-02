class Solution {
public:
    bool hasCycle(ListNode* head) {

        ListNode* temp = head;
        unordered_map  <ListNode* , bool>mapping;

        while(temp != NULL){
            if(mapping.find(temp) != mapping.end()){
                return true;
            }

            else{
                mapping[temp] = true;
            }

            temp = temp -> next;
        }
        return false;
    }
};
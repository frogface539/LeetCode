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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head; // Node immediately before the current group
        int groupLen =
            2; // Start with length 2 as the head is a single node group

        while (prev->next != nullptr) {
            ListNode* node = prev;
            int numNodes = 0;

            // Determine the number of nodes in the current group
            for (int i = 0; i < groupLen; i++) {
                if (node->next == nullptr)
                    break;
                numNodes++;
                node = node->next;
            }

            if (numNodes % 2 == 0) { // Even length
                ListNode* reverse = node->next;
                ListNode* curr = prev->next;
                ListNode* currNext;

                // Reverse the nodes in the group
                for (int j = 0; j < numNodes; j++) {
                    currNext = curr->next;
                    curr->next = reverse;
                    reverse = curr;
                    curr = currNext;
                }

                // Update the prev pointer after reversal of the even group
                ListNode* prevNext = prev->next;
                prev->next = node;
                prev = prevNext;
            } else { // Odd length
                prev = node;
            }

            // Move to the next group
            groupLen++;
        }
        return head;
    }
};
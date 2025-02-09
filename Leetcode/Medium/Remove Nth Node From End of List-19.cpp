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
        ListNode* dummy1 = new ListNode(-1, head);
        ListNode* dummy2 = new ListNode(-1, head);
        ListNode* current1 = dummy1; 
        ListNode* current2 = dummy2;

        int size = 0;
        while (current1 -> next != nullptr) {
            size++;
            current1 = current1 -> next;
        }

        int target = size - n;
        int index = 0;
        while(current2 -> next != nullptr) {
            
            if (index == target) {
                ListNode* tempt = current2 -> next;
                current2 -> next  = current2 -> next -> next; 
                delete tempt; 
            } else {
                current2 = current2 -> next;

            }
            index++;
        }
        ListNode* ans =  dummy2 -> next;
        delete dummy2;
        return ans;
    }
};
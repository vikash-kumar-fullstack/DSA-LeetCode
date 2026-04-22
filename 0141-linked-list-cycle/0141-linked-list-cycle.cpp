/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*tor=head;
        ListNode*hare=head;
        while(hare!=NULL&&hare->next!=NULL){
            tor=tor->next;
            hare=hare->next->next;
            if(tor==hare)return true;
        }
        return false;
    }
};
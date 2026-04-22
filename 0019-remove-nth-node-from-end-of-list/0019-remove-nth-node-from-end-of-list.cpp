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
        int trace=0;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        head=dummy;
        ListNode*forward=dummy;
        while(trace!=n+1){
            forward=forward->next;
            trace++;
        }
        ListNode*back=dummy;
        while(forward!=NULL){
            forward=forward->next;
            back=back->next;
        }
        back->next=back->next->next;
        return dummy->next;
    }
};
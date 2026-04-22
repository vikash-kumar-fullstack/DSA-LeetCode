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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr_next=head;
        ListNode* curr=head;
        while(curr_next!=NULL){
            curr_next=curr_next->next;
            curr->next=prev;
            prev=curr;
            curr=curr_next;
        }
        return prev;
    }
};
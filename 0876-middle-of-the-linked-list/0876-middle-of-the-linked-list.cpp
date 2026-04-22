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
// class Solution {
// public:
//     int findLen(ListNode* head){
//         if(head==NULL){
//             return 0;
//         }
//         int count=0;
//         ListNode*temp=head;
//         while(temp!=NULL){
//             temp=temp->next;
//             count++;
//         }
//         return count;
//     }
//     ListNode* solve(ListNode*head,int mid){
//         if(mid==1){
//             return head;
//         }
//         ListNode*temp=head;
//         while(mid!=1){
//             temp=temp->next;
//             mid--;
//         }
//         return temp;
        
//     }
//     ListNode* middleNode(ListNode* head) {
//         int length=findLen(head);
//         int mid=length/2+1;
//         ListNode* ans=solve(head,mid);
//         return ans;
//     }
// };


// 2nd method

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*tor=head;
        ListNode*hare=head;
        while(hare!=NULL && hare->next!=NULL){
            tor=tor->next;
            hare=hare->next->next;
        }
        return tor;
    }
};
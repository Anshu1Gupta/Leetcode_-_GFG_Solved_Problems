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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL||head->next==NULL)return NULL;
        ListNode*curr=head;
        ListNode*next=head->next;
        ListNode*prev=curr;
        
        while(next!=NULL&&next->next!=NULL){
           next=next->next->next;
            
            curr=curr->next;
            if(next!=NULL&&next->next!=NULL)prev=curr;
        }
        
        if(next==NULL){
            prev->next=curr->next;
        }
        else if(next->next==NULL){
            curr->next=curr->next->next;
        }
        
    return head;
    }
};
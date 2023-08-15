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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode(-1);
        ListNode*ans=less;
        ListNode* gequal=new ListNode(-1);
        ListNode*tail=gequal;
        
        
        ListNode*temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                less->next=temp;
                less=temp;
            }
            else{
                gequal->next=temp;
                gequal=temp;
            }
            temp=temp->next;
        }
        
       gequal->next=NULL;
       less->next=tail->next;
        
        return ans->next;
        
        
        
    }
};
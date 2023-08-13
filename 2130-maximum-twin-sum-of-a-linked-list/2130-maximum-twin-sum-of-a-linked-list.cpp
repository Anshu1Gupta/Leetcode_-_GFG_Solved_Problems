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
    pair<ListNode*,ListNode*>findMid(ListNode*temp){
        ListNode*p=NULL,*q=NULL,*r=temp;
        
        ListNode*slow=temp;
        ListNode*fast=temp;
        
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        
        return {q,r};
    }
    int pairSum(ListNode* head) {
        
        auto it=findMid(head);
        ListNode*back=it.first;
        ListNode*front=it.second;
        int ans=0;
        while(back!=NULL&&front!=NULL){
            ans=max(ans,(back->val+front->val));
            front=front->next;
            back=back->next;
        }
        return ans;
    }
};
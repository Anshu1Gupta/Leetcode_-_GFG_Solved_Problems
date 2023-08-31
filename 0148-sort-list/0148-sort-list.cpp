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
    ListNode* merge(ListNode*first,ListNode*second){
        
        ListNode*dummy=new ListNode(-1);
        ListNode*ans=dummy;
        while(first!=NULL&&second!=NULL){
            if(first->val<=second->val){
                dummy->next=first;
                dummy=dummy->next;
                first=first->next;
            }
            else{
                dummy->next=second;
                dummy=dummy->next;
                second=second->next;
            }
        }
        dummy->next=first!=NULL?first:second;
        return ans->next;
    }
    // I will use merge sort
    ListNode*findMid(ListNode*head){
        if(head==NULL)return NULL;
        ListNode*slow=head;
        ListNode*fast=head->next;
        
       while(fast!=NULL&&fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
       }
        ListNode*mid=slow->next;
        slow->next=NULL;
        return mid;
    }
  
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        
        ListNode*mid=findMid(head);
        
        
       ListNode*left=sortList(head);
       ListNode*right=sortList(mid);
        
      return  merge(left,right);
    }
};
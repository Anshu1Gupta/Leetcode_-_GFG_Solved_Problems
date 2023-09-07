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
    ListNode* reverse(ListNode*node,int len){
        ListNode*start=node;
        ListNode*p=NULL,*q=NULL,*r=node;
        while(r!=NULL&&len--){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        start->next=r;
        return q;
        
        
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL||head==NULL)return head;
        
        ListNode*ans=NULL;
        if(left==1)
        {
            head=reverse(head,right-left+1);
        }
        else
        {
            ListNode*curr=head;
            int count=1;
            while(curr!=NULL){
                count++;
                if(count==left){
                    curr->next=reverse(curr->next,right-left+1);
                    break;
                }
                curr=curr->next;
            }
        }
        return head;
    }
};
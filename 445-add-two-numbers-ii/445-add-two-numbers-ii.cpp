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
    ListNode*reverseList(ListNode*node){
        ListNode*p=NULL,*q=NULL,*r=node;
        while(r!=NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        return q;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=reverseList(l1);
        l2=reverseList(l2);
        
         ListNode* res=new  ListNode(-1);
         ListNode*ans=res;
        int carry=0;
        while(l1!=NULL&&l2!=NULL){
             ListNode*node=new  ListNode(-1);
            int sum=l1->val+l2->val+carry;
            
            if(sum>=10){
                carry=1;
            }
            else{
                carry=0;
            }
            
            sum=sum%10;
            node->val=sum;
            res->next=node;
            res=res->next;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1!=NULL){
             ListNode*node =new ListNode(-1);
            int sum=l1->val+carry;
            
            if(sum>=10){
                carry=1;
            }
            else{
                carry=0;
            }
            
            sum=sum%10;
            node->val=sum;
            res->next=node;
            res=res->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            ListNode*node =new ListNode(-1);
            
            int sum=l2->val+carry;
            
            if(sum>=10){
                carry=1;
            }
            else{
                carry=0;
            }
            
            sum=sum%10;
            node->val=sum;
            res->next=node;
            res=res->next;
            l2=l2->next;
        }
        if(carry==1){
             ListNode* node=new  ListNode(1);
            res->next=node;
            res=res->next;
        }
        
        
        
        ans=ans->next;
        ans=reverseList(ans);
        return ans;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int carry=0;
        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }
        if(sum>=10){
            sum=sum%10;
            carry=1;
        }
        ListNode* result=new ListNode(sum);
        ListNode*ans=result;
        while(l1!=NULL&&l2!=NULL){
            
            int x=l1->val;
            int y=l2->val;
            if(x+y+carry>=10){
                sum=(x+y+carry)%10;
                ListNode* newnode=new ListNode(sum);
                result->next=newnode;
                result=result->next;
                
                carry=1;
            }
            else{
                sum=x+y+carry;
                ListNode* newnode=new ListNode(sum);
                result->next=newnode;
                result=result->next;
                carry=0;
            }
            l2=l2->next;
            l1=l1->next;
            
        }
        while(l1!=NULL){
           if(carry+l1->val>=10){
               sum=(carry+l1->val)%10;
                ListNode* newnode=new ListNode(sum);
                result->next=newnode;
                result=result->next;
               carry=1;
           }
            else{
                sum=carry+l1->val;
                 ListNode* newnode=new ListNode(sum);
                result->next=newnode;
                result=result->next;
                carry=0;
            }
            l1=l1->next;
        }
        while(l2!=NULL){
           if(carry+l2->val>=10){
               sum=(carry+l2->val)%10;
                ListNode* newnode=new ListNode(sum);
                result->next=newnode;
                result=result->next;
               carry=1;
           }
            else{
                sum=carry+l2->val;
                 ListNode* newnode=new ListNode(sum);
                result->next=newnode;
                result=result->next;
                carry=0;
            }
            l2=l2->next;
        }
        if(carry==1){
            ListNode* newnode=new ListNode(1);
            result->next=newnode;
            result=result->next;
        }
        return ans;
        
    }
};
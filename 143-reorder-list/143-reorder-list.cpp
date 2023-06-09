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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)return;
        //finding middle
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        ListNode*firsthalf=head;
        ListNode*secondhalf=slow->next;
        
        //reversing second half
        ListNode*p=NULL,*q=NULL,*r=secondhalf;
        while(r!=NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        secondhalf=q;
        
        
        // merging the two lists
        ListNode*ans=firsthalf;
        ListNode*temps=secondhalf->next;
            ListNode*tempf=firsthalf->next;
        while(firsthalf&&secondhalf){
            temps=secondhalf->next;
            tempf=firsthalf->next;
            firsthalf->next=secondhalf;
             secondhalf->next=tempf;
            firsthalf=secondhalf->next;
            secondhalf=temps; 
        }
     firsthalf->next=NULL;
    }
};
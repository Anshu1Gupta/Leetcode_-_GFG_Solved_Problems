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
    ListNode* rotateRight(ListNode* head, int k) {
        int length=0;
        if(head==NULL)return head;
        ListNode*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        k=k%length;
        while(k--&&fast!=NULL){
            fast=fast->next;
        }
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        ListNode*ans=slow->next;
        slow->next=NULL;
        return ans;
    }
};
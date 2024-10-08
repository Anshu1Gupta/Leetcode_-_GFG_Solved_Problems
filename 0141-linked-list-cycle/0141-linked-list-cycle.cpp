/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        if(head==NULL)return false;
        
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast)fast=fast->next;
        }while(slow!=fast && fast!=NULL);
        
        if(fast==NULL)return false;
        return true;
    }
};
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
    int sizeOfList(ListNode* head){
        int count=0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int size=sizeOfList(head);
        int target=size-n-1;
        ListNode*node=head;
        if(target==-1)return head->next;
        
        while(target--){
            node=node->next;
        }
        if(n==1){
            node->next=NULL;
        }
        else{
            node->next=node->next->next;
        }
        return head;
        
    }
};
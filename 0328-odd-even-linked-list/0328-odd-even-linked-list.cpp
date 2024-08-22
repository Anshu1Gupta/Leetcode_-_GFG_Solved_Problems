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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*odd=new ListNode(-1e9);
        ListNode*even=new ListNode(-1e9);
        if(head==NULL)return NULL;
        ListNode*oddo=odd;
        ListNode*eveno=even;
        
        int size=0;
        while(head && ++size){
            if(size%2==1){
                odd->next=head;
                odd=odd->next;
                // odd->next=NULL;
            }
            else{
                even->next=head;
                even=even->next;
                // even->next=NULL;
            }
            
            head=head->next;
        }
        even->next=NULL;
        if(odd->val==-1e9)return eveno->next;
        if(even->val==-1e9)return oddo->next;
         
        odd->next=eveno->next;
        return oddo->next;
    }
};
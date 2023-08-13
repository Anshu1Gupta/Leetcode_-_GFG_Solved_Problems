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
        if(head==NULL||head->next==NULL)return head;
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*tail=even;
        while(true){
            if(odd->next==NULL||even->next==NULL){
                odd->next=tail;
                cout<<1<<endl;
                break;
            }
            
            if(even){
                odd->next=even->next;
                odd=odd->next;
            }
            if(odd){
                even->next=odd->next;
                even=even->next;
            }
        }
        return head;
        
      
    }
};
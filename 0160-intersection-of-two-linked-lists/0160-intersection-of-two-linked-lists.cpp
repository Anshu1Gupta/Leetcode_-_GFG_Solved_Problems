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
    int sizeOfList(ListNode* head){
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1=sizeOfList(headA);
        int size2=sizeOfList(headB);
        
        int diff=abs(size1-size2);
        
        
        if(size1>size2){
            while(diff--){
                headA=headA->next;
            }
        }
        else{
            while(diff--){
                headB=headB->next;
            }
        }
        
        
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
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
    int size(ListNode *head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        
        int x1=size(head1);
        int x2=size(head2);
        
        while(x2>x1){
            head2=head2->next;
            x2--;
        }
        while(x1>x2){
            head1=head1->next;
            x1--;
        }
        
        // Node*ans=NULL;
        
        while(head1!=head2){
            head1=head1->next;
            head2=head2->next;
        }
        return head1;
    }
};
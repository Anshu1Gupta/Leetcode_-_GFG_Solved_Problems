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
    pair<ListNode*,ListNode*>rev(ListNode*r,int len){
	ListNode*p=NULL,*q=NULL,*temp=r;
	
 
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count<len)return {r,NULL};
	while(r!=NULL&&len--){
		p=q;
		q=r;
		r=r->next;
		q->next=p;
	}

	return {q,r};
}
    ListNode* reverseKGroup(ListNode* head, int k) {

if(head==NULL||head->next==NULL)return head;

pair<ListNode*,ListNode*>p=rev(head,k);
ListNode*entry=p.first;
ListNode*start=entry;
ListNode*r=p.second;
    
        while(r!=NULL){
           while (entry->next != NULL) {
                  entry = entry->next;
                }
	 pair<ListNode*,ListNode*>p=rev(r,k);
	 entry->next=p.first;
		r=p.second;
}

	  return start;
    }
    };
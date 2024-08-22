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
    ListNode*merge(ListNode*left,ListNode*right){
        ListNode*node=NULL,*nodeTail=NULL;
        
        if(left->val<right->val){
            node=left;
            nodeTail=node;
            left=left->next;
            
        }
        else{
            node=right;
            nodeTail=node;
            right=right->next;
        }
        
        
        while(left&&right){
            if(left->val<right->val){
                node->next=left;
                node=left;
                left=left->next;
            }
            else{
                node->next=right;
                node=right;
                right=right->next;
                
            }
        }
        
        if(left){
            node->next=left;
            node=node->next;
        }
        if(right){
            node->next=right;
            node=node->next;
        }
        
        return nodeTail;
    }
    ListNode* midFind(ListNode* head){
        if(head==NULL)return NULL;
        ListNode*slow=head;
        ListNode*fast=head->next;
        
       while(fast!=NULL&&fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
       }
        ListNode*mid=slow->next;
        slow->next=NULL;
        return mid;
    }
    ListNode* mergeSort(ListNode* node){
        if(node==NULL || node->next ==NULL)return node;
        
        ListNode*mid=midFind(node);
        ListNode* left=mergeSort(node);
        ListNode* right=mergeSort(mid);
        
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {        
        return mergeSort(head);

    }
};
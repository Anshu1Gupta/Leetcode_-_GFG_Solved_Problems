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
    ListNode* merge(ListNode*l1,ListNode*l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val<=l2->val){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l2->next,l1);
            return l2;
        }
        return NULL;
    }
    ListNode*mergedLists(int start,int end,vector<ListNode*>& lists){
        if(start>end)return NULL;
        if(start==end)return lists[start];
        int mid=(start+end)/2;
        ListNode*l1=mergedLists(start,mid,lists);
        ListNode*l2=mergedLists(mid+1,end,lists);
        
        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size()-1;
        if(lists.size()==0)return NULL;
        return mergedLists(0,k,lists);
    }
};
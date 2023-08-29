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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*ans=head;
        unordered_map<int,int>mp;
        while(ans!=NULL){
            mp[ans->val]++;
            ans=ans->next;
        }
        
        ans=new ListNode(-1);
        ListNode*res=ans;
        ListNode*dummy=head;
        while(dummy!=NULL){
            if(mp[dummy->val]==1){
                ans->next=dummy;
                ans=ans->next;
            }
            dummy=dummy->next;
        }
        ans->next=NULL;
        return res->next;
        
        
        
    }
};
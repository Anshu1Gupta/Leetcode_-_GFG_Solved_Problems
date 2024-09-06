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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            if(mpp.find(temp->val)!=mpp.end()){
                if(temp==head){
                    temp=temp->next;
                    head=temp;
                }
                else{
                    prev->next=temp->next;
                    temp->next=NULL;
                    temp=prev->next;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;   
    }
};
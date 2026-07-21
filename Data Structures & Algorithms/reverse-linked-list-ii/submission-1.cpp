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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int>arr;
        ListNode* temp=head;
        
        ListNode* beforeLeft=nullptr;
        ListNode* curr=head;
        for(int i=1;i<left;i++){
            beforeLeft=curr;
            curr=curr->next;
        }
        ListNode*prev= nullptr;
        ListNode* leftNode = curr;
        
        for(int i=0;i<right-left+1;i++){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        leftNode->next=curr;

        if(beforeLeft){
            beforeLeft->next = prev;
            return head;
        }
        return prev;
    }
};
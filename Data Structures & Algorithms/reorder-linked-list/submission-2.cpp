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
private:
ListNode* reverseList(ListNode* curr,ListNode*prev,ListNode* nxt){
if(curr==nullptr){
    return prev;
}
curr->next=prev;
prev=curr;
curr=nxt;
nxt = (curr != nullptr) ? curr->next : nullptr;
return reverseList(curr,prev,nxt);
}
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;
        ListNode*temp=reverseList(slow->next,nullptr,slow->next->next);
        slow->next=nullptr;
        ListNode* l1=head;
        ListNode* l2=temp;
        while(l2!=nullptr){
            ListNode*t=l1->next;
            ListNode*lt=l2->next;
            l1->next=l2;
            l2->next=t;
            l1=l2->next;
            l2=lt;
        }
    }
};

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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*>s;
        int len=0;
        while(temp){
            s.push(temp);
            temp=temp->next;
            len++;
        }
        temp=head;
        int n=len/2;
        for(int i=0;i<n;i++){
            ListNode* t=s.top();
            s.pop();
            ListNode*temp2=temp->next;
            
            if(t==temp || t==temp2){
                temp2->next=nullptr;
                return;
            }
            temp->next=t;
            t->next=temp2;
            temp=temp2;
        }
        temp->next=nullptr;
    }
};

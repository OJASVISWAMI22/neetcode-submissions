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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* temp=head;

        while(temp){
            i++;
            temp=temp->next;
        }
        if(i==n)
        return head->next;
        i=i-n-1;
        temp=head;
        while(i--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
        return nullptr;
        unordered_map<Node*,Node*>hash;

        Node*temp=head;

        while(temp){
            hash[temp]=new Node(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(temp){
            hash[temp]->next=hash[temp->next];
            hash[temp]->random=hash[temp->random];
            temp=temp->next;
        }
        return hash[head];
    }
};

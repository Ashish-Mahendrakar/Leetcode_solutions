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
        if(head == NULL)
            return head;
        Node* ans=new Node(head->val);
        Node* prev=ans;
        Node* temp=head->next;
        unordered_map<Node* ,Node*> mp;
        mp[head]=ans;
        while(temp != NULL)
        {
            Node* next=new Node(temp->val);
            mp[temp]=next;
            prev->next=next;
            temp=temp->next;
            prev=next;
        }
        temp=head;
        prev=ans;
        while(temp != NULL)
        {
            prev->random=mp[temp->random];
            prev=prev->next;
            temp=temp->next;
        }
        return ans;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void rr(Node* head,stack<Node*> &st)
    {
        if(head==NULL)
        {
            return;
        }

        if(head->child == NULL)
        {
            rr(head->next,st);
        }
        else
        {
            Node* part=head->next;
            if(part)
                st.push(part);
            head->next=head->child;
            head->child->prev=head;
            head->child=NULL;
            rr(head->next,st);

        }
    }
    Node* flatten(Node* head) {
        if(head==NULL)
        {
            return NULL;
        }
        stack<Node*> st;
        rr(head,st);
        Node* tail=head;
        while(tail->next)
        {
            tail=tail->next;
            //cout<<tail->val<<" "<<(tail->child==NULL)<<endl;
        }
        while(!st.empty())
        {
            tail->next=st.top();
            st.top()->prev=tail;
            st.pop();
            while(tail->next)
            {
                tail=tail->next;
                //cout<<tail->val<<" "<<(tail->child==NULL)<<endl;
            }

        }
        return head;
    }
};
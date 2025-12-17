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
    void inserth(ListNode* &head,int data)
    {
        ListNode* temp=new ListNode(data);
        temp->next=head;
        head=temp;
    }
    void rr(ListNode* head,stack <int> &st,ListNode* &ans)
    {
        if(head->next==NULL)
        {
            st.push(head->val);
            return;
        }

        rr(head->next,st,ans);
        cout<<head->val<<" "<<st.top()<<endl;
        if(head->val < st.top())
        {
            inserth(ans,st.top());
            st.push(head->val);
        }
        else 
        {
            while( !st.empty() && st.top() <= head->val)
            {
                if(st.top()==0) break;
                st.pop();
            }
            inserth(ans,st.top());
            st.push(head->val);
        }
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        
        stack <int> st;
        st.push(0);
        rr(head,st,ans);
        vector<int> ans1;
        while(ans != NULL)
        {
            ans1.push_back(ans->val);
            ans=ans->next;
        }
        return ans1;
    }
};
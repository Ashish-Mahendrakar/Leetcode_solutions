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
void insertatend(ListNode* &ans,ListNode* cur)
{
    ListNode* temp=ans;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=cur;
}
class compare{
    public:
        bool operator()(ListNode* a,ListNode*b){
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode* front=new ListNode();
       
       priority_queue <ListNode*,vector<ListNode*>,compare> pq;
       for(int i=0;i<lists.size();i++)
       {
        if(lists[i]!=NULL)
            pq.push(lists[i]);
       } 
       while(!pq.empty()){
        ListNode* cur=pq.top();
        pq.pop();
        
        if(cur->next!=NULL)
        {
            pq.push(cur->next);
        }
        cur->next=NULL;

        // function to insert at of ll
        insertatend(front,cur);
       }
       return front->next;
    }
};
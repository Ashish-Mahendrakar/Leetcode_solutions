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
    int findlen(ListNode* &head)
    {
        int count=0;
        ListNode* temp=head;
        while(temp != NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void insertll(int i,ListNode*  &head,ListNode*  &tail)
    {
        if(head==NULL && tail==NULL)
        {
            ListNode* temp=new ListNode(i);
            head=temp;
            tail=temp;
            return;

        }
        ListNode* temp=new ListNode(i);
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        vector<int> num;
        ListNode* temp=list1;
        while(temp != NULL)
        {
            num.push_back(temp->val);
            temp=temp->next;
        }
        temp=list2;
        while(temp != NULL)
        {
            num.push_back(temp->val);
            temp=temp->next;
        }
        sort(num.begin(),num.end());

        ListNode* ans_head=NULL;
        ListNode* ans_tail=NULL;
        for(auto i : num )
        {
            //cout<<i<<endl;
            insertll(i,ans_head,ans_tail);
        }
        return ans_head;
    }
};
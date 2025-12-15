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
    int findlen(ListNode* head)
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len=findlen(head);
        vector<int>crit;
        vector<int>ans(2,-1);
        ListNode* prev=head;
        if(len<=2)
        {
            return ans;
        }
        ListNode* curr=head->next;
        ListNode* nex=curr->next;
        int index=2;
        while(nex != NULL)
        {
            if(curr->val > prev->val && curr->val > nex->val)
            {
                crit.push_back(index);
            }
            else if(curr->val < prev->val && curr->val < nex->val)
            {
                crit.push_back(index);
            }
            index++;
            prev=curr;
            curr=nex;
            nex=nex->next;
        }
        int min_d=INT_MAX;
        if(crit.size()<=1)
        {
            return ans;
        }
        ans[1]=crit.back()-crit[0];
        for(int i=1;i<crit.size();i++)
        {
            if(min_d>crit[i]-crit[i-1])
            {
                min_d=crit[i]-crit[i-1];
            }
        }
        ans[0]=min_d;

        return ans;
    }
};
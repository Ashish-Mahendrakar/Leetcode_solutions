class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        int p1=0;
        int p2=0;
        int last_element;
        int ll_elemnt;
        int count=0;
        int stop=(l1+l2)/2;
        if(l1==1 && l2==1)
        {
            return ((double)nums1[0]+(double)nums2[0])/2;
        }

        if(l1==2 && l2==0)
        {
            return ((double)nums1[0]+(double)nums1[1])/2;
        }

        if(l2==2 && l1==0)
        {
            return ((double)nums2[0]+(double)nums2[1])/2;
        }
        while(count <=stop)
        {
            if(p1>=l1)
            {
                ll_elemnt=last_element;
                last_element=nums2[p2];
                p2++;
            }
            else if(p2>=l2)
            {
                ll_elemnt=last_element;
                last_element=nums1[p1];
                p1++;
            }
            else
            {
                if(nums2[p2]>nums1[p1])
                {
                    ll_elemnt=last_element;
                    last_element=nums1[p1];
                    p1++;
                }
                else
                {
                    ll_elemnt=last_element;
                    last_element=nums2[p2];
                    p2++;
                }
            }
            count++;

        }
        cout<<last_element<<" "<<ll_elemnt;
        if((l1+l2)&1)
        {
            return last_element;
        }
        else
        {
            return ((double)last_element+(double)ll_elemnt)/2;
        }
        //return 0;
    }
};
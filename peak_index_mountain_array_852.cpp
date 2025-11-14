class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int len=arr.size();
        // if(arr[len-2]<arr[len-1])
        // {
        //     return len-1;    
        // }

        // if(arr[0]>arr[1])
        // {
        //     return 0;
        // }

        int start =0;
        int end=len-1;
        while(start+1<end)
        {
            
            int mid=(start + end)/2;
            if(mid-1 >=0 && mid+1<len && arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid] )
            {
                return mid;
            }
            else if(mid-1 >=0 &&  mid+1<len && arr[mid-1]<arr[mid] && arr[mid+1]>arr[mid])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }

            

            
        }

        if(start +1 ==end)
            {
                if(arr[start]>arr[end])
                {
                    return start;
                }
                else
                {
                    return end;
                }
            }

        return start;

    }
};
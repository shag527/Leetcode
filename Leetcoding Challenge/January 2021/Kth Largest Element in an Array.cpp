/* Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5


Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length. */

class Solution {
public:
    int partition(vector<int>& nums, int l, int r)
    {
        int pivot=nums[r],i=l;
        for(int j=l;j<=r;j++)
        if(nums[j]<pivot)
        swap(nums[i++],nums[j]);
        swap(nums[i],nums[r]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,p=0;
        k=nums.size()-k;
        while(l<=r)
        {
            p=partition(nums,l,r);
            if(p==k)
                return nums[p];
            else if(p>k)
                r=p-1;
            else 
                l=p+1;
        }
        return -1;
    }
};

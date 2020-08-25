/* Given two sorted arrays nums1 and nums2 of size m and n respectively.

Return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)). */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<long int>v;
        int i=0,j=0,n=nums1.size(),m=nums2.size();
        double res=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size())
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size())
        {
            v.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2==1)
            res=float(v[(n+m)/2]);
        else
            res=float(v[(n+m)/2]+v[(n+m)/2-1])/2;
        return res;
    }
};

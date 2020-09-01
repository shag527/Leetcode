/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2. */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1=0,p2=height.size()-1,area=0,max_area=0;
        while(p2>p1)
        {
            area=min(height[p1],height[p2])*(p2-p1);
            if(area>max_area)
                max_area=area;
            if(height[p1]<height[p2])
                p1++;
            else
                p2--;
        }
        return max_area;
    }
};

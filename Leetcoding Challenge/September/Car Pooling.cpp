/* You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive 
west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be 
picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Example:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n;
        for(auto i:trips) n = max(n,i[2]);        
        vector<int>count(n+1);
        for(auto i:trips)
        {
            count[i[1]] += i[0];         
            count[i[2]] -= i[0];
        }
        for(int i=1 ; i<=n ; i++) count[i] += count[i-1];
        for(int i=0 ; i<n ; i++)
            if(count[i]>capacity) 
                return false;
        return true;
    }
};

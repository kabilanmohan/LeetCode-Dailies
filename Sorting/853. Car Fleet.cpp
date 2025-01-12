
    /*
    Time complexity : O(nlogn)
    Space complexity : O(n)
    */


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<pair<int, double>> posi_time(n);

        // Calculate position and time to reach target
        for (int i = 0; i < n; i++) {
            posi_time[i].first = position[i];
            posi_time[i].second = (double)(target - position[i]) / speed[i];
        }

        // Sort by position in descending order
        sort(posi_time.begin(), posi_time.end(), [](pair<int, double>& a,pair<int, double>& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double maxTime = 0.0;

        // Iterate through cars from closest to furthest
        for (int i = 0; i < n; i++) {
            if (posi_time[i].second > maxTime) {
                fleets++;             // New fleet is formed
                maxTime = posi_time[i].second; // Update the max time
            }
        }

        return fleets;
    }
};


    /*
    Author : kabilanmohan
    Question Link : https://leetcode.com/problems/car-fleet/
    */

    
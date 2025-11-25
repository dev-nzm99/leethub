/*
 Author: Nazmul Islam
 Created: 2025-11-25 18:28
 Approach: Using Monotonic Increasing stack Logic 
 Complexity: O(nlogn) time & O(n) space
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(),
             [](const pair<int, double> a, const pair<int, double> b) {
                 return a.first > b.first;
             });
        stack<double> stk;
        for (int i = 0; i < n; i++) {
            double speed = cars[i].second;
            if (!stk.empty() && speed <= stk.top()) {
                continue;
            }
            stk.push(speed);
        }
        return stk.size();
    }
};

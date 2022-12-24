class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //map position to time needed to arrive at target (negative pos so iterator starts with car closest to target)
        map<int, double> cars;
        for(int i=0; i<position.size(); i++)
            cars[-position[i]] = (double)(target - position[i]) / speed[i];
            
        int result = 0;
        double cur = 0;
        for(auto &c : cars)
            //all cars with time greater than the current time will arrive as one fleet
            if(c.second > cur) { 
                cur = c.second;
                result++;
            }

        return result;
    }
};
//https://leetcode.com/problems/car-fleet/
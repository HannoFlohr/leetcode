class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for(int& asteroid : asteroids) {
            if(asteroid > 0 || stack.empty()) {
                stack.push_back(asteroid);
                continue;
            }

            bool destroyed = false;
            while(!stack.empty() && !destroyed) {
                if(stack.back() < 0)
                    break; 
                
                if(stack.back() >= abs(asteroid))
                    destroyed = true;
                if(stack.back() <= abs(asteroid))
                    stack.pop_back();
            }

            if(!destroyed)
                stack.push_back(asteroid);
        }

        return stack;
    }
};
//https://leetcode.com/problems/asteroid-collision/description/
class Solution {
    
static bool compare(vector<int>& a, vector<int>& b) {
    return a[0]==b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
}
    
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int weak = 0, low = INT_MIN;
        
        sort(properties.begin(), properties.end(), compare);
        
        for(int i=properties.size()-1; i>=0; i--) {
            if(properties[i][1] < low)
                weak++;
            low = max(low, properties[i][1]);
        }
            
        return weak;
    }
};
//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
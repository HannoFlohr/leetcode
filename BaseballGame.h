class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;

        for(const auto &op : operations) {
            if(op == "C")
                record.pop_back();
            else if(op == "D") 
                record.push_back(record[record.size()-1] * 2);
            else if(op == "+")
                record.push_back(record[record.size()-1] + record[record.size()-2]);
            else {
                record.push_back(stoi(op));
            }
        }

        return reduce(record.begin(), record.end());
    }
};
//https://leetcode.com/problems/baseball-game/
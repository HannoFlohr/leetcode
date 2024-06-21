class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,bool> feedback;
        for(string& s : positive_feedback) {
            feedback[s] = true;
        }
        for(string& s : negative_feedback) {
            feedback[s] = false;
        }

        map<int, priority_queue<int, vector<int>, greater<int>>> results;
        string word;
        int points;
        for(int i = 0; i < report.size(); ++i) {
            points = 0;
            stringstream ss (report[i]);
            while(ss >> word) {
                if(feedback.find(word) != feedback.end()) {
                    points += feedback[word] ? 3 : -1;
                }
            }
            results[points].push(student_id[i]);
        }

        vector<int> sorted;
        for(auto it = results.rbegin(); it != results.rend(); ++it) {
            while(!it->second.empty()) {
                sorted.push_back(it->second.top());
                it->second.pop();
                if(sorted.size() == k) {
                    return sorted;
                }
            }
        }

        return sorted;
    }
};
//https://leetcode.com/problems/reward-top-k-students/
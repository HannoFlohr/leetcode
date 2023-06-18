class Solution {
public:
    double average(vector<int>& salary) {
        const auto [min_salary, max_salary] = minmax_element(salary.begin(), salary.end());
        return (accumulate(salary.begin(), salary.end(), 0.) - *min_salary - *max_salary) / (salary.size() - 2); 
    }
};
//https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

/*
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
    
        double sum = 0.0;
        for(size_t i = 1; i < salary.size()-1; ++i)
            sum += salary[i];

        return sum / (salary.size()-2);
    }
}; 
*/
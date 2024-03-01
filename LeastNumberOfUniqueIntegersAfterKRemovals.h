class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> number_frequency;
        vector<pair<int,int>> numbers;
        int erasable = 0;

        //frequency of each number 
        for(int i : arr) 
            number_frequency[i]++;
        //pair numbers with their frequency and sort by frequency
        for(pair<int,int> i : number_frequency) 
            numbers.push_back(i); 
        sort(numbers.begin(), numbers.end(), [](const pair<int,int>& a, const pair<int,int>& b){ return a.second < b.second; });

        //count how many numbers are completely erasable using k removes
        for(pair<int,int> i : numbers) {
            if(k < i.second)
                break;

            erasable++;
            k -= i.second; 
        }
        
        return numbers.size() - erasable;
    }
};
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
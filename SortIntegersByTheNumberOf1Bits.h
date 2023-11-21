class Solution {
    static bool bitCompare(const int& a, const int& b) {
        int count_a = bitset<16>(a).count();
        int count_b = bitset<16>(b).count();
        if(count_a == count_b) {
            return a < b;
        }
        return count_a < count_b;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), bitCompare);
        return arr;
    }
};
//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

/* 
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> bits_numbers;
        for(int n : arr) {
            bits_numbers[bitset<16>(n).count()].push_back(n);
        }

        vector<int> sorted;
        for(auto& [bits,numbers] : bits_numbers) {
            sort(numbers.begin(),numbers.end());
            sorted.insert(sorted.end(), numbers.begin(), numbers.end());
        }

        return sorted;
    }
};
*/
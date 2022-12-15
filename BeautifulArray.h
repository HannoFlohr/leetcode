class Solution {
private:
    static bool compare(const int &a, const int &b) {
        int bit = 1;
        while((a & bit) == (b & bit))
                bit <<= 1;
        return (a & bit) > (b & bit);
    }

public:
    vector<int> beautifulArray(int n) {
        vector<int> array;

        while(n) array.push_back(n--);
        sort(array.begin(), array.end(), compare);

        return array;
    }
};
//https://leetcode.com/problems/beautiful-array/

/*
a beautiful array with the given properties can be built by sorting according to the last bit, second to last bit, and so on..
e.g. for n = 5 -> {1,5,3,2,4}

3	011
5	101
1	001
2	010
4	100
*/
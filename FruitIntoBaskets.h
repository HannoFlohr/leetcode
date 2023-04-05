class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count_fruit;
        int start, end;

        for(start = 0, end = 0; end < fruits.size(); end++) {
            count_fruit[fruits[end]]++;

            if(count_fruit.size() > 2) {
                if(--count_fruit[fruits[start]] == 0)
                    count_fruit.erase(fruits[start]);
                start++;
            }
        }

        return end - start;
    }
};
//https://leetcode.com/problems/fruit-into-baskets/
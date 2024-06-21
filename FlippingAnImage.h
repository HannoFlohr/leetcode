class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(vector<int>& row : image) {
            int front = 0, back = row.size()-1;
            while(front < back) {
                int tmp = !row[back];
                row[back] = !row[front];
                row[front] = tmp;
                ++front;
                --back;
            }
            if(front == back)
                row[front] = !row[front];
        }

        return image;
    }
};
//https://leetcode.com/problems/flipping-an-image/
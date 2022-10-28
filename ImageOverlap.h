class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<int> a, b;
		//<distance, amount of times the distance was found>
        unordered_map<int,int> distance;
        
        for(int i=0; i<n*n; i++)
            if(img1[i/n][i%n] == 1)
                a.push_back(i / n * 100 + i % n);
        for(int i=0; i<n*n; i++)
            if(img2[i/n][i%n] == 1)
                b.push_back(i / n * 100 + i % n);

        for(const auto &i : a)
            for(const auto &j : b)
                distance[i-j]++;
        
        int max_overlap = 0;
        for(const auto &it : distance) 
            max_overlap = max(max_overlap, it.second);
        return max_overlap;
    }
};
//https://leetcode.com/problems/image-overlap/

/*
index of A and B = [0, N*N -1] 

(1) loop through 'img1' and for each 1 encountered: save its location in vector 'a' as  i/n*100 + i%n
	we use 100 because we need a value > 2*n-1 (n max 30 for this problem)  
	this way we get, for example, vector a=[0, 1, 101, 201] 
	for img1 = [[1,1,0],[0,1,0],[0,1,0]] 
(2) loop through 'img2' and save locations of '1's in b the same way 
(3) loop through all a and b and increment each distance encountered at [a[i]-b[j]
(4) max distance contains the desired result
*/
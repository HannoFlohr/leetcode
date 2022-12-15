class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = 0, n2 = 0, i1 = 0, i2 = 0;

        while(i1 < version1.size() || i2 < version2.size()) {
            while(i1 < version1.size() &&  version1[i1] != '.')
                n1 = 10 * n1 + (version1[i1++]-'0');
            while(i2 < version2.size() &&  version2[i2] != '.')
                n2 = 10 * n2 + (version2[i2++]-'0');
            
            if(n1 < n2) return -1;
            else if(n1 > n2) return 1;

            n1 = 0, n2 = 0;
            i1++, i2++;
        }

        return 0;
    }
};
//https://leetcode.com/problems/compare-version-numbers/
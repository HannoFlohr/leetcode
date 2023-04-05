class Solution {
private: 
    bool isGoodInteger(int n) {
        int x;
        bool rotating = false;
        while(n) {
            x = n%10;
            
            if(x==3 || x==4 || x==7)
                return false;
            if(x==2 || x==5 || x==6 || x==9)
                rotating = true;
            
            n /= 10;
        }
        return rotating;
    }
	
public:
    int rotatedDigits(int n) {
        int good_integers = 0;
        for(int i=2; i<=n; i++)
            good_integers += isGoodInteger(i);
        return good_integers;
    }
};
//https://leetcode.com/problems/rotated-digits/
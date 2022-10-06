class Solution {
private:
    bool selfDivides(const int& n) {
        int mod, x = n;
        while(x) {
            mod = x % 10;
            x /= 10;
            if(mod==0 || n % mod != 0) 
                return false;
        }
        return true;
    }
    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left; i<=right; i++)
            if( selfDivides(i) )
                result.push_back(i);
        
        return result;
    }
};
//https://leetcode.com/problems/self-dividing-numbers/
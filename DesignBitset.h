class Bitset {
private:
    vector<bool> bits;
    int ones, bitsSize;
    bool isFlipped;

public:
    Bitset(int size) {
        bits = vector<bool> (size, 0);
        bitsSize = size;
        ones = 0;
        isFlipped = false;
    }
    
    void fix(int idx) {
        if((bits[idx] + isFlipped) % 2 == 0) {
            ones++;
            bits[idx] = !bits[idx];
        }
    }
    
    void unfix(int idx) {
        if((bits[idx] + isFlipped) % 2 == 1) {
            ones--;
            bits[idx] = !bits[idx];
        }
    }
    
    void flip() {
        isFlipped = !isFlipped;
        ones = bitsSize - ones;
    }
    
    bool all() {
        return ones == bitsSize;
    }
    
    bool one() {
        return ones >= 1;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string bitset = "";
        for(const auto& bit : bits)
            bitset.push_back((bit + isFlipped) % 2 == 1 ? '1' : '0');
        return bitset;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
 
 //https://leetcode.com/problems/design-bitset/
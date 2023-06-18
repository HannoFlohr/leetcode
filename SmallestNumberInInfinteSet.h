class SmallestInfiniteSet {
private:
    int smallest_infinite;
    set<int> added_back;

public:
    SmallestInfiniteSet() {
        smallest_infinite = 1;
    }
    
    int popSmallest() {
        if(!added_back.empty()) {
            int smallest = *added_back.begin();
            added_back.erase(smallest);
            return smallest;
        }

        smallest_infinite++;
        return smallest_infinite-1;
    }
    
    void addBack(int num) {
        if(smallest_infinite > num)
            added_back.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
 
 //https://leetcode.com/problems/smallest-number-in-infinite-set/
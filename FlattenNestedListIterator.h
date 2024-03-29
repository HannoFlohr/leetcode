/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> start, end;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        start.push(nestedList.begin());
        end.push(nestedList.end());
    }
    
    int next() {
        hasNext();
        return (start.top()++)->getInteger();
    }
    
    bool hasNext() {
        while(start.size()) {
            if(start.top() == end.top()) {
                start.pop();
                end.pop();
                continue;
            }

            auto cur = start.top();
            if(cur->isInteger()) {
                return true;
            }

            start.top()++;
            start.push(cur->getList().begin());
            end.push(cur->getList().end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
 
 //https://leetcode.com/problems/flatten-nested-list-iterator/
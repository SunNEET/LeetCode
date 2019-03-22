class Solution {
    /*
        用 BFS 的方式做類似 tree-level order traversing
        sum += 現在的level * isInteger 的數字
        如果還不是 Integer 表示還是 nestedInteger
        要透過 getList() 取出內層元素後 push 到 queue
    */
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        if(!nestedList.size()) return 0;
        int sum = 0, level = 1;
        queue<NestedInteger> q;
        for(auto nest_int : nestedList) q.push(nest_int);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto nest_int = q.front();
                q.pop();
                if(nest_int.isInteger()) sum += nest_int.getInteger()*level;
                else {
                    auto inner_nestedlist = nest_int.getList();
                    for(auto inner_nest_int : inner_nestedlist) {
                        q.push(inner_nest_int);
                    }
                }
            }
            level++;
        }
        return sum;
    }
};
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
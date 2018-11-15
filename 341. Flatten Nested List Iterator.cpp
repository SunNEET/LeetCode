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
    /* 
        Solution: 基於呼叫 next() 前，會先用 hasNext() 確認的前提，來設計這個 Iterator。
        為了滿足 next() 和 hasNext() 的需求，我們需要保存它當前的狀態，也就是目前處理到哪個 NestedInteger 了。
        (1) 在建構式裡把list的元素反過來push進去，這樣就滿足我們next走訪的順序。
        (2) 在 hasNext 裡確認 stack 是否空了，空了就回傳 false，沒空就看當前 top 元素是否是單純的integer(isInteger)。
            - 如果是，那就回傳 true，不用做事
            - 如果不是，代表是個 list，我們需要把他壓平。先透過 getList 拿到這個 NestedInteger 的 list
              這 list 裡的元素有可能是 integer 也有可能是 list，但這邊不管，反正就是 list 裡的東西通通塞 stack
              反正如果又遇到 list 的話，就再重複一樣的動作就好。
        (3) 在 next 裡就直接回傳 top 元素(getInteger)就好，list 在 hasNext 就被處理好了

        Time Complexity: 

        Edge cases: 

    */
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=(int)nestedList.size()-1;i>=0;i--)
            st.push(nestedList[i]);
    }

    int next() {
        auto top = st.top();
        st.pop();
        return top.getInteger();
    }

    bool hasNext() {
        while(!st.empty()) {
            NestedInteger cur = st.top();
            if(cur.isInteger()) return true;
            st.pop();
            for(int i=(int)cur.getList().size()-1;i>=0;i--)
                st.push(cur.getList()[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
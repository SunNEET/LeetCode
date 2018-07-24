// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// 題意是說, 要我們實作一個peek()能偷看下一個元素的val, 但不會動到iterator的位置
// 題目註解有強調不要直接操作nums作弊哈哈, 只能用Iterator提供的method
// 第一種方法可以直接用Copy constructor就好, 這樣可以直接知道當下iterator的狀況
// 做了操作又不會影響到原本的, 所以就對這個copy出來的iterator直接做next然後回傳就好
// 
class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        // this是指向自己這個物件的 指標, 所以要加*轉回物件傳進去
        return Iterator(*this).next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }

    bool hasNext() const {
        return Iterator::hasNext();
    }
};
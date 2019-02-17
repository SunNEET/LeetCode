class MedianFinder {
    /*
        可以用兩個 heap 來處理這個問題，一個是 minHeap 而另一個是 maxHeap。
        透過將輸入的資料拆成兩個部分來儲存，我們能夠用O(1)的時間取得中位數
        By breaking up the input data into two heaps, we're able to get
        medium number in O(1) time.
        
        e.g. [4,3,2,....]
        left(maxHeap)  right(minHeap)
        [2,3]          [4]
           ^ when total size is odd
        [1,2]          [3,4]
           ^            ^
            when total size is even           
            
        當輸入數字(addNum)的時候，我們將數字插入到其中一個 heap，
        根據 num 的大小來決定，先跟 left 的 top 比，<=就插入left，否則就right
        
        先插入左邊的理由是因為我想維持 left  >= right
        這樣找 median 的時候我就可以保證會是左邊的max
        或是 the top value of the two heaps by 2
        
        注意我需要平衡兩側的大小，這樣才可以維持中位數在上面所說的位置
        所以當 right > left 的時候，就把right的top給left
        當left-right>=2的時候，就把left的top給right

        Time: O(1) for findMedian, O(logn) for addNum
        Space: O(n)
    */
private:
    priority_queue<int, vector<int>, less<int>> left; // maxHeap
    priority_queue<int, vector<int>, greater<int>> right; // minHeap
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    // keep left.size() >= right.size()
    void addNum(int num) {
        // Step 1: select one heap to insert
        if(left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);
        // Step 2: balance two heaps 
        if(left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        } else if(left.size() - right.size() >= 2) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return (double)left.top();
        else
            return (double)(left.top()+right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

class MedianFinder {
    /*
        另一種做法是用語言內建的 balanced binary search tree, 像是 c++ 的 multiset。
        利用這種結構來完成有排序的資料存儲. It takes O(logn) for inserting a new element.
        We need two pointers to keep track of the median position in the tree.
        
        指針的移動分成四種情況
        New BST size is odd number:
        (1) input >= *right, e.g. 2,2,3,4 => 2,2,3,4,6
                                    ^ ^              ^ new input
                                    l r        l r
                                    這個情況需要將l往右移
        (2) input < *right, e.g. 2,2,3,4 => 1,2,2,3,4
                                   ^ ^      ^   
                                   l r          l r
                                            需要將 r 左移 且 assign 給 l
                                            因為當插入一個一樣大的元素的時候，BST會把他
                                            放到最後一個位置
                                        2,2,2,3,4
                                          ^ ^ ^ 
                                          l ^ r
                                            new
                                            像這種情況，如果單純只左移 r 的話，l並不會指向
                                            目前 median 的 position
        even number:
        (1) input >= *right, e.g. 2,2,3,4,6 => 2,2,3,4,6,9
                                      ^                  ^
                                      lr
                                      需要將r右移
        (2) input < *right, e.g. 2,2,3,4,6 => 1,2,2,3,4,6
                                     ^            ^ ^   ^
                                     lr           l r
    */
    
    multiset<int> BST;
    multiset<int>::iterator left; // current left median
    multiset<int>::iterator right;// current right median
public:
    /** initialize your data structure here. */
    MedianFinder():left(NULL),right(NULL){}
    
    void addNum(int num) {
        if(BST.empty()) {
            left = right = BST.insert(num);
            return ;
        }
        BST.insert(num);
        int sz = BST.size();
        if(sz&1) {
            if(num >= *right) left++;
            else left = --right;
        } else {
            if(num >= *right) right++;
            else left--;
        }
    }
    
    double findMedian() {
        if(BST.size()&1)
            return *right;
        else
            return (double)(*right + *left)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
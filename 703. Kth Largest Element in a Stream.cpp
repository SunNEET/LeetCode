class KthLargest {
    /*
        Use a minHeap with size K, then the element remained at the top of the heap is going to be the KthLargest
        minHeap [8,9,10]

        Time:  O(logK) for each add() call, O(NlogK) for init the data)
        Space: O(K)
    */
public:
    KthLargest(int k, vector<int> nums):k_(k), pq_(nums.begin(), nums.end()){
        while(pq_.size()>k) pq_.pop();
    }
    
    int add(int val) {
        pq_.push(val);
        if(pq_.size() > k_)
            pq_.pop();
        return pq_.top();
    }
private: 
    int k_;
    priority_queue<int,vector<int>,greater<int>> pq_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
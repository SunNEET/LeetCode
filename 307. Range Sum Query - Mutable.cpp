class NumArray {
    /*
      RSQ: 指標版線段樹
      new 的 cost 比較大，所以會比 array 版花更多時間，但實作上比較直觀

      首先建立 SegmentTreeNode, 裡面有
      - int start, end: 代表區間的範圍
      - left, right 指向左右子節點
      - sum 代表這個區間的合
      然後是根據 input 的 vector 建樹，基本上我們就是一直把現在的區間，
      拆成兩半給左右節點，讓他們建出子樹，然後再把這兩個子樹的sum加總，就是自己的sum。
      base case 是 start == end 的時候。

      update的做法：
      因為結構上就是個 binary tree，對於特定位置的i只要O(logN)就可以到達並且更新他的值，
      把他的值 update 了以後，往回 return 的過程中順便把區間的 sum 都更新。

      sumRange的做法：
      base case: 如果要查詢的區間頭尾就是目前的區間頭尾，直接回傳 sum
      不然的話都是把查詢區間往涵蓋答案的部分送過去，如果查詢的 end <= 目前的 mid 表示答案都只在左半邊，
      start >= mid+1 表示都在右半邊，蓋到 mid 的情況就分成左右兩塊下去查詢

      坑點:
      (1) 記得 update 完回傳的時候要順便更新區間
      (2) update 和 sumRange 裡的 start end 是看區間的(root的) 而不是 query 的。
    */
    struct SegmentTreeNode {
        int start, end;
        SegmentTreeNode *left, *right;
        int sum;
        
        SegmentTreeNode(int _start, int _end)
            :start(_start),end(_end),left(NULL),right(NULL),sum(0) {}
    };
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(const vector<int>& nums, int start, int end) {
        SegmentTreeNode* ret = new SegmentTreeNode(start,end);
        if(start == end) {
            ret->sum = nums[start];
        } else {
            int mid=start+(end-start)/2;
            ret->left = buildTree(nums,start,mid);
            ret->right = buildTree(nums,mid+1,end);
            ret->sum = ret->left->sum + ret->right->sum;
        }
        return ret;
    }
    void update(SegmentTreeNode* root, int pos, int val) {
        if(root->start == root->end) {
            root->sum = val;
        } else {
            int mid = root->start+(root->end-root->start)/2;
            if(pos <= mid) {
                update(root->left, pos, val);
            } else {
                update(root->right, pos, val);
            }
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
    int sumRange(SegmentTreeNode* root, int start, int end) {
        if (root->end == end && root->start == start) {
            return root->sum;
        } else {
            int mid=root->start+(root->end - root->start)/2;
            if (end <= mid) {
                return sumRange(root->left, start, end);
            } else if (start >= mid+1) {
                return sumRange(root->right, start, end);
            }  else {    
                return sumRange(root->left, start, mid)+sumRange(root->right, mid+1, end);
            }
        }
    }
public:
    NumArray(vector<int> nums) {
        if(nums.size())
            root = buildTree(nums, 0, nums.size()-1);    
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
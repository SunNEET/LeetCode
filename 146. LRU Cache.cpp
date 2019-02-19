class LRUCache {
    /*
        使用兩種資料結構，hashmap 和 doubly linked list
        hashmap 的 key 就是該 key-value 的 key, 
        而他的 value 則是一個 iterator，指向 linked list 上該 key 所在的節點
        hashmap 是用來判斷該 key 存不存在以及快速定位到 linked list 上的 key 節點
        
        doubly linked list 則是存著 pair<int,int>
        pair的第一個元素是 key, 第二個就是 value 了
        透過移動 linked list 的 iterator 來把有使用的向前移動
        
        list 的 splice 用法
        從某個list移動單一元素到某個位置
        void splice (const_iterator position, list& x, const_iterator i);
                                    ^ 插入的位置 ^ 來自哪個list ^ 該list的iterator
        
        We need two data structures, hashmap and doubly linked list, to address this problem.
        The key of the hashmap is the key of the key-value we input,
        and its value is an iterator, pointing to a node on the linked list
        Hashmap is used to determine if the input key exists or not, and quickly find out where
        the node is on the linked list.

        Doubly linked list is used as cache, I'll store pair<int,int> inside it.
        The first element of pair is key, and the second one is value.
        I'll move the recent used node towards beginning of the list by using its iterator and splice


    */
public:
    LRUCache(int capacity):capacity_(capacity) {
        
    }
    
    int get(int key) {
        auto it = m_.find(key);
        // if key doesn't exist
        if(it == m_.end()) return -1;
        // Move this key to the front of the list
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m_.find(key);
        
        // key already exist
        if(it != m_.end()) {
            it->second->second = value;
            // Move this key to the front of the list
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        // key doesn't exist
        // Reach the capacity, remove the oldest element
        if (cache_.size() == capacity_) {
            auto node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }
        // Insert the entry into list and update mapping
        cache_.insert(cache_.begin(), make_pair(key,value));
        // cache_.emplace_front(key,value);
        m_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int,list<pair<int,int>>::iterator> m_;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
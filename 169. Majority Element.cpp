class Solution {
    /*
      方法1: HashTable
      因為majority element的條件是出現超過n by 2 floor times，所以只會存在一個
      當 cnt 超過 n by 2 floor 的時候就可以直接回傳了，不用全部走完

      Time: O(N)
      Space: O(N)
    */
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int i=0; i<nums.size(); i++)
            if(++cnt[nums[i]]>(int)nums.size()/2)
                return nums[i];
        return 0;
    }
};

class Solution {
    /*
        方法2: 用 quick_select 挑出排第 n/2 個的值 (在nums從小排到大已經排序好的情況)
        這個值就會是答案
        這是因為 majority element 超過 n by 2 floor 個，所以不管他是從nums開頭開始
        出現的最小元素，還是會出現在尾端的最大元素，他必定會 cover 到nums中間的地方
        
        nth_element 就是做 quick select，但他沒有回傳值，只負責把填進去的第 n 個
        element 的值填好

        Time: average O(N), worst case O(N^2)
        Space: O(1), no extra space;
    */
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
    /*
        方法3: 隨機挑
        這東西能行得通也是很瞎，總之就是隨邊挑一個數當candidate
        統計他的 occurrence，超過 n/2 就return 否則就隨機找下一個
        
        因為正確的candidate會超過 n/2 個所以每次隨機挑其實都有超過 50% 的機率選到
        Time: O(?)
        Space: O(1)
    */
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(time(NULL));
        while(true) {
            int idx = rand()%n;
            int candidate = nums[idx];
            int cnt = 0;
            for(int i=0; i<n; i++) {
                if(nums[i] == candidate)
                    cnt++;
            }
            if(cnt > n/2) return candidate;
        }
    }
};

class Solution {
private:
    /*
        方法4: D&C
        不是很直觀的方法，而且時間複雜度還比較高，就是一直把array分兩邊然後看左右兩邊的majority 分別是什麼，如果一樣直接回傳，不一樣的話就要看他們在這個區間誰出現的比較多次。
        
        Time: O(nlogn)
        Space: O(n), for function stack
    */
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
    
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
};

class Solution {
    /*
        方法5: Moore Voting Algorithm
        
        This Method only works when we are given that majority element do exist in the array. 
        Basic idea of the algorithm is that if we cancel out each occurrence of an element e 
        with all the other elements that are different from e then e will exist till end 
        if it is a majority element.
        
        簡而言之，走訪 nums 的時候，如果目前沒人當major那就是讓現在的元素當 major
        當有人當 major 的時候，他如果遇到跟自己一樣的 nums[i] 就增加 cnt，
        但他的 cnt 會被跟他不一樣的nums[i]抵銷。cnt 變 0 的話再下個數就會變成新的major，以此類推。這方法行得通是因為 major 出現超過 n by 2 次，所以就算一直被抵銷掉，
        他最終也還會是 major。
        
        Time: O(n)
        Space: O(1)
    */
public:
    int majorityElement(vector<int>& nums) {
        int major, cnt = 0;
        for(int i=0; i<(int)nums.size(); i++) {
            if(!cnt) {
                major = nums[i];
                cnt = 1;
            } else {
                cnt += (nums[i] == major) ? +1 : -1;
            }
        }
        return major;
    }
};
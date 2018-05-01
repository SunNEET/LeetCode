class Solution {
    // 用2sum的方式來做，可以把時間複雜度降到O(N^2)，但空間複雜度會用掉O(N^2)
    // 雙層for迴圈把i,j能組出的sum先存到map
    // 然後再枚舉k,l，用target - (a[k]+a[l]) 去查找map O(1)
    
    // 這題在建hash和最後枚舉的時候，為了排除重複的狀況，需要比較特別的處理方法，要特別注意！
    // 簡單的說，就是建表的時候要以靠右邊的組合為最優先(重複的時候)，而枚舉的時候就以靠左邊的組合為優先(重複的時候)。
    // 這樣左邊右邊才兜得出sum，而不會在有解的情況下，i出現在l的左邊，導致解答被跳過。
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        printf("case: \n");
        vector<vector<int>> ans;
        unordered_map<int,vector<vector<int>>> hash;
        sort(nums.begin(),nums.end());
        if (nums.size() < 4) return ans;
        
        // for(int i=0;i<nums.size()-1;i++) {
        //     // 排除index不同但nums[i],nums[j]的值是相同的情況，避免後面map查找出現重複解。
        //     if(i>0 && nums[i] == nums[i-1]) 
        //         continue;
        //     for(int j=i+1;j<nums.size();j++) {
        //         if(j-i>1 && nums[j] == nums[j-1])
        //             continue;
        //         vector<int> tmp;
        //         tmp.push_back(i);
        //         tmp.push_back(j);
        //         hash[nums[i]+nums[j]].push_back(tmp);
        //     }
        // }
        
        // 為了留下想要的組合，需要從後面往回掃來建map！
        // 這是因為像[-3,0,0,3]，如果我們用正著掃，並且排除重複的情況，我們會得到{(0,1),(0,3),(1,2),(1,3)}，遇到重複的情況會優先保留左邊的。
        // 但這樣會讓我枚舉不出答案，因為我用來排除重複的方式是在枚舉(k,l)查找hash的時候，抓出來的(i,j)必須i>l
        // 而上面的方法會讓我抓出(i,j)的i位於(如果是同數字)排列的最左邊，使得i,l交錯而求不出解(我們要{....,0,3}而不能是{0,...,3})
        // 而從右邊掃回來並排除重複的做法，可以確保我們保留的是連續重複值中，“最右邊”的那組，這樣才能跟等會兒的枚舉組合起來。
        for(int j=nums.size()-1;j>=1;j--) {
            if(j<nums.size()-1 && nums[j]==nums[j+1])
                continue;
            for(int i=j-1;i>=0;i--) {
                if(j-i>1 && nums[i]==nums[i+1])
                    continue;
                hash[nums[i]+nums[j]].push_back({i,j});
            }
        }
        // for(unordered_map<int,vector<vector<int>>>::iterator it=hash.begin(); it!=hash.end(); it++) {
        //     for(int j=0;j<(int)it->second.size();j++) {
        //         printf("sum=%d, index=%d, %d\n", it->first, it->second[j][0], it->second[j][1]);
        //     }
        // }
        int ssum;
        for(int k=0;k<nums.size()-1;k++) {
            //避免枚舉到一樣值，而抓出相同的解
            if(k>0 && nums[k]==nums[k-1]) 
                continue;
            for(int l=k+1;l<nums.size();l++) {
                //同上
                if(l-k>1 && nums[l]==nums[l-1]) 
                    continue;
                ssum = nums[k] + nums[l];
                auto it = hash.find(target-ssum);
                if(it!=hash.end()) {
                    // 遍歷同一種sum裡不同的i,j組合,如果有的話
                    for(auto v: it->second) {
                        // i>l，為了要避開抓到相同的index。因為j>i且l>k，所以當i>l的時候就可以確保map抓出來的i,j一定在k,l後面，不會重複
                        if(v[0]>l)
                            ans.push_back({nums[k],nums[l],nums[v[0]],nums[v[1]]});
                    }
                }
            }
        }
        return ans;
    }
};
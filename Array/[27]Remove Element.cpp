class Solution {
public:
    // 直覺作法: 遇到指定的val直接用vector自帶的erase移除掉
    // 有一點要注意，當使用erase的時候，erase會回傳移除後當下的位置。也就是說，erase移除完當前的值之後，會將後面的值補到原來被移掉的位置上，而這就相當於是一個it++了(因為it已經指向下一個value)。假如直接將it++寫在for(;;)裡，就會出問題(有內容被跳過/it出界) 
    // i.e [3,2,2,3] 3
    // 就會造成第一個2被跳過，以及最後面的3刪完後又做一次it++導致runtime error
    // 處理方式： 把it++改寫在迴圈內容中，有做erase的時候就不做。
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator it=nums.begin();it!=nums.end();){
            if (*it == val) {
                // printf("remove前 val=%d\n",*it);
                nums.erase(it);
                // printf("remove後 val=%d\n",*it);
            } else {
                it++;
            }
        }
        return (int)nums.size();
    }
};
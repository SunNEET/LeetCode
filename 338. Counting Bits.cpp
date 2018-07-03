class Solution {
    // 透過觀察規律, 可以看出從每2^n的區間的1的數量, 其實就是前面2^(n-1)的次方的值, 
    // 重複一遍然後把下面那組通通+1... ex:
    // i | bit       k   
    // 0 | 0         
    // 1 | 0+1    #2^0  
    // 2 | 1      #2^1
    // 3 | 1+1=2  ____  
    // 4 | 1      #2^2
    // 5 | 2
    // 6 | 1+1=2   
    // 7 | 2+1=3  ____
    // 8 | 1      #2^3

public:
    vector<int> countBits(int num) {
        if(num==0) return {0};
        vector<int> ans = {0,1};
        int i=2, k=2;
        while(i<=num) {
            // 從i=2^(k-1)開始到2^k次方個區間, 會滿足上面說的規律
            // 前半就是直接拿前面的值, 後面就是前半抄過來再通通+1
            for(i=pow(2,k-1);i<pow(2,k);i++) {
                // 超過了 提早break
                if(i>num) break;
                // 這個區間的一半其實就是前一個區間的大小
                int t = pow(2,k-2);
                // 還在前半段, 照抄前面, 所以用目前的i扣掉前一個區間的大小就可以了
                if (i < pow(2,k-1) + t)
                    ans.push_back(ans[i-t]);
                else
                    ans.push_back(ans[i-t]+1);
            }
            k++;
        }
            
        return ans;
    }
};
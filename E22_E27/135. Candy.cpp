class Solution {
    // 貪婪
    // 先給所有人一顆糖, 然後從左往右掃一遍, 讓ratings[i+1]>ratins[i]的都加1, 否則就是1
    // 這樣做可以確保每個人會比自己正左邊rating較低的還多一顆
    // 但這樣會發生相鄰rating一樣的, 後面的還是只分一個, 而可能再往右的值比這個小
    // 為了要確保他們會比正右邊,較低rating的大, 所以要再做一次從右掃到左
public:
    int candy(vector<int>& ratings) {
        int len = (int)ratings.size();
        vector<int> cnt(len,1);
        for(int i=1;i<len;i++) {
            if(ratings[i]>ratings[i-1])
                cnt[i] = cnt[i-1]+1;
        }
        // 把前面因為連續同rating,而只有1顆糖的加到比右邊raring低得多一顆
        // 如果他本來就比右邊rating小於自己的多, 那保持一樣就好了
        // ex: [1,3,4,5,2] 這邊上面for做完後的cnt會是[1,2,3,4,1]
        // 這時就不用管那個拿4顆的了, 否則用cnt[i+1]+1還會變少
        // 需要用cnt[i+1]+1的只有連續同rating的最後一個數
        for(int i=len-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1])
                cnt[i] = max(cnt[i],cnt[i+1]+1);
        }
        for(int i=0;i<len;i++)
            printf("%d ",cnt[i]);
        puts("");
        int ans=0;
        for(int i=0;i<len;i++)
            ans += cnt[i];
        return ans;
    }
};
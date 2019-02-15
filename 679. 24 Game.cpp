class Solution {
    /*
      DFS 窮舉
      (1) 為了要做出類似 real division 的效果，定 eps 為 10^-6，當最後運算出來的結果跟
          24不差超過 eps 的話，就表示用普通的除法運算也能求出整數的24。

      (2) 在DFS裡雙層for迴圈枚舉兩個元素，把他們的加減乘除能得出的結果都做一遍，放到一個vector，假設叫next裡
          存著，等等會從這個 vector 裡拿元素出來加到 arr 然後繼續遞回。注意加跟乘順序不影響結果，所以只要
          各做一次，但減跟除都要考慮 num1, num2 分別在前後的可能性，而且除法的時候要注意分母絕對值不能
          小於 eps。
      
      (3) 把枚舉的兩個元素從 arr 中移除，枚舉 next 中的各種計算結果進 arr，遞迴，
          結束後把被移除的原本兩個元素加回去。這裏要注意移除跟補回去的先後順序，在我
          的枚舉方法中，j 必定在 i 的右側，所以移除時需要先移j再移i，才不會因為array
          移動的關係移錯格(當然手動指定j+1之類的也行但就是不直觀)，補回去同理，先補i
          再補j。

      Time: O(N^2), DFS裡的雙層 for 迴圈，遞迴深度因為最多就三層所以差不多可以無視
      Space: O(N)

    */
    bool res = false;
    const double eps = 1e-6;
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr(nums.begin(), nums.end());
        DFS(arr);
        return res;
    }
    
    void DFS(vector<double>& arr) {
        if(res) return;
        if(arr.size() == 1) {
            if(abs(arr[0]-24.0) < eps)
                res = true;
            return;
        }
        for(int i=0; i<arr.size()-1; i++) {
            for(int j=i+1; j<arr.size(); j++) {
                vector<double> next;
                double num1 = arr[i], num2 = arr[j];
                next.push_back(num1+num2);
                next.push_back(num1*num2);
                next.push_back(num1-num2);
                next.push_back(num2-num1);
                if(abs(num2) > eps)  next.push_back(num1/num2);
                if(abs(num1) > eps)  next.push_back(num2/num1);
                // 要先移除 j 再移除 i，因為 j 必定在 i 的右側，
                // 如果先移除 i 的話會導致 j 的相對位置改變，
                // 就變成要移的元素會位在 j-1 的位置
                arr.erase(arr.begin()+j);
                arr.erase(arr.begin()+i);
                for(double num : next) {
                    arr.push_back(num);
                    DFS(arr);
                    arr.erase(arr.begin()+arr.size()-1);
                }
                // 要先把 i 移回去，不然先插入 j 再插入 i 的話，
                // 會導致 j 的相對位置跑掉，最後變成在 j+1 的位置
                arr.insert(arr.begin()+i, num1);
                arr.insert(arr.begin()+j, num2);
            }
        }
    }
};
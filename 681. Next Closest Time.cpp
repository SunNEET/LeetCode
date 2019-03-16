class Solution {
    /*
        從右往左，一個位數一個位數的考慮，解題的邏輯跟 next perm 和 prev perm 其實有點類似
        如果現在這個位數可以從 4 個數字裡找到一個：
        (1) 比他大 
        (2) 不超過該位子的 upperlimit (比方說 HH:_M 的位子就不能超過5, 只能是0~5)
        找的到的話就將該位數的結果寫到 res 上然後直接 return
        否則的話，就找最小的放上去，因為接下來會往左邊找，把位於他左邊的數字換成更大的，
        這樣出來的結果才會是最接近的下個結果(跟 next perm 的道理一樣)
        
        Time:  O(NlogN), where N is only 4 right here... 
        Space: O(N), N is only 4 as well...
    */
public:
    string nextClosestTime(string time) {
        string res(time);
        vector<char> digits = {time[0], time[1], time[3], time[4]};
        sort(digits.begin(), digits.end());
        res[4] = findNext(res[4], '9'+1 , digits);
        if(res[4] > time[4]) return res;
        res[3] = findNext(res[3], '6', digits);
        if(res[3] > time[3]) return res;
        res[1] = res[0] == '2' ? findNext(res[1], '5', digits) : findNext(res[1], '9'+1, digits);
        if(res[1] > time[1]) return res;
        res[0] = findNext(res[0], '3', digits);
        
        return res;
    }
    
private:
    char findNext(char cur_dg, char upperlimit, vector<char>& digits) {
        int idx = upper_bound(digits.begin(), digits.end(), cur_dg) - digits.begin(); 
        if(idx < 4 && digits[idx] < upperlimit) return digits[idx];
        else return digits[0];
    }
};
class Solution {
    /*
        直覺作法就是每次看到 start 就把 log 推進 stack 裡，
        當遇到 end 的時候，就拿現在的 log 跟他比較 timestamp，計算過了多久，得到 times 。
        而且現在 stack 裡的 top 一定跟他是同一個 id，
        (中間不同 id 的會先遇到同 id 的 end 將它 pop 掉，否則這 function call 邏輯不對)
        有點類似 matching parentheses 問題。

        關鍵點在於 function 只計算它本身實際有用到的時間，所以必須扣掉它裡面那層佔用了多久，
        因此最終結果會是 res = times - 裡面一層佔用的時間。
        這裡有個實作上的技巧，因為我是從最內層開始處理的，所以每當算出內層的時間後，就先把外層的
        res 減掉現在的 times(記得確認還有外層，也就是st不為空)，之後處理外層的時候再把外面的 times 加進 res。
        
    */
private:
    struct Log {
        int id;
        string status;
        int timestamp;
    };
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        stack<Log> st;
        
        for(int i=0;i<(int)logs.size();i++) {
            vector<string> tmp = splitLog(logs[i]);
            Log item = {
                stoi(tmp[0]),
                tmp[1],
                stoi(tmp[2])
            };
            if(item.status == "start") {
                st.push(item);
            } else {
                int times = item.timestamp - st.top().timestamp + 1;
                res[item.id] += times;
                st.pop();
                if(!st.empty())
                    res[st.top().id] -= times;
            }
        }
        return res;
    }
    
    vector<string> splitLog(string log) {
        vector<string> res;
        int idx = 0,pre = 0;
        while(idx < log.length() && log[idx++]!=':');
        res.push_back(log.substr(pre,idx-pre-1));
        pre = idx;
        while(idx < log.length() && log[idx++]!=':');
        res.push_back(log.substr(pre,idx-pre-1));
        res.push_back(log.substr(idx));
        return res;
    }
};
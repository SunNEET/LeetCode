class Solution {
public:
    // pretty confusing question.
    // It means when there's a sequence "1", we read it as "one 1"
    // so the next term would be "11"
    // then "two 1s" => "21"
    // "one 2 one 1" => "1211"
    string countAndSay(int n) {
        if(n==0) return "";
        string ans = "1";
        n--;
        while(n--) {
            string cur = "";
            for(int i=0;i<ans.size();i++) {
                int cnt = 1;
                // 1 (i=0, cnt=1)
                // ^  => 11
                // 11 (i=0, cnt=1)
                // ^ 
                // 11 (i=1, cnt=2)
                //  ^ => 21
                while( i+1<ans.size() && ans[i]==ans[i+1] ) {
                    cnt++;
                    i++;
                }
                cur += to_string(cnt) + ans[i];
            }
            ans = cur;
        }
        return ans;
    }
};
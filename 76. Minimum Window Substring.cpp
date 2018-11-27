class Solution {
    /*
        
        用一個 hashmap 來記錄 t 裡字元的出現次數，這表示我們至少要找這個元素幾次，然後用 two pointer 掃 s。
        宣告一個 counter = T 的長度，表示需要找到這麼多目標。
        接著如果做 sliding window 時， r 遇到的是 hashmap 裡的元素，
        且它還沒在 sliding window 裡找齊 (hash[i] > 0)，就把 counter - 1;
        當 counter == 0 時，表示 [l,r] 內的 value 涵蓋了 target 的字元，更新res和長度
        然後一直移動 l，直到 target 又不滿足 (counter > 0) 了
    
        clarify: 
        (1) Does the input string contain only letters?
        (2) How long the two string can be?
        (3) What should I return if there ie no such window?
        (4) Will it have multiple minimum window?
    */
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hash;
        for(int i=0; i<t.length(); i++) hash[t[i]]++;
        int counter = t.length();
        string str = "";
        int l = 0, r = 0, minLen = INT_MAX, head = 0;
        while(r < s.length()){
            if(hash[s[r]]-- > 0)
                counter--;
            r++;
            while(counter==0) { // valid
                if(r - l< minLen) {
                    minLen = r-l;
                    head = l;
                }
                if(hash[s[l]]++==0) 
                    counter++; // make it invalid
                l++;
            }
            
        }
        return minLen == INT_MAX ? "" : s.substr(head,minLen);
    }
};
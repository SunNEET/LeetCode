class Solution {
    // 所謂的shift就是把一個string裡的每一個char都換成他的下一個字母
    // 而題目就是要找出有同樣shift變化的string把他group起來 
    // 可以理解成字母間規律一樣, shift到後面可以成為group裡的任一個string
    
    // 而這可以用Hash來解決, 因為有同樣shift規律的string, 把每個char都減掉string開頭的首字母,
    // 相加求出來的Hash會是一樣 (小於0要加26, 例如yza這種情況)
    // 用這種方法把它還原成首字母由a開始shift的string, 藉此來分類
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        unordered_map<string, vector<string> > mp;
        for (string s : strings) {
            // 把Hash後一樣的s丟在一起, 然後推入原本的s
            mp[shift(s)].push_back(s);
            cout << shift(s) << "\n";
        }
        vector<vector<string> > groups;
        for (auto m : mp) {
            vector<string> group = m.second;
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
        return groups;
    }
    
    // 還原的方法是將每個字母扣掉開頭, 將char的 val 從 ascii 0 開始算
    // 在把diff串回新的字串上時加上lowercase開頭的'a'
    // 這樣就可以還原成首字母由a開始shift的string
    string shift(string& s) {
        string t;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int diff = s[i]-s[0];
            if (diff < 0)
                diff += 26;
            t += 'a' + diff;
        }
        return t;
    }
};
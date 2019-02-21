class Solution {
    /*
      用 stringstream 做字串處理，用一個 hashmap 來存有同樣內容的 file 的路徑
    */

public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files;
        vector<vector<string>> result;
        for(auto path : paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while(getline(ss, s, ' ')){
                string filename = root + '/' + s.substr(0, s.find('('));
                string filecontent = s.substr(s.find('(')+1, s.find(')'));
                files[filecontent].push_back(filename);
            }
        }
        
        for(auto file : files) {
            if(file.second.size()>1) {
                result.push_back(file.second);
            }
        }
        
        return result;
    }
};
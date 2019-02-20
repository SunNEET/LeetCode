class Solution {
  /*
    字串處理，直接做
  */
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> cnt;
        if(!emails.size()) return 0;
        for(int i=0; i<emails.size(); i++) {
            string email = emails[i];
            int j = email.find('@');
            string local_name = email.substr(0,j);
            string domain_name = email.substr(j+1,email.length()-j-1);
            string pre = "";
            for(int k=0; k<local_name.length(); k++) {
                if(local_name[k] == '.') continue;
                else if(local_name[k] == '+') break;
                else pre += local_name[k];
            }
            string res = pre + "@" + domain_name;
            cnt.insert(res);
        }
        return cnt.size();
    }
};
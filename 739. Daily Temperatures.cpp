class Solution {
    /*
        用 stack + hashmap，基本想法跟 496. next greater integer 一樣 
        不過這邊 map 跟 stack 都是存 index，
        因為題目是問差距 index 間的差距， 而且有重複，用 value 的話會有混淆
    */
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> st;
        unordered_map<int, int> next_greater_temp;
        for(int i=0; i<T.size(); i++) {
            while(!st.empty() && T[i] > T[st.top()]) {
                next_greater_temp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<T.size(); i++) {
            if(next_greater_temp.count(i)) 
                res[i] = next_greater_temp[i] - i;
            else
                res[i] = 0;
        }
        return res;
    }
};
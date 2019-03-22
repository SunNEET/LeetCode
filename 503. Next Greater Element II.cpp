class Solution {
    /*
        用 stack + hashmap，基本想法跟 496. next greater integer 一樣
        不過因為有重複，所以 stack 是存 index; hashmap 是存 {index, integer}
        因為可以循環搜，所以要延伸 array => [a1,a2,a3,a4,a1,a2,a3,a4] 像這樣
        這樣 a1 比 a2,a3,a4 大的情況，才會把他們的 next 寫成 a1
    */
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        unordered_map<int,int> next_greater_integer; //{integer_value, index}
        for(int i=0; i<n*2; i++) {
            int num = nums[i%n];
            while(!st.empty() && num > nums[st.top()]) {
                next_greater_integer[st.top()] = num;
                st.pop();
            }
            if(i < n) st.push(i);
        }
        for(int i=0; i<n; i++) {
            if(next_greater_integer.count(i)) res[i] = next_greater_integer[i];
        }
        return res;
    }
};
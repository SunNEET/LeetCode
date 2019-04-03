# LeetCode
LeetCode練習的備份，含註解

## 1. Two Sum:
Hashmap O(N)

## 2. Add Two Number:
Dummy node, while(l1||l2||carry)

## 3. Longest Substring Without Repeating Characters
unordered_map + sliding window
(1)while(right < s.length()) (2)if(!s.length()) return 0

## 4. Median of Two Sorted Arrays
(1) Find out a partition point of nums1 & nums2 s.t. the values in the left of the partition are all less than/equal to the right of partition
x1, x2 | x3
y1, y2 | y3, y4
=> x2 ≤ y3 && y2 ≤ x3 => if x2 > y3, move partitionX left by 1 step(which also make partitionY move right by 1 step); if y2 > x3 ...

(2) We want the number of elements on the left side of the merged array are (n+m+1)/2, (odd && odd, (3,3) => mid = 3, odd && even, (3,4) => 4, even && even, (2,2) => 2), so if we decide the partition place of nums1, it also decide the partition place of nums2.

(3) l=0, r=n, while(l<=r), maxleftX,minRightX,maxLeftY,minRightY 

## 5. Longest Palindromic Substring
Find out a res_start & res_len, try to start from every possible (i,i), (i,i+1)

## 6. ZigZag Conversion
---
Δ1 = 2n-2 Δ2 = 0            1                           2n-1                         4n-3
Δ1 = 2n-4 Δ2 = 2            2                     2n-2  2n                    4n-4   4n-2
Δ1 = 2n-6 Δ2 = 4            3               2n-3        2n+1              4n-5       .
Δ1 = ...  Δ2 =              .           .               .               .            .
Δ1 = ...  Δ2 =              .       n+2                 .           3n               .
Δ1 = 2n-2*(i+1)             n-1 n+1                     3n-3    3n-1                 5n-5
Δ1 = 0    Δ2 = 2n-2         n                           3n-2                         5n-4
---
Init delta1 = 2\*numRows-2\*(i+1); delta2 = 2*i;
We do it row by row
As row number gets bigger, delta1 gets smaller and delta2 gets bigger
\* if(pos >= len) break;

## 7. Reverse Integer
Overflow cases: (1) INT_MIN (2) ans > INT_MAN/10 (3) ans > INT_MAX + x%10
take off the sign and multiply it back when return

## 8. String to Integer (atoi)
Handle 4 cases: (1) discards all leading whitespaces (2)sign of the number
(3)overflow (4)invalid input

## 9. Palindrome Number
Special cases: (1) x<0 (2) only 1 digit
Without converting the integer to a string: get left half part and compare to right half part
12|1  => (12/10, 1) => true
12|21 => (12, 12) => true

## 10. Regular Expression Matching
Too hard to summarize...

## 11. Container With Most Water
2 pointer: move pointer points to shorter height move inside to look for higher height
while (height[i] <= h && i < j) i++; while (height[j] <= h && i < j) j--;

## 12. Integer to Roman
Define THOUS[]={"","M","MM","MMM"}, HUNDS[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}
, TENS[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};, ONES[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
THOUS[(num%10000)/1000]+HUNDS[(num%1000)/100]+TENS[(num%100)/10]+ONES[num%10]

## 13. Roman to Integer
最右邊開始往左一個一個看羅馬數字就好了
unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
if(roman[s[i]] < roman[s[i+1]]) sum -= roman[s[i]];
else sum += roman[s[i]];

## 14. Longest Common Prefix
從 0 開始枚舉 idx，然後比對所有字串的 s[idx] 字元，idx > s的長度或有不合就直接 return res

## 15. 3Sum
Sort + 2 pointers: 枚舉 nums[i]，然後往右看nums[left] 和 nums[right] 能否湊出 -nums[i]

## 16. 3Sum Closest
Sort + 2 pointers: 枚舉 nums[i]，然後往右看nums[left] 和 nums[right] 
if(sum == target) return sum, 用 abs(target-sum) 找距離最短的sum

## 17. Letter Combinations of a Phone Number
Map '2' -> "abc", '3' -> "def" ... + DFS enumerate each possible combination

## 18. 4Sum
用 O(N^2) extra space 建表，就可以用O(N^2)算出答案

## 19. Remove Nth Node From End of List
Method1: Dummy node + backtracking + counter
Method2: 2 pointers (slow & fast), Make fast n nodes ahead of slow

## 20. Valid Parentheses
stack + hashmap

## 21. Merge Two Sorted Lists
Dummy node + if(!l1 || (l2 && l2->val < l1->val))

## 22. Generate Parentheses
DFS + goal depth is 2*n + if(left < n) DFS(+'(') if(left>right) DFS(')')

## 23. Merge k Sorted Lists
D&C + Merge Two Sorted Lists

## 24. Swap Nodes in Pairs
Dummy node + cur = &dummy + while(cur->next && cur->next->next)

## 25. Reverse Nodes in k-Group
Use hasKNodes to determine if the number of the remaining nodes are greater than k
pre=NULL, cur=head --> nxt = cur->next, cur->next = pre, pre = cur, cur = nxt

## 26. Remove Duplicates from Sorted Array
2 pointers ans_idx, idx: if(a[ans_idx]==a[idx]) 繼續往後找到不重複的為止 a[++ans_idx] = a[idx]

## 27. Remove Element
2 pointers: 跟 26. 差不多

## 28. Implement strStr()
two for loop 

## 29. Divide Two Integers
巧秒的處理 -2^31 和其他會造成 overflow 的計算 
(1) dividend == INT_MIN ---> (i) if(divisor == -1) return INT_MAX; if(divisor == 1) return INT_MIN; 
if(divisor == INT_MIN) return 1; 為了避免等等 abs(dividend) overflow，所以先減去一份 divisor（ dividend += abs(divisor);quotient++;），只是因為現在是負數，其實就跟轉成絕對值後減掉 divisor 是一樣的
(2) 將 dividend - (tmp<<1) >= 0 拆開，避免 tmp overflow 

logic: shift 被除數和mul, quotient += mul

## 31. Next Permutation
從後往前找第一個遞增發生的位置(a[i] < a[i+1]), 然後跟後面那串大於a[i]中的最小值互換

## 32.
Too hard...

## 33. Search in Rotated Sorted Array
Binary search
看到排序且O(logn)就肯定是二分搜，只是 array 有 rotate 過，所以需要多一些判斷
(1) 先比較 nums[mid] 和 nums[l]，如果 nums[mid] < nums[l]，就是有元素 rotate 到左邊，
    因此，nums裡的最大值會在 mid 的 左半邊。
    (i). 如果 target > mid 且 target <= nums[r]，代表 target 就位於mid右邊的部分
    (ii). 否則的話 (target 比 nums[mid] 小 || target 比 nums[r] 還大 )，這值都只會出現在左邊
        - e.g [5,6,0,1,2,3,4], target=2, l=0, r=5, mid=3, 這樣的話就會是 (1)-(i). 的情況
        - 假如同樣是上面的例子, target=0 or 5, 那都會是 (1)-2. 的情況
(2) nums[mid] > nums[r] 同理，nums 裡的最小值會在 mid 的 右半邊。
(3) 以上情形都沒發生，那就是正常做 binary search

## 34. Find First and Last Position of Element in Sorted Array
Do binary search 2 times

## 36. Valid Sudoku
row[x][num], col[y][num], use (3*(i/3)+j/3) to locate the block

## 38. Count and Say
while( i+1 < ans.size() && ans[i]==ans[i+1] ) {
    cnt++;
    i++;
}
cur += to_string(cnt) + ans[i];

## 39. Combination Sum
DFS +  for(int i=start; i < candidates.size(); i++) + if(cur < 0) return; if(cur == 0){res.push_back(tmp); return;}

## 41. First Missing Positive
keep swap the positive number "N" to index "N-1" if N > 0 && N <= nums.size() && no duplicate
if nums[i]!=i+1 return i+1;

## 42. Trapping Rain Water
Method(1) 基本的思路就是, 不是用底*高來算, 而是每個單元寬度分開看，最左跟最右自然不用管, 所以只要把[1~n-1]裡的每格，他能有多高的水加起來, 就是答案。每格的水的高度求法: h = min(left_max,right_max) - height[i]; 淺顯易懂
但直接雙層迴圈(第一層枚舉要計算高度的格子, 第二層分別找左邊最高跟右邊最高)枚舉的話, 時間複雜度會上到O(N^2)
    
這邊可以用DP把到[0~i]為止, 左邊的最高值存起來
以及[i~n]為止, 右邊最高的值存起來
然後就可以用一個迴圈來求上面提過的式子了

Method(2) 可以不用 extra space，用 two pointer 就行了。想法很類似，一樣是一次處理一個unit。
當 A[left] <= A[right]，表示當前左界的高度比較矮，所以往這邊注水的話，右邊比較高或一樣高的那個，
是一定能擋住的。有點像我們從左右各放一個柱子進去看能 trap 住多少水

## 45. Jump Game II
reedy, 考量三個變數 reach, step 和 maxposition: reach 代表目前能到的最右界, step  表示擴展到這個reach要走了步
maxposition 表示下一次的step能走到的最右界. 如果 i 走到 reach 了，代表已經走到這一次 step 的極限，要 step++ 了

## 46. Permutations
for(int i=pos; i < nums.size(); i++) {
    swap(nums[i], nums[pos]);
    helper(res, nums, pos+1);
    swap(nums[i], nums[pos]);
}

## 47. Permutations II
基本上一樣，要先排序再用if (i != k && num[i] == num[k]) continue; 來跳過 duplicate combination

## 48. Rotate Image
Rotated clockwise: Reverse the rows, and then swap symmetric (swap(M[i][j], M[j][i]))
anticlockwise rotate: Reverse the cols, then swap symmetric

## 49. Group Anagrams
複雜度O(N*(M+26)), 為了省去sort這個步驟
需要多用一個字串cnt來存每個字元的出現次數, 並且用這個字串當作map的key
例如 "abc" 的 cnt 就會是 "#1#1#1#0....."
"bac" 也會跟上面一樣

## 50.
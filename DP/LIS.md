[300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/solution/jiao-ni-yi-bu-bu-si-kao-dpfu-o1-kong-jia-4zma/)
## <font  color='dc843f'>方法一：记忆化搜索</font>
dfs(i) 表示以 nums[i] 结尾的最长递增子序列（LIS）的长度。

枚举子序列的倒数第二个数的下标是 j，如果 nums[j]<nums[i]，那么有

$dfs(i)=dfs(j)+1$
取最大值。

注意 nums[i] 可以单独形成一个长为 1 的子序列。
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            int& res = memo[i]; // 注意这里是引用
            if (res > 0) { // 之前计算过
                return res;
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    res = max(res, dfs(j));
                }
            }
            return ++res; // 加一提到循环外面
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
```
复杂度分析  
时间复杂度：O($n^2$)，其中 n 为 nums 的长度。由于每个状态只会计算一次，动态规划的时间复杂度 = 状态个数 × 单个状态的计算时间。本题中状态个数等于 O(n)，单个状态的计算时间为 O(n)，所以动态规划的时间复杂度为 O($n^2$)。  
空间复杂度：O(n)。

## <font  color='dc843f'>方法二：递推</font>
同记忆化搜索，f[i] 表示以 nums[i] 结尾的最长递增子序列（LIS）的长度。
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            f[i] = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i]++;
        }
        return ranges::max(f);
    }
};
```
复杂度分析  
时间复杂度：O($n^2$)，其中 n 为 nums 的长度。  
空间复杂度：O(n)。

## <font  color='dc843f'>方法三：贪心 + 二分查找</font>
前置知识：二分查找
写法一：额外空间
定义 g[i] 表示长为 i+1 的上升子序列的末尾元素的最小值。
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> g;
        for (int x : nums) {
            auto it = ranges::lower_bound(g, x);
            if (it == g.end()) {
                g.push_back(x); // >=x 的 g[j] 不存在
            } else {
                *it = x;
            }
        }
        return g.size();
    }
};
```
写法二：原地修改
直接把 g 填入 nums 中。
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto end = nums.begin();
        for (int x : nums) {
            auto it = lower_bound(nums.begin(), end, x);
            *it = x;
            if (it == end) { // >=x 的 g[j] 不存在
                ++end;
            }
        }
        return end - nums.begin();
    }
};
```
复杂度分析  
时间复杂度：O($nlogn$)，其中 n 为 nums 的长度。  
空间复杂度：O(1)。仅用到若干额外变量。  

练习：  
[2826. 将三个组排序](https://leetcode.cn/problems/sorting-three-groups/)  
[1671. 得到山形数组的最少删除次数](https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/)  
[1964. 找出到每个位置为止最长的有效障碍赛跑路线](https://leetcode.cn/problems/find-the-longest-valid-obstacle-course-at-each-position/)  
[673. 最长递增子序列的个数](https://leetcode.cn/problems/number-of-longest-increasing-subsequence/)  
[1626. 无矛盾的最佳球队](https://leetcode.cn/problems/best-team-with-no-conflicts/)  
[354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes/)  
[1187. 使数组严格递增](https://leetcode.cn/problems/make-array-strictly-increasing/)  


## <font  color='dc843f'>LCS转LIS</font>
[1713. 得到子序列的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-a-subsequence)

基本分析  
为了方便，我们令 target 长度为 n，arr 长度为 m，target 和 arr 的最长公共子序列长度为 max，不难发现最终答案为 n−max。  
因此从题面来说，这是一道最长公共子序列问题（LCS）。  
但朴素求解 LCS 问题复杂度为 O(n∗m)，使用状态定义「f[i][j] 为考虑 a 数组的前 i 个元素和 b 数组的前 j 个元素的最长公共子序列长度为多少」进行求解。  
而本题的数据范围为 $10^5$
 ，使用朴素求解 LCS 的做法必然超时。

一个很显眼的切入点是 target 数组元素各不相同，当 LCS 问题增加某些条件限制之后，会存在一些很有趣的性质。

其中一个经典的性质就是：当其中一个数组元素各不相同时，最长公共子序列问题（LCS）可以转换为最长上升子序列问题（LIS）进行求解。同时最长上升子序列问题（LIS）存在使用「维护单调序列 + 二分」的贪心解法，复杂度为 O(nlogn)。

因此本题可以通过「抽象成 LCS 问题」->「利用 target 数组元素各不相同，转换为 LIS 问题」->「使用 LIS 的贪心解法」，做到 O(nlogn) 的复杂度。
https://leetcode.cn/problems/minimum-operations-to-make-a-subsequence/solutions/896862/gong-shui-san-xie-noxiang-xin-ke-xue-xi-oj7yu/
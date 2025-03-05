# <font  color='3d8c95'>MIS(max interval sum)最大子数组和</font>

有两种做法：  
- <font  color='dc843f'>定义状态 f[i] 表示以 a[i] 结尾的最大子数组和</font>,不和 i 左边拼起来就是 f[i]=a[i]，和 i 左边拼起来就是 f[i]=f[i−1]+a[i]，取最大值就得到了状态转移方程 f[i]=max(f[i−1],0)+a[i]，答案为 max(f)。这个做法也叫做 Kadane 算法。
- 用<font  color='dc843f'>前缀和</font>解决。

[53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)  
[2606. 找到最大开销的子字符串 1422](https://leetcode.cn/problems/find-the-substring-with-maximum-cost/)  
[1749. 任意子数组和的绝对值的最大值 1542](https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/)  
[1191. K 次串联后最大子数组之和 1748](https://leetcode.cn/problems/k-concatenation-maximum-sum/)  
[918. 环形子数组的最大和 1777](https://leetcode.cn/problems/maximum-sum-circular-subarray/) 
[2321. 拼接数组的最大分数 1791](https://leetcode.cn/problems/maximum-score-of-spliced-array/)  
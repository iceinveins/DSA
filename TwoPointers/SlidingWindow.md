# <font  color='3d8c95'>SlidingWindow滑动窗口</font>
当我们发现在暴力穷举的策略中left和right指针都是同一个方向时，可以用滑动窗口，<font  color='fed3a8'>本质就是同向双指针，利用单调性优化.</font>

一般做法就是枚举right，移动left
移动left即缩小窗口的条件则根据题意，比如定长则区间长度为条件

模板：[2379. 得到 K 个黑块的最少涂色次数](https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/)
```
int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int b=0;
    int bMx=0;
    int left=0, right=0;
    while(right < n) {
        auto in = blocks[right++];
        b += (in=='B');
        if(right < k) {
            continue;
        }
        while(left < right && right - left > k) {
            b -= blocks[left++] == 'B';
        }
        bMx = max(bMx, b);
    }
    return k-bMx;
}
```
## <font  color='dc843f'>求指定区间长度下的最？</font>
最直接，即区间长度是移动left的条件

常见题型：  
指定半径k内的/接下来k个以及先前k个/数组中某数聚集/交集连续区间最大长度  

[2090. 半径为 k 的子数组平均值 1358](https://leetcode.cn/problems/k-radius-subarray-averages/)  
[1652. 拆炸弹](https://leetcode.cn/problems/defuse-the-bomb)  
[2134. 最少交换次数来组合所有的 1 II](https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together-ii/)  
[2653. 滑动子数组的美丽值](https://leetcode.cn/problems/sliding-subarray-beauty)

## <font  color='dc843f'>求最长/最大</font>
一般题目都有「至多」的要求。

常见题型：  
子数组区间值在一定范围内  
操作数组两端数字==》逆向思维：剩余的中间窗口条件  
限定k操作数后得到的最？子数组

[2779. 数组的最大美丽值](https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation)  
[1658. 将 x 减到 0 的最小操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero)  
[1423. 可获得的最大点数](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/)  
[1838. 最高频元素的频数](https://leetcode.cn/problems/frequency-of-the-most-frequent-element)  
[2516. 每种字符至少取 K 个](https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right)  
[2831. 找出最长等值子数组](https://leetcode.cn/problems/find-the-longest-equal-subarray)  
[2106. 摘水果](https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps)  
[2555. 两个线段获得的最多奖品](https://leetcode.cn/problems/maximize-win-from-two-segments)  

## <font  color='dc843f'>求最短/最小</font>
一般题目都有「至少」的要求。  
常见的做法是在移动left的while中更新ans

[209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum)  
[1234. 替换子串得到平衡字符串](https://leetcode.cn/problems/replace-the-substring-for-balanced-string)  
[632. 最小区间](https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists)

## <font  color='dc843f'>求子数组个数</font>
1. 越长越合法  
    一般要写 `ans += left`。<font  color='fed3a8'>累加贡献值</font>  
    滑动窗口的内层循环结束时，右端点固定在 right，左端点在 0,1,2,…,left−1 的所有子数组（子串）都是合法的，这一共有 left 个。  
    [1358. 包含所有三种字符的子字符串数目](https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters)  
    [2799. 统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/)  
    [2537. 统计好子数组的数目](https://leetcode.cn/problems/count-the-number-of-good-subarrays)

2. 越短越合法
   一般要写`ans += right - left + 1`。  
   滑动窗口的内层循环结束时，右端点固定在 right，左端点在 left,left+1,…,right 的所有子数组（子串）都是合法的，这一共有 right−left+1 个。  
   [3134. 找出唯一性数组的中位数](https://leetcode.cn/problems/find-the-median-of-the-uniqueness-array)  
   [3261. 统计满足 K 约束的子字符串数量 II](https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-ii)  
   [2781. 最长合法子字符串的长度](https://leetcode.cn/problems/length-of-the-longest-valid-substring/)  
   [1040. 移动石子直到连续 II](https://leetcode.cn/problems/moving-stones-until-consecutive-ii/)

## <font  color='dc843f'>求恰好</font>

例如，要计算有多少个元素和恰好等于 k 的子数组，可以把问题变成：

>计算有多少个元素和 ≥k 的子数组。
计算有多少个元素和 >k，也就是 ≥k+1 的子数组。
答案就是元素和 ≥k 的子数组个数，减去元素和 ≥k+1 的子数组个数。这里把 > 转换成 ≥，从而可以把滑窗逻辑封装成一个函数 f，然后用 f(k) - f(k + 1) 计算，无需编写两份滑窗代码。

<font  color='fed3a8'>总结：「恰好」可以拆分成两个「至少」，也就是两个「越长越合法」的滑窗问题。</font>

注：也可以把问题变成 ≤k 减去 ≤k−1（两个至多）。可根据题目选择合适的变形方式。  
注：也可以把两个滑动窗口合并起来，维护同一个右端点 right 和两个左端点 left1和 left2，我把这种写法叫做三指针滑动窗口。  
[3306. 元音辅音字符串计数 II](https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii)  
[2401. 最长优雅子数组](https://leetcode.cn/problems/longest-nice-subarray)  
[1712. 将数组分成三个子数组的方案数
](https://leetcode.cn/problems/ways-to-split-array-into-three-subarrays)
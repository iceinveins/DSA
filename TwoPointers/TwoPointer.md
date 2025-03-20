# <font  color='3d8c95'>TwoPointer双指针</font>
一般通过一左一右left, right两个指针来确定最终范围

根据指针移动方向不同，可以分为以下几类

## <font  color='dc843f'>同向</font>
两个指针的移动方向相同（都向右，或者都向左）。

如 [滑动窗口](SlidingWondow.md)  
[395. 至少有 K 个重复字符的最长子串](https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters)  
[611. 有效三角形的个数](https://leetcode.cn/problems/valid-triangle-number/)  
[1574. 删除最短的子数组使剩余数组有序 1932](https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)  
[2972. 统计移除递增子数组的数目 II 2153](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-ii/description/)  

## <font  color='dc843f'>相向</font>
[2105. 给植物浇水 II](https://leetcode.cn/problems/watering-plants-ii/)  
[658. 找到 K 个最接近的元素](https://leetcode.cn/problems/find-k-closest-elements/)  
[167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)  
[2824. 统计和小于目标的下标对数目](https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target/)  
[1577. 数的平方等于两数乘积的方法数](https://leetcode.cn/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers)   
[923. 三数之和的多种可能 1711](https://leetcode.cn/problems/3sum-with-multiplicity/description/)  
[948. 令牌放置 1762](https://leetcode.cn/problems/bag-of-tokens/description/)  
[11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/description/)  
[42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/description/)  
[1616. 分割两个字符串得到回文串 1868](https://leetcode.cn/problems/split-two-strings-to-make-palindrome/description/)  
[1498. 满足条件的子序列数目 2276](https://leetcode.cn/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)  

## <font  color='dc843f'>反向</font>
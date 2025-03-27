## <font  color='dc843f'>巧用位运算记录存在性 再借助GCCbuildin统计</font>
`lower |= 1 << s[j]-'a';`  
[1763. 最长的美好子字符串](https://leetcode.cn/problems/longest-nice-substring/)  
[1930. 长度为 3 的不同回文子序列](https://leetcode.cn/problems/unique-length-3-palindromic-subsequences)

## <font  color='dc843f'>数值范围包含负数为了方便映射，可以统一加OFFSET</font>
[2653. 滑动子数组的美丽值](https://leetcode.cn/problems/sliding-subarray-beauty)

## <font  color='dc843f'>找$nums[i] (+or*) nums[j] == target$可以用map先统计元素数量</font>
[1577. 数的平方等于两数乘积的方法数](https://leetcode.cn/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers) 

## <font  color='dc843f'>带绝对值的问题先不等式转换，找出条件范围</font>
如
```
// arr1[i] - arr2[j] <= d ==> arr2[j] >= arr1[i] - d
// -arr1[i] + arr2[j] <=d ==> arr2[j] <= arr1[i] + d
```
[1385. 两个数组间的距离值](https://leetcode.cn/problems/find-the-distance-value-between-two-arrays)  


## <font  color='dc843f'>不需要统计完后再算贡献</font>
二数之和的思想下一直遍历中间，先前遍历过的和当前节点的组合都是贡献，且因为枚举的中间下标一直变所以不算重复
[447. 回旋镖的数量](https://leetcode.cn/problems/number-of-boomerangs)

## <font  color='dc843f'>乘法原理</font>
[3067. 在带权树网络中统计可连接服务器对数目](https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network)
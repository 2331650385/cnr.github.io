# 001两数之和

> 方法一: 双重暴力破解

```python
class Solution:
    def twoSum(self, nums, target):
        n = len(nums)
        for i in range(n):
            res = target-nums[i]
            for j in range(i+1,n):
                if res == nums[j]:
                    return [i,j]
```

> 方法二:哈希表 ☆

```python
class Solution:
    def twoSum(self, nums, target):
        hash_map = {}
        n = len(nums)
        for i in range(n):
            res = target- nums[i]
            if hash_map.get(res,-1) != -1:
                return [i,hash_map[res]]
            hash_map[nums[i]] = i
        return []
```





# 049 字母异味词分组

> 哈希表

```python
class Solution(object):
    def groupAnagrams(self, strs):
        hashmap = dict()
        for s in strs:
            t = "".join(sorted(s))

            if t in hashmap:
                hashmap[t].append(s)
            else:
                hashmap[t] = [s]

        return list(hashmap.values())
```

# 283 移动零

```python
class Solution:
    def moveZeroes(self, nums):
        """
        x : 左指针
        y : 右指针
        """
        x = 0  # 左指针本质 表示 左边均为非0
        for y in range(len(nums)):
            if nums[y] != 0:
                nums[x], nums[y] = nums[y], nums[x]
                x += 1
        return nums

    def moveZeroes2(self, nums):
        """
        思路：直接遍历 值等于0的下标，当场给它右移，但要考虑连续的就要成片移动
        """
        i = 0
        n = len(nums)
        while i < n:
            flag = 0
            count = 0
            while nums[i] == 0 and i<n-1:
                nums.append(nums.pop(i))
                flag = 1
                count +=1
                if count == n:
                    break
            if flag:
               if count == n:
                   break
            else:
                i+=1
        return nums

```

# 128 最长连续序列

```python
class Solution:
    def longestConsecutive(self, nums):
        res = 0
        n = set(nums)
        for y in n:
            if y - 1 in n:
                pass
            else:
                count = 1
                while y + 1 in n:
                    count += 1
                    y += 1
                if count>res:
                    res = count
        return res
```


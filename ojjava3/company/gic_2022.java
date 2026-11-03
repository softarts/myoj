package company;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
Q1. Device Name System Suggested Problem Name: 

Create unique device names to be used in a residential loT (Internet of Things) system. If a device name already exists in the system, an integer number is added at the end of the name to make it unique. The integer added starts with 1 and is incremented by 1 for each new request of an existing device name. Given a list of device name requests, process all requests and return an array of the corresponding unique device names. 

["lamp","lamp","tv","lamp"]

你的代码输出：
["lamp","lamp1","tv","lamp2"]

*/
public class gic_2022 {
    // 
    public static List<String> deviceNamesSystem(List<String> deviceNames) {

    }

/*
Q2: The Jungle Book / Minimum Groups (HackerRank)

题目描述

给定一个数组 predators，其中：

predators[i] 表示第 i 个动物的直接捕食者编号。 如果 predators[i] = -1，则表示该动物没有捕食者。

要求将所有动物分成尽可能少的组，并满足：

同一个组内不能同时出现直接捕食关系的动物
同一个组内不能同时出现间接捕食关系的动物

返回最少需要多少个组。

示例

输入：

predators = [1, 2, -1]

关系：

0 -> 1 -> 2

分组：

Group 1: [2] Group 2: [1] Group 3: [0]

输出：

3

思路

predators 实际上表示一片森林（Forest）：

predators[i] = parent(i)

题目要求的最少组数 = 整个森林的最大深度。

例如：

predators = [-1, 0, 1, 2]

结构：

0 | 1 | 2 | 3

最大深度为 4，因此答案为：

4
*/
    public static int minimumGroups(int[] predators) {
        int ans = -1;

        for (int i = 0; i < predators.length; i++) {
            int depth = findDepth(predators[i], predators, 0);
            ans = Math.max(ans, depth);
        }

        return ans;
    }

    public static int findDepth(int idx, int[] predators, int depth) {
        if (predators[idx] != -1) {
            return findDepth(predators[idx], predators, depth + 1);
        } else {
            return depth;
        }
    }

/*
There are n horizontal bars and m vertical bars.

Some horizontal bars h[]
and vertical bars v[]
are removed.

Find the area of the largest hole that can be formed.
A prison gate is made up of horizontal and vertical bars.

Given:

n = number of horizontal bars

m = number of vertical bars

h = indices of horizontal bars removed

v = indices of vertical bars removed

Find the area of the largest rectangular hole after all specified bars are removed.

Example

Input:

n = 6 m = 6

h = [2, 3, 4] v = [3, 4]

Horizontal bars:

1 2 3 4 5 6

Remove:

2 3 4

Remaining:

1 5 6

Largest horizontal opening:

5 - 1 = 4

Therefore:

height = 4

Vertical bars:

1 2 3 4 5 6

Remove:

3 4

Remaining:

1 2 5 6

Largest vertical opening:

5 - 2 = 3

Therefore:

width = 3

Largest area:

4 × 3 = 12

Output:

12

标准解法

假设：

h = [2,3,4]

连续删除了：

2,3,4

连续长度：

3

则形成的高度：

3 + 1 = 4

原因：

删除 1 根连续栏杆 -> 长度 2

删除 2 根连续栏杆 -> 长度 3

删除 3 根连续栏杆 -> 长度 4

即：

最大边长 = 最长连续删除长度 + 1

答案：

(maxHorizontalRun + 1) * (maxVerticalRun + 1)
 */    


public static long prison(int n, int m,
                          List<Integer> h,
                          List<Integer> v) {

    int hGap = maxGap(n, h);
    int vGap = maxGap(m, v);

    return (long) hGap * vGap;
}

private static int maxGap(int limit, List<Integer> removed) {

    Set<Integer> removedSet = new HashSet<>(removed);

    List<Integer> bars = new ArrayList<>();
    bars.add(0);

    for (int i = 1; i <= limit; i++) {
        if (!removedSet.contains(i)) {
            bars.add(i);
        }
    }

    bars.add(limit + 2);

    int gap = 1;

    for (int i = 1; i < bars.size(); i++) {
        gap = Math.max(gap, bars.get(i) - bars.get(i - 1));
    }

    return gap;
}

    
}

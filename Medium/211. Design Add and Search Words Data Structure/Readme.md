# 1536. Minimum Swaps to Arrange a Binary Grid

### Description

Given an `n` x `n` binary `grid`, in one step you can choose two **adjacent rows** of the grid and swap them.

A grid is said to be **valid** if all the cells above the main diagonal are **zeros**.

Return the minimum number of steps needed to make the grid valid, or **-1** if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell `(1, 1)` and ends at cell `(n, n)`.

### Example 1:

```
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
```

### Example 2:

```
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
```

### Example 3:

```
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
```

### Constraints:

 - `n == grid.length == grid[i].length`
 - `1 <= n <= 200`
 - `grid[i][j]` is either `0` or `1`

---

### Thought:

### Approach
 This problem can see like an one array swap steps question.
 The row data can see like how many continue zeros count from the end.
 So, for `Example 1`
 ```
 Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
 Equals to: array = [0,1,2]
 Expected: array = [2,1,0]
 Output: 3
 ```

 In my first thought, this is an bubble sort swapping count proglem!
 Than, after trying, I realize that this is not easy.
 For example:
 ```
 Input grid = [[1,0,0,0,0,0],[0,1,1,1,0,0],[1,0,0,0,0,0],[0,1,1,0,0,0],[0,1,0,1,0,0],[1,0,0,0,0,0]]
 Equals to: array = [5,2,5,3,2,5]
 Expected: array = [5,5,5,3,2,5] // For bubble sort expected.
 Output: 5 
 ```
 But acturally, it should be:
 ```
 Expected: array = [5,5,3,2,2,5] // At least [5,4,3,2,1,0] is enough.
 Output: 2
 ```
 So, there comes out another thought.
 I first figure out the minimun count of zeros that is needed.
 Than I consider if this current number is not enought, I finded the closest vaild row than count the swap times that was needed to swap to the current position.
 And move on to the next row.
 For example:
 ```
 Input grid = [[1,0,0,0,0,0],[0,1,1,1,0,0],[1,0,0,0,0,0],[0,1,1,0,0,0],[0,1,0,1,0,0],[1,0,0,0,0,0]]
 Equals to: array = [5,2,5,3,2,5]
 Minimun zeros: array = [5,4,3,2,1,0]
 Steps 1: [5,2,5,3,2,5] // 5 in array[0] is enough.
 Steps 2: [5,5,2,3,2,5] // 2 in array[1] is not enough, 5 in array[2] swap 1 times to reach this position.
 Steps 3: [5,5,3,2,2,5] // 2 in array[2] is not enough, 3 in array[3] swap 1 times to reach this position.
 Steps 4: [5,5,3,2,2,5] // 2 in array[3] is enough.
 Steps 5: [5,5,3,2,2,5] // 2 in array[4] is enough.
 Steps 6: [5,5,3,2,2,5] // 5 in array[5] is enough.
 Expected: array = [5,5,3,2,2,5]
 Output: 2
 ```
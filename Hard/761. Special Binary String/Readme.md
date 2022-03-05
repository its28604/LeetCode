# 10. Regular Expression Matching

### Description

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:
 - `'.'` Matches any single character.
 - `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).

### Example 1:

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

### Example 2:

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

### Example 3:
```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```
 
### Constraints:

 - `1 <= s.length <= 20`
 - `1 <= p.length <= 30`
 - `s` contains only lowercase English letters.
 - `p` contains only lowercase English letters, `'.'`, and `'*'`.
 - It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.


---

### Thought:

#### Situation

 - Normal expression(without any special latters).
 - Universal character expression `.*`
 - Duplicate expression `a*`

#### Approach
 For time saving, doing the basic judgment first for the expression that is impossible matching.
  - `s` = `"abc"`
  - `p` = `".*a"`
  - The `p` is ending by letter `'a'` and `s` is ending by letter `'c'`, so that is an impossible match.

 Next, if universal character expression `.*` exists, skip it to figure out the necessary pattern in this match by recursion.

 If it's not exists, comparing the character in `s` and `p` one by one (including `'.'`).

 If it's a duplicate expression, try to findout how many duplicate is needed.

 Finally, Recursion all situation, like the mouse through the maze.
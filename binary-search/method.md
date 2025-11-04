# Binary Search Method
for binary search, you must make sure the interval [left, right]
or [left, right), or event (left, right) only then you can apply the binary search method. 
## the code
```
class Solution:
    # Find the smallest integer x such that check(x) == True
    def binarySearchMin(self, nums: List[int]) -> int:
        # Binary search on the answer space: check whether mid satisfies the condition
        def check(mid: int) -> bool:
            # TODO: implement the condition
            pass

        left =   # Invariant: check(left) is always False
        right =  # Invariant: check(right) is always True
        while left + 1 < right:  # While the open interval (left, right) is not empty
            mid = (left + right) // 2
            if check(mid):  # If check(mid) == True, then all values >= mid also satisfy the condition
                right = mid  # Continue searching in (left, mid)
            else:  # If check(mid) == False, then all values <= mid also fail the condition
                left = mid   # Continue searching in (mid, right)
        # When the loop ends, we have left + 1 == right
        # At this point, check(left) == False and check(left + 1) == check(right) == True
        # Therefore, right is the smallest value satisfying check(x) == True
        return right
```
and notice the differnce beteween getting the smallest and the largest:
```
class Solution:
    # Find the largest integer x such that check(x) == True
    def binarySearchMax(self, nums: List[int]) -> int:
        # Binary search on the answer space: check whether mid satisfies the condition
        def check(mid: int) -> bool:
            # TODO: implement the condition
            pass

        left =   # Invariant: check(left) is always True
        right =  # Invariant: check(right) is always False
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                left = mid  # Note: update left here, opposite of the "find first True" template
            else:
                right = mid
        # When the loop ends, left + 1 == right
        # At this point, check(left) == True and check(left + 1) == check(right) == False
        # Therefore, left is the largest value satisfying check(x) == True
        return left  # Always return the variable that was updated when check(mid) == True
```
## the order to practice binary search is as follows:
https://leetcode.com/problems/binary-search/description/
https://leetcode.com/problems/search-insert-position/description/
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
https://leetcode.com/problems/sqrtx/description/
https://leetcode.com/problems/valid-perfect-square/description/
https://leetcode.com/problems/find-peak-element/description/
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/


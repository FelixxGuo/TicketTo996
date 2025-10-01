N items for i in N
W bag that can contain the maximum weights
every item weights w[i], and the correspoding value is v[i], every item can only be put into the bag ONCE.
Solve: pick the items that can get the maximum value.
dp[j]
dp[j - weight[i]]
max(dp[j], dp[j - weight[i]])

So:
j stands for the weight filled in the bag and j <= W
for every item i, we can choose or not.

dp[j] = 0 for j = 0
for i in N
    for j in W
        res = max(dp[j], dp[j - weight[i]])

the step to sovle the dp problem:
1. define the dp table and the index meaning
2. define the recurrence relation
3. initialize the initial value for the dp table
4. the traverse order
5. print some dp table to make sure your result

Time complexity with recursive: O(2^N)
    We can express the recurrence as:

    T(n) = 1 + \sum_{k=0}^{n-1} T(k)
    T(n) = 2^n
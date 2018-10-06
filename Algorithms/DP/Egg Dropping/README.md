# Egg Dropping

Imagine that you live in a *k floor* building in the great city of Teresina and you have *n eggs*. Your magic building have a special property: if you throw a egg from *floor
i* or lower it won’t be broken and you can throw it again, and if you throw it from floor i + 1 or higher, it will definitely be broken.

a.  **Higher than i**: broken
b. **Lower than i**: safe

**The problem is discover the optimal *floor i* using the minimum of trial.**

To solve this problem, let's build a **matrix dp[n][k]**.

The base case is when you have only 1 egg. In that case, you will need to try from  the first floor, the in the second one, and so on. In the worst case, you'll do n trial (when the *i* is equals to *n*). So, the matrix will be:

k | 1 | 2 |3 | 4
:---------: | :------: | :-------: | :-------: | :-------:
n = 1 | 1 | 2 | 3 | 4

Now, if you have 2 eggs, you can choose the optimal strategy, but you have to consider the worst case possible.

a. **n = 2, k = 1**
As you have only 1 floor, dp[2][1] = 1

b. **n = 2, k = 2**
    i. When you start in the first floor, if the egg breaks in your first attempt, you already have the answer. However, if your egg doesn't break, you have 2 eggs and 1 floor, so you only need 1 more trial => 1 + max(0,1)
    ii. When you start in the second floor, if the egg breaks in your first attempt, you have 1 egg and 1 floor, so you will need one more trial. However, if the egg doesn't break, you won't need any more => 1 + max(1, 0)
    
    So, dp[2][2] = min( 1 + max(0,1), 1 + max(1,0) ) = 2
    
c. **n = 3, k = 2**
    i. When you start in the first floor, if the egg breaks in your first attempt, you already have the answer. However, if your egg doesn't break, you have 2 eggs and 2 floors, so you only need 2 more trials (use dp[2][2]) => 1 + max(0,2)
    ii. When you start in the second floor, if the egg breaks in your first attempt, you will need one more trial. If the egg doesn't break, you will still need one more trial => 1 + max(1, 1)
    iii. When you start in the third floor, if the egg breaks in your third attempt, you have 2 eggs and 2 floors (use dp[2][2]). If the egg doesn't break, you already have the answer => 1 + max(2, 0)
    
    So, dp[2][2] = min( 1 + max(0, 2), 1 + max(1,1), 1 + max(2, 0) ) = 2

Following this process, we have:

k | 1 | 2 |3 | 4 | 5 
:---------: | :------: | :-------: | :-------: | :-------: | :-------:
n = 1 | 1 | 2 | 3 | 4 | 5
n = 2 | 1 | 2 | 2 | 3 | 3

Following this approach, we know that:
1) If the egg breaks after dropping from jth floor, then you only need to check for floors lower than x with remaining eggs. So the problem reduces to j-1 floors and n-1 eggs
2) If the egg doesn’t break after dropping from the jth floor, then you only need to check for floors higher than x. So the problem reduces to k-j floors and n eggs.

Finally, you can write the dynamic programming equation:

**d[n][k] = 1 + min { max( dp[n-1][k-1], dp[n][k - j]) }, for j in [1, 2, ... , k] }**

# Convex Hull

**Problem**: Given a set of points int the 2D space, find the Convex Hull that is the smallest convex polygon that contains all the points of it.

<p align="center">
<img src=convex_hull.png>
</p>

To solve this problem, let's use **Graham's Scan Algorithm**.
1. Sort the points according to the angle with respect to a referencial point as pivot, wich takes *O(n log n)*

<p align="center">
<img src=convex_hull_sort.png>
</p>

2. Iterate through the set of points: for each 3 points (previous, current, next) test the orientation of these points. If the orientation is not counterclockwise, discard current. It takes *O(n)*

<p align="center">
<img src=convex_hull_execution.png>
</p>

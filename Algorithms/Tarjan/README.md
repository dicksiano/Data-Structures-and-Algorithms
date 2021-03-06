# Tarjan

Let's analyse the exploration tree created from **DFS algorithm** execution.

<p align="center">
<img src=assets/graph.png>
</p>

Starting DFS from vertex A, we have:


<p align="center">
<img src=assets/Tarjan1.png>
</p>

Those edges are called **Tree edges**. They are the most regular edges: from an explored, but not completed vertex to a vertex not explored (not completed, consequently).

<p align="center">
<img src=assets/Tarjan2.png>
</p>

The blue edge is called **Back edge**. An edge to an **not completed** ancestor vertex.
<p align="center">
<img src=assets/Tarjan3.png>
</p>

The red edge is called **Forward edge**. An edge to an **already completed**  descendent vertex.
<p align="center">
<img src=assets/Tarjan4.png>
</p>

We've now finished all vertex that can be reached from A. As none of the previews vertex can reach D, the exploration of D will create a new subtree.

<p align="center">
<img src=assets/Tarjan5.png>
</p>

The green edge is called **Cross edge**. An edge to an **already completd** ancestor.




**Tree edges**: edge to an unexplored descendent          &rightarrow; **started[destiny] = 0**<br>
**Back edge**: edge to an not completed ancestor          &rightarrow; **started[destiny] < started[origin] && finished[destiny] = 0**<br>
**Forward edge**: edge to an already completed descendent  &rightarrow; **started[destiny] > started[origin] && finished[destiny] = 1**<br>
**Cross edge**: edge to an already completd ancestor      &rightarrow; **started[destiny] > started[origin] && finished[destiny] = 1**<br>

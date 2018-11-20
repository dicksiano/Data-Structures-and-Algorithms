# Tarjan

Let's analyse the exploration tree created from **DFS algorithm** execution.

<p align="center">
<img src=assets/graph.png>
</p>

Starting DFS from vertex A, we have:


<p align="center">
<img src=assets/Tarjan1.png>
</p>

Those edges are called **Tree edges**. They are the more regular edges: from an explored, but not completed vertex to a vertex not explored (not completed, consequently).

<p align="center">
<img src=assets/Tarjan2.png>
</p>

The blue edge is called **Return edge**. An edge to an **not completed** ancestor vertex.
<p align="center">
<img src=assets/Tarjan3.png>
</p>

The red edge is called **Forward edge**. An edge to an **already completed**  descendent vertex.
<p align="center">
<img src=assets/Tarjan4.png>
</p>

We've now finished all vertex that can be reached from A.

<p align="center">
<img src=assets/Tarjan5.png>
</p>

The green edge is called **Cross edge**. An edge to an **already completd** ancestor.
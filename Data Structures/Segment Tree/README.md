# Build

Let's build the segment tree from **v = {0, 1, 2,3, 4, 5, 6, 7}**.

``` cpp
n = v.size();
a.assign(2 * n, 0);
            
for(int i = 0; i < n; i++) a[i + n] = v[i];
``` 

<p align="center">
<img src=assets/segtreebuild1.png>
</p>

``` cpp
for(int i = n-1; i > 0; i--) a[i] = a[i * 2] + a[1 + i*2];
``` 

<p align="center">
<img src=assets/segtreebuild2.png>
</p>

<p align="center">
<img src=assets/segtreebuild3.png>
</p>

<p align="center">
<img src=assets/segtreebuild4.png>
</p>

<p align="center">
<img src=assets/segtreebuild5.png>
</p>

<p align="center">
<img src=assets/segtreebuild6.png>
</p>

<p align="center">
<img src=assets/segtreebuild7.png>
</p>

<p align="center">
<img src=assets/segtreebuild8.png>
</p>

Finally, the segment tree:

<p align="center">
<img src=assets/segtreebuild9.png>
</p>
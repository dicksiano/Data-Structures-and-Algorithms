#include <bits/stdc++.h>
using namespace std;

/*
    Time: O(n^2 2^n)
    Space: O(n 2^n)
*/
int tsp(int p, int bitmask) {
    if (bitmask == (1 << (n + 1)) - 1) return dist[pos][0]; // Have already visited all cities
   	
	if (dpTable[pos][bitmask] == -1) {
   		for (int next = 0; next <= n; next++)               // O(n) here
   			if (next != pos && !(bitmask & (1 << next) ) )  // if coordinate next is not visited yet
   				dpTable[pos][bitmask] = min(dpTable[pos][bitmask], dist[pos][next] + tsp(next, bitmask | (1 << next)));
   	}
   	return dpTable[pos][bitmask];
}
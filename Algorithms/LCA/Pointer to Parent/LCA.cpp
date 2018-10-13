
#include <bits/stdc++.h>
using namespace std;

/* 
  Pointer to Parent
  Each node has a pointer to left child, to right child and to its parent.
  As it has a pointer to parent, lets use it to produce a solution
  
  Time: O(log n)
  Space: O(1)

  i.   Find the difference from the root.
  ii.  Take the deepest element and make it go to the same level of the other node
  iii. Make them bouth go to their parents until they find each other
*/
class node {
  public:
    node(int x, node* parent) {
      this->elem = x;
      this->left = NULL;
      this->right = NULL;
      this->parent = parent;
    }
    ~node();    

    int elem;
    node *left, *right, *parent;
};

int depth(node *root) {
  int ans = 0;
  while( root != NULL ){
    root = root->parent;
    ans++;
  }
  return ans;
}

int firstCommonAncestor1(node *p, node *q) {
  if(p == NULL || q == NULL) return -1; // error
  if(p == q) return p->elem;

  int pDepth = depth(p);
  int qDepth = depth(q);

  for (int i = 0; i < pDepth-qDepth; ++i)
    p = p->parent;
  for (int i = 0; i < qDepth-pDepth; ++i)
    q = q->parent;
  
  while(p != q) { p = p->parent; q = q->parent; }

  return p->elem;
}
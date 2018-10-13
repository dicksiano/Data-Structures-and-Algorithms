
#include <bits/stdc++.h>
using namespace std;

/* 
  Solution with no extra pointers, but if pointer to root
  Time: O(n)
  Space: O(n) - recursion stack
              - Tree could be not balanced. Worst case: n
              Worst case:
                          root
                              \ 
                               a
                                \
                                 b
                                  \
                                  ...
                                    \
                                     p 
                                      \ 
                                       q
                                        \
                                        NULL
*/


class node {
  public:
    node(int x) {
      this->elem = x;
      this->left = NULL;
      this->right = NULL;
    }
    ~node();    

    int elem;
    node *left, *right;
};

node *firstCommonAncestor2(node *root, node *p, node *q) {
  if(p == NULL || q == NULL || root == NULL) return NULL; // error

  if(root == p || root == q) return root;

  node *lcaLeft = firstCommonAncestor2(root->left, p, q);
  node *lcaRight = firstCommonAncestor2(root->right, p, q);

  if(lcaLeft && lcaRight) return root;
  return (lcaLeft) ? lcaLeft : lcaRight;
}
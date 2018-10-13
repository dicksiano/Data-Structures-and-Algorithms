
#include <bits/stdc++.h>
using namespace std;

/* 
  As the tree is a Binary Search Tree, lets use BST hirarchy to 
  produce the solution.

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

node *lca(node *root, node *p, node *q) {
  if(p == NULL || q == NULL || root == NULL) return NULL; // error

  if(root == p || root == q) return root;

  if(p->elem < root-> elem && q->elem < root->elem) return lca(root->left, p, q);
  else if(p->elem > root-> elem && q->elem > root->elem) return lca(root->right, p, q);

  return root;
}

int main() {
  node * head = new node(8);
  head->left = new node(4);
  head->right = new node(12);
  
  node *l = head->left;
  l->left = new node(2);
  l->right = new node(6);

  node *ll = l->left;
  ll->left = new node(1);
  ll->right = new node(3);

  node *lr = l->right;
  lr->left = new node(5);
  lr->right = new node(7);

  node *r = head->right;
  r->left = new node(10);
  r->right = new node(14);

  node *rl = r->left;
  rl->left = new node(9);
  rl->right = new node(11);

  node *rr = r->right;
  rr->left = new node(13);
  rr->right = new node(15);

  cout << "LCA (" << ll->left->elem << "," << l->elem << "): " << lca(head, ll->left,l)->elem << endl;
  cout << "LCA (" << rr->left->elem << "," << rr->right->elem << "): " << lca(head,rr->left, rr->right)->elem << endl;
  cout << "LCA (" << rl->elem << "," << rr->right->elem << "): " << lca(head,rl, rr->right)->elem << endl;
  return 0;
}
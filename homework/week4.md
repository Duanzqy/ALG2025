# Exercises 12.3-6 
###### TREE-SEARCH算法与原来的SEARCH一样，不需要改变。
###### 我们需要先实现PARENT, 方便我们后续处理
```
PARENT(T, z)
  x = T.root
  y = NIL
  while x != NIL and x.key != z.key
    y = x
    if z.key < x.key
      x = x.left
    else
      x = x.right
  if x == NIL
    return NIL
  return y
```
###### TREE-INSERT与PARENT类似
```
TREE-INSERT(T, z)
  x = T.root
  y = NIL
  // pre是z的前驱节点。由于z是叶子节点，因此z的前驱必定在从根节点r到z的路径上。
  pre = NIL
  while x != NIL
    y = x
    if z.key < x.key
      x = x.left
    else
      pre = x
      x = x.right
  if y == NIL
    T.root = z
  else if z.key < y.key
    y.left = z
    // z是叶子节点，没有右孩子，因此其后继就是y。
    z.succ = y
    if pre != NIL
      pre.succ = z
  else
    y.right = z
    z.succ = y.succ
    y.succ = z
```
###### 相比于TRANSPLANT，算法TRANSPLANT'不再考虑父节点指针的指向。
```
TRANSPLANT'(T, u, v)
  p = PARENT(T, u)
  if p == NIL
      T.root = v
  else if u == p.left
      p.left = v
  else
      p.right = v
```
###### 我们还需要求取z的前驱节点的算法，方便TREE-DELETE中查找前驱
```
TREE-PREDECESSOR(T, z)
  if z.left != NIL
    return TREE-MAXIMUM(x.left)
  x = T.root
  // 此时前驱节点pre必定在从根节点r到z的路径上。
  pre = NIL
  while x != NIL and x.key != z.key
    if z.key < x.key
      x = x.left
    else
      pre = x
      x = x.right
  return pre
```
###### TREE-DELETE
```
TREE-DELETE(T, z)
  pre = PREDECESSOR(T, z)
  if pre != NIL
    pre.succ = z.succ
  if z.left == NIL
    TRANSPLANT(T, z, z.right)
  else if z.right == NIL
    TRANSPLANT(T, z, z.left)
  else
    y = TREE-MIMIMUM(z.right)
    if PARENT(T, y) != z.right
      TRANSPLANT(T, y, y.right)
      y.right = z.right
    TRANSPLANT(T, z, y)
    y.left = z.left
```

# Problems 9-1
### a
对数字进行排序的运行时间是 $O(n\,lg\,⁡n)$. 列出最大的 $i$ 个数字的运行时间是 $O(i)$. 因此，总运行时间是$O(n\,lg\,⁡n+i)$.
### b
构建一个最大优先队列（使用堆）的时间复杂度为 $O(n)$ ，每次调用 EXTRACT-MAX 的时间复杂度为 $O(lg⁡\,n)$), 因此, 总的时间复杂度为 $O(n+i\,lg\,⁡n)$
### c 
寻找并围绕第 $i$ 大的数进行划分的时间复杂度为 $O(n)$, 排序前 $i$ 大的数的时间复杂度为 $O(i\,lg\,i)$. 因此, 总的时间复杂度为 $O(n+i\,lg\,⁡i)$.
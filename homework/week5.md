# Exercises 13.1-3 
###### 它仍然是红黑树，理由如下：
先考虑改变根节点前的 **relaxed red-black tree** （记为$T$）所满足的性质：
1. **每个节点**要么是红色，要么是黑色；
2. **根节点**是红色的；
3. 所有叶子节点（NIL 空节点）都是黑色；
4. **红色节点不能连续**：一个红色节点不能有红色的子节点（即红色节点的孩子只能是黑色）；
5. **从任意节点到其所有后代叶子的路径上，黑色节点数量相同**。

改变后(记为$T'$)，让我们依次考虑红黑树需要满足的性质。
1. 由于只改变了根节点的颜色为黑色，所以$T'$ 的每个节点都为黑色或红色，成立。
2. 根节点是黑色的，成立。
3. 由于只改变了根节点的颜色，所以 $T'$ 的所有叶子节点颜色与 $T$ 一样为黑色的，成立。
4. $T$ 的红色节点不连续，则根节点的两个孩子节点为黑色的。改变后，根节点为黑色，仍然没有连续的红色节点，成立。
5. 从非根节点到所有后代叶子的路径上，黑色节点数量相同，在 $T$ 中已满足，$T'$ 中不变。$T'$ 从根节点到后代叶子的路径上，黑色节点的数量相较 $T$ 都增加了1，黑色节点数量仍然相同，故成立。

综上所述，$T'$ 是红黑树。

# Problems 13-3 AVL Trees
#### a
令 $T(h)$ 表示高度为 $h$ 的 AVL 树中最少的节点数。由于树的高度为 $h$ ，因此最大子树的高度为 $h-1$ ，我们要使节点最小，则另一子树应尽量小，由于 AVL 树的限制，另一子树的最小高度为 $h-2$ ，并且这些子树的节点数也应该尽量少（分别达到 $T(h−1)$, $T(h−2)$ ）, 此时仍是 AVL 树。因此，可以写出 $T$ 的递推式为: 
$T(h) = T(h-1) +T(h-2) +1, where \, T(0) =0, T(1) = 1.$   
该递归关系和初始条件，就像斐波那契数列一样，故 $T(h) = \Theta (\phi^h)$ , 又 $T(h) \leq n$ , 故 $h = O(log_{\phi}\, n )$, 即 $h = O(lg\, n)$ .


#### b
判断两棵子树的高度，然后对根节点 x 进行旋转即可.
```
BALANCE(x)
  if x.right.h == x.left.h + 2
    y = x.right
    LEFT-ROTATE(x)
    x.h = max{x.left.h, x.right.h} + 1
    y.h = max{x.h, y.right.h} + 1
    return y
  else if x.left.h == x.right + 2
    y = x.left
    RIGHT-ROTATE(x)
    x.h = max{x.left.h, x.right.h} + 1
    y.h = max{x.h, y.left.h} + 1
    return y
// 返回平衡之后的根节点, 帮助后续insert处理
```


#### c
```
AVL-INSERT(T, z)
  x = T.root
  y = T.nil
  while x ≠ T.nil
    y = x
    if z.key < x.key
      x = x.left
    else
      x = x.right
  z.p = y
  if y == T.nil
    T.root = z
  else if z.key < y.key
    y.left = z
  else y.right = z
  z.h = 0
  x = z.p
  // 从下向上逐步保持平衡
  while |x.left.h - x.right.h| > 1
	y = BALANCE(x)  
    x = y.p
```


#### d
树的高度为  $O(lg\,n)$ , 故 AVL-INSERT 中的每个 while 循环最多执行 $O(lg\,n)$ 次，每次需要一次 BALANCE，即一次 ROTATION，故需要 $O(lg\,n)$ 次 ROTATION, 时间复杂度也为 $O(lg\,n)$ . 
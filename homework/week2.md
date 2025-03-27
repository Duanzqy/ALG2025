# week2

## Problems 4-7 Monge Array

### a
充分性：由定义即可得到

必要性：

由 $A[i,j] + A[i+1, j+1] \leq A[i,j+1] + A[i+1, j]$ 可得

$A[i, j] - A[i, j+1] \leq A[i+1,j]- A[i+1,j+1] $

故$f_j(i) = A[i, j] - A[i, j+1]$ 关于i递增, 则有 $\forall 1 \leq i < k \leq m $, 有 $f_j(i) \leq f_j(k)$ 成立, 即$A[i,j] + A[k, j+1] \leq A[i,j+1] + A[k, j]$

同理对 $\forall 1 \leq j < l \leq n$, 有 $A[i,j] + A[i+1, l] \leq A[i,l] + A[i+1, j]$

综合上述两个式子可得 $A[i, j] + A[k,l] \leq A[i,l] + A[k, j]$

### b
答案不唯一，修改 
$
\begin{matrix}
23 & 22\\
6  & 7 \\
\end{matrix}
$ 中的数使其满足a中条件即可，如：

$
\begin{matrix}
37 &23 &\textbf{25} &32 \\
21 &6  &7  &10 \\
53 &34 &30 &31 \\
32 &13 &9  &6 \\
43 &21 &15 &8
\end{matrix}
$

### c
假设 $\exist a,b, 1\leq a < b \leq m $, 使得 $f(a) > f(b)$ 

由f定义有: $A[a, f(b)] > A[a, f(a)] $ 与 $A[b,f(b)] \leq A[b,f(a)]$

可得 $A[b,f(a)] + A[a, f(b)] > A[a,f(a)] + A[b, f(b)]$, 与Monge Array 的定义矛盾

### d
已知 $f(2), f(4), ... , f(2k)$, 求奇数行的 $f(2i+1)$, 查找时只需要检查 $f(2i), f(2i+2)$ 之间的数字，最多需要 $f(2i+2) - f(2i) + 1$ 步, 总时间为: 

$
\begin{aligned}
T(m,n) &= \sum_{i=0}^{m/2}(f(2i+2) - f(2i) + 1) \\
       &= f(m) - f(0) + m/2 \\
       &= n +m/2 \\
       &=O(m+n)
\end{aligned}
$

### e
假设 $T(m,n) = O(m+n) \leq cm + dn$, 则: 

$
\begin{aligned}
T(m) &= T(m/2) + T(m,n) \\
     &\leq T(m/2) + cm + dn\\
     &\leq cm + dn + cm/2 +dn + ... \\
     &= \sum_{i=0}^{lg\, m -1} \frac{cm}{2^i} + \sum_{i=0}^{lg\, m -1}dn \\
     &= 2cm + dn \, lg \,m\\
     &= O(n \,lg\,m + m)
\end{aligned}
$
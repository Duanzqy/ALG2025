# week3

> Author: **Boyang Guo**
> Can be found at [ALG2025](https://github.com/Duanzqy/ALG2025)
## Exercise 6.2-7

考虑大小为 $n$ 的堆 $A$，假设$A[1] = 1, A[i] = 2, i= 2,3,... , n$ , 由于1是堆z中最小的元素，需要在每一层进行交换直到它成为叶节点，由于堆的高度为 $\lfloor lg\,n \rfloor$, 所以MAX-HEAPIFY的最坏时间为 $\Omega(lg\,n)$.

## Exercise 6.4-3
两者的的时间复杂度均为 $O(n\,lgn)$. 
对于升序数组, 需要先将数组转化成堆，需要 $O(n)$. 之后需要调用 $n-1$ 次 MAX-HEAPIFY, 每次都需要执行全部的 $lg\, k$ 操作, 故总时间复杂度为: 
$\sum_{k=1}^{n-1} lg\,k = lg((n-1)!) = O(n\, lg\, n)$
对于降序数组同理, 主要计算时间为HEAPSORT中的循环MAX-HEAPIFY决定.

## Exercise 7.4-5
快速排序部分，递归在数组长度小于k时停止，故递归树高度为 $lg(n/k)$ ,而每一层调用的划分算法运行时间和为 $O(n)$ ,则快速排序部分的时间为 $lg(n/k)*O(n)=O(n\, lg(n/k))$.

插入排序部分，由于快速排序后，数组被分为$n/k$个长度为$k$的子数组，且大小互不相交，故插入排序的总时间为 $n/k * O(k^2) = O(nk) $.

故总时间复杂度为 $O(n\, lg(n/k)+ nk )$.

理论上，考虑常数因子后，假设总时间为$f(k) = c_i nk + c_q lg(n/k)$, 则有$f'(k) = c_i n-c_q \frac{n}{k\,ln2}$, $f''(k) = c_q\frac{n}{k^2\,ln2}$, 应取 $f'(k) =0$, 即 $k = \frac{c_q}{c_i \, ln2}$ 时, 总时间 $f(k)$取最小.

实践上，应根据实验分析选择k.
## Problem 8-2

#### a 
计数排序

#### b
快速排序

#### c
插入排序

#### d
使用算法(a)计数排序，因为它同时满足了稳定性和时间要求，算法(b)不能保证稳定性，算法(c)不能满足时间复杂度要求.

#### e
就地交换，使用额外 $O(k)$ 空间，但是不稳定

```
MODIFIED-COUNT-SORT(A, n, k)
  let B[0 : k], C[0 : k] and D[0 : k] be new arrays
  for i = 0 to k
    C[i] = 0
  for j = 1 to n
    C[A[j]] = C[A[j]] + 1
  // C[i] 现在表示A中值为 i 的元素数量.
  for i = 1 to k
    C[i] = C[i] + C[i – 1]
    B[i] = C[i - 1] + 1
    D[i] = C[i]
  // C [i] 现在表示A中元素小于或等于 i 的数量.
  // B是每一段的起点，C是每一段的终点，当B[i] > C[i]说明这一段所有数已经复位。
  for i = 1 to n
    while B[A[i]] <= C[A[i]] and (i <= C[A[i]] or i > D[A[i]])
      k = A[i]
      exchange A[i] and A[C[k]]
      C[k] = C[k] - 1
```

---

# External1：使用Git管理你的代码
> *Remark*：补充部分旨在为同学们介绍一些可能会用到的知识与工具，只是提供一个指针，更深入的知识同学们可以自行了解。


## 1.Git 与GitHub
- Git 是一个**分布式版本控制系统**（Distributed Version Control System，简称 DVCS），用于跟踪代码或文件的修改历史，帮助开发者进行协作开发。
- GitHub 是一个**基于 Git 的代码托管平台**，允许开发者存储、管理和共享 Git 仓库。它提供了一系列协作工具，如：**远程代码仓库**：可以将本地 Git 仓库推送到 GitHub，供他人访问。GitHub 是全球最大的开源代码托管平台，在上面可以找到许多开源项目进行学习借鉴。

## 2. 快速入门
### 2.1. 安装Git

下载地址：[Git]((https://git-scm.com/book/zh/v2/%E8%B5%B7%E6%AD%A5-%E5%AE%89%E8%A3%85-Git))
或者直接下载 [GitHub Desktop](https://github.com/apps/desktop)(**推荐！！！**)
注册一个[Github](https://github.com/)账号

### 2.2. 初始化你的仓库并完成一次提交
   对于你想管理的仓库，可以右键-打开终端，输入
```
git init
```
   如下图所示，我要在ALG2025文件夹下新建仓库
   
   ![Pasted image 20250327162259](attachments/Pasted%20image%2020250327162259.png)

接着，打开GitHub Desktop，登陆你的账号后，按下图所示添加一个本地仓库。

![Pasted image 20250327162847](attachments/Pasted%20image%2020250327162847.png)
选择你刚才创建仓库的路径，点击添加，就会得到类似下图的界面

![Pasted image 20250327163114](attachments/Pasted%20image%2020250327163114.png)

最后在左下角summary处，填上一些注释信息，比如 创建仓库、初始化仓库、initialize 等等，点击下面 **Commit to master** ，再点击右上角**Publish repository** （可能需要神秘魔法），你就成功完成了！ 可以在GitHub网站上看到你的代码！

![](attachments/Pasted%20image%2020250327175327.png)
### 2.3. 更新、维护你的代码

在你修改你的代码之后，你可以通过上面最后一步的操作来提交、推送你的更新。即
1. 填上你这次修改代码信息的Summary，然后 Commit to master 
2. Push Origin 
**Remark** ：你的信息一定要能有效反映你修改的意义，这样在你需要返回某个版本的代码时才能找到。代码记得及时提交。

以上的这些操作都可以通过命令行完成，可以在网上搜索各种教程来尝试，或者直接询问GPT等大模型。我选择使用图形化界面来入门是因为这样比较好上手，实际上很多时候还是需要使用命令行来执行，比如说在没有图形界面的Linux远程服务器上，都是依靠命令行来完成的。这里就放一些常用的Git命令。
```
# 初始化 Git 仓库
git init

# 克隆远程仓库
git clone <仓库地址>

# 查看当前状态
git status

# 添加文件到暂存区
git add <文件名>

# 提交更改
git commit -m "提交信息"

# 推送到远程仓库
git push origin main

# 拉取远程仓库更新
git pull origin main

# 创建新分支
git branch <分支名>

# 切换分支
git checkout <分支名>
```


## 3. 能否更进一步？

随着如今AI的迅速发展，我们已经改变了我们的搜索方式，许多问题都可以通过跟LLM(Large language Model)聊天解决。例如我们想学怎么使用 git 创建仓库、管理代码等，但是LLM只会告诉我们怎么去做，而不能直接帮我们完成。

所以我们的目标是：用人类语言告诉 LLM 我们要干什么，然后它就能直接帮我们解决，这更进一步的提高了效率。现在可以通过 **MCP** 解决一部分的问题。

[介绍模型上下文协议 Introducing the Model Context Protocol](https://www.anthropic.com/news/model-context-protocol)

通过 **MCP** 我们可以实现，告诉AI一个Prompt ，如"请帮我建一个 ALG2025 的Git仓库“，便能自动化的完成。关于 MCP 我也只是初步的了解了一些，还没上手操作过，等我先摸索明白了，再在补充中给大家介绍（画饼）。感兴趣的同学可以先行了解一下



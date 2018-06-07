# 3.3 平衡查找树
## 3.3.9  
**
&emsp;  (i). 不是红黑树，不平衡  
&emsp;  (ii). 不是红黑树，在E的左子树中存在F这个比E大的结点  
&emsp;  (iii). 是一颗只有2-结点的红黑树  
&emsp;  (iv). 是一颗红黑树
**
## 3.3.13  
**&emsp; `True`。参见下一题**
## 3.3.14
<center>![顺序插入生成红黑树的过程](D:/WorkSpace/项目之外/Algorithm-4th/image/ascending order.png)</center>
<center>将`A`~`K`按顺序插入所生成的红黑树</center>
**&emsp; 可以看到，树的高度在整个构造过程中完全是单调递增的，不会出现高度变小的情况**
## 3.3.15
<center>![逆序插入生成红黑树的过程](D:/WorkSpace/项目之外/Algorithm-4th/image/descending order.png)  
将`A`~`K`逆序插入所生成的红黑树</center>
**&emsp; (1). `False`。可以看到，在降序插入的情况下，红黑树的高度不是单调递增的，会出现高度变小的情况**  
**&emsp; (2). 最后生成的红黑树在降序插入的情况下和顺序插入是一样的**
## 3.3.21
**&emsp; 答案参考[这里](https://algs4.cs.princeton.edu/33balanced/TestRedBlackBST.java.html)**
## 3.3.33
+ **`is23()`，思路如下**：  
&emsp;&emsp; 1. 如果`x`为空节点，则直接返回`true`  
&emsp;&emsp; 2. 如果`x`的右结点为红链接，则直接返回`false`（**存在红色右链接**）  
&emsp;&emsp; 3. 如果在`x`不为根节点的情况下`x`本身为红链接并且`x`的左结点为红链接则直接返回`false`(**存在同时和两条红链接相连的节点**)  
&emsp;&emsp; 4. 递归判断`x`的左子树和右子树  

        public boolean is23()
        {
            return is23(root);
        }
        private boolean is23(Node x)
        {
            if(x == null)
                return true;
            if(isRed(x.right))
                return false;
            if(x != root && isRed(x) && isRed(x.left))
                return false;
            return is23(x.left) && is23(x.right);
        }  
+ **`isBalanced()`，思路如下：**  
&emsp;&emsp; 1. 先计算出最左边的叶子节点的高度，即黑色链接的个数，然后判断其他的叶子节点的高度和计算出来的高度是否相等  
&emsp;&emsp; 2. 在递归函数中，如果到达了叶子节点，那么black应该为`0`了  
&emsp;&emsp; 3.  递归判断左子树和右子树的黑色链接数是否和第一次算出来的黑色链接数相等

		public boolean isBalanced()
        {
        	int black = 0;
            Node x = root;
            while(x != null)
            {
            	if(!isRed(x))
                	black++;
            	x = x.left;
            }
            return isBalanced(root, black);
        }
        private boolean isBanlanced(Node x, int black)
        {
        	if(x == null)
            	return black == 0;
            if(!isRed(x))
            	black--;
            return isBalanced(x.left, black) && isBalanced(x.right, black);
        }
                        
## 3.3.38
**&emsp;&emsp; 证明：**  
&emsp;&emsp; 首先，证明任意一颗结点为`n`二叉树可以通过至多`n-1`次右旋转操作转化为一个右链二叉树(即所有的结点都没有左子树)。考虑所有的右结点的集合，每一次的右旋转操作都会使这个集合的结点数`+1`，当所有的结点都是右结点时这颗二叉树就变成了一个右链二叉树(**具体旋转时可以从最左边的一个结点开始，每次都对最左边的结点进行右旋转操作，最后会得到一个右链二叉树**)。  
&emsp;&emsp; 本题中，假设两颗二叉树分别为**T<sub>1</sub>, T<sub>2</sub>**，那么**T<sub>1</sub>**可以通过右旋转操作转化为一个右链二叉树，同样**T<sub>2</sub>**也可以通过右旋转操作转化为一颗右链二叉树，而**T<sub>1</sub>**和**T<sub>2</sub>**都是同样的元素插入构成的，那么所得到的右链二叉树也必然相同，如果对**T<sub>1</sub>**形成的右链二叉树执行与**T<sub>2</sub>**的右旋转相反的左旋转操作，则会得到**T<sub>2</sub>**。即，通过一系列的左旋转和右旋转操作可以得到由同一组键生成的其它任意一颗二叉树。  
## 3.3.39
**&emsp;&emsp; 删除最小键的操作。**  
&emsp;&emsp; 从树底部的3-结点删除键是很简单的，但是2-结点则不然。从2-结点删除一个键会留下一个空节点，一般我们会将它替换为一个空链接，但是这样会破坏树的完美平衡性。所以我们需要将树的最左边路径上的2-结点全部变换为3-结点或者**(临时的)**4-结点。具体来说，在沿着左链接向下的过程中，我们执行如下操作：   
1. 如果当前的结点的左子节点不是2-结点，当前结点操作结束；  
2. 如果当前结点的左子节点是2-结点而他的亲兄弟结点不是2-结点，将左子节点的兄弟结点中的最小键移动到左子节点中(其实是将它移动到父亲节点，而父亲结点的键移动到左子结点)；  
3. 如果当前结点的左子结点和它的亲兄弟结点都是2-结点，将左子结点、父结点中的最小键以及和左子结点最近的兄弟结点合并成为一个4-结点，使父结点由4-结点变为3-结点或者由3-结点变为2-结点。  

最后，从下往上分解所有临时的4-结点。
<center>![兄弟结点不为2-结点](D:/WorkSpace/项目之外/Algorithm-4th/image/3-node.png)</center>
<center>兄弟结点不为2-结点的变换过程</center>
<center>![兄弟结点为2-结点](D:/WorkSpace/项目之外/Algorithm-4th/image/2-node.png)</center>
<center>兄弟结点为2-结点的变换过程</center>
对比上面两幅图我们发现，无论亲兄弟结点是不是2-结点，父结点中的最小值都会从父结点中降下来，变成左子结点中的一个元素。也就是说整个第三点的操作实际上是第二点操作的一部分。  
为了实现以上过程，我们需要修改之前定义的`flipColors()`函数如下：  

		private void flipColors()
        {
        	assert(!isRed(h) && isRed(h.left) && isRed(h.right));
            assert(isRed(h) && !isRed(h.left) && !isRed(h.right)); //删除的过程中这个断言一定不会失败
            h.color = !h.color;
            h.left.color = !h.left.color;
            h.right.color = !h.right.color;
        }
可以看到，只要对父结点中的最小值调用 `flipColors()` 函数则可以直接将最小值从父结点中降下来，变成左子结点中的一个元素(因为这个过程中父结点一定不是2-结点)，即下面代码中的第三行的`flipColors()`函数调用。  
另外仔细观察上面操作的第二点，可以发现，要实现剩下的操作(除了`flipColors()`之外的操作)，直接对当前结点的右子树进行右旋转，然后对当前结点进行左旋转即可，再进行一次颜色转换(书上的代码有错误，具体可看[这里](https://algs4.cs.princeton.edu/errata/errata-printing5.php))即可。即下面代码中除了第一个`flipColors()`函数调用之外的部分。

		private Node moveRedLeft(Node h)
        {
        	flipColors(h);  // 这一句话就实现了上面所说的第三点
            // 下面的代码段加上上面的一句就实现了上面说的第二点
            if(isRed(h.right.left))
            {
            	h.right = rotateRight(h.right);
                h = rotateLeft(h);
                flipColors(h);  // 我觉得这里需要一次flipColors()，但是书上没有这一个(书本网站上的勘误指出了这个错误)
            }
            return h;
        }
删除最小值的全部代码如下：

		private void flipColors()
        {
        	assert(!isRed(h) && isRed(h.left) && isRed(h.right));
            assert(isRed(h) && !isRed(h.left) && !isRed(h.right)); //删除的过程中这个断言一定不会失败
            h.color = !h.color;
            h.left.color = !h.left.color;
            h.right.color = !h.right.color;
        }
        
        private Node moveRedLeft(Node h)
        {
        	flipColors(h);
            if(isRed(h.right.left))
            {
            	h.right = rotateRight(h.right);
                h = rotateLeft(h);
                flipColors(h);
            }
            return h;
        }
        
        public void deleteMin()
        {
        	// 确保根结点为红色，这样才能在根节点的左子结点为2-结点时正确的调用 flipColor() 函数
        	if(!isRed(root.left) && !isRed(root.right))
            	root.color = RED;
            
            root = deleteMin(root);
            if(!isEmpty())
            	root.color = BLACK;
        }
        private Node deleteMin(Node h)
        {
        	// 找到了最小的，删除
        	if(h.left == null)
            	return null;
                
            // 判断当前结点的左子结点是否为2-结点
            if(!isRed(h.left) && !isRed(h.left.left))
            	h = moveRedLeft(h); // 为2-结点则执行上面描述的操作
            h.left = deleteMin(h.left); // 递归
            return balance(h);  // 从下往上分解所有临时的4-节点
        }
        private Node balance(Node h) 
        {
            // 调整右红链接
            if (isRed(h.right))    h = rotateLeft(h);
            // 调整连续的红链接
            if (isRed(h.left) && isRed(h.left.left)) h = rotateRight(h)
            // 删除临时的4-结点
            if (isRed(h.left) && isRed(h.right)) flipColors(h);

        return h;
		}

## 3.3.40
**&emsp;&emsp; 删除最大键的操作。**删除最大键和删除最小键的思路有所不同。如果含有最大键的结点是一个2-结点，那么可以直接删除，但是会破坏树的完美平衡性；但是如果是一个3-结点，则不能直接删除，因为该结点还有一个红色的左孩子，在这种情况下，需要对该结点进行右旋转，然后就可以直接删除了。因此，整体思路和删除最小键类似，我们再删除的过程中要保证最大键是3-结点，如何保证当前结点时3-结点呢？和删除最小值的思路一样，在沿着右链接向下的过程中，我们执行如下操作：  
1. 如果当前结点是3-结点，则结束当前结点上的操作；
2. 如果当前结点的右子结点和它的亲兄弟结点都是2-结点，将右子结点、父结点中的最大键以及和右子结点最近的兄弟结点合并成为一个4-结点，使父结点由4-结点变为3-结点或者由3-结点变为2-结点；
3. 如果当前结点的右子节点是2-结点而他的亲兄弟结点不是2-结点，将右子结点的兄弟结点中的最小键移动到右子节点中(其实是将它移动到父亲节点，而父亲结点的最大键移动到右子结点)。

最后，执行和删除最小键中一样的删除临时4-结点的工作。代码如下：

		private Node moveRedRight(Node h)
        {
        	flipColors(h); // 合并右结点、父结点中的最大键和右子结点的兄弟结点为一个4-结点
            if(isRed(h.left.left))  // 书中的代码有错误
            {
            	h = rotateRight(h);
                flipColors(h); // 书上的代码有误
            }
            return h;
        }
        public void deleteMax()
        {
        	if(!isRed(root.left) && !isRed(root.right))
            	root.color = RED;
            root = deleteMax(root);
            if(!isEmpty())
            	root.color = BLACK;
        }
        private Node deleteMax(Node h)
        {
        	if(isRed(h.left)) // h为3-结点则要执行右旋转操作
            	h = rotateRight(h);
            if(h.right == null)
            	return null;
            if(!isRed(h.right) && !isRed(h.right.left))  // h的右结点不为3-结点
            	h = moveRedRight(h);
            h.right = deleteMax(h.right);
            return balance(h);
        }
        
## 3.3.41
**&emsp;&emsp; 删除操作。**  
&emsp;&emsp; 如果理解了上述删除最小键和最大键，那么理解删除任意一个节点就要容易些了，实现比较繁琐。  
+ 从树的头节点开始，如果当前节点的键小于待删除的，则在左子树中递归删除；
+ 否则先判断一下当前节点的左孩子是否为红，是则左旋转，将红链接旋转到右孩子(跟删除最大值时一样)；
+ 判断待删除的节点是否为当前节点，且右孩子是否为空。如果右孩子为空，此时待删除的节点在树底，包含两种情况：其一，待删除的节点是红色节点，且为叶节点；其二，待删除的节点通过上一步的旋转变为了红色右孩子，且为叶节点。这样就可以直接删除这个叶结点；
+ 如果待删除的结点是当前结点，但是不是叶结点(即右子树不为空)，则采用后继节点替代的删除方式：与BST类似，先找到右子树的最小节点，将其键值对赋给当前的节点，然后采用递归删除的方式删除右子树中的最小节点（保证链接的正确性）
+ 否则（也就是当前节点的键大于待删除节点的键），递归在右子树中删除，在递归的过程中要保证当前节点或当前节点的右孩子为红节点（同样从父节点入手）。这里要注意这里的否则对应的else语句要放在上一个else中，以保证能将红色左孩子通过旋转变为红色右孩子
+ 最后，记得要修复沿路的红色右节点  
还有点要注意，不可在递归的开头定义一个int变量来记录当前节点与待删除节点的比较值，因为在上述第二步中，也就是将红色左孩子旋转变为红色右孩子，树的结构可能会变，应该还要重新再比较一次的。要是那么做了（一次比较两处使用，就像BST中那样），会有一个bug，当待删除的节点是一个红节点（左孩子）的父节点时，最终该节点不会被删除，而该节点的红色左孩子会被删除。  

		public void delete(Key key)
        {
        	if(!isRed(root.left) && !isRed(root.right))
            	root.color = RED;
            root = delete(root, key);
            if(!isEmpty())
            	root.color = BLACK;
        }
        private Node delete(Node h, Key key)
        {
        	if(key.compareTo(h.key) < 0)
            {	// 递归在左子树中删除，操作过程跟删除最小值一样
            	if(!isRed(h.left) && !isRed(h.left.left))  // 确保删除的结点不为2-结点
                	h = moveRedLeft(h);
                h.left = delete(h.left, key);
            }
            else
            {
            	if(isRed(h.left)) // 跟在删除最大值中的一样，确保右子树中出现红色右孩子，不然不能直接删除
                	h = rotateRight(h);
                if(key.compareTo(h.key) == 0 && (h.right == null)) // 找到了要删除的结点，且该结点为叶结点
                	return null;
                if(key.compareTo(h.key) == 0) // 要删除的结点不为叶结点
                {	// 和 BST 树中的删除一样，用最小值代替
                	h.val = get(h.right, min(h.right).key);
                    h.key = min(h.right).key;
                    h.right = deleteMin(h.right);
                }
                else
                {	// 递归在右子树中删除，操作过程跟删除最大值一样
                	if(!isRed(h.right) && !isRed(h.right.left))
                		h = moveRedRight(h);
                	h.right = delete(h.right, key);
                }
            }
            return balance(h);
        }

# 3.4 散列表
## 3.4.5
&emsp;&emsp; 合法，但是会把所有的键都映射到同样的位置，会导致非常差的性能。
## 3.4.24
这个没有仔细研究  

|方法|N个元素所需要的内存(Double类型)|
|-|:-:|
|基于拉链法的散列表|56+32M+48N|
|基于线性探测的散列表|~24+48N|
## 3.4.32
&emsp;&emsp; 因为已经知道`Aa`和`BB`的散列值相同，那么我们可以组合出任意长度的散列值相同的字符串，比如`AaAa`和`BBBB`，`AaBB`和`BBAa`等等。[这里](https://algs4.cs.princeton.edu/34hash/hash-attack.txt)有1000个散列值相同的字符串。
## 3.4.33
&emsp;&emsp; 确实，本题中的实现计算的更快，但是这会让更多的字符串映射到相同的散列值，导致在真实使用中的性能急剧下降。
# 3.5
// TODO
# 总结

|算法(数据结构)|查找(N次插入之后的最坏情况)|插入(N次插入之后的最坏情况)|查找命中(平均情况)|插入(平均情况)|
|:-:|:-:|:-:|:-:|:-:|
|顺序查询(无序链表)|N|N|N/2|N|
|二分查找(有序数组)|lgN|N|lgN|N/2|
|二叉查找树|N|N|1.39lgN|1.39lgN|
|2-3树查找(红黑树)|2lgN|2lgN|1.00lgN|1.00lgN|
|拉链法*(链表数组)|<lgN|<lgN|N/(2M)|N/M|
|线性探测法*(并行数组)|clgN|clgN|<1.5|<2.5|
&emsp;&emsp; *需要均匀并独立的散列函数  
&emsp;&emsp; 从表中可以知道，对于典型的应用程序，应该从二叉树和散列表中选择，相对于二叉查找树，散列表的优点在于代码简单且查找时间最优；二叉查找树相对于散列表的优点在于抽象结构更简单（不需要设计散列函数），红黑树可以保证最坏情况下的性能且它能支持的操作更多（如排名，选择，排序和范围查找）。根据经验，我们的第一选择一般都是散列表，在其它因素更重要时才会选择红黑树。


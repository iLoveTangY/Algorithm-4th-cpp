# Chapter 4
# 4.1 无向图
## 4.1.3
&emsp;&emsp; 注意，在复制图时必须得用一个栈将邻接表的顺序逆置，这样保存到新的图里面时邻接表的顺序才能和原来一样。代码如下：

        public Graph(Graph G)
        {
            this(G.V());
            this.E = G.E();
            for(int v = 0; v < G.V(); v++)
            {
            	Stack<Integer> reverse = new Stack<Integer>();
                for(int w : G.adj(v))
                	reverse.push(w);
                for(int w : reverse)
                	adj[v].add(w);
            }
        }
## 4.1.13
&emsp;&emsp; 如果要时间为常数则可以在类中增加一个数组`distTo[]`，其中每个元素代表该顶点到起点的距离。初始化时将数组初始化为无穷大，然后在`bfs`中更新数组中的值。代码如下：

		private void bfs(Graph G, int s) 
        {
        	Queue<Integer> q = new Queue<Integer>();
        	for (int v = 0; v < G.V(); v++)
            	distTo[v] = INFINITY;
        	distTo[s] = 0;
        	marked[s] = true;
        	q.enqueue(s);

        	while (!q.isEmpty()) 
            {
            	int v = q.dequeue();
            	for (int w : G.adj(v)) 
                {
                    if (!marked[w]) 
                    {
                        edgeTo[w] = v;
                        distTo[w] = distTo[v] + 1;
                        marked[w] = true;
                        q.enqueue(w);
                    }
                }
            }
        }
## 4.1.22
&emsp;&emsp; 参考[这里](https://algs4.cs.princeton.edu/41graph/BaconHistogram.java.html)。注意，题目中要求的是演员的`Kevin Bacon`数，所以最后输出的时候要输出偶数下标的直方图。
## 4.1.25
&emsp;&emsp; 代码见[这里](https://algs4.cs.princeton.edu/41graph/DegreesOfSeparationDFS.java.html)。很简单的代码，只要把书上的[`DegreesOfSeparation`](https://algs4.cs.princeton.edu/41graph/DegreesOfSeparation.java.html)中的`BFS`换成`DFS`就可以了。
## 4.1.26
&emsp;&emsp; 官方给出的答案是56+40V+128E。但是我死活算不出这个结果...
## 4.1.31
&emsp;&emsp; 一开始我的想法是对每个顶点维护一个布尔数组，在添加边时将数组对应的位置置位`true`，例如，数组名为`hasEdge`,插入2和3之间的一条边，那么就要将`hasEdge[2][3]`和`hasEdge[3][2]`都设为true。如果在插入边时返现对应位置已经为`true`，则表明产生一条平行边，平行边数量加1。假设顶点数量为`V`，边的数量为`E`很明显可以看到，虽然这种算法的时间复杂度为`O(1)`，但是空间复杂度为`O(V^2)`，对于顶点数比较大的图来说这种算法是完全行不通的。  
&emsp;&emsp;然后想到，对于用邻接表表示的图来说，如果3和2之间存在平行边，那么在3的邻接表中2一定出现了不止一次，那么通过遍历邻接表就能找到平行边。具体可以这样操作，对每一条邻接表，维护一个和顶点大小一样的数组，在遍历链表的过程中，数组每个位置的值就是该顶点在邻接表中出现的次数，那么当遍历完之后，如果数组中某处的值大于一，那么就出现了该值减一条平行边；对每个顶点都进行这样的遍历，并在遍历开始时将数组的值初始化为0，最后将统计出的平行边的条数除以2就是真正的平行边的条数。可以看到，这种算法的空间复杂度为`O(V)`，时间复杂度为`O(E)`。代码如下：

		public class ParallelEdge
        {
            public static void initializeArray(int[] hasEdge)
            {
                for(int i = 0; i < hasEdge.length; i++)
                    hasEdge[i] = 0;
            }

            public static void main(String[] args)
            {
                Graph G = new Graph(new In(args[0]));
                StdOut.println(G);
                int[] hasEdge = new int[G.V()];
                int parallelEdge = 0;
                for(int v = 0; v < G.V(); v++)
                {
                    initializeArray(hasEdge);
                    for(int w : G.adj(v))
                    {
                        hasEdge[w] += 1;
                        if(hasEdge[w] != 1)
                            parallelEdge += 1;
                    }
                }

                StdOut.println("Parallel Edge Numbers: " + parallelEdge / 2);
            }
        }
        
# 4.2 有向图
## 4.2.3  
&emsp;&emsp; 和无向图的一样。
## 4.2.17
&emsp;&emsp; False.  
&emsp;&emsp;到了图论的习题开始不会做了QAQ。。。
# 4.3 最小生成树
# 4.4 最短路径
# 4.5 总结


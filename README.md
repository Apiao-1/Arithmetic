# Arithmetic
试题来源：杭电OJ http://acm.hdu.edu.cn/listproblem.php?vol=1

## 试题小计
#### 1002 大数加法 
debug好久一直WA，还用上了对拍器，最后发现是输出的“case”应该是“Case” 
/(ㄒoㄒ)/~~

## PAT系列

#### 1060 Are They Equal (25)⭐️
考察科学计数法的转化，此题的测试用例涵盖有特殊情况，例：0000001、0.0000001、0.0与0的判断；故在处理之前需先处理数字前方的0
解决思路:
1.对数字进行预处理，去掉开头部分的0；
2.第二部根据小数点位置区分小数或非小数，计算阶码e；
3.根据有效位数输出有效数字部分，需考虑精度高于该数字时以0补足

（将科学计数法转化为一般式见题1073）

#### 1001 A+B Format (20) 

思路很简单，转化为字符串后每隔三位输出一个逗号，但每隔三位的把握卡了很久（未考虑到原始数位数的影响）

正解：(i+1) % 3 == length % 3 && (i+1)!=length 

#### 1133 Splitting A Linked List (25)⭐️ 

该题需注意
1.链表结构的存储用数组会大大提高写代码的效率；
2.注意最后的输出，小技巧（题意要求每一个节点的next节点都指向新的节点，只需把下一个节点的当前位置输出两遍即可，无需更改真实的指向）

#### 1068 Find More Coins (30)⭐️

01背包的变种问题，需要注意的是输出01背包的解，需添加choice\[i][j]数组
另：暴力dfs可解决

#### 1044 Shopping in Mars (25)

O(n^2)复杂度会有三组测试用例超时，此时改用二分法将复杂度下降为O(nlgn)

注意若超时的话，优先检查是否将**输入输出换成scanf 和 printf**

在输入输出量非常大时，能节省非常可观的时间

#### 1018 Public Bike Management (30)⭐️⭐

dijkstra（记录路径） + DFS
好题，目前碰到的考dijkstra最全面最复杂的题，涉及到用pre\[i]向量来多条最短路径，再用DFS模拟过程

#### 1003 Emergency (25)⭐️ 

dijkstra(涉及到点权值及多条最短路径的计数)

注意与1018的区分，不需要用DFS模拟路径

#### 1027 Colors in Mars (20) 

进制转换，巧妙的写法，因为0~168的十进制转换为13进制不会超过两位数，所以这个两位数为(num / 13)(num % 13)构成的数字 

#### 1007 Maximum Subsequence Sum (25)⭐️ 

最大子段和问题，多了一步求出最大字段具体的数值，牛客网上测试用例比较变态，做完好好检查下边界值

#### 1073 Scientific Notation (20) 

将科学计数法还原成一般形式

#### 1057 Stack (30) 

栈+树状数组+二分（较难）

树状数组的理解见 ：[掌握树状数组](https://www.cnblogs.com/acgoto/p/8583952.html#4041449)

#### 1067 Sort with Swap(0,*) (25)⭐️ 

此题对时间复杂度有一定要求，注意如下：

1.存储时为避免找数字的位置时每次都要从头遍历一遍，直接存储数字的位置（类似哈希表）；

2.0换到原位时，判断下一个不在位置上的数字用一个index存储，因为此前寻找的在之后一定还是有序的 

#### 1051 Pop Sequence (25) 

模拟栈的入栈出栈过程进行检验，**注意每次初始化相关STL容器**

#### 1077 Kuchiguse (20)  

最长后缀子串，需要注意的是getline的使用（gets方法目前已废除）；输入时若将字符串先直接反转，则可以免去len[k]的记录长度的数组 

#### 1045 Favorite Color Stripe (30) 

考察最长公共子序列的变种（LCS），允许元素重复

 这道题目，按照正常的思路求解，应该使用最长公共子序列算法LCS，但与常规的LCS有所差别，常规LCS是从两个序列中按索引递增顺序，不重复的选取最大公共子列，而现在的问题是在序列B中按照A中的元素顺序可重复的找出最大子列，这样说起来比较抽象，下面举个例子，对于序列： 

 A=｛2,3,1,5,6｝ B={2,2,4,1,5,5,6,3,1,1,5,6}

 如果是常规的LCS，我们找到的子列将会是{2,3,1,5,6}，因为B完全的包含了A（不必连续）

 如果是可重复的LCS，我们完全可以选择{2,2,3,1,1,5,6}，这便是变种的LCS。 

 对于常规的LCS，只有A[i] = B[j]时才让当前的最大子列长度为maxLen[i-1][j-1]+1，其他情况则取maxLen[i-1][j]或者maxLen[i][j-1]中的最大值，这样的算法只能不重复的找出子列，如果要考虑重复，应该修改算法，无论什么情况，都取maxLen[i-1][j-1]、maxLen[i-1][j]和maxLen[i][j-1]中的最大值，如果A[i]=B[j]，则在最大值的基础上+1，这样就可以处理重复的情况了。

#### 1034 Head of a Gang (30) 

方法一：DFS遍历图（推荐）

方法二：使用并查集

#### 1071 Speech Patterns (25) 

此题有几个注意点：

1.map默认按键的升序排序，此处即默认为字典序，故无需多处理；

2.特别注意若扫描到最后一位时，无论该位是否是字母都需将其加入map，否则可能产生最后一个单词未统计的情况 

#### 1072 Gas Station (30) 

做n次Dijkstra，花了很长时间找到的bug

1.答案错误时，第一步审题，第二步检查各处的初始化，例min，max，flag等的值

2.切记，字符数组保存字符串时，**一定要留一个空间保存结束符 '\0'（提示段错误）**，永远别把数组开得很极限 

#### 1063 Set Similarity (25) 

考察set与vector结合的使用，vector<set<int>> a(55);注意此处不能用[];

#### 1093 Count PAT's（25 分）

逻辑题，整个字符串扫描一遍，遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。然后把对于每一个A的结果相加即可 。

此题需额外注意对大数取模的应用：

这里由于pnum*tnum非常大直接写会出错，故加取模%1000000007

加上后还是显示答案错误，考虑到ans+(pnum*tnum)% 1000000007也会很大，再取余，AC

至于为什么要对1000000007取模，参加https://www.liuchuo.net/archives/645

#### 1046 Shortest Distance (20) 

用sum数组进行累加，顺时针情况两点见的值通过对应sum相减的方式处理，逆时针的话通过整个环的总和减去顺时针的就好 

#### 1098 Insertion or Heap Sort （25）

此题需手动模拟堆排序的排序过程，因为queue不支持遍历操作，无法输出一次操作后每个节点的情况 

考察了堆排序的模拟过程

#### 1091 Acute Stroke（30) 

BFS或DFS都可以，图的遍历 

#### 1010 Radix (25) 

通过率最低的试题，乍一看只是一道进制转化，但测试点的进制大到令人咂舌，比如214761.。。。

需要用到二分求解进制，不然会超时

#### 1037 Magic Coupon (25)

直接手动写sort的cmp函数还是会产生错误的地方，故默认排序，再分成两个部分判断即可，注意（牛客网处需要把数据类型都改成long long才可通过）

#### 1085 Perfect Sequence（25)

注意数据大小，n<10^9用long long型，此题dfs超时，用two points的思想求解

#### 1038 Recover the Smallest Number (30)

解法很巧妙，体会到了cmp函数的强大，此题的排序不是按照字典序排列就可以，而是必须保证两个字符串构成的数字是最小的才行，所以cmp函数写成return a + b < b + a;的形式，保证它排列按照能够组成的最小数字的形式排列。

#### 1014 Waiting in Line (30)

题目不是太难，考察queue的应用，反思没把bug找出来的原因：

1.忽略了题目中的“如果这个服务已经开始了，无论时间多长都要等他服务完毕”一条件；

2.注意到该条件后，最后判断是否在17点以前开始任务不应减去cost[i]进行判断（cost[i]在过程中就已被改变，故需在开始新设一个数组）

3.在初始化排队时，没注意到无法把n个窗口都排满的情况（注意到了在黄线内未排满，但忽略了人太少以致窗口都排不满)

#### 1061 Dating（20）

终于看懂了题，一开始对题目中的“since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D”，产生了误解（我说原序列中相等的位置明明是6呀，怎么会是4呢）

此题WA的原因——每次输出时分秒时注意控制%02d，不能光控制了分，不控制时

#### 1065 A+B and C (64bit)（20

 方法一，longlong类型再判断sum是否溢出

 因为A、B的大小为[-2^63, 2^63]，用long long 存储A和B的值，以及他们相加的值sum：

 如果A > 0, B < 0 或者 A < 0, B > 0，sum是不可能溢出的

 如果A > 0, B > 0，sum可能会溢出，sum范围理应为(0, 2^64 – 2]，溢出得到的结果应该是[-2^63, -2]是个负数，所以sum <= 0时候说明溢出了

 如果A < 0, B < 0，sum可能会溢出，同理，sum溢出后结果是大于0的，所以sum >= 0 说明溢出了

 

 这里需特别注意sum = 0的溢出判断，不然PAT最后一组测试用例过不去



方法二，直接用long double类型，求出的sum不会溢出

#### 1119 Pre- and Post-order Traversals（30）

给出前序后序，转中序，递归求解

#### 1123 Is It a Complete AVL Tree（30)⭐️

AVL数+层序遍历+判断是否是完全树

考察点很全面，重要

平衡二叉树详见https://www.cnblogs.com/zhangbaochong/p/5164994.html


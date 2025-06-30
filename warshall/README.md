### warshall
warshall函数接受二维布尔矩阵,代表输入的任意n阶01矩阵，计算这个关系的传递闭包t(S)
比较t(S)与S是都相等,相等则说明原关系是传递的,否则则不是传递的。

### CountTranRelation
CountTranRelation函数接受集合大小n,默认为4。将这个n元集合上所有总计2^(n^2)种关系矩阵映射到n^2长的二元串上，通过位移操作实现构建传递矩阵;通过warshell函数判断这个关系是否是传递的,遍历所有关系矩阵并计数，得到这个n元集合上的传递关系数。

### isTransitive
对输入的关系矩阵调用warshall函数判断是否传递并输出提示信息。

### count
提供外部接口，隐藏内部信息，调用CountTranRelation函数

### judge
同count，提示输入矩阵阶数并逐行读取数据,调用isTransitive函数判断是否传递。


[整个项目地址](https://github.com/hxhdhcjmet/Discrete-Mathematics-Final-Assignment-2025-.git)
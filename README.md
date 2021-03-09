# Garage Arithmetic
## <font color=#990000>Question Description</font>

在理想情况下（无障碍物，不考虑碰撞），4个同样类型小车（a, b, c, d）从任意位置同时出发，要分别到达4个指定的位置的车库（A, B, C, D）（一个车库只能停一辆车），假设**全部小车进库的时间**是T，即最后一辆小车完成入库的时间。编程求出**T的最小值**，并给出一种最优方案，即车和车库的对应关系。小车入库的时间如下表所示。

表1 小车入库时间表（单位：分钟）

|       |  A   |  B   |  C   |  D   |
| :---: | :--: | :--: | :--: | :--: |
| **a** |  4   |  8   |  7   |  15  |
| **b** |  7   |  9   |  17  |  14  |
| **c** |  6   |  9   |  12  |  8   |
| **d** |  6   |  7   |  14  |  6   |

## <font color=#990000>Solutions</font>

1. 建立二维数组

   ~~~C
   int matrix = { {4,8,7,15},{7,9,17,14},{6,9,12,8},{6,7,14,6} }
   ~~~

2. 建立一维数组，将二维数组中的值付给一维数组，并对一维数组进行从大到小的冒泡排序

   ~~~C
   int matrixToArray[16];
   
   int a = 0;
   for (int i = 0; i < 4; i++) {
   	for (int j = 0; j < 4; j++) {
   		matrixToArray[a] = matrix[i][j];
   		a++;
   	}
   }
   
   bubble_sort(matrixToArray);
   ~~~

3. 从最大值matrixToArray[0]开始，假定最终答案是当前最大值，在二维数组中删去这个数，将这个数所在位置的值置为0

   ~~~C
   void selectNum(int arrayOneDim[], int matrixTwoDim[][4],int zeroOneArray[][4], int n) {
   	for (int i = 0; i < 4; i++) {
   		for (int j = 0; j < 4; j++) {
   			if (arrayOneDim[n] == matrixTwoDim[i][j]) {
   				zeroOneArray[i][j] = 0;
   			}
   		}
   	}
   }
   ~~~

4. 判断此时的二维数组是否可以满足题目条件（一个车库只能停一辆车）

   对于$4 × 4$的二维数组有4种情况不能满足题目条件：

   - 有至少一行是4个0
   - 有至少一列是4个0
   - 有至少两行是3个0，且3个0的位置相同
   - 有至少两列是3个0，且3个0的位置相同

   ~~~C
   bool judgementLine4Zero(int zeroOneArray[][4]);
   bool judgementRow4Zero(int zeroOneArray[][4]);
   bool judementLine3Zero(int zeroOneArray[][4]);
   bool judementRow3Zero(int zeroOneArray[][4]);
   ~~~

5. 重复第3、第4步的操作，直到第4步的判断无法满足题目条件，此时在第3步中删去的值就是答案

   ~~~C
   for (int i = 0; i < 16; i++) {
   	selectNum(matrixToArray, matrix, matrixBool, i);
   	if (!judgement(matrixBool)) {
   		result = matrixToArray[i];
   		break;
   	}
   }
   cout << result << '\t';
   ~~~


## <font color=#990000>Answers</font>

1. T = <font color=#808080>8</font>

2. 最佳入库方案

   |  车库  |              A               |              B               |              C               |              D               |
   | :----: | :--------------------------: | :--------------------------: | :--------------------------: | :--------------------------: |
   | **车** | <font color=#808080>b</font> | <font color=#808080>d</font> | <font color=#808080>a</font> | <font color=#808080>c</font> |

   
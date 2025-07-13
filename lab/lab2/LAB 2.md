# LAB 2

马颢宸 23307110426

2025/3/18

---

## 2.1

### 2.1.1

1）

==参数匹配的规则==

1. **完全匹配的函数**：参数类型与函数声明完全一致

2. **不重要的转换**，如：

   加上或删去const/volatile限定符

   数组与指针的调整	

   函数名与函数指针的调整

   ​	……

3. **整型提升**，如：

   char/short -> int

   float -> double

   bool -> int

4. **标准转换**，如：

   算术转换（int->double、long->int）（可能丢失精度）

   指针转换：派生类->基类

   枚举类型->其底层整型

   nullptr->指针类型

5. **省略号匹配**：匹配可变参数，优先级最低

==转换顺序==

1. 1-5代表优先级顺序
2. 需要最少转换的候选函数有限
3. 若同一优先级存在多个候选函数，编译器会报错。



2）

![image-20250318205909947](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250318205909947.png)

第三个调用 reckon(3.0f,4.0f)没有匹配函数

因为该调用参数是两个float类型，而定义的float reckon(int a, float b)与float reckon(float b, int a)函数都可通过标准转换匹配调用函数，出现二义性，匹配失败。



3）

E2_1.cc

![image-20250318210625559](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250318210625559.png)



4)

E2_1.cc

![image-20250318210726975](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250318210726975.png)

因为对于调用**reckon**(3.0f,4)和**reckon**(3,4.0f)，唯一的函数float reckon(float a, float b)课通过标准转换与它们匹配，且不存在二义性。故三种调用都会与第三个函数成功匹配，所以最后均输出reckon @ line 23与3.5



## 2.2

代码略

prime_main.cc手动测试结果截屏

![image-20250318212128235](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250318212128235.png)



## 2.3

quick-bench测试结果截图

![image-20250318212007032](C:\Users\LENOVO\AppData\Roaming\Typora\typora-user-images\image-20250318212007032.png)




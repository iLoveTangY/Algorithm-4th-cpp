# Chapter 1
## 1.1
### 1.1.27
二项分布
计算递归次数可以用下一节中即将用到的[Counter](./Counter.hpp)类。代码如下所示。计算结果大约是100！次递归调用。  
![使用计数器类计算调用次数](../image/Chapter_1/计算二项分布递归调用次数.png)  
可以使用数组保存已经计算过的值，完整代码见[Binomial.hpp](./Binomial.hpp)和[Binomial.cpp](./Binomial.cpp)。

## 1.2
### 1.2.4
结果：   
![打印结果](../image/Chapter_1/1.2.4.png)
### 1.2.6 回环变位
```
s.size() == t.size() && (s+t).find(t) != string::npos;
```
### 1.2.7
将s逆置。
### 1.2.13
仿照[Date.hpp](./Date.hpp)和[Date.cpp](./Date.hpp)实现[Transaction.hpp](./Transaction.hpp)和[Transaction.cpp](Transaction.cpp)就好。
### 1.2.14
参见[Transaction.hpp](./Transaction.hpp)和[Transaction.cpp](Transaction.cpp)。
### 1.2.16 有理数
参见[Rational.hpp](./Rational.hpp)和[Rational.cpp](./Rational.cpp)。


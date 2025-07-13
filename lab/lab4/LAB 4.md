# LAB 4

马颢宸 23307110426

2025/4/13

---

## 2.1

###  2.1.3

代码略

==特别补充==

在`nsmap.cc`文件中，对`remove`函数的设计，原本采用和`nsvector.cc`相同逻辑，但研究`erase`函数后发现，可以直接将键值作为参数进行删除，效果相同。两种实现方式时间复杂度相同，但后者表达更简洁明了。

`naumap.cc`同上。

```cpp
bool remove(const HostName& hostname){
    //auto it = vns.find(hostname);
    //if (it != vns.end()) {
    //    vns.erase(it); // 删除元素
    //    return true;
    //}
    //return false;

    return vns.erase(hostname); // 使用erase直接删除键值的方法-->返回删除数量：成功删除=1，失败删除=0
}
```



### 2.1.4

运行截图如下

==直接运行`run.bat`==

![3e5529e6d491590e5d9a651702755bc](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\3e5529e6d491590e5d9a651702755bc.png)

按照`nsvector`  `nsmap`  `nsumap`顺序，依次执行20、40、80、160、224k的数据文件截图

![0bc99e57f55d74ecf3b6661627261d9](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\0bc99e57f55d74ecf3b6661627261d9.png)

![d991c3d9233da27a8b732ea4bb402b4](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\d991c3d9233da27a8b732ea4bb402b4.png)

![484ca5b56f1189086932bcfb1d6692a](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\484ca5b56f1189086932bcfb1d6692a.png)

![a6070f1cb590e04a10dd200662614fb](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\a6070f1cb590e04a10dd200662614fb.png)

![c78ba7189d85373a2dd98d2570f83a6](C:\Users\LENOVO\Documents\WeChat Files\wxid_hk333tei9oqm22\FileStorage\Temp\c78ba7189d85373a2dd98d2570f83a6.png)


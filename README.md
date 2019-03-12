# qt_360_safe
qt高仿360安全卫士

效果图地址:
https://blog.csdn.net/dkaily1314/article/details/65442765

说明：
1. 该代码写于2017年3月，所以现在的qt编译器可能有部分代码已经不相同了。
2. 仅供新手学习qt使用，因为我也是开始学习时，练手的小程序，里面有很多不合理的代码。


编译时，可能会出现 Project ERROR: Unknown module(s) in QT: webenginewidgets 错误。
解决办法: 
1. 替换源代码中web函数为您使用的qt web函数。
2. 直接注销掉web相关代码(qt_360_safe/dialog/market360dialog.h和/qt_360_safe/dialog/market360dialog.cpp中的代码)

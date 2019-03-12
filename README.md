# qt_360_safe
qt高仿360安全卫士

编译时，可能会出现 Project ERROR: Unknown module(s) in QT: webenginewidgets 错误。
解决办法: 
1. 替换相应qt版本中的web功能。
2. 直接注销掉web相关代码(qt_360_safe/dialog/market360dialog.h和/qt_360_safe/dialog/market360dialog.cpp中的代码)

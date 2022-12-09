7寸，bandage-rk3399

2022-12-09，version1.0.2，by dazhi
1.7寸和5寸主要的问题是 设备型号不能区分，串口读设备型号指令0x88，返回值一个是0（5寸），一个是1（7寸）

2.5寸，7寸，new5寸，都是使用跟这个源码更新，需要修改bsp_commm_uart.c
中DEVICE_TYPE(113行)的对应值（0x05：5寸屏；0x04：7寸屏,0x06: new5寸屏）

3.VERSION(bsp_commm_uart.c，114行)，升级版本为2 （2022-12-09）

4.增加调试串口中编译时间的打印信息。

5.修改version.h 中版本号为 1.0.2

6.原5寸屏使用project-5inch中的工程，7寸屏使用project-5inch中的工程，新5寸屏使用project-new5inch中的工程
主要的区别就是bsp_commm_uart.c使用了不同的文件（看app目录中），不用再去修改了。

7.编译输出的文件全部在output 目录中


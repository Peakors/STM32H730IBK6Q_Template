# STM32H730IBK6Q Template

基于反客STM32H730IBK6Q核心板(FK730M1-IBK6Q)的CLion + CMake + OpenOCD的外部Flash下载算法模板

感谢群友子衿、小黑、Status:Headcrabed、111222233333的帮助，站在了巨人的肩膀上完成了该项目模板

文档参考资料：www.armbbs.cn/forum.php?mod=viewthread&tid=116240

注意：
- 使用SPI屏幕需要在CubeMX中启用屏幕对应SPI，该核心板使用SPI5，则需启用SPI5，并在Project Manager中Advanced Settings中SPI5选项的Generate Code一栏中取消勾选，我们不需要lCubeMX帮我们生成SPI初始化代码，在反客驱动中已经初始化SPI。
- <img src="pic/LCD%20Test.jpg" alt="LCD Test" style="zoom: 10%;" />
- 添加printf和scanf重定向到串口1，具体代码参考`retarget.c`和`retarget.h`.
- <img src="pic/UART1%20Retarget.png" alt="UART1 Test" style="zoom: 67%;" />
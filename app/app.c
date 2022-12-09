/*
* Copyright(c)2022, 湖南航天捷诚电子装备有限责任公司
* ALL right reserved
* 文件名称：app.c
* 摘要：创建任务
* 当前版本：1.0.1
* 历史版本：1.0.0
*/
#include "bsp.h"

/*
* 函数介绍：任务创建
* 参数：argument：任务创建输入参数
* 返回值：无
* 备注：无
*/
void AppTask(void *argument)
{
    uint32_t startup_tick;
    uint32_t startup_s = 0;
    // 创建comm任务，用于串口通信
    xTaskCreate(StartCommTask, "comm", 128 * 2, NULL, 2, NULL);
    // 创建debug任务，用于串口调试
    xTaskCreate(StartDebugTask, "debug", 128, NULL, 2, NULL);

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));

        startup_tick = bsp_get_tick();

        if ((startup_tick / 1000) != startup_s)
        {
            startup_s = startup_tick / 1000;
            bsp_led_toggle();  // led灯翻转
        }

    }
}

void start_freertos(void)
{
    // 创建AppTask
    xTaskCreate(AppTask, "app", 128, NULL, 2, NULL);
    // 启动调度器，任务开始执行
    vTaskStartScheduler();

    while (1) ;
}


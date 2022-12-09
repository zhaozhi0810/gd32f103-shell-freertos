/*
* Copyright(c)2022, 湖南航天捷诚电子装备有限责任公司
* ALL right reserved
* 文件名称：main.c
* 摘要：系统初始化
* 当前版本：1.0.1
* 历史版本：1.0.0
*/
#include "bsp.h"


/*
* 函数介绍：初始化滴答定时器
* 参数：无
* 返回值：无
* 备注：FreeRTOS的系统时钟是由滴答定时器提供
*/
static void systick_config(void)
{
    /* setup systick timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / 1000U))
    {
        /* capture error */
        while (1)
        {
        }
    }
    /* configure the systick handler priority */
    NVIC_SetPriority(SysTick_IRQn, 0x00U);
}

void nvic_config(void)
{
    // 配置中断分组
    nvic_priority_group_set(NVIC_PRIGROUP_PRE1_SUB3);
}

int main()
{
    // 外设资源初始化
    bsp_init();
    // 滴答定时器初始化
    systick_config();
    // freertos任务创建
    start_freertos();

    return 1;
}


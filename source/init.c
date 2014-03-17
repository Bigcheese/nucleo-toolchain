typedef void InitFunc();
typedef void VectorFunc();

extern void _estack();
extern char _sidata;
extern char _sdata;
extern char _edata;
extern char _sbss;
extern char _ebss;
extern InitFunc *const __init_array_start __attribute__((weak));
extern InitFunc *const __init_array_end __attribute__((weak));

extern void SystemInit();
extern int main();

static void initArrays() {
  for (InitFunc *const *i = &__init_array_start; i != &__init_array_end; ++i) {
    (*i)();
  }
}

void Reset_Handler() __attribute__((weak));
void Reset_Handler() {
  for (char *from = &_sidata, *to = &_sdata; to < &_edata; ++from, ++to)
    *to = *from;
  for (char *to = &_sbss; to < &_ebss; ++to)
    *to = 0;
  SystemInit();
  initArrays();
  main();
  while (1);
}

// If a handler is not defined, default to infinite loop so it can be debugged.
static void defaultHandler() {
  while (1);
}

void NMI_Handler() __attribute__((weak, alias ("defaultHandler")));
void HardFault_Handler() __attribute__((weak, alias ("defaultHandler")));
void MemManage_Handler() __attribute__((weak, alias ("defaultHandler")));
void BusFault_Handler() __attribute__((weak, alias ("defaultHandler")));
void UsageFault_Handler() __attribute__((weak, alias ("defaultHandler")));
void SVC_Handler() __attribute__((weak, alias ("defaultHandler")));
void DebugMon_Handler() __attribute__((weak, alias ("defaultHandler")));
void PendSV_Handler() __attribute__((weak, alias ("defaultHandler")));
void SysTick_Handler() __attribute__((weak, alias ("defaultHandler")));
void WWDG_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void PVD_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TAMPER_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void RTC_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void FLASH_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void RCC_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI0_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI1_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI2_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI3_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI4_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel1_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel2_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel3_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel4_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel5_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel6_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void DMA1_Channel7_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void ADC1_2_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void USB_HP_CAN1_TX_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void USB_LP_CAN1_RX0_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void CAN1_RX1_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void CAN1_SCE_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI9_5_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM1_BRK_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM1_UP_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM1_TRG_COM_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM1_CC_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM2_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM3_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void TIM4_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void I2C1_EV_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void I2C1_ER_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void I2C2_EV_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void I2C2_ER_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void SPI1_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void SPI2_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void USART1_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void USART2_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void USART3_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void EXTI15_10_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void RTCAlarm_IRQHandler() __attribute__((weak, alias ("defaultHandler")));
void USBWakeUp_IRQHandler() __attribute__((weak, alias ("defaultHandler")));

__attribute__((section(".isr_vector"), used)) VectorFunc *const VectorTable[] = {
    _estack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
    WWDG_IRQHandler,
    PVD_IRQHandler,
    TAMPER_IRQHandler,
    RTC_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_Channel1_IRQHandler,
    DMA1_Channel2_IRQHandler,
    DMA1_Channel3_IRQHandler,
    DMA1_Channel4_IRQHandler,
    DMA1_Channel5_IRQHandler,
    DMA1_Channel6_IRQHandler,
    DMA1_Channel7_IRQHandler,
    ADC1_2_IRQHandler,
    USB_HP_CAN1_TX_IRQHandler,
    USB_LP_CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,
    EXTI9_5_IRQHandler,
    TIM1_BRK_IRQHandler,
    TIM1_UP_IRQHandler,
    TIM1_TRG_COM_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,
    EXTI15_10_IRQHandler,
    RTCAlarm_IRQHandler,
    USBWakeUp_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (VectorFunc *)0xF108F85F, // BootRAM
  };

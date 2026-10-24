#include <stdint.h>
#define RCC_AHB1ENR  (*(volatile uint32_t *)0x40023830U)
#define GPIOC_MODER  (*(volatile uint32_t *)0x40020800U)
#define GPIOC_OTYPER (*(volatile uint32_t *)0x40020804U)
#define GPIOC_PUPDR  (*(volatile uint32_t *)0x4002080CU)
#define GPIOC_ODR    (*(volatile uint32_t *)0x40020814U)
#define LED1_PIN     (1U << 10)
#define LED2_PIN     (1U << 12)
void delay(volatile uint32_t count)
{
    while (count--)
    {
        __asm volatile ("nop");
    }
}

int main(void)
{
    GPIOC_MODER &= ~((3U << 20) | (3U << 24));
    GPIOC_MODER |=  ((1U << 20) | (1U << 24));
    GPIOC_OTYPER &= ~(LED1_PIN | LED2_PIN);
    GPIOC_PUPDR &= ~((3U << 20) | (3U << 24));
    while (1)
    {
        GPIOC_ODR |= LED1_PIN;
        GPIOC_ODR &= ~LED2_PIN;
        delay(1000000U);
        GPIOC_ODR &= ~LED1_PIN;
        GPIOC_ODR |= LED2_PIN;
        delay(1000000U);
    }
}

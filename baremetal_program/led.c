#include <stdint.h>
#define RCC_AHB1ENR  (*(volatile uint32_t *)0x40023830U)
#define GPIOA_MODER  (*(volatile uint32_t *)0x40020000U)
#define GPIOA_BSRR   (*(volatile uint32_t *)0x40020018U)
static void delay(volatile uint32_t count)
{
    while (count > 0U)
    {
        count--;
    }
}
int main(void)
{
    RCC_AHB1ENR |= (1U << 0);
    GPIOA_MODER &= ~(3U << 10);
    GPIOA_MODER |=  (1U << 10);
    while (1)
    {
    	GPIOA_BSRR = (1U << 5);
    	delay(1000000U);
        GPIOA_BSRR = (1U << 21);
        delay(1000000U);
    }
}

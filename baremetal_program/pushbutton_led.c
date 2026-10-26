#include <stdint.h>
#define RCC_AHB1ENR	(*(volatile uint32_t *)0x40023830U)
#define GPIOA_MODER (*(volatile uint32_t *)0x40020000U)
#define GPIOA_ODR   (*(volatile uint32_t *)0x40020014U)
#define GPIOC_MODER (*(volatile uint32_t *)0x40020800U)
#define GPIOC_IDR   (*(volatile uint32_t *)0x40020810U)
int main(void)
{
	RCC_AHB1ENR |= (1U << 0);
    RCC_AHB1ENR |= (1U << 2);
    GPIOA_MODER &= ~(3U << 10);
    GPIOA_MODER |=  (1U << 10);
    GPIOC_MODER &= ~(3U << 26);
    while (1)
    {
        if ((GPIOC_IDR & (1U << 13)) == 0U)
        {
           GPIOA_ODR |= (1U << 5);
        }
        else
        {
            GPIOA_ODR &= ~(1U << 5);
        }
    }
}

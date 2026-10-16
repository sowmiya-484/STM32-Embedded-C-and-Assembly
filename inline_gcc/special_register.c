#include <stdint.h>
int main(void)
{
    uint32_t control_value;
    __asm volatile(
    		"mrs %0,control"
    		:"=r"(control_value)
			 :
			 :
    		);
	/* Loop forever */
	for(;;);
}

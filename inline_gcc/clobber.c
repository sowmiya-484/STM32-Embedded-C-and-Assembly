#include <stdint.h>
int main(void)
{
	int a=10,b=20;
	__asm volatile("cmp %0,%1"
			:
			:"r"(a),"r"(b)
			 :"cc");
	for(;;);
}

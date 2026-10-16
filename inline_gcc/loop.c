#include <stdint.h>
int main(void)
{
	int n=5;
	int sum;
	__asm volatile("mov r0,#0 \n"
			"mov r1,#1 \n"
			"loop:\n"
			"cmp r1,%1 \n"
			"bgt done \n"
			"add r0,r0,r1 \n"
			"add r1,r1,#1 \n"
			"b loop \n"
			"done : \n"
			"mov %0,r0 \n"
			:"=r"(sum)
			 :"r"(n)
			  :"r0" ,"r1", "cc");
    /* Loop forever */
	for(;;);
}

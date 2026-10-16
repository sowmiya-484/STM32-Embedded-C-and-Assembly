#include <stdint.h>
int main(void)
{
	int32_t a=10;
	int32_t b=5;
	int32_t result;
	__asm volatile(
			"cmp %[a],%[b]\n"
			"ite gt \n"
			"movgt %[res],#1\n"
			"movle %[res],#1\n"
			:[res]"=&r"(result)
			 :[a]"r"(a),[b]"r"(b)
			  :"cc");
    /* Loop forever */
	for(;;);
}

#include <stdint.h>
int main(void)
{
    uint32_t source =25;
    uint32_t destination=0;
    __asm volatile ("LDR R0,[%0]\n"
    				"STR R0,[%1]\n"
    				:
    		        :"r"(&source),"r"(&destination)
					:"r0", "memory");
	for(;;);
}

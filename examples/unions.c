
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct some_struct {
	int int_val;
	float float_val;
};

union some_union {
	// union is a collection of variables that use the same memory location
	
	// the values overlap - they occupy the same space in memory
	int int_val;
	float float_val;
};

union x86_register {
	struct {
		uint8_t high;
		uint8_t low;
	} byte[4];			// %ah, %al, %dh, %dl
	uint16_t word[4];	// %ax, %dx, %sp, %si
	uint32_t dword[2];  // %eax, %edx, %esp, %esi
	uint64_t qword;		// %rax, %rdx, %rsp, %rsi
};


int main() {
	
	struct some_struct s;
	union some_union u;

	printf("struct :: int: 0x%p, float: 0x%p\n", &s.int_val, &s.float_val);
	printf("union :: int: 0x%p, float: 0x%p\n", &u.int_val, &u.float_val);

	union x86_register rax;
	rax.qword = 0xDEADBEEFCAFE0000;
	printf("%%rax: %llu, %%eax[h]: %x, %%eax[l]: %x\n",
		rax.qword, rax.dword[0], rax.dword[1]);

    return EXIT_SUCCESS;
}
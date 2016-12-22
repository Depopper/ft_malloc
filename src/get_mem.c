#include "mall.h"

t_mem *get_memory(void)
{
	static t_mem memory;

	return(&memory);
}

void *get_tiny(void)
{
	static void *ptr = NULL;

	if(ptr == NULL)
		ptr = mmap(0, getpagesize(), PROT_READ|PROT_WRITE,
										MAP_PRIVATE|MAP_ANON, -1, 0);
	return(ptr);
}

void *get_small(void)
{
	static void *ptr = NULL;

	if(ptr == NULL)
		ptr = mmap(0, getpagesize() * 2, PROT_READ|PROT_WRITE,
										MAP_PRIVATE|MAP_ANON, -1, 0);
	return(ptr);
}

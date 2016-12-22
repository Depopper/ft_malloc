#include "mall.h"


static void *get_alloc(size_t size)
{
	t_alloc *new;

	printf("%lu\n", getpagesize());
	printf("%lu\n", sizeof(t_alloc));
	printf("%lu\n", sizeof(t_zone));


	return(NULL);
}


static void mem_init(void)
{
	t_mem *memory;

	memory = get_memory();
	memory->tiny = get_tiny();
	memory->small = get_small();
	tiny_init(memory->tiny);
	small_init(memory->small);
}

void *ft_malloc(size_t size)
{
	static bool init = false;
	void *ptr;

	if (!init)
		mem_init();
	ptr = get_alloc(size);
	printf("Sa marche ou pas:%d\n", ((t_zone *)get_tiny())->nb_alloc);
	return(ptr);
}

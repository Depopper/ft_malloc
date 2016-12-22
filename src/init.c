#include "mall.h"

void tiny_init(void *ptr)
{
	t_zone *tiny;

	tiny = ptr;
	tiny->size = getpagesize() - sizeof(t_zone);
	tiny->size_left = tiny->size;
	tiny->nb_alloc = 0;
	tiny->first = ptr + sizeof(t_zone);
	tiny->next = NULL;
}

void small_init(void *ptr)
{
	t_zone *small;

	small = ptr;
	small->size = (getpagesize() * 2) - sizeof(t_zone);
	small->size_left = small->size;
	small->nb_alloc = 0;
	small->first = ptr + sizeof(t_zone);
	small->next = NULL;
}

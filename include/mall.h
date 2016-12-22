#ifndef MALL_H
# define MALL_H

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>


typedef enum e_bool bool;
enum e_bool
{
	false,
	true,
};

typedef struct s_alloc t_alloc;
struct s_alloc
{
	int 	size;
	bool 	free;
	t_alloc *next;
};

typedef struct s_zone t_zone;
struct s_zone
{
	int size;
	int size_left;
	int nb_alloc;
	t_alloc *first;
	t_zone *next;
};

typedef struct s_mem t_mem;
struct s_mem
{
	void *tiny;
	void *small;
};


void	*ft_malloc(size_t size);

t_mem	*get_memory(void);
void	*get_small(void);
void	*get_tiny(void);

void	tiny_init(void *ptr);
void	small_init(void *ptr);

#endif

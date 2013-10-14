/*
Coursera HW/SW Interface
Lab 4 - Mystery Caches

Mystery Cache Geometries (for you to keep notes):
mystery0:
    block size =
    cache size =
    associativity =
mystery1:
    block size =
    cache size =
    associativity =
mystery2:
    block size =
    cache size =
    associativity =
mystery3:
    block size =
    cache size =
    associativity =
*/

#include <stdlib.h>
#include <stdio.h>

#include "mystery-cache.h"

/*
 * NOTE: When using access_cache() you do not need to provide a "real"
 * memory addresses. You can use any convenient integer value as a
 * memory address, you should not be able to cause a segmentation
 * fault by providing a memory address out of your programs address
 * space as the argument to access_cache.
 */

/*
   Returns the size (in B) of each block in the cache.
*/
int get_block_size(void) {
  /* YOUR CODE GOES HERE */
  flush_cache();
  int size = 1;
  long long int addr = 1<<10;
  access_cache(addr);
  while(1)
  {
   	addr ++;
	if (access_cache(addr) == FALSE)
		return size;
	size++;
	
	
  }



  return -1;
}

/*
   Returns the size (in B) of the cache.
*/
int get_cache_size(int size) {
  /* YOUR CODE GOES HERE */
  long long int addr = 1 << 10;
  int hypo = size;
  int i = 0;
  //printf("dasdas");
  while (1)
  {
	flush_cache();
	i = 0;
	//printf("ASSA");
	while (i < hypo / size)
	{
		access_cache(addr + i * size);
		//printf("%d\n",i);
		i ++;
	}
  	if (access_cache(hypo + addr) == FALSE && access_cache(addr) == FALSE)
		return hypo;
	hypo <<= 1;
	//printf("%d\n",hypo);
  }
	



  return -1;
}

/*
   Returns the associativity of the cache.
*/
int get_cache_assoc(int size) {
  /* YOUR CODE GOES HERE */
  
  return get_cache_size(size)/size;
}

//// DO NOT CHANGE ANYTHING BELOW THIS POINT
int main(void) {
  int size;
  int assoc;
  int block_size;

  /* The cache needs to be initialized, but the parameters will be
     ignored by the mystery caches, as they are hard coded.  You can
     test your geometry paramter discovery routines by calling
     cache_init() w/ your own size and block size values. */
  cache_init(0,0);

  block_size=get_block_size();
  //printf("%d\n",block_size);
  size=get_cache_size(block_size);
  assoc=get_cache_assoc(size);

  printf("Cache block size: %d bytes\n", block_size);
  printf("Cache size: %d bytes\n", size);
  printf("Cache associativity: %d\n", assoc);

  return EXIT_SUCCESS;
}

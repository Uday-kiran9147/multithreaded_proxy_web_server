// Lib imports
#include <stdio.h>
#include<stdio.h>
#include<time.h>

// Local imports
#include "proxy_parse.h"

typedef struct cache_element cache_element;

struct cache_element {
    char* data;
    int len;
    time_t lru_time;
    struct cache_element* next;
};


cache_element* find(char* url);

int add_cache_element(char* data, int size, char* url);

void remove_cache_element();

int PORT = 8080;

#include<stdio.h>

int main()
{

return 0;
}

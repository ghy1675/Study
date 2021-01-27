#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define max(a,b) a<b?b:a
#define min(a,b) a<b?a:b

int compare(const void* a, const void* b)
{
    return (strcmp(*(char**)a, *(char**)b));
}
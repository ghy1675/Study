#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h> 

#define MEM_BANK1 0x400000000
#define MEM_BANK2 0x400008000
#define MEM_BANK3 0x400010000 // Input

#define MEM_BANK4 0x400018000
#define MEM_BANK5 0x400020000
#define MEM_BANK6 0x400028000 // Filter

#define MEM_BANK7 0x400030000
#define MEM_BANK8 0x400038000 // PSum

//0x400040008 lsb = 1 = done BANK 7,8 Read
#define lsb_read  0x400040008

//
// Length To Compare With CPU Calc
#define add_dst_A   0x400040100
//#define add_dst_B   0x400040200
//#define add_dst_C   0x400040300 


#define Gemm_En 1 // address
#define MEM_RST 1 // address
#define MEM_RD 1  // address

#define ENABLE 1
#define DISABLE 0

// Memory R/W
#define MAP_SIZE 4096UL 			// Memory Paging Size 4KB
#define MAP_MASK (MAP_SIZE - 1) 	// Memory Address Mask
#define MAXLINE 511 				// buf max
#define COMMAND_ERROR "Unknown command!!"

uint8_t read_SFR(int fd, off_t target);
void write_SFR(int fd, off_t target, unsigned long value);

uint8_t read_SFR(int fd, off_t target)
{
    void* map_base;
    void* virt_addr;
    uint8_t output;
    map_base = mmap(0, MAP_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, target & ~MAP_MASK);
    virt_addr = map_base + (target & MAP_MASK);
    output = *((uint8_t*)virt_addr);
    munmap(map_base, MAP_SIZE);
    return output;
}

void write_SFR(int fd, off_t target, unsigned long value)
{
    void* map_base;
    void* virt_addr;
    map_base = mmap(0, MAP_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, target & ~MAP_MASK);
    virt_addr = map_base + (target & MAP_MASK);
    *(volatile unsigned long*)virt_addr = value;
    munmap(map_base, MAP_SIZE);
}
/*
void write_SFR(int fd, off_t target, unsigned long value)
{
    void* map_base;
    void* virt_addr;
    map_base = mmap(0, MAP_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, fd, target & ~MAP_MASK);
    virt_addr = map_base + (target & MAP_MASK);
    *(volatile unsigned long*)virt_addr = value;
    munmap(map_base, MAP_SIZE);
}
*/

/*
float* deQuantize_8bits(uint8_t x[], uint8_t min, uint8_t max, int len, float scale_factor, uint8_t zero_point) 
{
    int i;
    float temp[len];
    for(i=0;i<len;i++)
    {
        temp[i] = (x[i] - zero_point) * scale_factor;
    }
    return &temp;
}
*/
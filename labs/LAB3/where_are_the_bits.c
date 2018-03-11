// where_are_the_bits.c ... determine bit-field order
// COMP1521 Lab 03 Exercise
// Written by ...

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct _bit_fields {
   unsigned int a : 4,
                b : 8,
                c : 20;
};

int main(void)
{
    struct _bit_fields x;

    x.a = 0x4;  
    x.b = 0xb2; 
    //a: 0100 
    //b:  1101 0010 
    x.c = 0xa532d; 
    //c: 10100101001100101101   
    
    unsigned char * p = (unsigned char *)&x;
    printf("The size of the Variable: %li Bytes and 32 bits\n",sizeof(x));
    printf("\n");  
    printf(
        "Variable set to be :\n "
        "a = 0x4 | b = 0xb2 | c = 0xa532d \n\n"
        "Sequencial Memory mapping for given struct\n"); 

    for(int i = 0;i < 4; i++){
        for(int j =0;j < 7;j++){
            if(*(p + i) & (1 << j)) printf("1"); 
            else printf("0");
        }
        printf(" ");
    }
    printf("\n\n");
    printf(
        "From Memory mapping,the bit-field layout is\n"
        "[aaaa] | [bbbbbbbb] | [cccccccccccccccccccc] \n"
        ); 
    
    
    return 0;
}

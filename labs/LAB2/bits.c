// COMP1521 18s1 Week 02 Lab (warm-up)

#include <stdio.h>

int main()
{
	// Code to generate and display the largest "int" value
    
    //variables 
	int x = 0x00000001;
    int i;

    for(i = 30;i > 0;i--){
        x = x | (0x00000001 << i);
    }

    printf("int %x, %d\n", x, x);
    
	// Code to generate and display the largest "unsigned int" value

	unsigned int y = 0x00000001;

    for(i = 31;i > 0;i--){
        y = y | (0x00000001 << i);
        //printf("%x \n", y);
    }

	printf("unsigned int %x, %u\n", y, y);
    
	// Code to generate and display the largest "long int" value

	long int xx = x;
	printf("long int %lx, %li\n", xx, xx);

	// Code to generate and display the largest "unsigned long int" value
    //
	unsigned long int xy = y;
	printf("unsigned long int %lx, %lu\n", xy, xy);

	// Code to generate and display the largest "long long int" value
    
	long long int xxx = 0x1; 
    //what the f....
    for(i = 62;i > 0;i--){
        //printf("%d\n",i);
        if(i > 30){
            long long int k = 0x1 << 30; 
            k = k << (i - 30);
            //printf("%llx\n", k); 
            xxx = xxx | k;
            
        }else{
            xxx = xxx | (0x1 << i);
        }
    }
    printf("long long int %llx, %lli\n", xxx, xxx);

	// Code to generate and display the largest "unsigned long long int" value

	unsigned long long int xxy = 0x1;

    //what the f....
    for(i = 63;i > 0;i--){
        //printf("%d\n",i);
        if(i > 30){
            long long int k = 0x1 << 30; 
            k = k << (i - 30);
            //printf("%llx\n", k); 
            xxy = xxy | k;
            
        }else{
            xxy = xxy | (0x1 << i);
        }
    }

	printf("unsigned long long int %llx, %llu\n", xxy, xxy);
	return 0;
}


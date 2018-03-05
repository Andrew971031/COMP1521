// BigNum.h ... LARGE positive integer values

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "BigNum.h"

//can be a macro but cannot be bothered right now
int is_digit(char); 
//optimize result...not rlly needed :/ 
void optimize(BigNum *n); 

// Initialise a BigNum to N bytes, all zero
void initBigNum(BigNum *n, int Nbytes)
{
    //init
    assert(Nbytes != 0);
    //find space in heap
    n = (BigNum *)malloc(sizeof(BigNum)); 
    //heap has space
    assert(n != NULL); 
    //set 
    n->nbytes = Nbytes;
    //set space for main array
    n->bytes = (Byte *)malloc(Nbytes*sizeof(Byte));
    //set zero
    memset(n->bytes,0,Nbytes);
    return;
}

// Add two BigNums and store result in a third BigNum
void addBigNums(BigNum n, BigNum m, BigNum *res)
{
    //current checking value 
    int current = 0; 
    //new size 
    int size  = ((n.nbytes - m.nbytes) >= 0) ? n.nbytes : m.nbytes;
    
    if(res->nbytes < size + 1){
        res->nbytes = size + 1;
        //free(res->bytes);
        res->bytes = calloc(size + 1,sizeof(Byte)); 
    }

    //if more than 10 
    int up_val = 0;

    //check until maximum + 1, probs wont reach there 
    while(current <= size){
        
        //case of which one more is needed and has reached the end 
        if(current == size && up_val != 0){
            //one more size
            res->bytes[size] = 1;
            break; 
        //case of no need
        }else if(current == size && up_val == 0){
            //if not then exit
            break;
        //case of which 
        }else{
            //check buffer
            int buffer = n.bytes[current] + m.bytes[current] + up_val;
            //more than 10 then up one
            if(buffer >= 10){
                res->bytes[current] = buffer - 10; 
                up_val = 1;
            }else{
                res->bytes[current] = buffer; 
                up_val = 0;
            }
        }
        current++;
    }
    //reduce and optimize
    optimize(res);
    return;
}

// Set the value of a BigNum from a string of digits
// Returns 1 if it *was* a string of digits, 0 otherwise
int scanBigNum(char *s, BigNum *n)
{
    //just checking.... u know.. .
    assert(n != NULL); 
    assert(s != NULL);
    
    //keep track of variables
    int start = 0; 
    int finish = 0; 

    //start from start of string 
    int counter = 0; 
    char buffer = s[counter];
    int flag = 0;

    //main loop (loop through all chars) 
    //(NOPEEEEEEEE)assuming that the chars are NULL terminated
    while(buffer != '\0'){
        //has seen a digit
        if(flag){
            //continue as a digit
            if(!is_digit(buffer)){
                finish = counter - 1;
                break;
            }     
        }else{
            //is a digit?
            if(is_digit(buffer)){
                //record where it starts  
                start = counter;
                //update flag 
                flag = 1;
            }
        }
        printf("0");
        //update next char
        counter++; 
        buffer = s[counter]; 
    }  

    //return straight away if not any digits
    if(flag == 0) return 0; 
    //set all digits
    counter = 0; 
    for(int i = finish;i > start; i--){
        n->bytes[counter] = s[i];  
        counter++; 
    }
    return 1;
}

// Display a BigNum in decimal format
void showBigNum(BigNum n)
{
    assert(n.nbytes > 0);

    //simple flag 
    int flag = 0;
    //main loop for each char 
    int counter = n.nbytes - 1;
    while (counter >= 0){
        //basic flag checking
        if(flag){
            printf("%c",n.bytes[counter]);
            counter--;
        }else{
            if(n.bytes[counter] != '0') flag = 1;
        } 
    }
    return;
}
//is this char digit? 
int is_digit(char b){
    if(b >= '0' && b <= '9') return 1; 
    return 0; 
}
//optimize the digit 
void optimize(BigNum *n){
    //current set 
    int current = n->nbytes - 1;
    //checking.. but will not reach the end
    while(current >= 0){
        if(is_digit(n->bytes[current])) break;
        current--; 
    }
    
    //new pointer
    BigNum * r = NULL; 
    initBigNum(r,current + 1); 
    //make new value
    for(int i = 0;i <= current; i++){
        r->bytes[current] = n->bytes[current]; 
    }

    //free old
    free(n->bytes); 
    free(n);
    //reset n 
    n = r; 
}



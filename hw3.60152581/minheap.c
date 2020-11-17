#include <stdio.h>

#define MAX_HEAP_SIZE 10

typedef char Element;
Element heap[MAX_HEAP_SIZE];
int heap_size;

// 구현하여야 할 함수
void init(){}
void insert(Element key) {} 
Element delete() {} // 가장 작은 값을 가지고 있는 Element 삭제(Root)
int is_empty() {} // empty면 1 아니면 0을 return
int is_full() {} // full이면 1 아니면 0을 return

// 구현하여야 할 함수 2
void print_pre_order() {}  // 출력 예 =>  PRE : A B C D E F G H I J
void print_in_order() {}   // 출력 예 =>  IN : A B C D E F G H I J
void print_post_order() {} // 출력 예 =>  POST : A B C D E F G H I J

// 구현된 함수 
void print_check_minheap(){
    for(int i = 1; i <= heap_size; ++i){
       printf(" %c ", heap[i]);
    }
    printf("\n");
}

void print_all(){
    print_check_minheap();
    print_pre_order(); 
    print_in_order();
    print_post_order();
}

int main(){
    char inputs1[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char inputs2[10] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q'};
    int i;

    init();
    for(i = 0; i < 10; ++i){
         insert(inputs1[i]); 
    }
    print_all(); 

    for(i = 0; i < 10; ++i){
         delete(); 
         print_all();
    }

    init();
    for(i = 0; i < 10; ++i){
         insert(inputs2[i]);
    }
    print_all(); 

    for(i = 0; i < 10; ++i){
         delete(); 
         print_all();
    }

    return 0; 
}

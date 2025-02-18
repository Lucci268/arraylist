#include <stdio.h>
#include <stdlib.h>

int* Array_Create (int capacity);
void Array_Destroy (int* values);
void Array_Insert (int* values, int newValues);
int Array_Get (int* values, int index);
void Array_Print (int* values);

int capacity;
int* values;
int size;
int factor;

int main(){
    capacity = 2;
    size = 0;
    factor = 2;
    values = Array_Create(capacity);
    Array_Print(values);
    for (int i = 0; i < 2;i++){
        Array_Insert(values, i * 10);
        Array_Print(values);

    }
    Array_Destroy(values);


    return 0;
}

int* Array_Create (int capacity){
    int* values = (int*) malloc(sizeof(int) * capacity);
    return values;
}

void Array_Destroy (int* values){
    free(values);
}

void Array_Insert (int* values, int newValues){
    *(values + size) = newValues;
    size++;
}

int Array_Get (int* values, int index){
    int value = *(values + index);
    return value;
}

void Array_Print (int* values){
    for(int i = 0; i < capacity; i++){
        if (i < size){
            printf("%d",*(values + i));
        } 
        else{
            printf("x");
        }
        if ( i < capacity - 1){
            printf(" ");
        }
    }
    printf("\n");
}
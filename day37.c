#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if(size == MAX){
        return;
    }

    pq[size++] = x;
}

int findMinIndex(){
    if(size == 0) return -1;

    int min = 0;

    for(int i = 1; i < size; i++){
        if(pq[i] < pq[min])
            min = i;
    }

    return min;
}

void deletePQ(){
    int idx = findMinIndex();

    if(idx == -1){
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[idx]);

    for(int i = idx; i < size - 1; i++){
        pq[i] = pq[i+1];
    }

    size--;
}

void peek(){
    int idx = findMinIndex();

    if(idx == -1){
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[idx]);
}

int main(){

    int N, x;
    char op[10];

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%s",op);

        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0){
            deletePQ();
        }
        else if(strcmp(op,"peek")==0){
            peek();
        }
    }
}
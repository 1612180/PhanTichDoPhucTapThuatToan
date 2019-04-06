#include <stdio.h>

int SomeSum(int n, int &count_assign, int &count_compare){
    // Phan 1
    count_assign += 2;
    int sum = 0, i = 1;
    
    // Phan 2
    int j;
    while(++count_compare && i <= n){
        count_assign += 1;
        j = n - i;

        while(++count_compare && j <= i * i){
            count_assign += 2;
            sum = sum + i * j;
            j = j + 1;
        }
        
        count_assign += 1;
        i = i + 1;
    }

    // Phan 3
    count_assign += 1;
    return sum;
}

int main(){
    FILE *f = fopen("result.csv",  "w");
    fprintf(f, "N,Số phép gán,Số phép so sánh\n");
    for(int i = 1; i <= 500; ++i){
        int count_assign = 0, count_compare = 0;
        SomeSum(i, count_assign, count_compare);
        fprintf(f, "%d,%d,%d\n", i, count_assign, count_compare);
    }

    fclose(f);
    return 0;
}
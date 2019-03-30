#include <stdio.h>

// n >= 2
// f_sosanh(n) = 1 + f_sosanh(n - 1) + f_sosanh(n - 2)
// f_sosanh(0) = 1
// f_sosanh(1) = 1
// 2 -> 3, 3 -> 5, 4 -> 9, 5 ->  15, 6 -> 25
// f_gan(n) = 1 + f_gan(n - 1) + f_gan(n - 2)
// f_gan(0) = 1
// f_gan(1) = 1
// f_gan(n) = f_sosanh(n)
int fibonaci_dquy(int n, int &count_assign, int &count_compare){
     // 1 lần so sánh
     if(++count_compare && n <= 1){
          // 1 phép gán
          ++count_assign;
          return 1;
     }

     // 1 lần gán
     ++count_assign;
     return fibonaci_dquy(n - 1, count_assign, count_compare) + 
          fibonaci_dquy(n - 2, count_assign, count_compare);
}    


// n >= 2
// f_gan(n) = 3 + n + 3(n - 1) + 1 = 4n + 1
// f_gan(1) = 2
// f_sosanh(n) = 1 + n
// f_sosanh(1) = 1 
int fibonaci_kdquy(int n, int &count_assign, int &count_compare){
     if (++count_compare && n <= 1){
          ++count_assign;
          return 1;
     }

     // 3 lần gán
     count_assign += 3;
     int last = 1;
     int nextToLast = 1;
     int answer = 1;


     // i gán từ 2 đến n + 1 -> n lần
     // trong vòng lặp có 3 lần gán, mà vòng lặp chạy với i từ 2 đến n -> 3(n - 1) lần
     // i so sánh từ 2 đến n + 1 -> n lần
     ++count_assign;
     for(int i = 2; ++count_compare && i <= n; ++count_assign && ++i){
          count_assign += 3;
          answer = last + nextToLast;
          nextToLast = last;
          last = answer;
     }

     // 1 lần gán
     ++count_assign;
     return answer;
}

int main(){
     int n;
     scanf("%d", &n);
     
     int a = 0, b = 0;
     int result = fibonaci_dquy(n, a, b);
     printf("%d %d %d\n", result, a, b);
     
     a = 0, b = 0;
     result = fibonaci_kdquy(n, a, b);
     printf("%d %d %d\n", result, a, b);
     
     return 0;
}
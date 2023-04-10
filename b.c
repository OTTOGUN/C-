#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 10

typedef int Status;


//反转字符串
Status reverse(char* S,int length){
    int left = 0;
    int right = length - 1;

    while(left < right){
        char temp = S[right];
        S[right] = S[left];
        S[left] = temp;
        left++;
        right--;
    }
}

//求100以内的素数
Status Prime_Number(int Number){
    int i = 0;
    if(Number == 1){
        printf("素数必须是大于1的\n");
        return ERROR;
    }
    if(Number >= 2){
        for(i = 2;i <= sqrt(Number);i++){
            if(Number % i == 0){
                printf("%d不是素数\n",Number);
                break;
            }
        }
        if(i > sqrt(Number)){
                printf("%d是素数\n",Number);
        }
    }
    return 0;
}

//对10个数字排序      注：》》》》》》》》》》》》》出了限定范围就会被销毁(局部变量)
Status Bubble_Sort(int* Array,int length){
    for(int i = length - 1;i > 0;i--){
        for(int j = 0;j < i;j++){
            if(Array[j] < Array[j + 1]){
                int temp = Array[j + 1];
                Array[j + 1] = Array[j];
                Array[j] = temp;
            }
        }
    }
    return OK;
}

//遍历数组
Status Traverse_Array(int* a,int length){
    for(int i = 0;i < length;i++){
        printf("%d\n",a[i]);
    }
    return OK;
}

//创建数组
int* CreateArray(void){
    int Number[3];
    for(int i = 0;i < 3;i++) {
        int temp;
        printf("请输入第%d个数据:\n", i + 1);
        scanf("%d", &temp);
        Number[i] = temp;
    }
    int* a = Number;
    return a;
}

//对角线之和
Status Sum_Array(int a[3][3]){
    int sum = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            if(j == i) {
                sum += a[i][i];
            }
        }
    }
    return sum;
}

//二分法
Status Binary_Analysis(int* a,int length,int b){
    if(b > a[length - 1]){
        a[length] = b;
    }
    int left = 0;
    int right = length - 2;
    int middle = (left + right) / 2;

    while(left <= right){
        middle = (left + right) / 2;
        if(a[middle] < b){
            left = middle + 1;
        }else if(a[middle] > b){
            right = middle - 1;
        }
    }

    for(int j = length - 2;j >= left;j--){
        a[j + 1] = a[j];
    }
    a[left] = b;
    return OK;
}

Status reverse1(int* a,int length){
    int left = 0;
    int right = length - 1;
    while(left < right){
        int temp = a[right];
        a[right] = a[left];
        a[left] = temp;
        left++;
        right--;
    }
    return 0;
}

//static的作用
void fool(){
    static int x = 0;
    x++;
    printf("%d\n",x);
}

//宏的另一种使用方式
#define SQ(x) (x)*(x)

//同样是宏的另一种使用方式
#define exchange(a,b) {int t;t = a;a = b;b = t;}

//还是宏的使用方式
#define LAG >
#define SMA <
#define EQ ==



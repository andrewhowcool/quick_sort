//
//  main.c
//  quick sort
//
//  Created by 楊博名 on 2016/12/27.
//  Copyright © 2016年 楊博名. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void quicksort(int *data, int left, int right);
void swap(int *a, int *b);
int n=0; //資料筆數

int main(void)
{
    int i, data[10];
    
    printf("請輸入資料筆數 n(<= 10): ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        printf("請輸入第 %d 筆資料: ", i + 1);
        scanf("%d", &data[i]);
    }
    
    // 執行快速排序法
    quicksort(data, 0, n - 1);
    
    printf("\n排序後的結果: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    
    printf("\n");

}

void quicksort(int *data, int left, int right)
{
    int pivot, i, j;
    
    if (left >= right){//全部找完時則停止
        return;
    }
    
    pivot = data[left];//支點設為最左邊的數字
    
    i = left + 1;
    j = right;
    
    while (1)
    {
        while (i <= right)//到最右邊以前執行while
        {
            if (data[i] > pivot)//檢測數字是否大於支點
            {
                break;//找到後停止尋找
            }
            
            i = i + 1;
        }
        
        while (j > left)//到最左邊以前執行while
        {
            if (data[j] < pivot)//檢測數字是否小於支點
            {
                break;//找到後停止尋找
            }
            
            j = j - 1;
        }
        
        
        printf("j:%d, left:%d\n",j,left);
        //印出交換的結果
        for (int count = 0; count < n; count++)
        {
            printf("%d ", data[count]);
        }
        printf("\n");
        
        
        
        if (i > j){//全部找完時則停止（此時j<i!!!!）
            break;
        }
        
        
        swap(&data[i], &data[j]);//將大於和小於支點的交換
        
    }
    
    swap(&data[left], &data[j]);//將left放到最後交換的位置（亦即最後才交換的j）  left,x,x,x,j, i,z,z,z
    //此時left的位置不變，但“值”已經與j的“值”交換
    quicksort(data, left, j - 1);//排序左邊
    quicksort(data, j + 1, right);//排序右邊
}

void swap(int *a, int *b)//交換
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

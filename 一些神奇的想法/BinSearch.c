/*------------------------------------------------
    注意：部分源程序给出如下，请勿改动主方法main和其它
    方法中的任何内容，仅在 Begin-End 区间补充代码。
---------------------------------------------------*/
#include <stdio.h>
int f[10000];

int search(int n,int* nums, int T){
    /********* Begin *********/
    int left = 0, right = n, mid;
    while(right >= left){
        mid = (right + left) / 2;
        if(nums[mid] < T)
            left = mid + 1;
        else if(nums[mid] > T)
            right = mid - 1;
        else if(nums[mid] == T)
            return mid;
    }
    return -1;
    /********* End *********/
}


int main(){
    int n,T;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&f[i]);
    scanf("%d",&T);
    int result=search(n,f, T);
    printf("%d",result);
    return 0;
}
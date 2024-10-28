#include <stdio.h>

int partition(int nums[], int check[], int start, int k, int targetSum, int nowSum, int length){
    if(k == 0)
        return 1;
    if(nowSum == targetSum)
        return partition(nums, check, 0, k - 1, targetSum, 0, length);
    for(int x = 0; x < length; x++){
        if(check[x])
            continue;
        check[x] = 1;
        if(partition(nums, check, x + 1, k, targetSum, nowSum + nums[x], length))
            return 1;
        check[x] = 0;
    }
    return 0;
}

int canPartition(int array[], int k, int length){
    int sum = 0;
    for(int n = 0; n < length; n++)
        sum += array[n];
    if(sum % k != 0)
        return 0;
    int target = sum / k, check[length];
    for(int j = 0; j < length; j++)
        check[j] = 0;
    if(partition(array, check, 0, k, target, 0, length))
        return 1;
    else
        return 0;
}

int main(){
    int length;
    scanf("%d", &length);
    int array[length];
    for(int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    if(canPartition(array, 4, length))
        printf("true");
    else
        printf("false");
    return 0;
}
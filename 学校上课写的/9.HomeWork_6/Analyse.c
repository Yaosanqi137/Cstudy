// 分析输出
// 输出了一个楼梯状的杨辉三角形
// 首先程序先定死第一项和最后一项为1
// 然后上一层的最后一项就是下一层的倒数第二项，这时候只需要让他自己加自己和上一层的自己这项的上一项就可以了
// 接着继续故技重施，直到加到上一层的第二项为止，此时下一层也就铺好了
// e.g.
// a[n - 1] a[n]
// a[n - 1] a[n] a[n + 1]
// 下一层的 a[n + 1] = 1，新的a[n] = 旧的a[n] + 旧的a[n - 1]，以此类推
#include <stdio.h>
#define LASTROW 9

int main(){
    int row, col, a[LASTROW];
    a[0] = 1;
    printf("%5d\n", a[0]); // 首先输出 1
    for(row = 1;row < LASTROW;row++){
        a[0] = a[row] = 1;
        for(col = row - 1;col >= 1;col--)
            a[col] = a[col - 1] + a[col];
        for(col = 0;col <= row;col++)
            printf("%5d", a[col]);
        printf("\n");
    }
    return 0;
}

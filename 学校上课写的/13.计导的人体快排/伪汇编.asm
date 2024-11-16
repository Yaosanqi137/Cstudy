# end (或语句关键字): 结束结构体
# save a, b: 保存内存位置a的数据或a的指针到内存位置b
# mov a, b: 将内存位置b的数据拷贝到a位置
# add a, b:将值b或内存位置b的数据与内存a位置的数据相加或内存位置的16进制加法
# swp a, b:将内存位置a和b的值互换或指针互换位置
# loop 循环，若上一步为cmp，则每次结束后再次执行cmp语句
# data a, b: x1,x2,x3... : 分配内存a一直到内存b的空间，然后将数据传入
# code: 程序开始
# cmp a, b JE, JNE, JL JNA: 比较大小，若真则跳转到内部语句中(即:里面)(JE表示等于，JNE表示不等于，JL表示小于, JNA表示不大于)
# call <name>: 调用函数
# func <name>:定义函数
code:
    data 0x00, 0x13: # 按顺序写入同学的学号;
    free 0x00, 0x13;
    data 0x00, 0x13: # 按刚刚对应的同学，这次写入他们对应的身高，此时没有顺序;
    data 0x19, 0;
    pnt p1, 0x00;
    pnt p2, 0x13;
    call quickSort;
    free p1;
    free p2;
end code;
func quickSort:
    save *p1 0x14;
    save p1, 0x15;
    pnt p3, 0x15;
    save p2, 0x16;
    pnt p4, px16;

    cmp p1, p2 JL:
    loop:
        cmp p1, p2 JNE:
        cmp 0x14, *p2 JNA:
        INC 0x15;
        loop:
            DEC p2;
        end loop, cmp, cmp;
        mov *p1, *p2;
        cmp p1, p2 JNE:
        cmp *p1, 0x14 JNA:
        INC 0x15;
        loop:
            INC p1;
        end loop, cmp, cmp;
        mov *p2, *p1;
    end loop, cmp;
    mov *p1, 0x14;

    cmp p3, p1 JL:
    DEC p1;
    save p2, 0x17;
    swp p1, p2;
    pnt p1, p3;
    call quickSort;
    pnt p2, 0x17;
    end cmp;
    cmp p2, p4 JL:
    INC p2;
    save p1, px18;
    swp p1, p2;
    pnt p2, p4;
    call quickSort;
    pnt p1, 0x18;
    end cmp;
end func;


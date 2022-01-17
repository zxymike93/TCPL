# 结构

## 基本

声明
```c
        struct point {
                int x;
                int y;
        };
```

定义
```c
        struct point pt;
        struct point maxpt = {320, 200};
```

引用成员
```c
        pt.x
        pt.y
        // or
        pt->x
        pt->y
```

## 类型定义

简单的两个例子

```c
        typedef int Length;
        typedef char* String;
```

这样，我们定义的类型就能充当 int char* 来使用了。
另一个典型的例子

```c
        // 指向 tnode 的指针
        typedef struct tnode *Treeptr;
        // 内容为 text 的树结构体
        typedef struct tnode {
                char *word;
                int count;
                struct tnode *left;
                struct tnode *right;
        } Treenode;
```
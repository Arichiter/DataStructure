# 8.09
> 内容：
>
> - [x] 顺序栈的定义与基本操作实现
> - [x] 链栈的定于与基本操作实现
>
> 对顺序栈做了一些测试

---

# 8.12
> 问题3：
> 判断入栈、出栈序列是否合理

**基本设计思想：**

​		

```c
bool Is_ERROR_Seqence(char *c)
{
    int i = 0, j = 0;
    while (c[i] != '\0')
    {
        if (c[i] == 'I') j++;
        else j--;

        if (j < 0) return false;

        i++;
    }
    return true;
}
```


# 8.14
- 实现了队列的定义与基本操作

# 8.19
- 循环队列的入队，出队处理算法

# 8.20
- 队列习题1-2
> 问题1：\
> 带有tag的循环队列的入队出队算法

**基本设计思想：**
<p>
    
</p>

```c
bool EnQueue(CQueue *Q, ElemType x)
{
    if (Q->front == Q->rear && Q->tag == 1) // Queue full!
        return false;
    
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MaxSize;
    Q->tag = 1;
    return true;
}

bool DeQueue(CQueue *Q, ElemType *x)
{
    if (Q->front == Q->rear && Q->tag == 0) // Queue empty!
        return false;

    (*x) = Q->data[Q->front];
    Q->front = (Q->front + 1) % MaxSize;
    Q->tag = 0;
}
```

> 问题2：\
> 使用栈将队列内容的元素倒置

```c
void Q2Test()
{
    printf("\n************Q2************\n");
    CQueue Q;
    InitQueue(&Q);

    SqStack S;
    InitStack(&S);

    for (int i = 0; i < 5; i++)
        EnQueue(&Q, rand() % 20 + 1);
    PrintQueue(Q);

    ElemType x;
    while (DeQueue(&Q, &x))
        Push(&S, x);
    PrintSqStack(S);

    while (Pop(&S, &x))
        EnQueue(&Q, x);

    PrintQueue(Q);
}
```
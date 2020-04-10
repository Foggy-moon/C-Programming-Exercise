#include <stdio.h>
#include <malloc.h>

#define DataType int
#define MAXSIZE 1024

typedef struct {
    DataType data[MAXSIZE];
    int top;
}SeqStack;

SeqStack* Init_SeqStack() {  //ջ��ʼ��
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    if (!s) {
        printf("�ռ䲻��\n");
        return NULL;
    }
    else {
        s->top = -1;
        return s;
    }
}

int Empty_SeqStack(SeqStack* s) {  //��ջ��
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int Push_SeqStack(SeqStack* s, DataType x) {  //��ջ
    if (s->top == MAXSIZE - 1)
        return 0;//ջ��������ջ
    else {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int Pop_SeqStack(SeqStack* s, DataType* x) {  //��ջ
    if (Empty_SeqStack(s))
        return 0;//ջ�ղ��ܳ�ջ
    else {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }//ջ��Ԫ�ش���*x������
}

DataType Top_SeqStack(SeqStack* s) {  //ȡջ��Ԫ��
    if (Empty_SeqStack(s))
        return 0;//ջ��
    else
        return s->data[s->top];
}

int Print_SeqStack(SeqStack* s) {
    int i;
    printf("��ǰջ�е�Ԫ��:\n");
    for (i = s->top; i >= 0; i--)
        printf("%3d", s->data[i]);
    printf("\n");
    return 0;
}

int main() {
    SeqStack* L;
    int n, num, m;
    int i;

    L = Init_SeqStack();

    printf("��ʼ�����\n");
    printf("ջ�գ�%d\n", Empty_SeqStack(L));
    printf("��������ջԪ�ظ�����\n");
    scanf_s("%d", &n);
    printf("������Ҫ��ջ��%d��Ԫ�أ�\n", n);

    for (i = 0; i < n; i++) {
        scanf_s("%d", &num);
        Push_SeqStack(L, num);
    }

    Print_SeqStack(L);

    printf("ջ��Ԫ�أ�%d\n", Top_SeqStack(L));
    printf("������Ҫ��ջ��Ԫ�ظ��������ܳ���%d������\n", n);
    scanf_s("%d", &n);
    printf("���γ�ջ��%d��Ԫ�أ�\n", n);

    for (i = 0; i < n; i++) {
        Pop_SeqStack(L, &m);
        printf("%3d", m);
    }

    printf("\n");
    Print_SeqStack(L);
    printf("ջ��Ԫ�أ�%d\n", Top_SeqStack(L));

    return 0;
}
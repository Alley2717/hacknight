#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Deque {
    int elements[MAX];
    int front, rear;
}Dequeue;

void initialize(Dequeue *dq) {
    dq->front = dq->rear = -1;
}

void insertFront(struct Deque *dq, int var) {
    if (dq->front == 0 && dq->rear == MAX - 1) {
        printf("Deque is full.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
        dq->elements[dq->front] = var;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
        dq->elements[dq->front] = var;
    } else {
        dq->front--;
        dq->elements[dq->front] = var;
    }
}

void insertRear(Dequeue *dq, int var) {
    if (dq->front == 0 && dq->rear == MAX - 1) {
        printf("Deque is full.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
        dq->elements[dq->rear] = var;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
        dq->elements[dq->rear] = var;
    } else {
        dq->rear++;
        dq->elements[dq->rear] = var;
    }
}

void delete(Dequeue *dq) {
    if (dq->front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void rotate(Dequeue *dq, int n) {
    if (dq->front == -1) {
        return;
    }
    if (x< 0) {
        for (int i = 0; i < -n; i++) {
            int v = dq->elements[dq->rear];
            delete(dq);
            insertRear(dq, v);
        }
    } else if (n > 0) {
        for (int i = 0; i < n; i++) {
            int v = dq->elements[dq->front];
            delete(dq);
            insertRear(dq, v);
        }
    }
}

int findGreater(Dequeue *dq, int entry, int num)
{
    int ans = -1;
    if (entry == 1)
    {
        int i = dq->front;
        while (i != dq->rear)
        {
            if (dq->elements[i] > num)
            {
                ans = dq->elements[i];
                break;
            }
            i = (i + 1) % MAX;
        }
    }
    else if (entry == 2)
    {
        int i = dq->rear;
        while (i != dq->front)
        {
            if (dq->elements[i] > num)
            {
                ans = dq->elements[i];
                break;
            }
            i = (i - 1 + MAX) % MAX;
        }
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);

    Dequeue dq;
    initialize(&dq);

    int i;
    for (i = 0; i < N; i++) {
        int op, entry, num;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d %d", &entry, &num);
            if (entry == 1) {
                insertFront(&dq, num);
            } else {
                insertRear(&dq, num);
            }
        } else if (op == 2) {
            scanf("%d", &entry);
            if (entry == 1) {
                delete(&dq);
            } else {
                dq.rear = (dq.rear - 1 + MAX) % MAX;
            }
        } else if (op == 3) {
            int rot;
            scanf("%d", &rot);
            rotate(&dq, rot);
        } else if (op == 4) {
            scanf("%d %d", &entry, &num);
            int greater = findGreater(&dq, entry, num);
            printf("%d\n", greater);
        }
    }

    return 0;
}

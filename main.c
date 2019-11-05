#include<stdio.h>

struct node
{
    int data;
    int priority;
    struct node*next;
};

struct node*front = NULL;
struct node*rear = NULL;



void enqueue()
{
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Memory Not Allocated\n\n");
        return;
    }
    int item , prio;
    printf("Enter a data : \n");
    scanf("%d" , &item);
    temp->data = item;
    printf("Enter a priority : \n");
    scanf("%d" , &prio);
    temp->priority = prio;

    if(front==NULL || temp->priority < front->priority)
    {
        temp->next = front;
        front = temp;
    }
    else
    {
        struct node*p;
        p = front;

        while(p->next!=NULL && p->next->priority <= temp->priority)
        {
            p = p->next;

        }
         temp->next=  p->next;
         p->next = temp;
    }


}

void dequeue()
{
    if(front==NULL)
    {
        //printf("Queue is Empty...!");
        return;
    }
    struct node*t;
    t = front;

    front = front->next;
    free(t);




}

void front_node()
{
    if(front==NULL)
    {
        printf("Queue is Empty..!");
        return;
    }
    else
    {
        printf("front node is %d and priority is %d " , front->data , front->priority);
    }
}

void rear_node()
{
    if(front==NULL)
    {
        printf("Queue is Empty..!");
        return;
    }
    else
    {
        struct node *t;
        t = front;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        rear  =t;
        printf("rear node is %d and priority is %d" , rear->data , rear->priority);
    }
}



void display()
{
    struct node*t;
    t= front;
    if(front==NULL)
    {
        printf("Queue Is Empty..!");
        return;
    }
    else
    {


    printf("Data  priority\n");
    while(t!=NULL)
    {
        printf("%d     %d\n" , t->data , t->priority);
        t = t->next;
    }
    printf("\n");
    }
}


int main()
{
    int ch;
    while(1)
    {
        printf("1 Insert \n");
        printf("2 Delete\n");
        printf("3 Front node\n");
        printf("4 Rear Node\n");
        printf("5 Exit\n");
        printf("Enter your choice : ");
        scanf("%d" , &ch);

        switch(ch)
        {
        case 1:
            enqueue();
            display();
            printf("\n\n");
            break;
        case 2:
            dequeue();
            display();
            printf("\n\n");
            break;
        case 3:
            front_node();
            printf("\n\n");
            break;
        case 4:
            rear_node();
            printf("\n\n");
            break;
        case 5:
            exit(0);

        }
    }
}



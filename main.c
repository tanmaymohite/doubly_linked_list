#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}Node;


Node *createSLL();
void displaySLL(Node *p);
Node *CN();
Node *insertFirst(Node *head,int x);
Node *insertLast(Node *head,int x);
Node *insertBetween(Node *head,int pos,int x);
int countNodes(Node *head);
Node *deleteFirst(Node *head);
Node *deleteLast(Node *head);
Node *deleteBetween(Node *head,int pos);

int main()
{
    int choice,x,pos;
    Node *HEAD=NULL;

    while(1)
    {
        printf("\n=========================================");
        printf("\n1  :  Create SLL");
        printf("\n2  :  Display SLL");
        printf("\n3  :  Insert First Node in SLL .");
        printf("\n4  :  Insert Last Node in SLL .");
        printf("\n5  :  Insert Between Node in SLL .");
        printf("\n6  :  Delete First Node From SLL .");
        printf("\n7  :  Delete Last Node From SLL .");
        printf("\n8  :  Delete Between Node From SLL .");
        printf("\n9  :  Count Nodes.");
        printf("\n=========================================");

        printf("\nSelect Your Choice[1-25] : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                HEAD = createSLL();
                printf("Successfully SLL created!!! ");
                break;

            case 2:
                displaySLL(HEAD);
                break;
            case 3:
                printf("Enter Data - ");
                scanf("%d",&x);
                HEAD = insertFirst(HEAD,x);
                printf("Successfully Inserted First Element!!! ");
                break;
            case 4:
                printf("Enter Data - ");
                scanf("%d",&x);
                HEAD = insertLast(HEAD,x);
                printf("Successfully Inserted Last Element!!! ");
                break;
            case 5:
                printf("Enter Position: ");
                scanf("%d",&pos);
                printf("Enter Data: ");
                scanf("%d",&x);
                HEAD = insertBetween(HEAD,pos,x);
                printf("Successfully Inserted Between Element!!! ");
                break;
            case 6:
                HEAD = deleteFirst(HEAD);
                printf("Successfully Deleted first Element!!!");
                break;
            case 7:
                HEAD = deleteLast(HEAD);
                printf("Successfully deleted Last Element!!! ");
                break;
            case 8:
                printf("Enter Position: ");
                scanf("%d",&pos);
                HEAD = deleteBetween(HEAD,pos);
                printf("Successfully deleted Between Element!!! ");
                break;

            case 9:
                printf("No. of Nodes are %d",countNodes(HEAD));
                break;
        }
    }
}
//head p           q
//NULL|10|2002     1002|20|3002   2002|20|NULL
//1002             2002           3002

//head p            q
//NULL|10|2002      1002|20|NULL
//1002              2002
Node *createSLL()
{
    int i=1,n,x;
    printf("\nHow many nodes you want: ");
    scanf("%d",&n);

    Node *head = NULL;
    head = CN();

    printf("Enter Data: ");
    scanf("%d",&x);

    head->prev=NULL;
    head->data=x;
    head->next=NULL;

    Node *p = head;

    while(i<n)
    {
        Node *q = CN();
        printf("Enter Data: ");
        scanf("%d",&x);

        q->data = x;
        q->prev = p;
        q->next = NULL;

        p->next=q;
        p=p->next;
        i++;

    }
    return head;
}

Node *CN()
{
    return (Node *)malloc(sizeof(Node));
}

void displaySLL(Node *p)
{
    if(p==NULL)
        printf("Empty List");
    else
    {
        printf("\n");
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}
//p                    head
//NULL|5|1002          NULL|10|2002     1002|20|3002   2002|20|NULL
//102                  1002             2002           3002

Node *insertFirst(Node *head,int x)
{

    Node *p = CN();
    p->prev=NULL;
    p->data=x;
    p->next=head;

    head = p ;
    return head;
}
//head                                                 q                p
//NULL|5|1002          102|10|2002      1002|20|3002   2002|30|4002     3002|40|NULL
//102                  1002             2002           3002             4002
Node *insertLast(Node *head,int x)
{
    if(head == NULL)
        return insertFirst(head,x);
    Node *q = head;
    while(q->next!=NULL)
        q=q->next;
    Node *p = CN();
    p->prev=q;
    p->data=x;
    p->next=NULL;

    q->next=p;

    return head;
}

//head             p                q
//NULL|10|2002     1002|20|4002     2002|25|3002      4002|20|NULL
//1002             2002             4002              3002

Node *insertBetween(Node *head,int pos,int x)
{
    if(pos == countNodes(head)+1)
        return insertLast(head,x);
    int i=1;
    Node *p = head;

    while(i<pos-1)//3<3
    {
        p=p->next;
        i++;//
    }
    Node *q = CN();
    q->prev=p;
    q->data=x;
    q->next=p->next;

    p->next=q;
    q->next->prev=q;

    return head;
}

//head                                                p
//NULL|10|2002     1002|20|4002     2002|25|3002      4002|20|NULL
//1002             2002             4002              3002

int countNodes(Node *head)
{
    int count=1;
    Node *p = head;
    while(p->next!=NULL)
    {
        p=p->next;
        count++;//1,2,3
    }
    return count;
}
//p                head
//NULL|10|2002     NULL|20|3002   2002|20|NULL
//1002             2002           3002
Node *deleteFirst(Node *head)
{
    if(head == NULL)
        return head;
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *p=head;
    head = head->next;

    head->prev = NULL;
    free(p);
    return head;
}

//head                            p
//NULL|10|2002     1002|20|NULL   2002|20|NULL
//1002             2002           3002

Node *deleteLast(Node *head)
{
    if(head == NULL)
        return head;
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *p = head;
    while(p->next!=NULL)
        p=p->next;
    p->prev->next=NULL;

    free(p);
    return head;
}
//head             q
//NULL|10|2002     1002|20|3002     2002|20|NULL
//1002             2002             3002
Node *deleteBetween(Node *head,int pos)
{
    if(head == NULL)
        return head;
    if(pos == 1)
        return deleteFirst(head);

    if(pos == countNodes(head))
        return deleteLast(head);

    Node *p=head;
    int i=1;
    while(i<pos)//1<2
    {
        p=p->next;
        i++;
    }
    Node *q= head;
    while(q->next!=p)
        q=q->next;
    q->next=p->next;
    q->next->prev=q;

    free(p);
    return head;
}


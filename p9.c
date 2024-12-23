#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coff,xexp,yexp,zexp;
    struct node *next;
};
struct node *poly1,*poly2,*temp,*p;
struct node *createnode(){
    int c,x,y,z;
    printf("\nEnter coefficient, exponents of x,y,z: ");
    scanf("%d%d%d%d",&c,&x,&y,&z);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coff=c;
    temp->xexp=x;
    temp->yexp=y;
    temp->zexp=z;
    temp->next=NULL;
    return temp;
}
void display(struct node *head)
{
    p=head;
    do
    {
        if(p->coff>=0)
        {
            printf("+%dx^%dy^%dz^%d ",p->coff,p->xexp,p->yexp,p->zexp);
        }
        else
        {
            printf("%dx^%dy^%dz^%d ",p->coff,p->xexp,p->yexp,p->zexp);
        }
        p=p->next;
        
    }while(p!=head);
    
}
int evaluate(struct node *head)
{
    int x,y,z,sum=0;
    printf("\nEnter the values of x,y,z:");
    scanf("%d%d%d",&x,&y,&z);
    p=head;
    do
    {
        sum=sum+(p->coff*pow(x,p->xexp)*pow(y,p->yexp)*pow(z,p->zexp));
        p=p->next;
    } while (p!=head);
    printf("Sum of the polynomial %d",sum);
    return sum;
}
int sum(int sum1,int sum2)
{
    int s;
    s=sum1+sum2;
    printf("\nSum of two polynomials=%d",s);
}
int main()
{
    printf("Name-Aditya Kumar\nUSN-1AY23CS012\n\n");
    int n1,sum1,sum2;
    printf("\nHow many terms in polynomial 1= ");
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++)
    {
        struct node *newnode=createnode();
        if(poly1==NULL){
            poly1=newnode;
            newnode->next=poly1;
        }
        else{
            p=poly1;
            while(p->next!=poly1)
            {
                p=p->next;
            }
            newnode->next=poly1;
            p->next=newnode;
        }
    }
    printf("Displaying polynomial 1: ");
    display(poly1);
    sum1=evaluate(poly1);
       int n2;
    printf("\nHow many terms in polynomial 2= ");
    scanf("%d",&n2);
    for(int i=1;i<=n2;i++)
    {
        struct node *newnode=createnode();
        if(poly2==NULL){
            poly2=newnode;
            newnode->next=poly2;
        }
        else{
            p=poly2;
            while(p->next!=poly2)
            {
                p=p->next;
            }
            newnode->next=poly2;
            p->next=newnode;
        }
    }
    printf("Displaying polynomial 2: ");
    display(poly2);
    sum2=evaluate(poly2);
    sum(sum1,sum2);
}
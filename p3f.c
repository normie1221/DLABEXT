#include<stdio.h>
#include<string.h>
char stk[20];
int top=-1;
int max=20;
void push()
{
	char ele;
	printf("enter elements for pushing:");
	scanf("%s",&ele);
	if(top>=max-1)
	{
		printf("stack overflow\n");
		return;
	}
	top++;
	stk[top]=ele;
	printf("%c pushed to stack.\n",ele);
}
char pop()
{
	if(top==-1)
	{
		printf("stack underflow\n");
		return'\0';
	}
	else
	{
		char ele=stk[top];
		top--;
		printf("%s popped from stack.\n",ele);
		return ele;
	}
}
int palindrome()
{
	char str[50];
	printf("enter a word to check:");
	scanf("%s",str);
	int len=strlen(str);
	char pstk[len];
	for(int i=0;i<len;i++)
	{
		pstk[i]=str[len-i-1];
	}
	for(int i=0;i<len;i++)
	{
		if(str[i]!=pstk[i])
		{
			printf("not a palindrome!\n");
			return 1;
        	}
        }
	printf("it is a palindrome!\n");
	return 0;
}
void display()
{
	if(top==max-1)
	{
		printf("stack is full!\n");
	}
	else if(top==-1)
	{
		printf("stack is empty!\n");
	}
	else
	{
		printf("stack is partially full ! current size:%d\n",top+1);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n1.push\n2.pop\n3.Display\n4.check palindrome\n5.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:	
				palindrome();
				break;
			case 5:
				return 0;
			default:
				printf("invalid choice!\n");
		}
	}
	return 0;
}
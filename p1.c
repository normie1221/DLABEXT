#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct calElement
{
char *day;
int date;
char *activity;
};
struct calElement* create() 
{
struct calElement *calendar;
calendar = (struct calElement *)malloc(sizeof(struct calElement)*7);
return calendar;
}
void read(struct calElement *calendar)
{
char day[10];
char activity[25];
int i, date;
for(i = 0; i<7; i++)
{
printf("Enter the day : ");
scanf("%s",day);
calendar[i].day = (char *)malloc(strlen(day)+1); 
strcpy(calendar[i].day, day);
printf("Enter the date : ");
scanf("%d",&date);
calendar[i].date = date;
getchar();
printf("Enter description of the activity : ");
scanf("%[^\n]s",activity);
calendar[i].activity = (char *)malloc(strlen(activity)+1);
strcpy(calendar[i].activity, activity);
}
}
void display(struct calElement *calendar)
{
int i;
printf("\n\nYour calendar\n");
printf("Day\t\tDate\t\tActivity");
for(i = 0; i<7; i++){
printf("\n%s\t\t%d\t\t%s",calendar[i].day,calendar[i].date,calendar[i].activity );
}
}
void main()
{
     printf("ADITYA KUMAR\nUSN - 1AY23CS012\n");
struct calElement *calendar;
calendar=create();
read(calendar);
display(calendar);
free(calendar); 
}
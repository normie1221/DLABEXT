#include<stdio.h>
char STR[100],PAT[100],REP[100],ANS[100];
int s, p, r, a, flag = 0;
void read();
void replace();
void display();
void main()
{
     printf("ADITYA KUMAR\nUSN - 1AY23CS012\n");
read();
replace();
display();
}
void read()
{
printf("Enter the MAIN string: \n");
scanf("%[^\n]s",STR);
printf("Enter a PATTERN string: \n");
scanf("%s",PAT);
printf("Enter a REPLACE string: \n");
scanf("%s",REP);
}
void replace ()
{
s = p = a = 0;
while ( STR[s] != '\0')
{
if ( STR[s] == PAT[p] )
{
p++;
s++;
if ( PAT[p] == '\0')
{
flag=1;
for(r = 0; REP[r] != '\0';r++, a++)
ANS[a] = REP[r];
p = 0;
}
}
else
{
ANS[a] = STR[s];
s++;
a++;
p = 0;
}
}
}
void display()
{
    if(flag==0)
printf("Pattern doesn't found!!!");
else
{
ANS[a] = '\0';
printf("\nThe RESULTANT string is:\n%s\n" ,ANS);
}
}
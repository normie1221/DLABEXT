#include <stdio.h>

void towerofHanoi(int n, char Sour, char Aux, char Dest)
{
    if (n == 1)
    {
        printf("\n Move disk from %c to %c", Sour, Dest);
        return;
    }
    towerofHanoi(n - 1, Sour, Dest, Aux);
    printf("\n Move disk from %c to %c", Sour, Dest);
    towerofHanoi(n - 1, Aux, Sour, Dest);
}

int main()
{
    printf("ADITYA KUMAR\nUSN-1AY23CS012\n\n");
    int n;
    char Sour, Aux, Dest;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Enter the source rod: ");
    scanf(" %c", &Sour);

    printf("Enter the destination rod: ");
    scanf(" %c", &Dest);

    printf("Enter the auxiliary rod: ");
    scanf(" %c", &Aux);

    printf("\nThe sequence of moves involved in the Tower of Hanoi are:");
    towerofHanoi(n, Sour, Aux, Dest);

    return 0;
}
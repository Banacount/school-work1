#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Function declaration
void displayMenu ();
void enqueue (int main_queue[], int *rear);
void displayQueue (int main_queue[], int rear, int front);
void dequeue (int *front);

// Global variables
int QSIZE = 10;
int POPULATED = 0;

int main () 
{
    size_t queueSize = 10;
    int userPicked = 0;

    printf("Type the size of queue(10 min / 200 max): ");
    fflush(stdout);
    scanf("%d", &userPicked);

    // Verify if queue is probable
    if (userPicked < 10) {
        printf("The index is less than minimum..\nUsing the minimum instead.\n");
    } else if (userPicked > 200) {
        printf("The index is beyond the maximum..\nUsing the maximum instead.\n");
        queueSize = 200;
    } else {
        queueSize = (int)userPicked;
    }
    printf("Initializing queue size %zu.\n", queueSize);

    QSIZE = queueSize+1;
    // Initialize queue
    int queue[QSIZE], user_option, front = 0, rear = 0, isRun = 1;

    printf("Enter to continue...");
    fflush(stdout);
    getchar();
    getchar();

    while (isRun)
    {
        system("clear");
        displayMenu();
        displayQueue(queue, rear, front);
        printf("Enter an option: ");
        fflush(stdout);
        scanf("%d", &user_option);
        switch (user_option) {
            case 1:
                enqueue(queue, &rear);
                break;
            case 2:
                dequeue(&front);
                break;
            /*case 3:
                displayQueue(queue, rear);
                break;*/
            default:
                printf("\nGoodbye...\n"); isRun = 0; break;
        }
    }

    // Queue operations
    return 0;
}

void displayMenu () 
{
    printf("-- Queue Menu --\n");
    printf("[ 1 ] - Enqueue a value.\n");
    printf("[ 2 ] - Dequeue.\n");
    printf("[ 3 ] - Display queue value.\n");
    printf("[ 4 ] - Exit.\n");
}

void enqueue (int main_queue[], int *rear) 
{
    if (POPULATED >= QSIZE-1) {
        printf("Queue overflow..");
        fflush(stdout);
        getchar();
        getchar();
        return;
    }

    int value = 0;
    printf("Enter a value: ");
    fflush(stdout);
    scanf("%d", &value);

    main_queue[*rear] = value;
    (*rear)++;
    POPULATED++;
}

void dequeue (int *front) 
{
    if (*front <= 0) {
        printf("Queue underflow..");
        fflush(stdout);
        getchar();
        getchar();
        return;
    } else if (*front >= POPULATED-1) {
        printf("Minimum is 1..");
        fflush(stdout);
        getchar();
        getchar();
        return;
    }

    (*front)++;
}

void displayQueue (int main_queue[], int rear, int front)
{
    for (int i = front; i < rear; i++) {
        if (i == rear-1) printf("%d", main_queue[i]);
        else printf("%d -> ", main_queue[i]);
    }
    printf("\n");
}

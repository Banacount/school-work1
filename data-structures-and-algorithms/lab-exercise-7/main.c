#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Function declaration
void displayMenu ();
void enqueue (int main_queue[], int *rear);
void displayQueue (int main_queue[], int rear, int front);
void dequeue (int *front, int main_queue[]);
void pauseInput() {
    fflush(stdout);
    getchar();
    getchar();
}

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
    pauseInput();

    while (isRun)
    {
        system("clear");
        displayQueue(queue, rear, front);
        printf("\n");

        displayMenu();
        printf("Enter an option: ");
        fflush(stdout);
        scanf("%d", &user_option);

        switch (user_option) {
            case 1:
                enqueue(queue, &rear);
                break;
            case 2:
                dequeue(&front, queue);
                break;
            case 3:
                printf("\nGoodbye...\n"); isRun = 0; break;
            default:
                printf("Invalid command...");
                fflush(stdout);
                getchar();
                getchar();
        }
    }

    return 0;
}

// Queue operations

void displayMenu () 
{
    printf("-- Printer Queue Menu --\n");
    printf("[ 1 ] - Request to print.\n");
    printf("[ 2 ] - Perform printing.\n");
    printf("[ 3 ] - Exit.\n");
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
    printf("Enter number of pages: ");
    fflush(stdout);
    scanf("%d", &value);

    main_queue[*rear] = value;
    (*rear)++;
    POPULATED++;
    printf("Print request added: %d pages", value);
    pauseInput();
}

void dequeue (int *front, int main_queue[]) 
{
    if (*front < 0) {
        printf("Queue underflow..");
        fflush(stdout);
        getchar();
        getchar();
        return;
    } else if (*front >= POPULATED) {
        printf("Blank queue..");
        fflush(stdout);
        getchar();
        getchar();
        return;
    }

    printf("Printing %d...", main_queue[*front]);
    pauseInput();
    (*front)++;
}

void displayQueue (int main_queue[], int rear, int front)
{
    printf("Current Printer Queue:\n");

    for (int i = front; i < rear; i++) {
        printf("[ %d pages ] ", main_queue[i]);
    }

    if (front >= rear) printf("[ EMPTY ]");
    printf("\n");
}

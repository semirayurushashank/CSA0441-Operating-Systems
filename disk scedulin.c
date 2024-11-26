#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek_time = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Head Movement: %d", head);
    for (int i = 0; i < n; i++) {
        seek_time += abs(head - requests[i]);
        head = requests[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);

    return 0;
}



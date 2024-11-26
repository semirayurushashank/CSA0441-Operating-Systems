#include <stdio.h>

#define MAX_FRAMES 7

int main() {
    int ref[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
    int frames[MAX_FRAMES], framePointer = 0, pageFaults = 0;
    int n = sizeof(ref) / sizeof(ref[0]);

    // Initialize frames to -1 (empty)
    for (int i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;

    printf("Page Replacement Process:\n");

    for (int i = 0; i < n; i++) {
        int page = ref[i], hit = 0;

        // Check if page is already in the frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        // If not a hit, replace the page
        if (!hit) {
            frames[framePointer] = page;
            framePointer = (framePointer + 1) % MAX_FRAMES;
            pageFaults++;
            printf("Page %d -> MISS: ", page);
        } else {
            printf("Page %d -> HIT:  ", page);
        }

        // Print current frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", n - pageFaults);
    return 0;
}


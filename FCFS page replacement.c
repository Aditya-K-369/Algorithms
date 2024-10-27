#include <stdio.h>
#include <stdbool.h>

void print_frames(int frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] != -1) {
            printf("%d", frames[i]);
        } else {
            printf("-1"); // Displaying -1 for empty slots
        }

        // Adding tab after each frame, even the last one
        printf("\t");
    }
    printf("\n"); // Ending with a newline character
}
int main() {
    int num_pages, num_frames, page_faults = 0;
    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    int pages[num_pages];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < num_pages; i++) {
        printf("Page %d: ", i + 1);
        scanf("%d", &pages[i]);
	}
    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);
    // Display the page reference string
    printf("Page Reference String: ");
    for (int i = 0; i < num_pages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n"); // Ending with a newline character
    int frames[num_frames];
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;  // Initialize frames as empty
	}
    // FCFS Page Replacement Algorithm
    int index = 0;
    for (int i = 0; i < num_pages; i++) {
        bool page_fault = true;
        // Check if the page is already in the frames
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == pages[i]) {
                page_fault = false;
                break;
            }
		}
  // If there is a page fault
        if (page_fault) {
            frames[index] = pages[i];
            index = (index + 1) % num_frames;  // Move to the next frame in a circular manner
            page_faults++;
		}
        // Print the current page and state of frames after each page reference
        print_frames(frames, num_frames);
	}
    // Print total page faults at the end
    printf("Total Page Faults: %d\n", page_faults);
    return 0;
}


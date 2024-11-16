#include <stdio.h>
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos,
        max, faults = 0;
    printf("Number of Frames:\n");
    scanf("%d", &no_of_frames);
    scanf("%d", &no_of_pages);

    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }
    // Initialize frames to 0 instead of -1
    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = 0; // Changed from -1 to 0
    }
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;
        // Check if the page is already in one of the frames
        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }
        // If the page is not found in frames
        if (flag1 == 0)
        {
            // Check for an empty frame (marked by 0)
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == 0)
                { // Check for 0 instead of -1
                    printf("Page Fault:\n");
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        // If no empty frame was found
        if (flag2 == 0)
        {
            flag3 = 0;
            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1; // Keep this as is, for finding future pages
                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }
            // Find a frame to replace
            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;
                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            printf("Page Fault:\n"); // Added before replacing
            frames[pos] = pages[i];
            faults++;
        }
        // Print the current state of frames
        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d ", frames[j]);
        }
        printf("\n"); // Move to the next line after frames
    }
    printf("Page faults = %d\n", faults);
    return 0;
}
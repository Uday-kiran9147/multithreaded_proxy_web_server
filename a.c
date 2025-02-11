#include <windows.h>
#include <stdio.h>

DWORD WINAPI ThreadFunction(LPVOID lpParam) {
    int threadId = *(int*)lpParam;
    printf("Thread %d is running\n", threadId);
    return 0;
}

int main() {
    HANDLE hThread;
    DWORD dwThreadId;
    int threadParam = 1;

    // Create a thread
    hThread = CreateThread(
        NULL,                   // Default security attributes
        0,                      // Default stack size
        ThreadFunction,         // Thread function
        &threadParam,           // Parameter to pass to the thread
        0,                      // Default creation flags
        &dwThreadId             // Returns the thread identifier
    );

    if (hThread == NULL) {
        printf("Failed to create thread\n");
        return 1;
    }

    // Wait for the thread to finish
    WaitForSingleObject(hThread, INFINITE);

    // Close the thread handle
    CloseHandle(hThread);

    printf("Thread has finished execution\n");
    return 0;
}
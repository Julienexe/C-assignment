#include <stdio.h>

// Function to lock all doors
void lockDoors() {
    printf("Locking all doors...\n");
    // Add code here to lock all doors
}

// Function to unlock all doors
void unlockDoors() {
    printf("Unlocking all doors...\n");
    // Add code here to unlock all doors
}

int main() {
    int vehicleSpeed = 0;

    // Get the current vehicle speed
    printf("Enter the current vehicle speed (in mph): ");
    scanf("%d", &vehicleSpeed);

    // If the vehicle is moving faster than 20 mph, lock all doors
    if (vehicleSpeed > 20) {
        lockDoors();
    }
    // Otherwise, unlock all doors
    else {
        unlockDoors();
    }

    return 0;
}
// Simulate distance measurement and signaling based on ranges
#include <stdio.h> // Logs
#include <unistd.h> // Delay

static void signal_distance(int cm) { // Signal policy
  if (cm < 10) { // Danger
    printf("DIST=%dcm ALERT=DANGER BUZZER=FAST LED=RED\n", cm); // Log
  } else if (cm < 20) { // Warning
    printf("DIST=%dcm ALERT=WARNING BUZZER=MED LED=YEL\n", cm); // Log
  } else { // Safe
    printf("DIST=%dcm ALERT=SAFE BUZZER=OFF LED=GRN\n", cm); // Log
  } // End ranges
}

int main(void) { // Entry
  printf("Arduino Car Parking Assistant\n"); // Title
  int samples[] = {35, 25, 18, 9, 12, 28}; // Example sequence
  for (int i = 0; i < 6; ++i) { // Iterate
    signal_distance(samples[i]); // Signal
    usleep(200000); // 200ms
  } // End loop
  return 0; // Exit
} // End main

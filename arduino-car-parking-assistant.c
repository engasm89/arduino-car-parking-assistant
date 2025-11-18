/*
 * Course: Arduino Car Parking Assistant
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Car Parking Assistant" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-car-parking-assistant/
 * Repository: https://github.com/engasm89/arduino-car-parking-assistant
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

int main(void) { // Program entry point
  printf("Arduino Car Parking Assistant\n"); // Title
  int samples[] = {35, 25, 18, 9, 12, 28}; // Example sequence
  for (int i = 0; i < 6; ++i) { // Iterate
    signal_distance(samples[i]); // Signal
    usleep(200000); // 200ms
  } // End loop
  return 0; // Exit
} // End of main function

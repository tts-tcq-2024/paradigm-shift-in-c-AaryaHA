#include <stdio.h>
#include "warning.h"
#include "warning_message_print.h"

void checkEarlyWarning(float value, float min, float max, float tolerance, const char* lowWarning, const char* highWarning) {
    printLowWarning(value, min, tolerance, lowWarning);
    printHighWarning(value, max, tolerance, highWarning);
}

void checkEarlyWarningForChargeRate(float value, float max, float tolerance, const char* highWarning) {
   printHighWarning(value, max, tolerance, highWarning);
}


void printLowWarning(float value, float min, float tolerance, const char* lowWarning) {
    if (value >= min && value <= min + tolerance) {
        printf("%s\n", lowWarning);
    }
}

void printHighWarning(float value, float max, float tolerance, const char* highWarning) {
    if (value >= max - tolerance && value <= max) {
        printf("%s\n", highWarning);
    }
}

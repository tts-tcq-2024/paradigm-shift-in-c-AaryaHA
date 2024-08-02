#include "Temperature_range_check.h"
#include "value_range_check.h"
#include "warning.h"

int isTemperatureOk(float temperature) {
    checkEarlyWarning(temperature, 0, 45, 2.25, "Warning: Approaching lower temperature limit", "Warning: Approaching upper temperature limit");
    return isValueInRange(temperature, 0, 45, "Temperature out of range!");
}

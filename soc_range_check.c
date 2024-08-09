#include "soc_range_check.h"
#include "value_range_check.h"
#include "warning.h"

int isSocOk(float soc) {
    checkEarlyWarning(soc, 20, 80, 4, "Warning: Approaching discharge", "Warning: Approaching charge-peak");
    return isValueInRange(soc, 20, 80, "State of Charge out of range!");
}

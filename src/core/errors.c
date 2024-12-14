#include "core/errors.h"
#include <stdio.h>

const char *errorMessage(ErrorCode code) {
  switch (code) {
  case ERR_OK:
    return "No error.";
  case ERR_MEMORY_ALLOCATION:
    return "Memory Allocation failed.";

  case ERR_UNKNOWN:
  default:
    return "Unknown error.";
  }
}

void handleError(ErrorCode code, const char *context) {
  fprintf(stderr, "Error (%s): %s\n", context, errorMessage(code));
}

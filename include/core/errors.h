#ifndef ERRORS_H
#define ERRORS_H

typedef enum {
  ERR_OK = 0,
  ERR_MEMORY_ALLOCATION,

  ERR_STACK_PUSH_FAILED,

  ERR_STACK_POP_FAILED,

  ERR_UNKNOWN
} ErrorCode;

const char *errorMessage(ErrorCode code);
void handleError(ErrorCode code, const char *context);

#endif

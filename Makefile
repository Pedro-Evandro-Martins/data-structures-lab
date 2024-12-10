# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Output executable
TARGET = $(BUILD_DIR)/ds_lab

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link objects to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $@

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean


##
## EPITECH PROJECT, 2025
## minilibc
## File description:
## Makefile
##

LD := ld
LDFLAGS :=

AS := nasm
ASFLAGS := -f elf64

CC := gcc
CFLAGS := -W -Wall -Wextra

NAME := libasm.so
TEST_NAME := unit_tests

BUILD_DIR := .build
SRC := $(shell find src -name '*.asm')
OBJ := $(SRC:%.asm=${BUILD_DIR}/%.o)

TEST_BUILD_DIR := .build_test
TEST_SRC := $(shell find test -name '*.c')
TEST_OBJ := $(TEST_SRC:%.c=${TEST_BUILD_DIR}/%.o)

all: $(NAME)

$(BUILD_DIR)/%.o: %.asm
	@ mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@

$(TEST_BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(NAME): LDFLAGS += -shared
$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

$(TEST_NAME): LDFLAGS += -lcriterion
$(TEST_NAME): $(TEST_OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^

tests_run: $(TEST_NAME) $(NAME)
	@-./$< --verbose

clean:
	@ rm -rf $(BUILD_DIR)
	@ rm -rf $(TEST_BUILD_DIR)

fclean: clean
	@ rm -f $(NAME) $(TEST_NAME)

re: fclean all

.NOTPARALLEL: re tests_run
.PHONY: all clean fclean re

# --- Project Name & Output ---
NAME        = libasm.a

# --- Directories ---
SRC_DIR     = src
INC_DIR     = inc
TEST_DIR    = test
OBJ_DIR     = obj
LIB_DIR     = lib

# --- Final Output Paths ---
LIB_PATH    = $(LIB_DIR)/$(NAME)

# --- Tools ---
NASM        = nasm
CC          = gcc
AR          = ar

# --- Flags ---
# NASM: Generate 64-bit ELF objects, include headers
NASMFLAGS   = -f elf64 -I$(INC_DIR)/
# GCC: Standard 42 CFLAGS, include headers
CFLAGS      = -Wall -Wextra -Werror -I$(INC_DIR)/
# AR: Create, replace, symlink index
ARFLAGS     = rcs

# --- Sources and Objects ---
# Dynamically find all .s files in src/
SRCS        = $(wildcard $(SRC_DIR)/*.s)
# Automatically transform src/file.s into obj/file.o
OBJS        = $(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(SRCS))

# --- Test Configuration ---
TEST_SRC    = $(TEST_DIR)/main.c
TEST_EXEC   = unit_tester

# --- Colors ---
GREEN       = \033[0;32m
RED         = \033[0;31m
BLUE        = \033[0;34m
NC          = \033[0m # No Color

# ============================================================================ #
# Rules                                                                        #
# ============================================================================ #

# --- Main Rules ---

all: $(LIB_PATH)
	@echo "$(GREEN)► All components built successfully.$(NC)"

# Rule to create the final library archive
$(LIB_PATH): $(OBJS) | $(LIB_DIR)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "$(BLUE)✓ Archive $@ created.$(NC)"

# Rule to compile object files from assembly sources
# The order-only prerequisite | $(OBJ_DIR) ensures the folder exists before compilation starts
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(NASM) $(NASMFLAGS) $< -o $@

# Directory creation rules
$(OBJ_DIR) $(LIB_DIR):
	@mkdir -p $@
	@echo "$(BLUE)○ Created directory: $@$(NC)"

# --- Utility Rules ---

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)× Removed object files.$(NC)"

fclean: clean
	@rm -rf $(LIB_DIR)
	@rm -f $(TEST_EXEC)
	@echo "$(RED)× Removed library and test executable.$(NC)"

re: fclean all

# --- Test Rule ---

# Compile main.c, link against libasm in lib/, and run
test: $(LIB_PATH)
	@echo "$(GREEN)► Building and running tests...$(NC)"
	@$(CC) $(CFLAGS) $(TEST_SRC) -L$(LIB_DIR) -lasm -o $(TEST_EXEC)
	@echo "$(BLUE)✓ Executable ./$(TEST_EXEC) created.$(NC)"
	@echo "-----------------------------------"
	@./$(TEST_EXEC)

malloc_error:
	@$(CC) $(CFLAGS) -DMALLOC_ERROR -Wl,--wrap=malloc $(TEST_SRC) -L$(LIB_DIR) -lasm -o $(TEST_EXEC)
	@./$(TEST_EXEC)

# Phony targets prevent conflicts with files named 'all', 'clean', etc.
.PHONY: all clean fclean re test
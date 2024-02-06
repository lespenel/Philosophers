NAME = 	philo

CFLAGS = -Wall -Wextra -Werror -g3 -O3 -I$(INCLUDES)

DFLAGS = -MMD -MP

SRC_DIR = srcs

BUILD_DIR = .build

SRC_FILES = main.c \
			ft_atoi.c \
			parsing.c \
			get_time.c \
			get_set.c \
			init_threads.c \
			free_data.c \
			eating_routine.c \
			sleeping_routine.c \
			thinking_routine.c \
			monitoring_thread.c \
			philo.c \

INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.PHONY: mlx
$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)

.PHONY: re
re : fclean
	$(MAKE) all

.PHONY: FORCE
FORCE:

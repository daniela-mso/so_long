NAME			= so_long

CFLAGS			= -Wall -Wextra -Werror -g


LIBFT_PATH		= ./libft

PRINTF_PATH		= ./ft_printf

MLX_PATH		= ./minilibx-linux


LIBFT			= $(LIBFT_PATH)/libft.a

FT_PRINTF		= $(PRINTF_PATH)/libftprintf.a

MLX_LIB			= $(MLX_PATH)/libmlx.a


INCLUDES		= -I. -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(MLX_PATH)


MLX_FLAGS		= -L $(MLX_PATH) -lmlx -lX11 -lXext -lm

# -lmlx	(MiniLibX)	The library compiled. It translates C commands into window instructions
# -lX11	(X11 Library)	The "Core" of Linux graphics. It handles pixels, windows, and mouse movement
# -lXext	(X Extensions)	Extra "pro" features for X11 (like handling window transparency or smoother shapes)
# -lm	(Math Library)	Provides functions like sin, cos, or square roots. MLX uses these to calculate window math


SRC				= so_long.c check_path.c checks.c cleanup.c init.c key_input.c


OBJS			= $(SRC:.c=.o)


all: $(NAME)


$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)


%.o:%.c
	cc $(CFLAGS)  $(INCLUDES) -c $< -o $@


$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)


$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_PATH)


$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)




clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean 
	$(MAKE) -C $(PRINTF_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean 
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(MAKE) -C $(MLX_PATH) clean   
#mlx doesent ususally have a fclean rule 
	

re: fclean all 

.PHONY: all clean fclean re

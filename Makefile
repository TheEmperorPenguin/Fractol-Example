NAME = fractol

NAME_BONUS = fractol_bonus

MLX = ./mlx_linux/libmlx.a

MLX_SUBDIR = ./mlx_linux

OBJ = $(SRC:.c=.o)

SRC =	mandatory/fractals.c		\
		mandatory/fractol_utils.c	\
		mandatory/mouse.c			\
		mandatory/keyboard.c		\
		mandatory/image.c			\
		mandatory/input.c			\
		mandatory/fractol.c			\

BONUS =	bonus/fractals_bonus.c		\
		bonus/fractol_utils_bonus.c	\
		bonus/mouse_bonus.c			\
		bonus/keyboard_bonus.c		\
		bonus/image_bonus.c			\
		bonus/input_bonus.c			\
		bonus/fractol_bonus.c		\

OBJ_BONUS = $(BONUS:.c=.o)

CC = clang

CFLAGS = -g -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c 

LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o 

all: $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_SUBDIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(NAME)
	@echo " ________ .-------.       ____        _______ ,---------.                ,-----.      .---.      ";
	@echo "|        ||  _ _   \    .'  __ \`.    /   __  \\          \             .'  .-,  '.    | ,_|      ";
	@echo "|   .----'| ( ' )  |   /   '  \  \  | ,_/  \__)\`--.  ,---'            / ,-.|  \ _ \ ,-./  )      ";
	@echo "|  _|____ |(_ o _) /   |___|  /  |,-./  )         |   \  _ _    _ _  ;  \  '_ /  | :\  '_ '\`)    ";
	@echo "|_( )_   || (_,_).' __    _.-\`   |\  '_ '\`)       :_ _: ( ' )--( ' ) |  _\`,/ \ _/  | > (_)  )    ";
	@echo "(_ o._)__||  |\ \  |  |.'   _    | > (_)  )  __   (_I_)(_{;}_)(_{;}_): (  '\_/ \   ;(  .  .-'    ";
	@echo "|(_,_)    |  | \ \`'   /|  _( )_  |(  .  .-'_/  ) (_(=)_)(_,_)--(_,_)  \ \`\"/  \  ) /  \`-'\`-'|___  ";
	@echo "|   |     |  |  \    / \ (_ o _) / \`-'\`-'     /   (_I_)                '. \_/\`\`\".'    |        \ ";
	@echo "'---'     ''-'   \`'-'   '.(_,_).'    \`._____.'    '---'                  '-----'      \`--------\` ";
	@echo "                                                                                                 ";

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_BONUS}
	@$(MAKE) -C $(MLX_SUBDIR) clean

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: $(MLX) $(OBJ_BONUS)	
	@$(CC) $(OBJ_BONUS) $(LDFLAGS) $(NAME_BONUS)

.PHONY: all clean fclean re bonus 

NAME = fractol

OBJ = $(SRC:.c=.o)

SRC =	mandatory/fractals.c    \
		mandatory/fractol_utils.c\
		mandatory/mouse.c			\
		mandatory/keyboard.c		 \
		mandatory/image.c           \
		mandatory/input.c            \
		mandatory/fractol.c			\

CC = clang

CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
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
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

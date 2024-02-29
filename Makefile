CC = cc
NAME = so_long
NAME_B = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
source =   flood_fill.c parsing.c draw_and_string.c start_and_end_game.c move_player.c monster_move_and_animtion.c load_and_destroy_xpm.c  draw_and_put.c door_open.c coin_animtion.c check_before_move.c main.c  utils/ft_bzero.c utils/ft_calloc.c utils/ft_split.c utils/ft_strchr.c utils/ft_strjoin.c \
			utils/ft_strlen.c utils/get_next_line.c utils/ft_itoa.c

source_bonus =   flood_fill_bonus.c parsing_bonus.c draw_and_string_bonus.c start_and_end_game_bonus.c move_player_bonus.c monster_move_and_animtion_bonus.c load_and_destroy_xpm_bonus.c  draw_and_put_bonus.c door_open_bonus.c coin_animtion_bonus.c check_before_move_bonus.c main_bonus.c  utils/ft_bzero_bonus.c utils/ft_calloc_bonus.c utils/ft_split_bonus.c utils/ft_strchr_bonus.c utils/ft_strjoin_bonus.c \
			utils/ft_strlen_bonus.c utils/get_next_line_bonus.c utils/ft_itoa_bonus.c

INC = ./utils/libft.h

INC_B = ./utils/libft_bonus.h
obj = $(source:.c=.o)
obj_bonus = $(source_bonus:.c=.o)
all:$(NAME)

$(NAME): $(obj) $(INC)
	$(CC)   $(obj)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean	:
	rm -fr $(obj) $(obj_bonus)
fclean	: clean
	rm -fr $(NAME) $(NAME_B)

re: fclean all

$(NAME_B):$(obj_bonus) $(INC_B)
	$(CC)   $(obj_bonus)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
bonus: $(NAME_B)


.SECONDARY : $(obj) $(obj_bonus) $(INC) $(INC_B)

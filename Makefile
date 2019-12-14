# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 12:47:01 by viclucas          #+#    #+#              #
#    Updated: 2019/11/05 09:42:13 by viclucas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

FLAG = -Wall -Wextra -Werror

LIB = -I includes/

INC = Bullet.hpp\
	Enemy.hpp\
	Infos.hpp\
	Parent.hpp\
	Player.hpp\
	Window.hpp\
	Infos.hpp\

INCPATH = includes
INCS = $(addprefix $(INCPATH)/,$(INC))

SRC = main.cpp \
	  Infos.cpp \
	  interactive/init_interactive_mode.cpp \
	  interactive/printingInfos.cpp \
	  interactive/userInput.cpp \
	  childClasses/Player.cpp \
	  childClasses/Enemy.cpp \
	  childClasses/Bullet.cpp\
	  childClasses/Background.cpp\
	  childClasses/Background_fct.cpp\
	  Parent.cpp \
	  list_management.cpp \
	  collisions.cpp\
	  Frame_per_sec.cpp \

OBJPATH = obj
SRCPATH = srcs

SRCS = $(addprefix $(SRCPATH)/,$(SRC))
OBJ =  $(SRCS:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(OBJ) -lncurses -o $(NAME)

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(FLAG) $(INCLUDES) $(LIB) -c $<

nf: $(OBJ)
	clang++ $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

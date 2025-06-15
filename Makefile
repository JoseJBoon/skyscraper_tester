CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
INC			:= 	-I ex00/
BIN			:=	bin
CKR_DIR		:=	bin/checker

# rush01
NAME		:=	rush-01
SRCS		:=	main.c validate.c rush01.c
OBJS		:=	$(SRCS:%.c=$(BIN)/%.o)
SRCS		:=	$(addprefix ex00/, $(SRCS))

# checker
CKR			:=	checker
CKR_SRCS	:=	checker/checker.c checker/helper.c checker/parse_grid.c\
				checker/print_grid.c validate.c rush01.c
CKR_OBJS	:=	$(CKR_SRCS:%.c=$(BIN)/%.o)
CKR_SRCS	:=	$(addprefix ex00/, $(CKR_SRCS))

all: $(NAME) $(CKR)

$(NAME): $(BIN) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CKR): $(BIN) $(CKR_DIR) $(CKR_OBJS)
	$(CC) $(CFLAGS) $(CKR_OBJS) -o $(CKR)

$(BIN):
	mkdir $(BIN)

$(CKR_DIR):
	mkdir $(CKR_DIR)

$(BIN)/%.o: ex00/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(BIN)/%.o: ex00/checker/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	$(RM) -r $(BIN)
	$(RM) $(NAME)
	$(RM) $(CKR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

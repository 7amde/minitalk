CLIENT = client.o

SERVER = server.o

UTILS = utils.o

CLIENT_B = client_bonus.o

SERVER_B = server_bonus.o

SRC = client.c server.c utils.c

SRC_BONUS = client_bonus.c server_bonus.c utils.c

CLIENT_NAME = client

SERVER_NAME = server

CLIENT_NAME_B = client_bonus

SERVER_NAME_B = server_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(CLIENT_NAME) $(SERVER_NAME)
		

bonus: $(CLIENT_NAME_B) $(SERVER_NAME_B)
		

$(CLIENT_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIENT) $(UTILS) -o $@
	
$(SERVER_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SERVER) $(UTILS) -o $@

$(CLIENT_NAME_B): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_B) $(UTILS) -o $@
	
$(SERVER_NAME_B): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(SERVER_B) $(UTILS) -o $@

clean:
	@$(RM) server.o client.o
	@$(RM) server_bonus.o client_bonus.o utils.o

fclean:
	@make -C ./ clean
	@$(RM) server client server_bonus client_bonus utils.o

re:
	@make fclean
	@make all

.PHONY:	all bonus clean fclean re norm
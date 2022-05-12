# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dvan-kri <dvan-kri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/02 16:45:56 by dvan-kri      #+#    #+#                  #
#    Updated: 2022/05/12 15:49:18 by dvan-kri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c time.c utils.c threads.c time.c act.c error.c init.c

SRC_FILES = $(addprefix $(SRCDIR)/,$(SRCS))

SRCDIR = srcs

OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

OBJDIR = objs

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c  $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

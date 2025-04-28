MAKEFLAGS		:=	--no-print-directory
.DEFAULT_GOAL	:=	all

.SECONDEXPANSION:

#=================================COMPILATION==================================#
CC					:=	g++
CPPFLAGS			:=	-MP -MMD -I includes -g3
LIBFSMLFLAG			:=	-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
#==================================VARIABLES===================================#
ID					:= 0

#=====================================NAME=====================================#
NAME	:=	MiniTankInterface

#==================================DIRECTORIES=================================#
BUILD				:= build


EXEC_DIR_LINUX		:=	linux_executable/
EXEC_LINUX			:=	$(EXEC_DIR_LINUX)$(NAME)

#====================================TARGETS===================================#
SRCS	:=	srcs/main.cpp \
			srcs/Tank.cpp \
			srcs/Interface.cpp \
			srcs/utils.cpp \
			srcs/Projectile.cpp \
			srcs/ProjectileAP.cpp \
			srcs/ProjectileAPCR.cpp \
			srcs/ProjectileHE.cpp \
			srcs/ProjectileHEAT.cpp \
			srcs/ProjectileManager.cpp \

OBJS 	:=	${SRCS:srcs/%.cpp=$(BUILD)/%.o}
DEPS	:=	$(SRCS:srcs/%.cpp=$(BUILD)/%.d)
DIRS	:=	$(BUILD)

#====================================COLORS====================================#
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLINK		= \e[5m
BLACK		= \033[1;30m
RED			= \e[1m;31m;
GREEN		= \e[1m;32m;
YELLOW		= \e[1m;33m;
RED			= \e[1m\e[38;5;196m
GREEN		= \e[1m\e[38;5;76m
YELLOW		= \e[1m\e[38;5;220m
BLUE		= \e[1m\e[38;5;33m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

#=================================COUNTER UTILS================================#
NB_COMPIL		:=	0

ifndef WIN
ifndef	RECURSIVE
TOTAL_COMPIL		:=	$(shell expr $$(make -n RECURSIVE=1 | grep $(CC) | wc -l) - 1)
endif
endif
ifndef TOTAL_COMPIL
TOTAL_COMPIL		:=	$(words $(OBJS))
endif

#=====================================RULES====================================#
$(DIRS):
	@mkdir $@

$(OBJS) : $(BUILD)/%.o : srcs/%.cpp | $$(@D)
	$(if $(filter $(NB_COMPIL),0), @echo "$(BLUE)Compiling$(NOC)")
	$(eval NB_COMPIL=$(shell expr $(NB_COMPIL) + 1))
	@echo "$(WHITE)[$(NB_COMPIL)/$(TOTAL_COMPIL)] $(VIOLET)Compiling $< $(NOC)"
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(EXEC_LINUX): $(OBJS)
	@echo "$(BLUE)Creation of binary$(NOC)"
	@mkdir $(EXEC_DIR_LINUX) 2>/dev/null || echo -n
	@g++ $^ $(LIBFSMLFLAG) -o $(EXEC_LINUX)
	@echo "$(GREEN)Done$(NOC)"

all : $(EXEC_LINUX)

clean :
	@echo "$(RED)Deleting objects$(NOC)"
	@rm -rf $(BUILD) 2>/dev/null || echo -n

fclean : clean
	@echo "$(RED)Deleting binary$(NOC)"
	@rm -f $(EXEC_LINUX)
	@rmdir $(EXEC_DIR_LINUX) 2>/dev/null || echo -n

re :
	@clear
	@make fclean
	@make

run: $(EXEC_LINUX)
	@echo "$(BLUE)Launch game$(NOC)"
	@cd $(EXEC_DIR_LINUX) && ./$(NAME) $(ID)
	@echo "$(GREEN)Have a nice day :)$(NOC)"

runval: $(EXEC_LINUX)
	@echo "$(BLUE)Debug$(NOC)"
	@cd $(EXEC_DIR_LINUX) && valgrind ./$(NAME)

install:
	@sudo apt install libsfml-dev -y

.PHONY : all clean fclean re forcerun run runval

-include $(DEPS)

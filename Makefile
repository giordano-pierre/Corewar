##
## EPITECH PROJECT, 2023
## B-CPE-200-LYN-2-1-corewar-pierre.giordano
## File description:
## Makefile
##

#COLORS
RED			=	\e[31m
GREEN		=	\e[32m
YELLOW		=	\e[33m
DEFAULT		=	\e[0m
BOLD		=	\e[1m
VIOLET		=	\e[35m

#MSG
NICE = $$'$(BOLD)$(GREEN)[The coding style logs : ]\t$(DEFAULT)'
NICE_END = $$'$(BOLD)$(GREEN)[Coding style logs end ! ]\t$(DEFAULT)'
NICE_SUP =$$'$(BOLD)$(YELLOW)[Please press -> y <- for clean logs.]\t$(DEFAULT)'
NICE_DESTROY = $$'$(BOLD)$(RED)[The logs are cleaned !]\t$(DEFAULT)'
COMPILE = $$'$(BOLD)$(GREEN)[All the project are compiled !]\t$(DEFAULT)'

#SHORTCUTS
RM = rm -Rf

ASM_CREATE = cd asm && make && cd ../
ASM_UNITS = cd asm && make tests_run && cd ../
ASM_DESTROY = cd asm && make fclean && cd ../

CORWAR_CREATE = cd corewar && make && cd ../
CORWAR_UNITS = cd corewar && make tests_run && cd ../
CORWAR_DESTROY = cd corewar && make fclean && cd ../

CODING_STYLE = coding-style . .
CODING_STYLE_MORE = cat coding-style-reports.log
CODING_DESTROY = rm coding-style-reports.log

LIB_PRINTF		=	-L lib/printf/. -lprintf
PRINTF_CREATE	= lib/printf && make && cd ../../
PRINTF_CLEAN	= lib/printf && make fclean && cd ../../

#RULES
all:
	@cd $(PRINTF_CREATE)
	@$(ASM_CREATE)
	@$(CORWAR_CREATE)
	@cd $(PRINTF_CLEAN)
	@echo $(COMPILE)

clean:
	@$(RM) solver/solver
	@$(RM) generator/generator

fclean:	clean
	@$(ASM_DESTROY)
	@$(CORWAR_DESTROY)

re: fclean all

tests_run:
	@$(ASM_UNITS)
	@$(CORWAR_UNITS)

nice:
	@$(CODING_STYLE)
	@echo $(NICE)
	@$(CODING_STYLE_MORE)
	@echo $(NICE_END)
	@echo $(NICE_SUP)
	@$(CODING_DESTROY)
	@echo $(NICE_DESTROY)

.PHONY: all, clean, fclean, re

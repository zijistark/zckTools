#!/usr/bin/make
# PURPOSE: Makefile Demo Application of Quex
#
# ABSOLUTELY NO WARRANTY
#_______________________________________________________________________________
.PHONY: clean
.SECONDARY:

ifndef QUEX_PATH
    $(error The environment variable QUEX_PATH is not defined!)
endif
ifdef ASSERTS_ENABLED_F
	CCFLAG_ASSERTS=# By default asserts are disabled
else 
	CCFLAG_ASSERTS=-DQUEX_OPTION_ASSERTS_DISABLED
endif

# (*) COMPILER SETTINGS ________________________________________________________
#     (change COMPILER to whatever you use as compiler on the command line,
#      e.g. "make COMPILER=icpc" will use intel's c++ compiler)
COMPILER = g++ -ggdb -Wconversion -Wall -Werror -W --std=c++17

CC = $(COMPILER) -c -I./ -I./lexer/ $(CCFLAG_ASSERTS) 
# Other useful options for debugging:
# -DQUEX_OPTION_ASSERTS_DISABLED
# -DQUEX_OPTION_ASSERTS_WARNING_MESSAGE_DISABLED 
# -DQUEX_OPTION_DEBUG_SHOW
   
LD = $(COMPILER) 

# (*) RULES ____________________________________________________________________
#
test_lexer: test_lexer.o lexer/Lexer.o
	$(LD) -o $@ test_lexer.o lexer/Lexer.o 
          
lexer/Lexer.o: lexer/Lexer.cpp 
	$(CC) $< -o $@ 

test_lexer.o: test_lexer.cpp lexer/Lexer.cpp
	$(CC) $< -o $@ 

lexer/Lexer.cpp: zck.qx 
	quex -i zck.qx -o Lexer --token-id-prefix TK_ --encoding cp1252 -b 1 --source-package lexer

# Macro expansions (only for debugging):
%.E: %.cpp    
	$(CC) -E $< -o $@ 

clean:	
	rm -f Lexer*
	rm -f *.o
	rm -f *.bak
	rm -f *.E
	rm -fr lexer/*
	rm -f test_lexer test_lexer.exe

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

CCFLAG_ASSERTS=-DQUEX_OPTION_ASSERTS_DISABLED

# (*) COMPILER SETTINGS ________________________________________________________
#     (change COMPILER to whatever you use as compiler on the command line,
#      e.g. "make COMPILER=icpc" will use intel's c++ compiler)
COMPILER = g++ -g0 -Os -Wall -Wconversion -Wno-register -std=c++17

QUEX_DEFINES = $(CCFLAG_ASSERTS)
# Other useful options for debugging:
# -DQUEX_OPTION_ASSERTS_DISABLED
# -DQUEX_OPTION_ASSERTS_WARNING_MESSAGE_DISABLED 
# -DQUEX_OPTION_DEBUG_SHOW

CC = $(COMPILER) -c -I./ -I./lexer/ $(QUEX_DEFINES)

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
	$(QUEX_PATH)/quex-exe.py -i zck.qx -o Lexer --sma --token-id-prefix T_ --encoding cp1252 --sp lexer

# Macro expansions (only for debugging):
lexer/%.E: lexer/%.cpp    
	$(CC) -E $< -o $@ 

clean:	
	rm -f Lexer*
	rm -f *.o
	rm -f *.bak
	rm -f *.E
	rm -fr lexer/*
	rm -f test_lexer test_lexer.exe

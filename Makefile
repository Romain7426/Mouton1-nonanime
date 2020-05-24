
default: Makefile build build/nonanime.a 




SHELL:= /bin/sh
.SHELLFLAGS: -u -e  
#MAKEFLAGS:= s --warn-undefined-variables 
#MAKEFLAGS:= s 
.SUFFIXES: 
#.SILENT:
.NOTPARALLEL:
.EXPORT_ALL_VARIABLES:
.SECONDARY:
.PRECIOUS:
.ONESHELL:




clean:
	rm -Rf build 2>&1

clean-all: clean
	rm -Rf destroot rundir *~ .*~ src/*~ src/*.output COPYING_at_start_of_c_files src/nonanime.parser.tab.c src/nonanime.parser.code.c src/nonanime.parser.tab.h src/nonanime.parser.code.h src/nonanime.lexer.c 2>&1


Makefile: Makefile-gen.mkf
	@echo "--- \"Makefile-gen.mkf\" changed. Please type './configure' (or 'romake -f Makefile-gen.mkf') to update this Makefile ---"
	@false

build:
	mkdir -p build 2>&1 


install: destroot_do

destroot_do:
	rm -Rf destroot
	mkdir -p destroot
	mkdir -p destroot/lib
	cp -fp build/nonanime.a destroot/lib/
	mkdir -p destroot/include/nonanime
	cp -fp src/nonanime.h destroot/include/nonanime/








run: build/nonanime.exe
	rm -f run
	ln -s build/nonanime.exe run


build/nonanime.exe: build/nonanime.a
	cc -o build/nonanime.exe build/nonanime.a -lm  2>&1


build/nonanime.a: build/nonanime.o build/nonanime.global.o build/nonanime.lexer.o build/nonanime.parser.tab.o build/nonanime.parser.code.o build/nonanime.lexer.o
	ar -r -c build/nonanime.a build/nonanime.o build/nonanime.global.o build/nonanime.lexer.o build/nonanime.parser.tab.o build/nonanime.parser.code.o build/nonanime.lexer.o 2>&1
	ranlib build/nonanime.a 2>&1









#src/nonanime.parser.c: src/nonanime.parser.y 
src/nonanime.parser.tab.h src/nonanime.parser.tab.c src/nonanime.parser.code.c: src/nonanime.parser.y 
#	bison --report=all,state,look-ahead,itemset --token-table --debug -d  src/nonanime.parser.y -o src/nonanime.parser.c 2>&1
#	yacc -d -t -p yynonanime -r -v  -o src/nonanime.parser.c src/nonanime.parser.y 2>&1
	yacc -d -t -p yynonanime -r -v  -b src/nonanime.parser src/nonanime.parser.y 2>&1
#	mv -f parser.c src/nonanime.parser.c 2>&1 || true 
#	mv -f nonanime.parser.c src/nonanime.parser.c 2>&1 || true
#	test -e src/nonanime.parser.c 2>&1






src/nonanime.lexer.c: src/nonanime.lexer.l 
	flex -Pyynonanime -Cfa -p  -o src/nonanime.lexer.c src/nonanime.lexer.l 2>&1
	test -e src/nonanime.lexer.c 2>&1






build/nonanime.o: src/nonanime.c src/nonanime.global.h src/nonanime.h src/nonanime.lexer.h src/nonanime.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced    -c src/nonanime.c -o build/nonanime.o  2>&1

build/nonanime.global.o: src/nonanime.global.c src/nonanime.global.h src/nonanime.h src/nonanime.lexer.h src/nonanime.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced    -c src/nonanime.global.c -o build/nonanime.global.o  2>&1

build/nonanime.lexer.o: src/nonanime.lexer.c src/nonanime.global.h src/nonanime.h src/nonanime.lexer.h src/nonanime.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced    -c src/nonanime.lexer.c -o build/nonanime.lexer.o  2>&1

build/nonanime.parser.code.o: src/nonanime.parser.code.c src/nonanime.global.h src/nonanime.h src/nonanime.lexer.h src/nonanime.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced    -c src/nonanime.parser.code.c -o build/nonanime.parser.code.o  2>&1

build/nonanime.parser.tab.o: src/nonanime.parser.tab.c src/nonanime.global.h src/nonanime.h src/nonanime.lexer.h src/nonanime.parser.tab.h
	cc -std=c99 -D_THREAD_SAFE -D_REENTRANT -D __DEBUG__ -D DEBUG  -O0 -Wall -fmessage-length=0 -fdiagnostics-show-location=once -fdiagnostics-show-option -Wnewline-eof -Wfatal-errors -Werror-implicit-function-declaration -fno-exceptions -fstack-check -Werror -W  -Wparentheses -fverbose-asm -fno-omit-frame-pointer -ffreestanding -fno-builtin -fno-builtin-printf -fno-builtin-abs -fno-builtin-strcpy -fno-builtin-strcat -fno-builtin-strlen -fno-builtin-bzero -fno-builtin-memset -fno-builtin-memcpy -fno-builtin-assert -fno-builtin-tolower -fno-builtin-toupper -fno-builtin-log -fno-builtin-alloca -fno-common -fno-exceptions -fno-non-call-exceptions -fno-asynchronous-unwind-tables -fno-inline -fno-inline-functions -fno-inline-functions  -gfull  -feliminate-unused-debug-types  -Wimplicit -Wreturn-type -Wcomment -Wpointer-arith -Wchar-subscripts -Wimplicit-int -Werror-implicit-function-declaration -Wmain -Wmissing-braces -Wmultichar -Wsequence-point -Wreturn-type  -Wstrict-prototypes -Wpacked -Wcast-qual -Wcast-align -Wno-system-headers -Winline -Wformat-nonliteral -Wwrite-strings -Wmissing-field-initializers -Wsign-compare  -Wformat-zero-length -Wswitch -Wswitch-enum -Wswitch-default -Wnested-externs -Wunknown-pragmas -Wno-undef -Wno-redundant-decls -Wno-unused -Wno-unused-parameter -Wno-unused-function -Wno-switch-default -Wno-format-nonliteral -Wno-unsequenced    -c src/nonanime.parser.tab.c -o build/nonanime.parser.tab.o  2>&1
















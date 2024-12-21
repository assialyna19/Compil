flex lexical.l
bison -d syntaxique.y
gcc syntaxique.tab.c lex.yy.c -o synt.exe -lfl -ly
synt.exe<test.txt

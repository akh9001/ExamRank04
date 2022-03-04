# #!/bin/bash

# test_line () {
# 	echo $@
# 	echo $@ >> out.res
# 	./microshell $@ >> out.res &
# 	sleep .250
# 	echo >> out.res
# 	leaks microshell > leaks.res 2> /dev/null
# 	if grep "ROOT LEAK" < leaks.res > /dev/null 2> /dev/null ; then
# 		printf "\e[0;31mLEAKS\n\e[0m"
# 	fi
# 	pid=$( pgrep microshell )
# 	printf "\e[0;31m"
# 	lsof -c microshell | grep $pid | grep -v cwd | grep -v txt | grep -v 0r | grep -v 1w | grep -v 2u | grep microshel
# 	printf "\e[0m"
# 	kill -9 $pid
# 	wait $pid 2>/dev/null
# 	#cat -e out.res > out
# }

# printf "\e[1;32mCompile\n"
# gcc -g -Wall -Werror -Wextra -DTEST_SH microshell.c -o microshell
# printf "\e[1;36mTest\n\e[0m"
# rm -f out.res leaks.res out
# test_line /bin/ls
# test_line /bin/cat microshell.c
# test_line /bin/ls microshell.c
# test_line /bin/ls salut
# test_line ";"
# test_line ";" ";"
# test_line ";" ";" /bin/echo OK
# test_line ";" ";" /bin/echo OK ";"
# test_line ";" ";" /bin/echo OK ";" ";"
# test_line ";" ";" /bin/echo OK ";" ";" ";" /bin/echo OK
# test_line /bin/ls "|" /usr/bin/grep microshell
# test_line /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro
# test_line /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro
# test_line /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell
# test_line /bin/ls ewqew "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo
# test_line /bin/ls "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo ftest ";"
# test_line /bin/echo ftest ";" /bin/echo ftewerwerwerst ";" /bin/echo werwerwer ";" /bin/echo qweqweqweqew ";" /bin/echo qwewqeqrtregrfyukui ";"
# test_line /bin/ls ftest ";" /bin/ls ";" /bin/ls werwer ";" /bin/ls microshell.c ";" /bin/ls subject.fr.txt ";"
# test_line /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";"
# test_line /bin/cat subject.fr.txt "|" /usr/bin/grep a "|" /usr/bin/grep b ";" /bin/cat subject.fr.txt ";"
# test_line /bin/cat subject.fr.txt "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat subject.fr.txt ";"
# test_line /bin/cat subject.fr.txt "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat subject.fr.txt
# test_line /bin/cat subject.fr.txt ";" /bin/cat subject.fr.txt "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat subject.fr.txt
# test_line ";" /bin/cat subject.fr.txt ";" /bin/cat subject.fr.txt "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat subject.fr.txt
# test_line blah "|" /bin/echo OK
# test_line blah "|" /bin/echo OK ";"
# printf "\e[1;32mDone\e[0m\n"
# rm -rf microshell.dSYM leaks.res
#!/bin/bash
clang microshell.c -o microshell -Wall -Wextra -Werror
echo Fuck minishell

./microshell /bin/ls
./microshell /bin/cat microshell.c
./microshell /bin/ls microshell.c
./microshell /bin/ls salut
./microshell ";"
./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"
./microshell ";" ";" /bin/echo OK
./microshell ";" ";" /bin/echo OK ";"
./microshell ";" ";" /bin/echo OK ";" ";"
./microshell ";" ";" /bin/echo OK ";" ";" ";" /bin/echo OK
./microshell /bin/ls "|" /usr/bin/grep microshell
./microshell /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro
./microshell /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro
./microshell /bin/ls "|" /usr/bin/grep microshell "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep micro "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell "|" /usr/bin/grep shell
./microshell /bin/ls ewqew "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo
./microshell /bin/ls "|" /usr/bin/grep micro "|" /bin/cat -n ";" /bin/echo dernier ";" /bin/echo ftest ";"
./microshell /bin/echo ftest ";" /bin/echo ftewerwerwerst ";" /bin/echo werwerwer ";" /bin/echo qweqweqweqew ";" /bin/echo qwewqeqrtregrfyukui ";"
./microshell /bin/ls ftest ";" /bin/ls ";" /bin/ls werwer ";" /bin/ls microshell.c ";" /bin/ls subject.fr.txt ";"
./microshell /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";" /bin/ls "|" /usr/bin/grep micro ";"
./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b ";" /bin/cat reserv_microsh.c ";"
./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat reserv_microsh.c ";"
./microshell /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep w ";" /bin/cat reserv_microsh.c
./microshell /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat reserv_microsh.c
./microshell ";" /bin/cat reserv_microsh.c ";" /bin/cat reserv_microsh.c "|" /usr/bin/grep a "|" /usr/bin/grep b "|" /usr/bin/grep z ";" /bin/cat reserv_microsh.c
./microshell blah "|" /bin/echo OK
./microshell blah "|" /bin/echo OK ";"
./microshell /bin/ls . "|" /usr/bin/grep micro "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e ";" /bin/echo OK ";"
./microshell cd ";" /bin/ls . "|" /usr/bin/grep micro "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e "|" /bin/cat -e  
./microshell ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" blah "|" /bin/echo OK ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";" ";"

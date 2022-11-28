#!/bin/bash

#compile the program
cc main.c libftprintf.a
# -Wall -Wextra -Werror

#Check if the program compiled correctly
if [ $? -eq 0 ]; then
	rm my_input.txt
	touch my_input.txt

	#execute norminette on all files in the directory and don't print the output
	norminette | grep Error >norminette_error.txt

	#if norminette_error.txt is empty, then there are no errors and execute the program
	if [ ! -s norminette_error.txt ]; then
		#write norminette OK on green
		echo -e "\e[32mNorminette OK\e[0m"
		./a.out
	else
		#write norminette KO on red
		echo -e "\e[31mNorminette KO\e[0m"
		./a.out
	fi

	while read line1 && read line2 <&3; do
		if [ "$line1" = "$line2" ]; then
			printf "%-50s %-50s \e[32mOK\e[0m" "$line1" "$line2"
			echo ""
		else
			printf "%-50s %-50s \e[31mKO\e[0m" "$line1" "$line2"
			echo ""
		fi
	done <my_input.txt 3<test.txt
else #if the program didn't compile correctly
	echo -e "\e[31mCompilation error\e[0m"
fi


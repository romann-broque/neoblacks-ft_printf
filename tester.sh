#!/bin/bash

clear
#Check if libftprintf.a exists else make
if [ ! -f libftprintf.a ]; then
	make
	clear
fi
#compile the program

cc -w main.c libftprintf.a
# -Wall -Wextra -Werror

#Check if the program compiled correctly
if [ $? -eq 0 ]; then
	rm my_input.txt
	touch my_input.txt

	#execute norminette on all files in the directory and don't print the output
	norminette | grep Error >norminette_error.txt
	#Write header ascii art to file and print it
	echo -e "\033[31m           0000\033[0m_____________0000________0000000000000000__000000000000000000+\n\033[31m         00000000\033[0m_________00000000______000000000000000__0000000000000000000+\n\033[31m        000\033[0m____000_______000____000_____000_______0000__00______0+\n\033[31m       000\033[0m______000_____000______000_____________0000___00______0+\n\033[31m      0000\033[0m______0000___0000______0000___________0000_____0_____0+\n\033[31m      0000\033[0m______0000___0000______0000__________0000___________0+\n\033[31m      0000\033[0m______0000___0000______0000_________000___0000000000+\n\033[31m      0000\033[0m______0000___0000______0000________0000+\n\033[31m       000\033[0m______000_____000______000________0000+\n\033[31m        000\033[0m____000_______000____000_______00000+\n\033[31m         00000000\033[0m_________00000000_______0000000+\n\033[31m           0000\033[0m_____________0000________000000007;"
	echo "Printf Tester by: amugnier"
	echo ""
	echo ""
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
		#Center the ok or ko in right column even whitespace and print what i want test and what it should be
			printf "%-50s %-50s \e[32mOK\e[0m \n" "$line1" "$line2"
			sleep 0.05
		else
			printf "%-50s %-50s \e[31mKO\e[0m \n" "$line1" "$line2"
			sleep 0.05
		fi
	done <my_input.txt 3<test.txt
else #if the program didn't compile correctly
	echo -e "\e[31mCompilation error\e[0m"
fi


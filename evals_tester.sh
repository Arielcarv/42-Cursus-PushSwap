#!/bin/bash

BLACK='\033[0;30m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
GREEN='\033[0;32m'
MAGENTA='\033[1;35m'
ORANGE='\033[1;38;5;214m'
RED='\033[0;31m'
RESET='\033[0m'
WHITE='\033[0;37m'
YELLOW='\033[0;33m'

printf " $MAGENTA MEMORY LEAKS $RESET \n"
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 0


printf "\n $MAGENTA -> ERROR MANAGEMENT $RESET \n"
printf "$CYAN Run push_swap with non numeric parameters. The program must display \"Error\".$RESET\n"
./push_swap 123 q 4

printf "$CYAN Run push_swap with a duplicate numeric parameter. The program must display \"Error\".$RESET\n"
./push_swap 1 2 3 4 5 1

printf "$CYAN Run push_swap with only numeric parameters including one greater than MAXINT. The program must display \"Error\".$RESET\n"
./push_swap 1 2 3 4 5 2147483648

printf "$CYAN Run push_swap without any parameters. The program must not display anything and give the prompt back.$RESET\n"
./push_swap 


printf "$MAGENTA\n -> PUSH SWAP - IDENTITY TEST $RESET \n"
printf "$CYAN Run the following command \"$>./push_swap 42\". The program should display nothing (0 instruction).$RESET\n"
./push_swap 42

printf "$CYAN Run the following command \"$>./push_swap 2 3\". The program should display nothing (0 instruction).$RESET\n"
./push_swap 2 3

printf "$CYAN Run the following command \"$>./push_swap 0 1 2 3\". The program should display nothing (0 instruction).$RESET\n"
./push_swap 0 1 2 3

printf "$CYAN Run the following command \"$>./push_swap 0 1 2 3 4 5 6 7 8 9\". The program should display nothing (0 instruction).$RESET\n"
./push_swap 0 1 2 3 4 5 6 7 8 9

printf "$CYAN Run the following command \"$>./push_swap <Between 0 and 9 randomly sorted values chosen>\". The program should display nothing (0 instruction).$RESET\n"
./push_swap 3 4 5 6 7


printf "$MAGENTA\n -> PUSH SWAP - SIMPLE VERSION $RESET \n"
printf "$CYAN Run \"$>ARG=\"2 1 0\"; ./push_swap $ARG | ./checker_linux $ARG\". Check that the checker program displays \"OK\" and that the size of the list of instructions from push_swap is 2 OR 3. Otherwise the test fails. $RESET\n"
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG

printf "$CYAN Run \"$>ARG=\"Between 0 and 3 randomly values chosen\"; ./push_swap $ARG | ./checker_linux $ARG\". Check that the checker program displays \"OK\" and that the size of the list of instructions from push_swap is between 0 AND 3. Otherwise the test fails. $RESET\n"
ARG="3 1 2"; ./push_swap $ARG | ./checker_linux $ARG


printf "$MAGENTA\n -> ANOTHER SIMPLE VERSION $RESET \n"
printf "$CYAN Run \"$>ARG=\"1 5 2 4 3\"; ./push_swap $ARG | ./checker_linux $ARG\". Check that the checker program displays \"OK\" and that the size of the list of instructions from push_swap isn't more than 12. Kudos if the size of the list of instructions is 8. $RESET \n"
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG

printf "$CYAN Run \"$>ARG=\"<5 random values>\"; ./push_swap $ARG | ./checker_linux $ARG\" and replace the placeholder by 5 random valid values. Check that the checker program displays \"OK\" and that the size of the list of instructions from push_swap isn't more than 12. Otherwise this test fails. You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it. $RESET \n"
ARG="5 2 1 4 3"; ./push_swap $ARG | ./checker_linux $ARG


printf "$MAGENTA\n -> PUSH SWAP - MIDDLE VERSION $RESET \n"
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1000), 100))) )"); ./push_swap $ARG | ./checker_linux $ARG

printf "$MAGENTA\n -> PUSH SWAP - ADVANCED VERSION $RESET \n"
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1000), 500))) )"); ./push_swap $ARG | ./checker_linux $ARG


printf "$MAGENTA\n -> BONUS $RESET \n"
printf "$MAGENTA\n -> BONUS - CHECKER PROGRAM - ERROR MANAGEMENT $RESET \n"
printf "$CYAN Run checker with non numeric parameters. The program must display \"Error\" $RESET. \n"
./checker 1 2 3 4 5a

printf "$CYAN Run checker with a duplicate numeric parameter. The program must display \"Error\" $RESET. \n"
./checker 1 2 3 4 5 1

printf "$CYAN Run checker with only numeric parameters including one greater than MAXINT. The program must display \"Error\" $RESET. \n"
./checker 1 2 3 4 5 2147483648

printf "$CYAN Run checker without any parameters. The program must not display anything and give the prompt back $RESET. \n"
./checker

printf "$CYAN Run checker with valid parameters, and write an action that doesn't exist during the instruction phase. The program must display \"Error\" $RESET. \n"
./checker 3 1 2

printf "$CYAN Run checker with valid parameters, and write an action with one or several spaces before and/or after the action during the instruction phase. The program must display \"Error\" $RESET. \n"
./checker 5 1 3 4 2


printf "$MAGENTA\n -> BONUS - CHECKER PROGRAM - FALSE TESTS $RESET \n"
printf "$CYAN Run checker with the following command \"$>./checker 0 9 1 8 2 7 3 6 4 5\" then write the following valid action list \"[sa, pb, rrr]\". Checker should display \"KO\". $RESET \n"
./checker 0 9 1 8 2 7 3 6 4 5

printf "$CYAN Run checker with a valid list as parameter of your choice then write a valid instruction list that doesn't order the integers. Checker should display \"KO\". You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it. $RESET \n"
./checker 0 9 1 8 2 7 3 6 4 5


printf "$MAGENTA\n -> BONUS - CHECKER PROGRAM - RIGHT TESTS $RESET \n"
printf "$CYAN Run checker with the following command \"$>./checker 0 1 2\" then press CTRL+D without writing any instruction. The program should display \"OK\". $RESET \n"
./checker 0 1 2

printf "$CYAN Run checker with the following command \"$>./checker 0 9 1 8 2\" then write the following valid action list \"[pb, ra, pb, ra, sa, ra, pa, pa]\". The program should display \"OK\". $RESET \n"
./checker 0 9 1 8 2

printf "$CYAN Run checker with a valid list as parameter of your choice then write a valid instruction list that order the integers. Checker must display \"OK\". You'll have to specifically check that the program wasn't developed to only answer correctly on the test included in this scale. You should repeat this test couple of times with several permutations before you validate it. ARG=0 2 1 3 [pb, sa, pa] $RESET \n"
./checker 0 2 1 3


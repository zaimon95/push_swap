#!/bin/bash

BIN=./push_swap # ou ./push_swap

GREEN="\033[0;32m"

RED="\033[0;31m"

NC="\033[0m"

tests=(

	"1 2 3|OK"

	" 1 2 3 |OK"

	"   1   2   3   |OK"

	"0|OK"

	"-1|OK"

	"+1|OK"

	"000|OK"

	"0000000001|OK"

	"-0000000001|OK"

	"2147483647|OK"

	"-2147483648|OK"

	"1 -2 +3 4|OK"

	"42|OK"

	"+|ERROR"

	"-|ERROR"

	"++1|ERROR"

	"--1|ERROR"

	"+-1|ERROR"

	"1+|ERROR"

	"1-|ERROR"

	"1 2a 3|ERROR"

	"a|ERROR"

	"1 a|ERROR"

	"1	2|ERROR"

	"1\n2|ERROR"

	"2147483648|ERROR"

	"-2147483649|ERROR"

	"9999999999|ERROR"

	"-9999999999|ERROR"

	"100000000000|ERROR"

	"1 1|ERROR"

	"1 2 1|ERROR"

	"0001 1|ERROR"

	"-0 0|ERROR"

	"+1 1|ERROR"

	" |ERROR"

	"    |ERROR"

	"|ERROR"

	"  +0000000000  |OK"

	"  -0000000000  |OK"

)

# echo "====== PARSING TESTS ======"

# for test in "${tests[@]}"; do

#   input="${test%%|*}"

#   expected="${test##*|}"

#   echo

#   echo "TEST: \"$input\" (expected: $expected)"

#   output=$($BIN "$input" 2>&1)

#   status=$?

#   has_error=0

#   if echo "$output" | grep -q "^Error$"; then

#     has_error=1

#   fi

#   if [[ "$expected" == "ERROR" && $has_error -eq 1 ]]; then

#     echo -e "${GREEN}✅ OK (Error detected)${NC}"

#   elif [[ "$expected" == "OK" && $has_error -eq 0 && $status -eq 0 ]]; then

#     echo -e "${GREEN}✅ OK (No Error)${NC}"

#   else

#     echo -e "${RED}❌ FAIL${NC}"

#     echo "Output:"

#     echo "$output"

#     echo "Exit code: $status"

#   fi

# done

echo "====== PARSING + VALGRIND ======"

for test in "${tests[@]}"; do

	input="${test%%|*}"

	expected="${test##*|}"

	echo

	echo "TEST: \"$input\" (expected: $expected)"

	vg_out=$(
		valgrind --leak-check=full --errors-for-leak-kinds=all

		--error-exitcode=42

		$BIN "$input" 2>&1
	)

	status=$?

	has_error=$(echo "$vg_out" | grep -c "^Error$")

	if [[ "$expected" == "ERROR" && $has_error -eq 1 && $status -ne 42 ]]; then

		echo -e "${GREEN}✅ OK (Error + no leaks)${NC}"

	elif [[ "$expected" == "OK" && $status -eq 0 ]]; then

		echo -e "${GREEN}✅ OK (No Error + no leaks)${NC}"

	else

		echo -e "${RED}❌ FAIL${NC}"

		echo -e "${YELLOW}Valgrind output:${NC}"

		echo "$vg_out"

	fi

done

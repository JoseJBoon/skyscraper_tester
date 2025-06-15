 #!/bin/bash

# COLORS
RED="\033[0;31m"
GRN="\033[0;32m"
YLW="\033[1;33m"
CLR="\033[0m"

# VARIABLES
SKY_GRID=grid
OUT=test_result
MAX_COL=10
ECHO="echo -ne"

rm -f $OUT

test_skyscrapper() {
	local CUR_COL=0
	$ECHO $YLW$1$CLR
	while IFS= read -r line; do
		./rush-01 "$line" &> $SKY_GRID
		./checker "$line" < $SKY_GRID 2>> test_result
		if [ "$?" -eq 0 ]; then
			$ECHO $GRN"[OK] "$CLR
		else
			$ECHO $RED"[KO] "$CLR
		fi
		((++CUR_COL))
		if [ $CUR_COL -eq $MAX_COL ]; then
			$ECHO "\n"
			CUR_COL=0
		fi
	done < $2
	$ECHO "\n"
}

test_skyscrapper "Test valid 4x4 puzzles:\n" "4x4s.txt"
test_skyscrapper "Test invalid inputs:\n" "invalidInput.txt"
# test_skyscrapper "Test bonus inputs:\n" "bonusInput.txt"

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/07 16:09:15 by cgiron            #+#    #+#              #
#    Updated: 2019/06/28 12:21:50 by yforeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

########################## Variables initialization ############################

player1=""
player2=""
n_turns=10
map=""
out_dir=output_tests
map_gen=map_gen/map_gen
vm=./filler_vm
visualizer=visualizer/visual_filler_vm
KEEP_OUTPUT=1
RAND_MAP=1
VISUALIZE=1
RAND_MAP_SIZE="30 25"
p1=0
p2=0
score_p1=0;
score_p2=0;
i=0

################################ Functions #####################################

function usage
{
	printf "usage: test.sh p1 p2 [-n turns] [-m map] [-s width height] [-rkhb]\n\n"
	printf "	-h | --help:	Print this.\n"
	printf "	-n | --turns:	Number of turns.\n"
	printf "	-m | --map:	Give a map to 'test.sh' instead of generating them.\n"
	printf "	-s | --size:	Size of the map to generate if it applies.\n"
	printf "	-d | --delete:	Delete output after turn.\n"
	printf "	-b | --blind:	Do not prompt for visualisation.\n"
}

############################# Options parser ###################################


while [ "$1" != "" ]
do
	OPT=$1
	case $OPT in
		-h | --help )
			usage
			exit 0
			;;
		-n | --turns )
			shift
			n_turns=$1
			;;
		-m | --map )
			shift
			map=$1
			RAND_MAP=0
			;;
		-s | --size )
			shift
			RAND_MAP_SIZE="$1 $2"
			shift
			;;
		-d | --delete )
			KEEP_OUTPUT=0
			;;
		-b | --blind )
			VISUALIZE=0
			;;
		* )
			if [ "$player1" == "" ]; then
				player1=$1
			elif [ "$player2" == "" ]; then
				player2=$1
			fi
			;;
	esac
	shift
done

if [ "$player1" == "" -o "$player2" == "" ]; then
	echo "Error: not enough players"
	exit 1
fi

if [ $VISUALIZE -ne 0 ]; then
	vm="${visualizer}"
fi

################################ Main loop #####################################

mkdir -p $out_dir

while [ $i -lt $n_turns ]
do
	if [ $((i+1)) -lt 10 ]; then
		istr="000$((i+1))"
	elif [ $((i+1)) -lt 100 ]; then
		istr="00$((i+1))"
	elif [ $((i+1)) -lt 1000 ]; then
		istr="0$((i+1))"
	else
		istr="$((i+1))"
	fi
	seed=$(($RANDOM%10000))
	if [ $RAND_MAP -ne 0 ]; then
		$map_gen $RAND_MAP_SIZE > $out_dir/round_"$istr"_map
		map=$out_dir/round_"$istr"_map
	fi
	echo "round" $istr/$n_turns "- seed:" $seed
	total=0
	for j in 1 2
	do
		if [ $j -eq 1 ]; then
			echo "turn a:"
			pstr1=$player1
			pstr2=$player2
		else
			echo "turn b:"
			pstr1=$player2
			pstr2=$player1
		fi
		if [ $VISUALIZE -eq 1 ]; then
			$vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2
		elif [ $KEEP_OUTPUT -eq 0 ]; then
			$vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2 &> /dev/null
		elif [ $j -eq 1 ]; then
			$vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2\
				 &> $out_dir/round_"$istr"_output_a
		else
			$vm -s $seed -f $map -p1 $pstr1 -p2 $pstr2\
			 	 &> $out_dir/round_"$istr"_output_b
		fi
		result=$(cat filler.trace | grep AGAINST | sed -e 's/AGAINST/ /g')
		if [ $j -eq 1 ]; then
			score_p1=$(echo $result | cut -d\  -f1)
			score_p2=$(echo $result | cut -d\  -f2)
		else
			score_p2=$(echo $result | cut -d\  -f1)
			score_p1=$(echo $result | cut -d\  -f2)
		fi
		echo "p1: $score_p1"
		echo "p2: $score_p2"
		if [ $score_p1 -gt $score_p2 ]; then
			((p1++))
			((total++))
		elif [ $score_p2 -gt $score_p1 ]; then
			((p2++))
			((total--))
		fi
	done
	if [ $VISUALIZE -eq 0 ]; then
		if [ $total -eq 2 ]; then
			echo "\033[0;32m$player1 (p1) won the round !\033[0m"
		elif [ $total -eq -2 ]; then
			echo "\033[0;31m$player2 (p2) won the round !\033[0m"
		else
			echo "no clear winer..."
		fi
	fi
	echo
	((i++))
done

echo "final score:"
echo "$player1 (p1): $p1"
echo "$player2 (p2): $p2"

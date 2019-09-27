#! /bin/bash
make
asm(){
local dasm=./resources/asm
local oasm=./asm
local dirc="resources/champs"
local allc=`ls $dirc | grep "\.s" | cut -d '.' -f 1`
if [ $2 == "all" ]
then
	for champ in $allc
	do
		printf "=======\033[36mOUR OUTPUT\033[0m=========\n"
		$oasm $dirc/$champ.s
		if [ -f "$dirc/$champ.cor" ]
		then
			hexdump -vC $dirc/$champ.cor > /tmp/asm_demo
		fi
		printf "=======\033[34mDEF OUTPUT\033[0m=========\n"
		$dasm $dirc/$champ.s
		if [ -f "$dirc/$champ.cor" ]
		then
			hexdump -vC $dirc/$champ.cor > /tmp/asm_our
		fi
		printf "\033[32;1mDIFF\033[0m\n>>>\n\033[33;1m"
		diff /tmp/asm_demo /tmp/asm_our > /tmp/asm_diff
		cat /tmp/asm_diff
		printf "\033[0m<<<\n\n\n"
	done
elif [ $# -eq 2 ]
then
	$dasm $2.s
	hexdump -vC $2.cor > /tmp/asm_demo
	$oasm $2.s
	hexdump -vC $2.cor > /tmp/asm_our
	diff /tmp/asm_demo /tmp/asm_our > /tmp/asm_diff
	cat /tmp/asm_diff
fi
}
corewar(){
local dcw=./resources/corewar
local ocw=./corewar
if [ $# -gt 4 ]
then
chs="$chs $5.cor"
fi
if [ $# -gt 3 ]
then
chs="$chs $4.cor"
fi
if [ $# -gt 2 ]
then
chs="$chs $3.cor"
fi
chs="$chs $2.cor"
if [ $# -gt 0 ]
then
	printf "TEST WITH $chs champions\n"
	$dcw $chs > /tmp/cw_demo
	$ocw $chs > /tmp/cw_our
	diff /tmp/w_demo /tmp/cw_our > /tmp/cw_diff
	cat /tmp/cw_diff
	printf "================\n"
fi
}
if [ $# -gt 1 ]
then
	if [ $1 == "cw" ]
	then
		corewar $@
	elif [ $1 == "asm" ]
	then
		asm $@
	fi
fi

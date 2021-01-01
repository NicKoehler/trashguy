#!/bin/bash

user_input=$1
speed=$2
trash="🗑"
right="(> ^_^)>"
left="<(^_^ <)"
l_space=" "
r_space=" "
user=$right

if [ -z $1 ]
then
    echo "Type $0 followed by some text."
    exit
fi

# if speed is not passed as argument I'll assign 1
if [ -z $2 ]
then
    speed=1
else
    re="^[0-9]+$"
    if ! [[ $2 =~ $re ]]
    then
        echo "Second argument must be speed (Default=1)"
        exit 1
    fi
fi

# this will be the ammount of time between movements
speed=$(awk "BEGIN {print 0.1/$speed}")

print() {
    echo -en "\r$trash$l_space$user$r_space$user_input"
    sleep $speed
}

# looping through the letters
while (( ${#user_input} > 0 ))
do
    # go right
    print
    while ((${#r_space} > 0))
    do
        r_space="${r_space:1}"
        l_space+=" "
        print
    done

    # take the letter
    letter=${user_input:0:1}
    user="$letter$left"
    user_input=${user_input:1}
    r_space+=" "
    l_space=${l_space:1}

    # go left
    print
    while (( ${#l_space} > 0 ))
    do
        l_space=${l_space:1}
        r_space+=" "
        print
    done

    # trash the letter
    user=${user:1}
    r_space+=" "
    print
    user=$right
    print
    l_space+=" "
    r_space=${r_space:1}

done
echo

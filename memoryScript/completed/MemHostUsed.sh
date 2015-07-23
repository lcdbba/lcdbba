#!/bin/sh

top -b -n1 |awk '{print $2, $10, $12}' | tail -n +8 | sort -rk 1 > MemUser.txt

cat MemUser.txt | awk '{print $1}'  > user.txt
sum[0]=0
count=0
echo "USER   USED"
for i in $(sort -u user.txt)
do
	sum[$count]=0
	for j in `cat MemUser.txt | grep $i | awk '{ print $2 }'| grep -v 0.0`
	do
		sum[$count]=`echo "${sum[$count]} + $j" |bc`
	done

	echo "$i" \t     "${sum[$count]}"
	count=`expr $count + 1`
done


rm -f MemUser.txt
rm -f user.txt


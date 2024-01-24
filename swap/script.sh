for ((i = 0; i< 10000; i++))
do
ARG=$(seq 0 99 | sort -R)
./push_swap $ARG | wc -l | awk '{if ($1 > 650) print $1}'
done
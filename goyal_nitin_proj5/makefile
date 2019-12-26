all:
	gcc -o hw5 hw5.c -lm
	./hw5 knapsack01.txt
	gcc -o brute brute.c -lm
	./brute knapsack01.txt
	gcc -o dp dp.c -lm
	./dp knapsack01.txt
	gcc -o backtrack backtrack.c -lm
	./backtrack knapsack01.txt
clean:
	rm -f *.o hw5
	rm -f *.o brute
	rm -f *.o dp
	rm -f *.o backtrack

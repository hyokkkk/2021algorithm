import random
import sys
import time

def randomized_select(arr, i):
	return -1

def linear_select(arr, i):
	return -1

def check(arr, i, x):
	return False

if __name__ == '__main__':
	# Read input.
	input_file = open(sys.argv[1], 'r')
	n, i = map(int, input_file.readline().strip().split(' '))
	arr = list(map(int, input_file.readline().strip().split(' ')))

	# Select i-th element (randomized select).
	x_start = time.time()
	x = randomized_select(arr, i)
	x_finish = time.time()

	# Select i-th element (deterministic select).
	y_start = time.time()
	y = linear_select(arr, i)
	y_finish = time.time()

	# Check correctness.
	x_correct = check(arr, x, i)
	y_correct = check(arr, y, i)

	print(f'randomized select    : {x}{" (CORRECT)" if x_correct else " (WRONG)"} (elapsed time: {x_finish - x_start} sec)')
	print(f'deterministic select : {y}{" (CORRECT)" if y_correct else " (WRONG)"} (elapsed time: {y_finish - y_start} sec)')


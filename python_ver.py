import random
import time

play = True
while play:
    numRange = int(input("Enter a number range (e.g. 100): "))
    amount = int(input("Enter amount of numbers to sort: "))
    unsorted = [random.randint(1, numRange) for x in range(amount)]
    target = sorted(unsorted)
    attempt = []
    timeStart = time.time()
    inputTimeSum = 0
    print(unsorted)
    while True:
        inputTimeStart = time.time()
        toAdd = int(input("Enter number: "))
        attempt.append(toAdd)
        inputTimeSum += time.time() - inputTimeStart
        if len(attempt) == amount:
            break
    timeEnd = time.time()
    errors = 0
    for i in range(amount):
        if target[i] != attempt[i]:
            errors += 1
    score = 5000 - errors * 100
    avgStart = (inputTimeSum / amount)
    print(f"Target: {target}")
    print(f"Attempt: {attempt}")
    print(f"You made {errors} errors ({errors/amount}% error)")
    print(f"You took {(timeEnd - timeStart):.2f} seconds to complete this")
    print(f"You took {avgStart:.2f} seconds on average to enter a number")
    choice = str(input("continue? (Y/N): "))
    if choice.upper() != "Y":
        play = False
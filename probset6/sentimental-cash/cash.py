from sys import exit

def main():
    while True:
        try:
            money = float(input('Change: '))
            if money > 0:
                break
        except ValueError:
            exit

    cents = [0.25, 0.10, 0.05, 0.01]
    dog = 0
    i = 0
    while True:
        if money == 0:
            print(dog)
            break
        elif (money - cents[i]) >= 0:
            money = round(money - cents[i], 2)
            dog += 1
        else:
            i += 1

if __name__ == "__main__":
    main()

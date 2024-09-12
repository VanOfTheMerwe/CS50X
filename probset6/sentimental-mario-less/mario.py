def main():
    while True:
        try:
            height = int(input("Height: "))
            if height >= 1 and height <= 8:
                break
        except ValueError:
            print("Please enter a valid integer.")

    make_pyramid(height)


def make_pyramid(height):
    for i in range(height):
        for x in range(height - i - 1):
            print(" ", end="")
        for y in range(i + 1):
            print("#", end="")
        print()


if __name__ == "__main__":
    main()

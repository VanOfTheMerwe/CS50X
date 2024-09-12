import re


def main():
    txt = str(input('Text: '))
    lttrs = len(re.findall('[a-zA-Z]', txt))
    wrds = len(txt.split())
    sntncs = len(re.findall(r'[.!?]+', txt))
    index = get_index(lttrs, wrds, sntncs)
    grade(index)


def get_index(letters, words, sentences):
    wp100 = words / 100
    l = letters / wp100
    s = sentences / wp100
    index = round(0.0588 * l - 0.296 * s - 15.8)
    return index


def grade(index):
    if index < 1:
        print('Before Grade 1.')
    elif index >= 16:
        print('Grade 16+')
    else:
        print(f'Grade {index}')


if __name__ == '__main__':
    main()

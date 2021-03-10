import sys

if __name__ == '__main__':
    output_file = sys.argv[1]
    with open(output_file, 'w') as fp:
        fp.write("#pragma once\ninline bool checkIfCorrect() { return true; }\n")
        fp.close()
import re
regex = re.compile("\d+[:]\d\d")
with open("1.txt") as f:
    for line in f:
        print("111")
        result = regex.search(line)
        print(result)

import re

print("test")
with open("1.txt", "r+") as f:
    lines = f.readlines()
    f.seek(0)
    f.truncate()
    for number, line in enumerate(lines):
        x = re.search("\d+[:]\d\d", line)
        print(x)
        if x:
            print(111)


# /\d+[:]\d\d/gm
# "\d+[:]\d\d"gm

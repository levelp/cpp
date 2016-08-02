import os
import sys

PREFIX = u'//*'

sys.stdout = open("README.md", "w", encoding="utf-8")


def parse(file_name):
    """
    :param file_name: имя файла
    :return:
    """
    code = False
    with open(file_name, "r", encoding="utf-8-sig") as f:
        for line in f:
            if '//-->' in line:
                print('``` cpp')
                code = True
                continue
            if '//<--' in line:
                print('```')
                code = False
                continue
            if code:
                print(line.rstrip())
                continue
            if line.startswith(PREFIX):
                print(line[len(PREFIX):].strip())


from os import listdir
from os.path import isfile, join

mypath = "."
extensions = [".cpp", ".c", ".h", ".hpp"]

files = [f for f in listdir(mypath) if isfile(join(mypath, f))]


def get_extension(file_name):
    return os.path.splitext(file_name)[1]


for file_name in files:
    ext = get_extension(file_name)
    if not ext in extensions:
        continue
    parse(file_name)
import os

# os.system("cat 2.txt")
try:
    os.chdir("/home/srinivas/Documents/")
    os.system("pwd")
    os.system("history")
except OSError as e:
    print(e)
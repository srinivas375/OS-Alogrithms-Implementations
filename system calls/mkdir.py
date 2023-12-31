import os

dir = "new_directory"

if os.path.exists(dir):
    print("{} already exists.".format(dir))
else :
    os.mkdir(dir)
    print("new directory named {} has been created.".format(dir))
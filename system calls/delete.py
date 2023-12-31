import os

dir = "new_directory"
copy = "new_directory/copied_file.txt"
new_name = "new_directory/renamed_file.txt"

if os.path.exists(copy):
    os.remove(copy)
    print("the copied file is deleted successfully")
else:
    print("no copied file exists or already deleted.")
    
if os.path.exists(new_name):
    os.remove(new_name)
    print("the file is deleted successfully")
else:
    print("no file exists or already deleted.")

if os.path.exists(dir):
    os.rmdir(dir)
    print("directory has been removed")
else:
    print("no such directory exists.")
import os

new = "new_directory/new_file.txt"
new_name = "new_directory/renamed_file.txt"
if os.path.exists(new):
    os.rename(new,new_name)
else :
    print("no such file exists.")

#copying a file
copy = "new_directory/copied_file.txt"

if not os.path.exists(copy):
    with open(new_name,'r') as file1 , open(copy,'w') as file2:
       file2.write(file1.read())
    print("contents have been copied into new file.")
else:
    print("contents already copied.")
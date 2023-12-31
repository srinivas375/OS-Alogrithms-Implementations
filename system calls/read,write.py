import os

new = "new_directory/new_file.txt"

with open(new,'w') as file:
    file.write("new text has been written")
print("new file created and text written")

#reading the file.
if os.path.exists(new):
    with open(new,'r') as file:
       data = file.read()
    print("the text of the file is :")
    print(data)
else:
    print("there is no such file exists.")
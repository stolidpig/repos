import os, shutil 

print("Select Citrix Destination:")
print("1 - BrightonXA01")
print("2 - BrightonXA02")
print("3 - BrightonXA03")
print("4 - LondonXA01")
print("5 - LondonXA02")
print("6 - LondonXA03")



# Get relevant our paths and directory lists
source = 'C:\DevLib\PyTest\Source'
destination = 'C:\DevLib\PyTest\Destination'
srcdir = os.listdir(source)

# List source files
print("Copying files:")
print(srcdir)
print(len(srcdir), "files found")

# Recursively copy
shutil.copytree(source, destination, dirs_exist_ok=True)

# List destination contents
print()
print("contents of", destination)
print(os.listdir(destination))
print(len(os.listdir(destination)), "files found")
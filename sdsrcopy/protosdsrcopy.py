# importing os & shutil module  
import os, shutil 

def sdsrcopy(source,destination):

    # Get source directory as a list
    srcdir = os.listdir(source)

    # Backup existing files, delete old backup
    backup = destination + "\old"
    try:
        shutil.rmtree(backup)
    except FileNotFoundError:
        print("No old directory")
    shutil.copytree(destination,backup,dirs_exist_ok=True)
  
    # List our source files
    print(len(srcdir), "files found")
    print("Copying files: ") 
    print(srcdir) 


    # Copy the content of source to destination 
    shutil.copytree(source,destination,dirs_exist_ok=True)

    # List our destination files
    print("New Directory:") 
    print(os.listdir(destination)) 
    print(len(os.listdir(destination)), "files found")

# Exit flag
exit = False

while not exit:
    
    # Get our source and destination paths
    source = ''
    destination = ''
    
    # Citrix target
    print("Choose a Citrix endpoint")
    print("BrightonXA01 = 1")
    print("BrightonXA02 = 2")
    print("BrightonXA03 = 3")
    print("LondonXA01 = 4")
    print("LondonXA02 = 5")
    print("LondonXA03 = 6")
    print("Quit = 0")
    
    # Get valid input
    while True:
        try:
            CitrixInput = int(input())
        except ValueError:
            print("Invalid input!")
            continue
        if CitrixInput >= 0 and CitrixInput <= 6:
            break
        else:
            print("Invalid input!")
            continue

    # Set destination or quit
    if CitrixInput == 0: 
        print("Quitting")
        exit = True
        break
    elif CitrixInput == 1:
            destination = "\\\\BrightonXA01\c$"
    elif CitrixInput == 2:
            destination = "\\\\BrightonXA02\c$"
    elif CitrixInput == 3:
            destination = "\\\\BrightonXA03\c$"
    elif CitrixInput == 4:
            destination = "\\\\LondonXA01\c$"
    elif CitrixInput == 5:
            destination = "\\\\LondonXA02\c$"
    elif CitrixInput == 6:
            destination = "\\\\LondonXA03\c$"
    else :
        print("Error")
        exit = True
        break
    
    # Application source
    print("Which application are you updating?")
    print("TINS = 1")
    print("TIN1 = 2")
    print("TIN2 = 3") 
    print("DINS = 4")
    print("DIN1 = 5") 
    print("DIN2 = 6")
    print("Quit = 0")
    
    # Get valid input
    while True:
        try:
            ApplicationInput = int(input())
        except ValueError:
            print("Invalid input!")
            continue
        if ApplicationInput >= 0 and CitrixInput <= 6:
            break
        else:
            print("Invalid input!")
            continue
        
    
    # Set source or quit    
    if ApplicationInput == 0: 
        print("Quitting")
        exit = True
        break
    elif ApplicationInput == 1: 
            source = "\\\\brighton11a\R-Drive\IT\ORBS Testing\ORBS TINS"
            destination += "\ORBS-TINS"
    elif ApplicationInput == 2: 
            source = "\\\\brighton11a\R-Drive\IT\ORBS Testing\ORBS TIN1"
            destination += "\ORBS-TIN1"
    elif ApplicationInput == 3: 
            source = "\\\\brighton11a\R-Drive\IT\ORBS Testing\ORBS TIN2"
            destination += "\ORBS-TIN2"
    elif ApplicationInput == 4: 
            source = "\\\\brighton11a\R-Drive\IT\ORBS Testing\ORBS DINS"
            destination += "\ORBS-DINS"
    elif ApplicationInput == 5: 
            source = "\\\\brighton11a\R-Drive\IT\ORBS Testing\ORBS DIN1"
            destination += "\ORBS-DIN1"
    elif ApplicationInput == 6: 
            source = "\\\\brighton11a\R-Drive\IT\ORBS Testing\ORBS DIN2"
            destination += "\ORBS-DIN2"
    else :
        print("Error")
        exit = True
        break
    
    print("You are about to copy from")
    print(source)
    print("to")
    print(destination)
    print("Continue? y/n")

    ConfirmInput = input()
    if ConfirmInput.strip() == 'y':
        # Copy files
        print("sdsrcopy(source, destination)")
        print("Transfer complete from")
        print(source)
        print("to")
        print(destination)
    else: 
        print("Confirmation failed, quitting")
        exit = True
        break

    print("Quit? y/n")
    QuitInput = input()
    if QuitInput.strip() == 'n':
        continue
    else: 
        print("Quitting")
        exit = True
        break
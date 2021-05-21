# importing os & shutil module  
import os, shutil 

def printTargets():
    print("Choose a Citrix endpoint")
    print("BrightonXA01 = 1")
    print("BrightonXA02 = 2")
    print("BrightonXA03 = 3")
    print("LondonXA01 = 4")
    print("LondonXA02 = 5")
    print("LondonXA03 = 6")
    print("Quit = 0")
def printSources():
    print("Which application are you updating?")
    print("TINS = 1")
    print("TIN1 = 2")
    print("TIN2 = 3") 
    print("DINS = 4")
    print("DIN1 = 5") 
    print("DIN2 = 6")
    print("Quit = 0")
def getInput():
    while True:
        try:
            tempInput = int(input())
        except ValueError:
            print("Invalid input!")
            continue
        if tempInput >= 0 and tempInput <= 6:
            break
        else:
            print("Invalid input!")
            continue
    return tempInput

def actionConfirmed():
    print("You are about to copy from")
    print(source)
    print("to")
    print(destination)
    print("Continue? y/n")
    
    ConfirmInput = input()
    if (ConfirmInput.strip() == 'y'):
        return True
    else :
        return False
def copyFolder(source,destination):
    shutil.copytree(source,destination,dirs_exist_ok=True)
def listFolderContents(folder):
    print(folder) 
    print(os.listdir(folder)) 
    print(len(os.listdir(folder)), "files found")
def createBackup(destination):
    backup = destination + "\old"
    try:
        shutil.rmtree(backup)
    except FileNotFoundError:
        print("No old directory")
    shutil.copytree(destination,backup,dirs_exist_ok=True)
def sdsrcopy(source,destination):
    createBackup(destination)
    listFolderContents(source)
    copyFolder(source,destination)
    listFolderContents(destination)
def userQuit():
    print("Quit? y/n")
    QuitInput = input()
    if QuitInput.strip() == 'n':
        return False
    else: return True

exit = False

while not exit:

    source = ''
    destination = ''
    sources = ["quit",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS TINS",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS TIN1",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS TIN2",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS DINS",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS DIN1",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS DIN2"]
    destinations = ["quit",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\BrightonXA01",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\BrightonXA02",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\BrightonXA03",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\LondonXA01",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\LondonXA02",
    "\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\LondonXA03"]
    destMod = ["null",
    "\ORBS-TINS",
    "\ORBS-TIN1",
    "\ORBS-TIN2",
    "\ORBS-DINS",
    "\ORBS-DIN1",
    "\ORBS-DIN2"]
    
    printTargets()
    CitrixInput = getInput()

    if CitrixInput == 0: 
        print("Quitting")
        exit = True
        break
    elif CitrixInput > 0 and CitrixInput <= 6 :
        destination = destinations[CitrixInput]
    else :
        print("Error")
        exit = True
        break
    
    printSources()
    AppInput = getInput()

    if AppInput == 0: 
        print("Quitting")
        exit = True
        break
    elif AppInput > 0 and AppInput <=6 : 
            source = sources[AppInput]
            destination += destMod[AppInput]
    else :
        print("Error")
        exit = True
        break
    

    if (actionConfirmed()) :
        sdsrcopy(source, destination)
        print("Transfer complete from")
        print(source)
        print("to")
        print(destination)
    else: 
        print("Confirmation failed, quitting")
        exit = True
        break

    if (userQuit()):
        print("Quitting")
        exit = True
        break
    else:
        continue
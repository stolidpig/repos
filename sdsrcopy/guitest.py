# This program was written by Liam Nichol to provide a GUI to a user wanting to update virtualised instances of the business systems application
# A backup will be taken of the destination folder and placed in a */old directory

# Dependancies
import os, shutil
import PySimpleGUI as sg

class sdsrcopy:
    
    # Initialised variables
    values = {}
    dests = []
    destinations = []
    source = ""
    
    # GUI Layout to construct the window with
    # To extend the program additional entries can be added to FrameLayout lists which interact with the program logic via their key variable
    # For additional info see PySimpleGUI docs
    sg.theme('DefaultNoMoreNagging')
    citrixFrameLayout = [
            [sg.Checkbox('BrightonXA01',key='bxa01'),sg.Checkbox('LondonXA01',key='lxa01')],
            [sg.Checkbox('BrightonXA02',key='bxa02'),sg.Checkbox('LondonXA02',key='lxa02')],    
            [sg.Checkbox('BrightonXA03',key='bxa03'),sg.Checkbox('LondonXA03',key='lxa03')]
            ] 
    citrixTargetsLayout = [
        [sg.Frame('Select Citrix Targets',  citrixFrameLayout)],
    ]
    appFrameLayout = [
        [sg.Radio('TINS','AppFrame',key='TINS'),sg.Radio('DINS','AppFrame',key='DINS')],
        [sg.Radio('TIN1','AppFrame',key='TIN1'),sg.Radio('DIN1','AppFrame',key='DIN1')],    
        [sg.Radio('TIN2','AppFrame',key='TIN2'),sg.Radio('DIN2','AppFrame',key='DIN2')]
        ]
    appSourcesLayout = [
        [sg.Frame('Select Application Source',  appFrameLayout)]
    ]
    layout = [citrixTargetsLayout,
            [sg.HSeparator()],
            appSourcesLayout,
            [sg.Submit(),sg.VerticalSeparator(), sg.Cancel()]
        ]
    
    # The following functions should not need changing 

    def addDestination(string):
        sdsrcopy.dests.append(string)
    
    def setSource(string):
        sdsrcopy.source = string
    
    def copyFolder(source,destination):
        shutil.copytree(source,destination,dirs_exist_ok=True)

    def listFolderContents(folder):
        print(folder) 
        print(os.listdir(folder)) 
        print(len(os.listdir(folder)), "files found")

    def createBackup(destination):
        backupFolder = destination + "\old"
        try:
            shutil.rmtree(backupFolder)
        except FileNotFoundError:
            print("No old directory")
        shutil.copytree(destination,backupFolder,dirs_exist_ok=True)
    
    def sdsrcopy(source,destination):
        sdsrcopy.createBackup(destination)
        sdsrcopy.listFolderContents(source)
        sdsrcopy.copyFolder(source,destination)
        sdsrcopy.listFolderContents(destination)

    # To extend the program additional cases will need to be added to below
    
    def appendDestinationTarget(target):
        match target:
            case "TINS":
                sdsrcopy.destinations = [dest + "\ORBS-TINS" for dest in sdsrcopy.dests]
            case "TIN1":
                sdsrcopy.destinations = [dest + "\ORBS-TIN1" for dest in sdsrcopy.dests]
            case "TIN2":
                sdsrcopy.destinations = [dest + "\ORBS-TIN2" for dest in sdsrcopy.dests]
            case "DINS":
                sdsrcopy.destinations = [dest + "\ORBS-DINS" for dest in sdsrcopy.dests]
            case "DIN1":
                sdsrcopy.destinations = [dest + "\ORBS-DIN1" for dest in sdsrcopy.dests]
            case "DIN2":
                sdsrcopy.destinations = [dest + "\ORBS-DIN2" for dest in sdsrcopy.dests]

    # To extend the program additional cases will need to be added to below

    def readinput():
        if sdsrcopy.values['bxa01']:
            sdsrcopy.addDestination("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\BrightonXA01")
        if sdsrcopy.values['bxa02']:
            sdsrcopy.addDestination("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\BrightonXA02")
        if sdsrcopy.values['bxa03']:
            sdsrcopy.addDestination("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\BrightonXA03")
        if sdsrcopy.values['lxa01']:
            sdsrcopy.addDestination("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\LondonXA01")
        if sdsrcopy.values['lxa02']:
            sdsrcopy.addDestination("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\LondonXA02")
        if sdsrcopy.values['lxa03']:
            sdsrcopy.addDestination("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\Destination\LondonXA03")
        if sdsrcopy.values['TINS']:
            sdsrcopy.setSource("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS TINS")
            sdsrcopy.appendDestinationTarget("TINS")
        if sdsrcopy.values['TIN1']:
            sdsrcopy.setSource("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS TIN1")
            sdsrcopy.appendDestinationTarget("TIN1")
        if sdsrcopy.values['TIN2']:
            sdsrcopy.setSource("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS TIN2")
            sdsrcopy.appendDestinationTarget("TIN2")
        if sdsrcopy.values['DINS']:
            sdsrcopy.setSource("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS DINS")
            sdsrcopy.appendDestinationTarget("DINS")
        if sdsrcopy.values['DIN1']:
            sdsrcopy.setSource("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS DIN1")
            sdsrcopy.appendDestinationTarget("DIN1")
        if sdsrcopy.values['DIN2']:
            sdsrcopy.setSource("\\\\b-ws-lnich\c$\PyTest\sdsrcopy\\brighton11a\ORBS DIN2")
            sdsrcopy.appendDestinationTarget("DIN2")

    def invoke():
        # Create window from our layout
        window = sg.Window("sdsrcopy GUI", sdsrcopy.layout, margins=(35, 50))
        
        # Main logic loop
        while True:
            # Ensure we have a fresh state
            sdsrcopy.setSource("")
            sdsrcopy.dests = []
            # For any event that happens, we read the state of the GUI into values as a list of dicts
            event, sdsrcopy.values = window.read()
            match event:
                case sg.WIN_CLOSED: # The event was the window being closed
                    break
                case "Cancel": # The event was the Cancel button being pressed
                    break
                case "Submit": # The event was the Submit button being pressed
                    sdsrcopy.readinput()
                    for dest in sdsrcopy.destinations:
                        sdsrcopy.sdsrcopy(sdsrcopy.source,dest)
                    print("Task Complete")
                    break
        window.close()

sdsrcopy.invoke()
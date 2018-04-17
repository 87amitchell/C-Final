# CPP-Final
Character data entry

## Synopsis & Motivation
I wanted to create a tool to help me in the further develop of a tabletop role-paying system. My goal was to develop a tool that offers the benefits of being able to easily track and coordinate resources and that also offers the open and adaptive nature of tabletop games. I was able to create code within the time given to allow a user to store a character name and character stats. I plan to continue adding a main menu for a user that will display basic character information and that will offer menu options that allow a user to view a list of: combat skills, none-combat skills and inventory items. A user would be able to display the details of these options and utilize, edit or delete any details from these lists.

## Pseudocode overview
```
int main()
{
fileCheckOrCharacterNameEntery(downloadFromFileToProgram/AskEnteryAndUploadToFile, enterAndCheckEntry)
characterStats(downloadFromFileToProgram/AskEnteryAndUploadToFile, enterAndCheckEntry, stateModBonusUploadToFile)
}//end main

Function definitions
```

## Install procedure
NA

## Licensing
I don't want others to use it at this time

## Picture Example
Command prompt
Text file (note: active data would be encoded into the file at the end of the program)

<img src="CPPCommandPrompt.png">

<img src="CPPTextFile.png">

##Feedback Notes

Starting with in the while loop starting on line 165 I added the following code to line 202. 
```
enterAndCheckEntry(entryConfirm, checkString, entryType, callCode);
				characterStats[row][0] = stoi(checkString);
				int tempInt = characterStats[row][0];
				temp = temp + '#' + entryType + ": "+ checkString;
				statsMod(tempInt);//row, characterStats[row][0], characterStats[row][1]);
				characterStats[row][1] = tempInt;
				temp = temp + "#Mod:" + to_string(tempInt);
```
After the end of the while loop I added the following line to add the contents of the entered stats and their modifiers.
```
ofCharacterData << temp;
```
The file creates endless loop because of the way that I encoded the while statement on line 157.

I had realized several potential problems that the way I had coded things could cause. Within my fifteen hours I had started to reorganize my code but had been unable to get it functioning and thus submitted my most recent working code for my final. With the way that I had started to reorganize my code it wouldn't cause a problem in the way that it has.

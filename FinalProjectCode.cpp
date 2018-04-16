#include <iostream>
#include <fstream>
using namespace std;

//function prototypes
void fileCheckOrCharacterNameEntery(char entryConfirm, string &checkString, string &entryType, string &characterName, string &temp, string callCode);
void pleaseEnter(string entryType, string &checkString);
void enterAndCheckEntry(char entryConfirm, string &checkString, string &entryType, string &callCode);
void characterStats(char entryConfirm, string checkString, string entryType, string callCode, string temp, int row, int col);
void statsMod(int &tempInt);

//void editCharacterStats();
//void display();
//void characterInventory();
//void characterSkills();
//void characterCombat();

int main(int argc, char *argv[])
{
	//declare variables
	char entryConfirm = ' ';
	string checkString = "";
	string entryType = "";
	string callCode = "";
	string characterName = "";
	string temp = "";
	//int characterStats[7][2] = {0};
	int row = 0;
	int col = 0;
	// row0 = Str/mod, row1 = Dex/mod, row2 = Con/mod, row3 = Int/mod, row4 = Wis/mod, row5 = Chr/mod,  row6 = HP Max/Temp HP,
	//int tempHP = 0;
	//int AC = 0;
	//int proficiencyBonus 0;	
	
	fileCheckOrCharacterNameEntery(entryConfirm, checkString, entryType, characterName, temp, callCode);
	characterStats(entryConfirm, checkString, entryType, callCode, temp, row, col);
	//void display(void CharacterDetails) (display character details)
	
/*	while(value != 4)
	{
		//void display(callCode(character details)) << endl << endl;
		//void display(callCode(mainMenueOptions(
		//cin >> value;
		entryType = cout << "Enter (1) for Combat options" << endl << "Enter (2) for Inventory << endl << "Enter (3) for Skills options" << endl << "Enter (4) to Save and Exit (sentinelValue) << endl;
		enterAndCheckEntry(char entryConfirm, string &checkString, string &entryType, string &callCode);
		if(value = 1)
		{
			void CombatMenu
		}
		else if(value = 2)
		{
			//void InventoryMenu
		}
		else if(value = 3)
		{
			//void SkillMenu
		}
		//alter enterAndCheckEntry with a valueCheckCode that void errorMessage (entered value)			
	}//end while
	cout << "Files close and saved," << endl << "Program end";
	
	//void display(mainMenue)
	//void display (combat options) (select attack(first redirect to create attack) Create attack, exit to main)
		//enter rolls, auto roll
	//void display(Inventory) (Add/remove Item, select item for edit, exit to main)
	//void display(skills) (select skill(first redirect to create skill) Create skill, exit to main)
		//enter rolls, auto roll
*/
}//end main

//*****function definitions*****
void fileCheckOrCharacterNameEntery(char entryConfirm, string &checkString, string &entryType, string &characterName, string &temp, string callCode)
{
	//declare variables
	ofstream ofCharacterData;
	ifstream ifCharacterData;
			
	//check file open and load character name or create file and add character name
	ifCharacterData.open("characterData.txt", ios::out);			
		
	//load character name
	if (ifCharacterData.is_open())
	{
		while (!ifCharacterData.eof())
		{	
			callCode = "CN";
			ifCharacterData >> temp;
			ifCharacterData.ignore(1);			
			if (callCode == temp)
			{
				ifCharacterData >> characterName;
				ifCharacterData.ignore(1);
			}
			//close file
			ifCharacterData.close();
		}//end while
	}//end if
	
	else //when new character don't exist
	{
		ofCharacterData.open("characterData.txt", ios::out);
		
		if (ofCharacterData.is_open())
		{
			entryType = " a character name";
			enterAndCheckEntry(entryConfirm, checkString, entryType, callCode);
			characterName = checkString;
			ofCharacterData << "CN#" << characterName;
		}//end if
	}//end else
	
	//close file
	ofCharacterData.close();
}//end fileCheckFileOrCharacterNameEntery void

void pleaseEnter(string entryType, string &checkString)
{
	cout << "Please enter" << entryType << endl;
	cin >> checkString;
}//end pleaseEnter void

void enterAndCheckEntry(char entryConfirm, string &checkString, string &entryType, string &callCode)
{
	pleaseEnter(entryType, checkString);
	while (toupper(entryConfirm) != 'Y')
	{
		//visual check for valid entery
		cout << "You entered " << checkString << " as" << entryType << ". Is this correct?" << endl << "Enter Y to continue or N re-enter" << endl;
		cin >> entryConfirm;
		
		//check none-valid entries & re-enter
		while (toupper(entryConfirm) != 'Y' && toupper(entryConfirm) != 'N')
			{
					cout << "Error, you entered " << entryConfirm << ". Please enter a valid character." << endl << "You entered " << checkString << " as" << entryType << ". Is this correct?" << endl << "Enter Y to continue or N re-enter" << endl;
					cin >> entryConfirm;
			}//end wile
		if (toupper(entryConfirm) == 'N')
		{
			pleaseEnter(entryType, checkString);
		}//end if
	}//end while loop
}//end checkEntery void

void characterStats(char entryConfirm, string checkString, string entryType, string callCode, string temp, int row, int col)
{	
	//declare variables
	ofstream ofCharacterData;
	ifstream ifCharacterData;
	int characterStats[7][2] = {0};
	
	//load or enter character stats
	ifCharacterData.open("characterData.txt", ios::out);			
			
	if (ifCharacterData.is_open())
	{
		//search for character stats
		while (!ifCharacterData.eof())
		{	
			callCode = "CS";
			ifCharacterData >> temp;
			ifCharacterData.ignore(1);
			//if callCode found, load data into characterStats double array
			if (callCode == temp)
			{
				while(entryConfirm != 'N')
				{
					ifCharacterData >> characterStats[row][col];
					ifCharacterData.ignore(1);
										
					if(row == 7)
					{
						if (col == 2 && row == 7)
						{
							entryConfirm = 'N';
						}//end if
						col += 1;
						row = 0;
					}//end if
					else 
					{
						row += 1;
					}//end else
				}//end while
			entryConfirm = 'Y';
			}//end if
			
			//if data not present enter stats into double array
			else
			{
				//editCharacterStats()
				cout << "Please enter character stats" << endl;
				//entryType = " character stats";
				//pleaseEnter(entryType, checkString);
				entryType = " character Strenght (Str)";
				row = 0;
				col = 0;
				while (entryConfirm != 'N')
				{
				
				enterAndCheckEntry(entryConfirm, checkString, entryType, callCode);
				characterStats[row][0] = stoi(checkString);
				
				if (entryType == " character Strenght (Str)")
				{
					entryType = " character Dexterity (Dex)";
				}//end if
				else if (entryType == " character Dexterity (Dex)")
				{
					entryType = " character Constitution (Con)";
				}//end if
				else if (entryType == " character Constitution (Con)")
				{
					entryType = " character Intelligence (Int)";
				}//end if
				else if (entryType == " character Intelligence (Int)")
				{
					entryType = " character Wisdom (Wis)";
				}//end if	
				else if (entryType == " character Wisdom (Wis)")
				{
					entryType = " character Charisma (Cha)";
				}//end if
				else if (entryType == " character Charisma (Cha)")
				{
					entryConfirm = 'N';
				}//end if
				int tempInt = characterStats[row][0];
				statsMod(tempInt);//row, characterStats[row][0], characterStats[row][1]);
				characterStats[row][1] = tempInt;
				}//end while
				entryConfirm = 'Y';
				//close file
				ofCharacterData.close();
			}//end else
		}//end while
	}//end if
}//end characterStats void

void statsMod(int &tempInt)//int row, int characterStats[row][0], int (&characterStats)[row][1]);
{
	if (tempInt <= 1)
	{
		tempInt = -5;
	}//end if
	else if (tempInt <= 3)
	{
		tempInt = -4;
	}//end if
	else if (tempInt <= 5)
	{
		tempInt = -3;
	}//end if	
	else if (tempInt <= 7)
	{
		tempInt = -2;
	}//end if	
	else if (tempInt <= 9)
	{
		tempInt = -1;
	}//end if	
	else if (tempInt <= 11)
	{
		tempInt = 0;
	}//end if	
	else if (tempInt <= 13)
	{
		tempInt = 1;
	}//end if	
	else if (tempInt <= 15)
	{
		tempInt = 2;
	}//end if
	else if (tempInt <= 17)
	{
		tempInt = 3;
	}//end if	
	else if (tempInt <= 19)
	{
		tempInt = 4;
	}//end if	
	else if (tempInt <= 21)
	{
		tempInt = 5;
	}//end if	
	else if (tempInt <= 23)
	{
		tempInt = 6;
	}//end if	
	else if (tempInt <= 25)
	{
		tempInt = 7;
	}//end if	
	else if (tempInt <= 27)
	{
		tempInt = 8;
	}//end if	
	else if (tempInt <= 29)
	{
		tempInt = 9;
	}//end if	
	else
	{
		tempInt = 10;
	}//end else
}//end statsMod void



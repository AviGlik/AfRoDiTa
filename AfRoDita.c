#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int getCommand();//÷áìú ô÷åãåú
void getUserName(char* name, DWORD len);//÷áìú ùí äîùúîù
void getComputerDetails(char* name, DWORD len);
void shutdown();//ëéáåé äîçùá
void restart();//äãì÷ä îçãù ùì äîçùá
void getCurrentDirectoryFunc(DWORD len, LPTSTR lpBuffer);
int main()
{
	int get=5;//î÷áì àú äô÷åãä
	DWORD len = 48;
	char* path = (char*)malloc(sizeof(char)*100);//äîé÷åí ùì ä÷åáõ ùìé
	char *userName = (char*)malloc(sizeof(char)*50);//ùí äîùúîù îå÷öä ìå òã 50 úååéí
	char* computerName = (char*)malloc(sizeof(char)*50);//ùí äîçùá îå÷öä ìå òã 50 úååéí
	LPTSTR lpBuffer = (char*)malloc(sizeof(char)*100);
	switch(MessageBox(0,"Becarful, this program may harm your computer.\ndo not allow it if you don't know what it is.", "Warning", MB_YESNO ))// äåãòú ùâéàä
	{
	case IDYES://ìî÷øä ùäîùúîù îæéï áúéáú äàæäøä YES
		{
			//get = getCommand;
			while(get != -1) //ì÷áì ô÷åãåú
			{
				switch (get)//÷øéàä ìôåð÷öéåú áäúàí
				{
				case 1:
					_flushall();
					getUserName(userName,len);
					printf("%s\n",userName);
					break;
				case 2:
					getComputerDetails(computerName,len);
					printf("%s\n",computerName);
					break;
				case 3:
					shutdown();
					break;
				case 4:
					restart();
					break;
				case 5:
					getCurrentDirectoryFunc(len, lpBuffer);
					printf("%s", lpBuffer);
					break;
				case 6:
					break;
				case 7:
					break;
				}
				/*get = getCommand();*/
			}
			break;
			}
		case IDNO://ìî÷øä ùäîùúîù îæéï áúéáú äàæäøä NO
		{
			break;
		}
	}
	system("pause");
	return 0;
}
void getUserName(char* name, DWORD len)
{
	GetUserName(name, &len);//ùí îùúîù ðåëçé
}
void getComputerDetails(char* name, DWORD len)//áòúéã éúååñôå ùí øùí åëúåáú îà÷
{
	GetComputerName(name, &len);// ùí îçùá
}
void shutdown()
{
	 system("C:\\WINDOWS\\System32\\shutdown /s"); //windows 7
	 system("C:\\WINDOWS\\System32\\shutdown -s"); //XP
	 system("shutdown -P now"); // ubuntu
}
void restart()
{
	system("C:\\WINDOWS\\System32\\shutdown /r"); //windows 7
	system("C:\\WINDOWS\\System32\\shutdown -r"); //XP
	system("gksudo shutdown -r"); // ubuntu
}
void getCurrentDirectoryFunc(DWORD len, LPTSTR lpBuffer)
{
	GetCurrentDirectory(len, lpBuffer);
}

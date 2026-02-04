1) Sample.cpp will create a file, donut_success.txt in C:\Windows\Tasks folder and open with notepad
2) It will be compiled into a .exe file and then converted into shellcode with donut.exe
	donut.exe -i [filename] -a 2 -f 6 -o scodecp.ps1 #Used for powershell test
	donut.exe -i [filename] -a 2 -f 7 -o scodecp.cs #Used for appdomain test
3) Powershell test
	- Creating a thread within powershell to run shellcode. Functions are all resolved during run time and did not use Add-Type to run C# code as it will trigger AV

4) AppDomain Manager Injection test
	- Compile tasks.cs file with the shellcode into Tasks.dll 
	- put tasks.dll into C:\Windows\System32\Tasks\Tasks.dll
	- Run the .bat file
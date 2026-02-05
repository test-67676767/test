1) Sample.cpp will create a file, donut_success.txt in C:\Windows\Tasks folder and open with notepad
2) It will be compiled into a .exe file and then converted into shellcode with donut.exe
	donut.exe -i [filename] -a 2 -f 6 -o scodecp.ps1 #Used for powershell test
	donut.exe -i [filename] -a 2 -f 7 -o scodecp.cs #Used for appdomain test
3) Powershell test
	- Creating a thread within powershell to run shellcode. Functions are all resolved during run time and did not use Add-Type to run C# code as it will trigger AV

4) AppDomain Manager Injection test 
	- Compile tasks.cs file with the shellcode into Tasks.dll
	[Method 1] If C:\Windows\System32\Tasks folder is world writeable
	- put tasks.dll into C:\Windows\System32\Tasks\Tasks.dll
	- Run the .bat file

	[Method 2]
	- Copy C:\Windows\System32\UevAppMonitor.exe (or any other .Net executable - tzsync.exe also can) to any random folder
	- paste the application manifest file (UevAppMonitor.exe.config) into the same folder
	- paste tasks.dll into same folder
	- Change the private path in the .config file to the folder tasks.dll is at.
		- If never change i think is still fine as CLR runtime will likely search for tasks.dll in same folder also 
	- Run UevAppMonitor.exe in the folder you copied to


5) AppDomain Manager Injection test with AES encryption to bypass AV static signature detection (Use the the files in appdomain_aes)
	- Convert sample.cpp into shellcode with donut and it will output a .bin file
		- donut.exe -i [filename] -a 2
	- Aes encrypt the .bin file with the encryptor
		- python3 aes_shellcode_encoder.py -cs loader.bin testing123 aes
	- Copy the shellcode part to tasks.cs and compile it
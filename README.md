# C-Basic-RAT
 C Based Remote Access Tool

Video to follow
 
Build Undetectable Malware Using C Language Ethical Hacking on YouTube\n

https://www.youtube.com/watch?v=6Dc8i1NQhCM&t=2686s\n
Learned approach from the above video.
![Alt Pic 1](images/pic1.png)

 
Get current IP Address from server box: 192.168.56.102
 ![Alt Pic 2](images/pic2.png)
 
Server.c
 
![Alt Pic 3](images/pic3.png)
 
Backdoor.c 

Make sure to update server and client programs

 ![Alt Pic 4](images/pic4.png)
Then compile using the above commands on a Linux box.

 

Once compiled, transfer it over.
 ![Alt Pic 5](images/pic5.png)
 ![Alt Pic 6](images/pic6.png)
 



Run server and execute on windows client.  The user will receive window stating "Your Device has been hacked!!!"
Server will receive a shell with the client's Ip Address

![Alt Pic 7](images/pic7.png)

![Alt Pic 8](images/pic8.png)
 
Dir Command

![Alt Pic 9](images/pic9.png)

Dir command

![Alt Pic 10](images/pic10.png)

Previous path
 
![Alt Pic 11](images/pic11.png)

Whoami command
 
![Alt Pic 12](images/pic12.png)
 
Keylogger is executed on server side
 
![Alt Pic 13](images/pic13.png)

The client opens up notepad by pressing the windows button and search for notepad. Once notepad is found, it is clicked and the user types "Hello World"
 
![Alt Pic 14](images/pic14.png)

Once the user starts typing, it starts logging the keys pressed in a file called windows.txt in the directory it was executed.  In this case, it is the IEUser user directory.
 
![Alt Pic 15](images/pic15.png)

If persist command is ran, it creates a regedit key to the run directory to auto run the program when windows boots up.

![Alt Pic 16](images/pic16.png)
 
Connection is re-established after logging in.

![Alt Pic 17](images/pic17.png)
 
When user inserts q, it will close connection
 


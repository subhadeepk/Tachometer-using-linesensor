# Tachometer-using-linesensor

The idea is pretty simple. A linesensor detects a dark patch or a dark color whenever it is at a certain distance from it. So if you attach a darp patch on a motor and hold a linesensor near it's body, it should detect the dark patch get in it's view once every rotation(and it will see it go away from it's view once). 

So, if we interface the linesensor with an arduino, it'll trigger a signal everytime a dark patch get's in it's view. Take the CPU time elapsed between two successive triggers and you'll get the rpm of the rotating motor. 

I have tested this with a real setup and it works fine. 

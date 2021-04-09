# Tello
> Created By: `Karan Singh`.
####  Librabry to controll Dji Tello
As there was no library available to control the Tello DJI drone by nodemcu or by Arduino, there was only 1 library founded, but even that was not working, so i have created a library from the scratch.


## Usage
This library includes a class "Tello"
- First, make an object of the class Tello
    ```sh
    Tello tello;
    ```
- Then you call init function to initialize it. In setup loop
    ```sh
    void setup(){
        .....
        tello.init();
    }
    ```
-  Then for take-off simply call takeoff
    ```sh
    tello.takeoff();
    ```
- And for landing 
    ```sh
    tello.land();
    ```
And of course Dillinger itself is open source with a [public repository][dill]
 on GitHub.

## Installation
##### Download, This library either by zip or by git.
##### Then add the tello file in Arduino library, located in Document -> Arduino -> Library.

## Funtions

| Funtion | Discribtion |
| ------ | ------ |
| takeoff() | To take-off |
|  land() |For Tello auto land |
| startVideoStream() | video stream on |
| stopVideoStream() | Set video stream off |
| turnOff() | Stop all motors immediately |
| up(int x) | Tello fly up with distance x cm(min:20cm , max = 500 cm) |
|down(int x)|Tello fly down with distance x cm(min:20cm , max = 500 cm)|
|left(int x)|Tello fly left with distance x cm(min:20cm , max = 500 cm)|
|right(int x)|Tello fly right with distance x cm(min:20cm , max = 500 cm)|
|forward(int x)|Tello fly forward with distance x cm(min:20cm , max = 500 cm)|
|back(int x)|Tello fly back with distance x cm(min:20cm , max = 500 cm)|
|rotate_clockwise(int deg)|Tello rotate x degree clockwise(min:1, max:3600)|
|rotate_anticlockwise(int deg)|Tello rotate x degree counter-clockwise	(min:1, max:3600)|
|flip_front()|Ask Tello to flip front|
|flip_right()|Ask Tello to flip Right|
|flip_left()|Ask Tello to flip Left|
|bool flip_back()|Ask Tello to flip Back|
|setSpeed(int x)|Set speed to x cm/s|
|sendRCcontrol(int x,int y,int z)|Send RC control via four channels(left/right (-100-100), forward/backward (-100-100), up/down (-100-100)) ,yaw (-100-100)|
|changeWifi(string ssid, string password)|Set Wi-Fi with SSID password(Works only with EDU version, so havent tested)|
|int getSpeed()|Get Speed|
|Get Battery level percentage|getBattery()|
| getTime()|Get Current Flying time|
|getHeight()|Get current flying height|
|getTemperature()|Get temperature (°C)|
## Development
Want to contribute? Great!
I will be availabe, making sure it always kept updated.

#### some of the best youtube channel to learn Dji tello drone coading:
Here's the [link](https://youtu.be/LmEcyQnfpDA)

## License

**Free Software, Hell Yeah!**




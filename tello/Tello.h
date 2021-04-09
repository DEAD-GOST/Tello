#include <String>
#include <String.h>
#include <WiFiUDP.h>
#include <ESP8266WiFi.h>

using namespace std;

class Tello {
private:
  /* data */
 String msg="";
 const char* TELLO_IP = "192.168.10.1";
 const int PORT = 8889;
 WiFiUDP Udp;
 char packetBuffer[255]; //buffer to hold incoming packet
 int networkState = 0;
 bool check_range(int x, int min, int max)
{
  return (min < x && x < max);
}
public:
  bool connected = false;

  // Funtions
  void sendMessage(String command) {
    Udp.beginPacket(TELLO_IP, PORT);
    // Udp.write(ReplyBuffer);
    Udp.write((const unsigned char*)command.c_str(), command.length());
    Udp.endPacket();
  }
  String listenMessage() {
    int packetSize = Udp.parsePacket();
    if (packetSize) {
      Serial.print("Received packet of size ");
      Serial.println(packetSize);
      Serial.print("From ");
      IPAddress remoteIp = Udp.remoteIP();
      Serial.print(remoteIp);
      Serial.print(", port ");
      Serial.println(Udp.remotePort());

      // read the packet into packetBufffer
      int len = Udp.read(packetBuffer, 255);
      if (len > 0) {
        packetBuffer[len] = 0;
      }
      Serial.println("Contents:");
      Serial.println(packetBuffer);
    }
    // this only works as tello's API doesn't return responses greater than 255 char
    return (char*) packetBuffer;
  }
  void connect() {
    Udp.begin(PORT);
    sendMessage("command");
  }
  void init(){
    connect();
  }
  void takeoff(){
    sendMessage("takeoff");
    msg = listenMessage();
    Serial.println(msg);
  }
  void land(){
    sendMessage("land");
    msg = listenMessage();
    Serial.println(msg);
  }
  void get_battery(){
    sendMessage("battery?");
    msg = listenMessage();
    Serial.print("battery : ");
    Serial.println(msg);
  }
  void startVideoStream()
  {
    sendMessage("streamon");
    msg = listenMessage();
    Serial.println(msg);
  }
  void stopVideoStream()
  {
    sendMessage("streamoff");
    msg = listenMessage();
    Serial.println(msg);
  }
  void  turnOff()
  {
    sendMessage("emergency");
    msg = listenMessage();
    Serial.println(msg);
  }
  void up(int x)
{
	char buff[10];
	string command = "up " + string(itoa(x,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void down(int x)
{
	char buff[10];
	string command = "down " + string(itoa(x,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void left(int x)
{
	char buff[10];
	string command = "left " + string(itoa(x,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void right(int x)
{
	char buff[10];
	string command = "right " + string(itoa(x,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void forward(int x)
{
	char buff[10];
	string command = "forward " + string(itoa(x,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void back(int x)
{
	char buff[10];
	string command = "back " + string(itoa(x,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void rotate_clockwise(int deg)
{
	char buff[10];
	string command = "cw " + string(itoa(deg,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void rotate_anticlockwise(int deg)
{
	char buff[10];
	string command = "ccw " + string(itoa(deg,buff,10));
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void flip_front()
{
  sendMessage("flip f");
  msg = listenMessage();
  Serial.println(msg);
}
void flip_right()
{
  sendMessage("flip r");
  msg = listenMessage();
  Serial.println(msg);
}
void flip_left()
{
  sendMessage("flip l");
  msg = listenMessage();
  Serial.println(msg);
}
void flip_back()
{
  sendMessage("flip b");
  msg = listenMessage();
  Serial.println(msg);
}
void setSpeed(int x)
{
	char buff[10];
	string command = "speed " + string(itoa(x,buff,10));
	string response ;
	if((x < 10) || (x > 100))
	{
		//cout << "speed out of range " << endl;
		return false;
	}

  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void changeWifi(string ssid, string password)
{
	string command = "wifi "+ ssid + " " +password;
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void getSpeed()
{
	string command = "speed?";
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);

}
void getTime()
{
	string command = "time?";
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void getHeight()
{
	string command = "height?";
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void getAcceleration()
{
	string command = "acceleration?";
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
void getWifiSnr()
{
	string command = "wifi?";
  sendMessage(command);
  msg = listenMessage();
  Serial.println(msg);
}
  //“a” = left/right (-100-100)
  //“b” = forward/backward (-100-100)
  //“c” = up/down (-100-100)
  //“d” = yaw (-100-100)
 void sendRCcontrol(int a, int b, int c, int d)
  {
  if(!(check_range(a, -100, 100)) || !(check_range(b, -100, 100)) || !(check_range(c, -100, 100)) || !(check_range(d, -100, 100)))
  {
    Serial.println("Wrong Input for RC control, Range -100 to 100") ;
  }
  char buff[10];
  String _a = String(itoa(a, buff, 10));
  String _b = String(itoa(b, buff, 10));
  String _c = String(itoa(c, buff, 10));
  String _d = String(itoa(d, buff, 10));
  _a += " ";
  _b += " ";
  _c += " ";
  String command = "rc " + _a + _b + _c+ _d;
  sendMessage(command);
  msg = listenMessage();
  }
};

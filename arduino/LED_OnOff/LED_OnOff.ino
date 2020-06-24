//define
int led = 13;
char cmd;
//setup
void setup()
{
	pinMode(led, OUTPUT);
	Serial.begin(9600);
}

//loop
void loop()
{
	if(Serial.available()>0){
		cmd=Serial.read();

		switch (cmd) {
		    case 'O':
		    case 'o':
		    case 's':
		      digitalWrite(led, HIGH);
		      Serial.println("LED is turned on!");
		      break;
		    case 'X':
		    case 'x':
		    case 'e':
		      digitalWrite(led, LOW);
		      Serial.println("LED is turned off!");
		      break;
		    default:
		      Serial.println("Ignore, input O or X only!");
		}
	}
}
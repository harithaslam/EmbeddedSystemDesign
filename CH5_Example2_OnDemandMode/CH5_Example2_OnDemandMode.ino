/*
   This program continuously prints out the analog
   value of PC3 through the serial prot
    clock speed: 16MHz
    desired clock speed of ADC is 125kHz
    AVCC as analog reference
    on-demand mode
*/
volatile unsigned char *admux = 0x7C;
volatile unsigned char *adcsra = 0x7A;
volatile unsigned char *adch = 0x79;
volatile unsigned char *adcl = 0x78;

void setup() {
  *admux = 0b01000011; // analog ref refs01, analog source mux 0011
  *adcsra = 0b11000111; //Turn on ADEN, ADSC and ADPS
  Serial.begin(9600);

}
void loop() {
  *adcsra |= 0b01000000; //ADC Start Conversion
  while (((*adcsra) & 0b01000000))
  {
    //wait while start conversion
  }
  int lowbyte = *adcl; //capture low byte
  int highbyte = *adch; // capture high byte
  int value = (highbyte << 8) | lowbyte; // merge them
  Serial.println(value);
}

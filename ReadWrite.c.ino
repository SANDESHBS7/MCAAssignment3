#include<EEPROM.h>
int eeprom_Memory_address = 0; 
int read_eepromDATA = 0; 
char serialDATA_to_write;
int write_memoryLED = 13; 
int end_memoryLED = 12; 
int eeprom_size = 1024; 

void setup() {
pinMode(write_memoryLED,OUTPUT); 
pinMode(end_memoryLED, OUTPUT); 
Serial.begin(9600); 
Serial.println(); 
Serial.println("The previous text saved in the EEPROM was: "); 
for(eeprom_Memory_address = 0; eeprom_Memory_address < eeprom_size; eeprom_Memory_address ++)
{
  read_eepromDATA = EEPROM.read(eeprom_Memory_address); 
  Serial.write(read_eepromDATA); 
}

Serial.println(); 
Serial.println(); 

for(eeprom_Memory_address = 0; eeprom_Memory_address < eeprom_size; eeprom_Memory_address ++)
{
 EEPROM.write(eeprom_Memory_address, " ");  
}
Serial.println("EEPROM memory is Erased."); 
Serial.println(); 
Serial.println("Write you new text :"); 
Serial.println(); 

for ( eeprom_Memory_address = 0; eeprom_Memory_address < eeprom_size;)
{
  if ( Serial.available())
  {
    serialDATA_to_write = Serial.read();
    Serial.write(serialDATA_to_write); 
    EEPROM.write(eeprom_Memory_address, serialDATA_to_write);
    eeprom_Memory_address++; 
    digitalWrite(write_memoryLED, HIGH); 
    delay(50); 
    digitalWrite(write_memoryLED, LOW); 
  }
}


}

void loop() {


}
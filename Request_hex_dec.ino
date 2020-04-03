void setup() {
  //Setup block
 Serial.begin(9600);
  while (!Serial) {
    ;
  }

  //Message refining
  String modbusMessage = "0011 0004 006B 0003 7687";
  String messageArray[modbusMessage.length()-1];
  int arrayLength = modbusMessage.length()-1;
  int s=0 ;
  String refMessage;
  
   for(int i =0; i < arrayLength; i++){
     if(!isWhitespace(modbusMessage[i])){
      refMessage = refMessage + modbusMessage[i];
     }
     
   }
  //End message refining
  
  //Separating message ID hex
  Serial.println(refMessage);
  String slaveIDhex;
  for(int i=0;i<4;i++){
     slaveIDhex = slaveIDhex + refMessage[i];
     
  }
  
  //Convert hex ID into decimal
  (char*) slaveIDhex.c_str();
    int x;
    char *endptr;
  
  x = strtol((char*) slaveIDhex.c_str(), &endptr, 16);
  Serial.print("Slave addres: ");
  Serial.println(x, DEC);
  //End separating

  //Separating Function Code
  String functionCodeHex;
  for(int i=4;i<8;i++){
     functionCodeHex = functionCodeHex + refMessage[i];
     
  }
  
  (char*) functionCodeHex.c_str();
    
  
  x = strtol((char*) functionCodeHex.c_str(), &endptr, 16);
  
  String fucntionString = String(x,DEC);
  Serial.print("Function Code type: ");
  switch (x) {
  case 1:
    Serial.println("Read Coil Status");
    break;
  case 2:
    Serial.println("Read Input Status");
    break;
  case 3:
    Serial.println("Read Holding Registers");
   break;
  case 4:
    Serial.println("Read Input Registers");
    break;
  case 5:
    Serial.println("Force Single Coil");
    break;
   case 6:
    Serial.println("Preset Single Register");
   break;
    case 15:
    Serial.println("Force Multiple Coils");
    break;
   case 16:
    Serial.println("Preset Multiple Registers");
   break;
  default:
    // if nothing else matches, do the default
    // default is optional
    break;
}
  //End


  //address of the first register
  String firstRegisterAdd;
  for(int i=8;i<12;i++){
     firstRegisterAdd = firstRegisterAdd + refMessage[i];
     
  }
  
  (char*) firstRegisterAdd.c_str();
    
  
  x = strtol((char*) firstRegisterAdd.c_str(), &endptr, 16);
  Serial.print("Address of first register: ");
  Serial.println(x,DEC);
  //End

   //number of required registers
  String noRegisters;
  for(int i=12;i<16;i++){
     noRegisters = noRegisters + refMessage[i];
     
  }
  
  (char*) noRegisters.c_str();
    
  
  x = strtol((char*) noRegisters.c_str(), &endptr, 16);
  Serial.print("Number of required registers: ");
  Serial.println(x,DEC);
  //End
  
  
 
}

void loop() {
 
 

  
}

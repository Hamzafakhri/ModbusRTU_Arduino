  void setup() {
  //Setup block
 Serial.begin(9600);
  while (!Serial) {
    ;
  }

  //Message refining
  String modbusMessage = "11 06 00 01 00 03 9A 9B ";
  String messageArray[modbusMessage.length()];
  int arrayLength = modbusMessage.length();
  int s=0 ;
  String refMessage;
  
   for(int i =0; i < arrayLength; i++){
     if(!isWhitespace(modbusMessage[i])){
      refMessage = refMessage + modbusMessage[i];
     }
     
   }
  //End message refining
 
  //Separating slave ID hex
  Serial.println(refMessage);
  String slaveIDhex;
  for(int i=0;i<2;i++){
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
  for(int i=2;i<4;i++){
     functionCodeHex = functionCodeHex + refMessage[i];
     
  }
  
  (char*) functionCodeHex.c_str();
    
  
  x = strtol((char*) functionCodeHex.c_str(), &endptr, 16);
  
  String fucntionString = String(x,DEC);
  Serial.print("function code: ");
  Serial.println(x,DEC);
  

  // Function Code 01
  if(x==1){
    
  
    //address of the first register
  String noOfBytes;
  for(int i=4;i<6;i++){
     noOfBytes = noOfBytes + refMessage[i];
     
  }
  
  (char*) noOfBytes.c_str();
    
  
  x = strtol((char*) noOfBytes.c_str(), &endptr, 16);

  Serial.print("no of bytes: ");
  Serial.println(x,DEC);
  int noBytes = x;
  String DO;
  int initalCounter = 6;
  int finalCounter =0;
  for(int i =0;i<noBytes;i++){
    finalCounter= initalCounter +2;
    for(int count =initalCounter;count<finalCounter;count++){
        
        DO = DO + refMessage[count];
       (char*) DO.c_str();
        
  
        x = strtol((char*) DO.c_str(), &endptr, 16);
      
       
    }
     Serial.print("Register value Digital Output : ");
     Serial.println(DO);
     Serial.print("Register value  : ");
     Serial.println(x,DEC);
    initalCounter = finalCounter;
    DO ="";
  }

  String CRCI;
  for(int i= finalCounter;i<finalCounter+2;i++){
    CRCI = CRCI + refMessage[i];
  }
      
      Serial.print("CRCI Hex  : ");
     Serial.println(CRCI);
      finalCounter= finalCounter+2;
      
      String CRCII;
  for(int i= finalCounter;i<finalCounter+2;i++){
    
    CRCII = CRCII + refMessage[i];
  }
      
      Serial.print("CRCII Hex  : ");
     Serial.println(CRCII);
     
  
  }
//End


  // Function code 02
  if(x==2){
    

     //address of the first register
  String noOfBytes2;
  for(int i=4;i<6;i++){
     noOfBytes2 = noOfBytes2 + refMessage[i];
     
  }
  
  (char*) noOfBytes2.c_str();
    
  
  x = strtol((char*) noOfBytes2.c_str(), &endptr, 16);

  Serial.print("no of bytes: ");
  Serial.println(x,DEC);
  int noBytes2 = x;
  String DI;
  int initalCounter2 = 6;
  int finalCounter2 =0;
  for(int i =0;i<noBytes2;i++){
    finalCounter2= initalCounter2 +2;
    for(int count =initalCounter2;count<finalCounter2;count++){
        
        DI = DI + refMessage[count];
       (char*) DI.c_str();
        
  
        x = strtol((char*) DI.c_str(), &endptr, 16);
      
       
    }
     Serial.print("Register value Digital Output : ");
     Serial.println(DI);
     Serial.print("Register value  : ");
     Serial.println(x,DEC);
    initalCounter2 = finalCounter2;
    DI ="";
  }

  String CRCI2;
  for(int i= finalCounter2;i<finalCounter2+2;i++){
    CRCI2 = CRCI2 + refMessage[i];
  }
      
      Serial.print("CRCI Hex  : ");
     Serial.println(CRCI2);
      finalCounter2= finalCounter2+2;
      
      String CRCII2;
  for(int i= finalCounter2;i<finalCounter2+2;i++){
    CRCII2 = CRCII2 + refMessage[i];
  }
      
      Serial.print("CRCII Hex  : ");
     Serial.println(CRCII2);
   }
   // End


  // Function code 03
 if(x==3){
    
  
   
     //address of the first register
  String noOfBytes2;
  for(int i=4;i<6;i++){
     noOfBytes2 = noOfBytes2 + refMessage[i];
     
  }
  
  (char*) noOfBytes2.c_str();
    
  
  x = strtol((char*) noOfBytes2.c_str(), &endptr, 16);

  Serial.print("no of bytes: ");
  Serial.println(x,DEC);
  int noBytes2 = x;
  String AO;
  int initalCounter2 = 6;
  int finalCounter2 =0;
  int charCount =0;
  for(int i =0;i<noBytes2;i++){
    finalCounter2= initalCounter2 +2;
    for(int count =initalCounter2;count<finalCounter2;count++){
        
        AO = AO + refMessage[count];
       (char*) AO.c_str();
        
  
        x = strtol((char*) AO.c_str(), &endptr, 16);
      
       
    }
    if(charCount % 2 ==0 ){
      
     Serial.print("Register value AO HI : ");
    }else{
      Serial.print("Register value AO LO : ");
    }
     Serial.println(AO);
     Serial.print("Register value  : ");
     Serial.println(x,DEC);
    initalCounter2 = finalCounter2;
    AO ="";
    charCount +=1;
  }

  String CRCI2;
  for(int i= finalCounter2;i<finalCounter2+2;i++){
    CRCI2 = CRCI2 + refMessage[i];
  }
      
      Serial.print("CRCI Hex  : ");
     Serial.println(CRCI2);
      finalCounter2= finalCounter2+2;
      
      String CRCII2;
  for(int i= finalCounter2;i<finalCounter2+2;i++){
    CRCII2 = CRCII2 + refMessage[i];
  }
      
      Serial.print("CRCII Hex  : ");
     Serial.println(CRCII2);
   }
   // End
   
  
  // Function code 04
 if(x==4){
    
  
   
     //address of the first register
  String noOfBytes2;
  for(int i=4;i<6;i++){
     noOfBytes2 = noOfBytes2 + refMessage[i];
     
  }
  
  (char*) noOfBytes2.c_str();
    
  
  x = strtol((char*) noOfBytes2.c_str(), &endptr, 16);

  Serial.print("no of bytes: ");
  Serial.println(x,DEC);
  int noBytes2 = x;
  String AI;
  int initalCounter2 = 6;
  int finalCounter2 =0;
  int charCount =0;
  for(int i =0;i<noBytes2;i++){
    finalCounter2= initalCounter2 +2;
    for(int count =initalCounter2;count<finalCounter2;count++){
        
        AI = AI + refMessage[count];
       (char*) AI.c_str();
        
  
        x = strtol((char*) AI.c_str(), &endptr, 16);
      
       
    }
    if(charCount % 2 ==0 ){
      
     Serial.print("Register value AI HI : ");
    }else{
      Serial.print("Register value AI LO : ");
    }
     Serial.println(AI);
     Serial.print("Register value  : ");
     Serial.println(x,DEC);
    initalCounter2 = finalCounter2;
    AI ="";
    charCount +=1;
  }

  String CRCI2;
  for(int i= finalCounter2;i<finalCounter2+2;i++){
    CRCI2 = CRCI2 + refMessage[i];
  }
      
      Serial.print("CRCI Hex  : ");
     Serial.println(CRCI2);
      finalCounter2= finalCounter2+2;
      
      String CRCII2;
  for(int i= finalCounter2;i<finalCounter2+2;i++){
    CRCII2 = CRCII2 + refMessage[i];
  }
      
      Serial.print("CRCII Hex  : ");
     Serial.println(CRCII2);
   }
   // End


   // Function code 05
 if(x==5){
    
  
   
     //address of the first register
  String addresHI;
  for(int i=4;i<6;i++){
     addresHI = addresHI + refMessage[i];
     
  }
  
  (char*) addresHI.c_str();
    
  
  x = strtol((char*) addresHI.c_str(), &endptr, 16);

  Serial.print("Address of the first register HI bytes: ");
  Serial.println(x,DEC);

  String addresLO;
  for(int i=6;i<8;i++){
     addresLO = addresLO + refMessage[i];
     
  }
  
  (char*) addresLO.c_str();
    
  
  x = strtol((char*) addresLO.c_str(), &endptr, 16);

  Serial.print("Address of the first register LO bytes: ");
  Serial.println(x,DEC);

  String valueHI;
  for(int i=8;i<10;i++){
     valueHI = valueHI + refMessage[i];
     
  }
  
  (char*) valueHI.c_str();
    
  
  x = strtol((char*) valueHI.c_str(), &endptr, 16);

  Serial.print("Value of Hi bytes: ");
  Serial.println(x,DEC);

  String valueLO;
  for(int i=10;i<12;i++){
     valueLO = valueLO + refMessage[i];
     
  }
  
  (char*) valueLO.c_str();
    
  
  x = strtol((char*) valueLO.c_str(), &endptr, 16);

  Serial.print("Value of Lo bytes: ");
  Serial.println(x,DEC);
  


  
  String CRCI2;
  for(int i= 12;i<14;i++){
    CRCI2 = CRCI2 + refMessage[i];
  }
      
      Serial.print("CRCI Hex  : ");
     Serial.println(CRCI2);
    
      
      String CRCII2;
  for(int i= 14;i<16;i++){
    CRCII2 = CRCII2 + refMessage[i];
  }
      
      Serial.print("CRCII Hex  : ");
     Serial.println(CRCII2);
   }
   // End


    // Function code 06
 if(x==6){
    
  
   
     //address of the first register
  String addresHI;
  for(int i=4;i<6;i++){
     addresHI = addresHI + refMessage[i];
     
  }
  
  (char*) addresHI.c_str();
    
  
  x = strtol((char*) addresHI.c_str(), &endptr, 16);

  Serial.print("Address of the first register HI bytes: ");
  Serial.println(x,DEC);

  String addresLO;
  for(int i=6;i<8;i++){
     addresLO = addresLO + refMessage[i];
     
  }
  
  (char*) addresLO.c_str();
    
  
  x = strtol((char*) addresLO.c_str(), &endptr, 16);

  Serial.print("Address of the first register LO bytes: ");
  Serial.println(x,DEC);

  String valueHI;
  for(int i=8;i<10;i++){
     valueHI = valueHI + refMessage[i];
     
  }
  
  (char*) valueHI.c_str();
    
  
  x = strtol((char*) valueHI.c_str(), &endptr, 16);

  Serial.print("Value of Hi bytes: ");
  Serial.println(x,DEC);

  String valueLO;
  for(int i=10;i<12;i++){
     valueLO = valueLO + refMessage[i];
     
  }
  
  (char*) valueLO.c_str();
    
  
  x = strtol((char*) valueLO.c_str(), &endptr, 16);

  Serial.print("Value of Lo bytes: ");
  Serial.println(x,DEC);
  


  
  String CRCI2;
  for(int i= 12;i<14;i++){
    CRCI2 = CRCI2 + refMessage[i];
  }
      
      Serial.print("CRCI Hex  : ");
     Serial.println(CRCI2);
    
      
      String CRCII2;
  for(int i= 14;i<16;i++){
    CRCII2 = CRCII2 + refMessage[i];
  }
      
      Serial.print("CRCII Hex  : ");
     Serial.println(CRCII2);
   }
   // End

   
   

  }
 

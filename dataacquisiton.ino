double tensao, leituratemp, convtemp; //Setting reading and conversion variables
float V, Vmed, tensao1, Imed, I, corrente, Pi, Pu,  correntegraf, tensaograf, corrente1, tempo; //Setting reading and conversion variables
int i,c; //Setting index control variables
unsigned long milisegundos; //Setting timing variable

void setup()
      {
	 		Serial.begin(9600); //Starting serial communication
           	Serial.print("Leitura de Tensão (V):"); //Voltage Title
           	Serial.print("\t");
			Serial.print("\t");
           	Serial.print("Leitura de Corrente (A):"); //Current Title
           	Serial.print("\t");
           	Serial.print("\t");
           	Serial.print("Temperatura (°C):"); //Temperature Title
           	Serial.print("\t");
           	Serial.print("\t");
           	Serial.print("Tempo (s):"); //Time Title      
	}

void loop() 
      {  
          // Data Acquition and conversion
          V = analogRead(A7); //Analog reading of voltage. It outputs a value between 0 and 1023 bits.
          tensao = 0.0048 * v + 0.0195; //Converting the bits value reading to voltage reading using a previously defined equation
          tensao1 = tensao * 3.21428571428571; //Value correction

          I = analogRead(A1)-512; //Analog reading of voltage. It outputs a value between 0 and 1023 bits. Since the sensor range is from -30 A to +30 A, the value 512 is the sensor 0A reading.
          corrente = 0.0258 * corrente + 0.0504; //Converting the bits value reading to current reading using a previously defined equation
          corrente1 = corrente1 * 0.804; //Value correction
           
          leituratemp = analogRead(A6); //Analog reading of temperature. It outputs a value between 0 and 1023 bits.
          convtemp = leituratemp * 0.00488 * 100; //Converting the bits value reading to ºC, using LM35 sensor convertion equation (see LM35 datasheet)

          milisegundos = millis(); //Timing in milliseconds
          tempo = (milisegundos/1000); //Conversion to seconds

          // Printing data in IDE's Serial Monitor to posterior analysis
          Serial.print(tensao1); //Print voltage value (V)
          Serial.print("\t");
		Serial.print("\t");
		Serial.print("\t");
          Serial.print(corrente1); //Print current value (A)
          Serial.print("\t");
		Serial.print("\t");
		Serial.print("\t");
          Serial.print(convtemp); //Print temperature value (ºC)
          Serial.print("\t");
          Serial.print("\t");
		Serial.print("\t");
		Serial.print(tempo); //Print instant time value (s)
          Serial.println("");          
      }


int val;
float kPa;

//Deklaraasi Injector 40 kPa
unsigned int durasi1 = 1;
unsigned int durasi2 = 3;
int s1 = durasi1;
int s2 = durasi2;

//Deklaraasi Injector 40 kPa
float durasi3 = 0.5;
unsigned int durasi4 = 3;
float s3 = durasi1;
int s4 = durasi2;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  val = analogRead(A0);
  kPa = ((float)val/(float)1023+0.095)/0.009;

 //Output Serial
 Serial.print("kPa : ");
 Serial.println(kPa); 
 delay (1000);
  
  //Durasi Injector Menyala dan Mati
  
  //Injector dengan kPa 40
    if (kPa >= 40 && kPa <= 41){
      //LED Menyla
      //for (s2;s2 > 0 ;s2--){
      Serial.println("Injector Hidup");
      for (s1 = 1;s1 < 4;s1++){
      digitalWrite(6,HIGH);
      Serial.print("kPa : ");
      Serial.print(kPa);
      Serial.print("  Durasi : ");
      Serial.print(s1);
      Serial.println(" mS");
      delay(1000);
    }
    if (kPa >= 40 && kPa <= 41){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}

    //Injector dengan kPa 90
    if (kPa >= 90 && kPa <= 91){
      //LED Menyla
      //for (s4;s4 > 0 ;s4--){
      Serial.println("Injector Hidup");
      for (s3 = -0.5;s3 < 8;s3++){
      digitalWrite(6,HIGH);
      Serial.print("kPa : ");
      Serial.print(kPa);
      Serial.print("  Durasi : ");
      Serial.print(s3);
      Serial.println(" mS");
      delay(1000);
    }
    if (kPa >= 90 && kPa <= 91){
      //LED Mati
      digitalWrite(6,LOW);
      Serial.println("Injector Mati");
      Serial.println("   ");
      delay(700);
    }}
}

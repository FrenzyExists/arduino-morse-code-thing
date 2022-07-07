// Morse Code thing, my second sketch

const char* chars[] = { 
"-----", // 0 48
".----", // 1 49
"..---", // 2 50
"...--", // 3 51
"....-", // 4 52
".....", // 5 53
"-....", // 6 54
"--...", // 7 55
"---..", // 8 56
"----.", // 9 57
"",
"",
"",
"",
"",
"..--..", // ? 63
"",
".-",    // A 0 65 
"-...",  // B 1
"-.-.",  // C 3
"-..",   // D 4
".",     // E 5
"..-.",  // F 6
"--.",   // G 7
"--.",   // H 8
"..",    // I 9
".---",  // J 10
"-.-",   // K 11
".-..",  // L 12
"--",    // M 13
"-.",    // N 14
"---",   // O 15
".--.",  // P 16
"--.-",  // Q 17
".-.",   // R 18
"...",   // S 19
"-",     // T 20
"..-",   // U 21
"...-",  // V 22
".--",   // W 23
"-..-",  // X 24
"-.--",  // Y 25
"--.."   // Z 26
};

const int dit = 110;
const int dah = dit*3;
const int sil = 60;

void lights(int delay_time) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(delay_time);
      digitalWrite(LED_BUILTIN, LOW);
      delay(sil);
}

int converter(char* m_input) {
  int i;
  for (i = 0; m_input[i] != '\0'; ++i) {
    if (m_input[i] == '.') {
      lights(dit);
    } else if (m_input[i] == '-') {
      lights(dah);
    } else if (m_input[i] == ' ') {
      delay(dit);
    } else if (m_input[i] == '/') {
      delay(sil*2);
    }
  }
}

void ascii_converter(String t_input) {
  int t[t_input.length()], i = 0, j;
  memset( t, 0, t_input.length()*sizeof(int) );

  while(t_input[i] != '\0') {
    t[i]= t_input[i]; i++;
  }
  for (j = 0; j < i - 1; j++) {
    int w = t[j];
    if (w-48 >= 0) {
    Serial.print(chars[w-48]);
    converter(chars[w-48]);
    }
    if (w == 32) {
      Serial.print("/");
      converter("/");
    }
    if (j < i) {Serial.print(" "); converter(" ");};
  }
  Serial.print("\n");
}

void setup() {
  // set the digital pin as output:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    String ch = Serial.readString();
    ch.toUpperCase();
    ascii_converter(ch);
  }
}


#include <MyHttpClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char MY_SSID[] = "";
const char WPA_PASSWORD[] = "";

const String KEY = "";

MyHttpClient myHttpClient;

DynamicJsonDocument doc(128 * 16);

String district[50];
int total_district;

void getDistricts() {
  String url = "http://api.airvisual.com/v2/cities?state=Bangkok&country=Thailand&key=" + KEY;
  myHttpClient.get(url.c_str());
  deserializeJson(doc, myHttpClient.getResponse());
  //Serial.println(myHttpClient.getResponse());
  total_district = doc["data"].size();
  for (int i = 0; i < total_district; i++) {
    String s = doc["data"][i]["city"];
    district[i] = s;
    Serial.println(district[i]);
  }
}

String urlencode(String str) {
  String encodedString = "";
  char c;
  char code0;
  char code1;
  char code2;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == ' ') {
      encodedString += '+';
    } else if (isalnum(c)) {
      encodedString += c;
    } else {
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) > 9) {
        code1 = (c & 0xf) - 10 + 'A';
      }
      c = (c >> 4) & 0xf;
      code0 = c + '0';
      if (c > 9) {
        code0 = c - 10 + 'A';
      }
      code2 = '\0';
      encodedString += '%';
      encodedString += code0;
      encodedString += code1;
      //encodedString+=code2;
    }
    yield();
  }
  return encodedString;

}
String getAQI(String city) {
  String url = "http://api.airvisual.com/v2/city?city={city}&state=Bangkok&country=Thailand&key=" + KEY;
  url.replace("{city}", urlencode(city));
  Serial.println(city);
  Serial.println(myHttpClient.get(url.c_str()));
  String r = myHttpClient.getResponse();
  Serial.println(r);
  return r;
}

void setup() {
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();

  myHttpClient.setup(MY_SSID, WPA_PASSWORD);

  getDistricts();
}

int map2(int val, int min, int max, int slot) {
   return map(val, min, max, 0, slot-1);
}

void loop() {
  static int index = -1;

  int analogVal = analogRead(A0);
  if (index == map2(analogVal, 0, 1023, total_district)) {
    delay(200);
    return;
  }
  index = map2(analogVal, 0, 1023, total_district);
  
  String result = getAQI(district[index]);
  deserializeJson(doc, result);
  int aqi = doc["data"]["current"]["pollution"]["aqius"];
  Serial.println(aqi);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(district[index]);
  lcd.setCursor(0, 1);
  if (myHttpClient.getHttpCode() == 200) {
    lcd.print(aqi);
  } else {
    lcd.print("N/A");
  }
  //index++;
  //if (index == total_district) index = 0;
  //delay(3000);
}

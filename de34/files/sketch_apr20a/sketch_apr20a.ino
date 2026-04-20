#include <Adafruit_NeoPixel.h>

#define PIN 9
#define NUMPIXELS 5
#define SENSOR A1

int brightness = 50;
bool wasDark = false; // 前の状態を記録

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 5色
uint32_t colors[5];

void setup() {
  pixels.begin();
  pixels.setBrightness(brightness);

  Serial.begin(9600);
  randomSeed(analogRead(0));

  colors[0] = pixels.Color(255, 0, 0);   // 赤
  colors[1] = pixels.Color(0, 255, 0);   // 緑
  colors[2] = pixels.Color(0, 0, 255);   // 青
  colors[3] = pixels.Color(255, 255, 0); // 黄
  colors[4] = pixels.Color(255, 0, 255); // 紫
}

void loop() {

  int val = analogRead(SENSOR);
  Serial.println(val);

  // 暗いかどうか判定（ここは環境に合わせて調整）
  bool isDark = (val < 300);

  // 明るいとき → 消灯
  if (!isDark) {
    pixels.clear();
    pixels.show();
  }

  // 🌙 暗くなった瞬間だけ実行
  if (isDark && !wasDark) {

    int selected[NUMPIXELS];

    // ランダム表示（1回）
    for (int i = 0; i < NUMPIXELS; i++) {
      selected[i] = random(0, 5);
      pixels.setPixelColor(i, colors[selected[i]]);
    }
    pixels.show();

    delay(500);

    // 揃ってるか判定
    bool allSame = true;
    for (int i = 1; i < NUMPIXELS; i++) {
      if (selected[i] != selected[0]) {
        allSame = false;
        break;
      }
    }

    // 🎉 当たり → 点滅
    if (allSame) {
      for (int j = 0; j < 5; j++) {
        pixels.clear();
        pixels.show();
        delay(150);

        for (int i = 0; i < NUMPIXELS; i++) {
          pixels.setPixelColor(i, colors[selected[0]]);
        }
        pixels.show();
        delay(150);
      }
    }
  }

  // 状態更新（これが超重要）
  wasDark = isDark;

  delay(100);
}
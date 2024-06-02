#include <Adafruit_GFX.h> // Подключаем библиотеку для работы с дисплеем
#include <Adafruit_SSD1306.h> // Подключаем библиотеку для работы с дисплеем
#include <Wire.h> // Подключаем библиотеку для работы с шиной I2C

#define SCREEN_WIDTH 128 // Ширина OLED-дисплея в пикселях
#define SCREEN_HEIGHT 32 // Высота OLED-дисплея в пикселях
#define OLED_RESET -1 // Код сброса дисплея

int irsensor = 6; // Вывод OUT на модуле подключен к выходу 6 Arduino
int prevData = 0; // Переменная для хранения предыдущих показаний
int sensorvalue; // Переменная для хранения показаний датчика
int count = 0; // Переменная для хранения количества людей

AdafruitSSD1306 display(SCREENWIDTH, SCREENHEIGHT, &Wire, OLEDRESET); //Объявляем имя и задаем параметры

void setup() { 
  Serial.begin(9600); // Задаем скорость передачи данных
  pinMode(irsensor,INPUT); // Установим вывод irsensor как вход

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Инициализируем дисплей
  display.display(); //Показываем дисплей
  delay(2000); // Пауза для инициализации дисплея

  display.clearDisplay(); //Очищаем дисплей
  display.setTextSize(2); //Указываем размер шрифта
  display.setTextColor(WHITE); //Указываем цвет текста
  display.setCursor(1,10); //Задаем координату начала текста в пикселях
  display.println("Hello user"); //Пишем сам текст
  display.display(); //Показываем дисплей
  delay(2000); // Пауза для инициализации дисплея
}

void loop() {
  sensorvalue = digitalRead(irsensor); //Условие проверки предыдущего значения цикла с нынешним. 
  
  if (prevData == 1 && sensorvalue == 0) {
    count += 1;
    prevData = sensorvalue; //Обновляем значение переменной предыдущих показаний

    display.clearDisplay(); //Очищаем дисплей
    display.setTextSize(2); //Указываем размер шрифта
    display.setTextColor(WHITE); //Указываем цвет текста
    display.setCursor(5,5); //Задаем координату начала текста в пикселях
    display.print("Humans:"); //Выводим напись "Humans" на дисплей
    display.println(count); //Рядом м надписью выводим количество людей

display.display(); //Показываем дисплей
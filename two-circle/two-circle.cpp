// Визначити в скількох точках перетинаються два кола.
//input:6 чисел x1, y1, r1, x2, y2, r2, де x1, y1, x2, y2, - координати центрів кіл, r1, r2 – їх радіуси. Всі числа - дійсні, не перевищують 1000000000 за модулем, та задані не більш ніж з 3 знаками після коми.
//output:Кількість точок перетину. Якщо точок перетину нескінченно багато, то вивести -1.
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double Points(float x1, float y1, float r1, float x2, float y2, float r2) {//оголошуємо функцію пошуку точок перетину
    double d= abs(sqrt(pow((x2 - x1), 2)+ pow((y2 - y1), 2)));//знаходимо відстань між центрами кіл
    if (x1 == x2 and y1 == y2 and r1 == r2) return -1;//при даній умові, два кола є концентричними та однакові, тому мають безліч точок перетину
    if (d == (r1 + r2) or d == (r1 - r2)) return 1;//при даній умові, кола мають зовнішній та внутрішній дотик- тобто одну точку перетину
    if (d <= (r1 + r2) ) return 2;//при даній умові, кола перетинаються в двох точках
    if (d >= (r1 + r2) or d <= (r1 - r2)) return 0;//при даній умові, кола не перетинаються
}
int main()
{   ifstream fileIn;//використовуємо для зчитування даних з файлу
    string Path = "C:/Users/Яна/Desktop/point.txt ";//шлях до файлу
    fileIn.open(Path);//відкриваємо файл за вказаним шляхом
    float  x1, y1, r1, x2, y2, r2;
    cout << "Enter the first point's coordinates" << endl;
    fileIn >> x1;//координати першої точки- зчитування даних з файлу
    fileIn >> y1;//координати першої точки
    cout << x1 <<"\t" << y1 << endl;
    cout << "Enter the second point's coordinates" << endl;
    fileIn >> x2;//координати другої точки
    fileIn >> y2;//координати другої точки
    cout << x2 << "\t" << y2 << endl;
    cout << "Enter radius of the first and the second circle" << endl;//радіус першого та другого кола 
    fileIn >> r1;//радіус першого кола
    fileIn >> r2;//радіуc другого кола
    cout << r1 << "\t" << r2 << endl;
    fileIn.close();//закриваємо файл	
   ofstream file;//використовуємо для запису даних у файлу
   string path = "C:/Users/Яна/Desktop/circle.txt ";//шлях до файлу
   file.open(path);//відкриваємо файл за вказаним шляхом
   if (!file.is_open()) cout << "Didn't open" << endl;//якщо файл не видкривається- виводимо повідомлення про це
   else {
       cout << "File is open" << endl;//якщо файл  видкривається- виводимо повідомлення про це
       file<< "Circles're  crossing in  " << Points(x1, y1, r1, x2, y2, r2) << "  points" << endl;//вводимо значення функції у файл
   }
   file.close();//закриваємо файл
}



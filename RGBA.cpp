#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

enum class PrintType {E_RGBA, E_HEX, E_INT};

class RGBA
{
    private:
        int r, g, b, a;

    public:

        RGBA()
        {
            r = 40;
            g = 15;
            b = 75;
            a = 255;
        }

        virtual void printInfo()
        {
            cout << "RGBA" << endl;
        }

        virtual void print()
        {
            cout << r << " " << g << " " << b << " " << a << endl;
        }

        virtual void setColor0()
        {
            r = g = b = a = 0;
            cout << "Color value set to = 0" << endl;
        }

        void setColor255(int rM, int gM, int bM, int aM = 255)
        {
            r = rM;
            g = gM;
            b = bM;
            a = aM;
            cout << "Color value set to = 255" << endl;
        }

        virtual void red()
        {
            cout << "Meaning of red = " << r << endl;
        }

        virtual void green()
        {
            cout << "Meaning of green = " << g << endl;
        }

        virtual void blue()
        {
            cout << "Meaning of blue = " << b << endl;
        }

        virtual void alpha()
        {
            cout << "Meaning of transparency = " << a << endl;
        }

        void PrintTy(PrintType type)
        {
            if (type == PrintType::E_RGBA) 
                cout << "RBGA values = " << r << " " << g << " " << b << " " << a << " " << endl;
    
            if (type == PrintType::E_HEX) 
                cout << "Meaning of colors in hex = " << hex << r << " " << g << " " << b << " " << a << dec << endl;
    
            if (type == PrintType::E_INT)
            {
                cout << "Color value in int = " << bitset<8>(r) << " " << bitset<8>(g) << " " << bitset<8>(b) << " " << bitset<8>(a) << endl;
            }
        }

};

class RGB: public RGBA
{
    private:
        int r, g, b;

    public:

        RGB()
        {
            r = 35;
            g = 30;
            b = 80;
        }

        virtual void printInfo() override
        {
            cout << "RGB" << endl;
        }

        virtual void print() override
        {
            cout << r << " " << g << " " << b << endl;
        }

        virtual void setColor0() override
        {
            r = g = b = 0;
            cout << "Color value set to = 0" << endl;
        }

        virtual void red() override
        {
            cout << "Meaning of red = " << r << endl;
        }

        virtual void green() override
        {
            cout << "Meaning of green = " << g << endl;
        }

        virtual void blue() override
        {
            cout << "Meaning of blue = " << b << endl;
        }

};

int main()
{
    RGBA color255;
    color255.printInfo();
    color255.print();
    color255.setColor255(255, 255, 255, 255);
    color255.red();
    color255.green();
    color255.blue();
    color255.alpha();
    cout << "---------" << endl;
    RGBA color0;
    color255.printInfo();
    color0.print();
    color0.setColor0();
    color0.red();
    color0.green();
    color0.blue();
    color0.alpha();
    cout << "---------" << endl;
    RGBA colorT;
    colorT.printInfo();
    colorT.PrintTy(PrintType::E_RGBA);
    colorT.PrintTy(PrintType::E_HEX);
    colorT.PrintTy(PrintType::E_INT);
    cout << "---------" << endl;
    RGB colorRGB;
    color255.printInfo();
    colorRGB.print();
    colorRGB.setColor0();
    colorRGB.red();
    colorRGB.green();
    colorRGB.blue();
    cout << "---------" << endl;

    RGBA* p1; RGB* p2;

    p1 = &color0; p2 = &colorRGB;

    vector<RGBA*> vec{p1, p2};
    for (size_t i = 0; i < vec.size() ; ++i)
    {
        vec[i]->printInfo();
    }
    
    return 0;
}
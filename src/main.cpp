#include "lib/FEHLCD.h"

int main()
{
    LCD.WriteLine("Hello World!");
    while (true)
    {
        LCD.Update();
        // Never end
    }

    return 0;
}

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    for (;;) {
    int heigh = get_int("Введите число");
    if (heigh == 1) {
        printf(" #  #\n");
        break;
    }
    if (heigh == 2) {
        printf("  #  #\n ##  ##\n");
        break;
    }
    if (heigh == 3) {
        printf("   #  #\n  ##  ##\n ###  ###\n");
        break;
    }
    if (heigh == 4) {
        printf("    #  #\n   ##  ##\n  ###  ###\n ####  ####\n");
        break;
    }
    if (heigh == 5) {
        printf("     #  #\n    ##  ##\n   ###  ###\n  ####  ####\n #####  #####\n");
        break;
    }
    if (heigh == 6) {
        printf("      #  #\n     ##  ##\n    ###  ###\n   ####  ####\n  #####  #####\n ######  ######\n");
        break;
    }
    if (heigh == 7) {
        printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n");
        break;
    }
    if (heigh == 8) {
        printf("        #  #\n       ##  ##\n      ###  ###\n     ####  ####\n    #####  #####\n   ######  ######\n  #######  #######\n ########  ########\n");
        break;
    }
    if (heigh < 1 && heigh > 8) {
        printf("Введите число от 1 до 8");
        continue;
    }
    }
}

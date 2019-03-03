/* 11037 在霍格沃茨找零钱 （20 分）
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long int galleon;
    long int sickle;
    long int knut;
} Money;

long int get_knut_from_money(Money money)
{
    return money.galleon * 17 * 29 + money.sickle * 29 + money.knut;
}

Money get_money_from_knut(long int knut)
{
    Money money;
    money.knut = knut % 29;
    money.sickle = knut / 29 % 17;
    money.galleon = knut / 29 / 17;
    return money;
}

int main(int argc, char *argv[])
{
    // 处理输入
    Money payable, paid;
    if (scanf("%ld.%ld.%ld %ld.%ld.%ld", &payable.galleon, &payable.sickle, &payable.knut, &paid.galleon, &paid.sickle, &paid.knut) != 6)
        return EXIT_FAILURE;
    // 计算找零
    int charge_knut = get_knut_from_money(paid) - get_knut_from_money(payable);
    int is_enough = charge_knut >= 0 ? 1 : -1;
    charge_knut = is_enough * charge_knut;
    Money charge = get_money_from_knut(charge_knut);
    // 处理输出
    if (is_enough == -1)
    {
        printf("-");
    }
    printf("%ld.%ld.%ld", charge.galleon, charge.sickle, charge.knut);

    return EXIT_SUCCESS;
}

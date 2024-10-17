#include <iostream>

void main()
{
    setlocale(LC_ALL, "ru");

    int juiceChoice, discountPrice = 500, discount = 13;
    int litreChoice;
    int apple = 90, orange = 100, apricot = 110, pear = 150;
    int tomato = 70, onion = 60, ququmber = 85;
    int garlic = 180, parsley = 190;
    float result{}, minusResult{}, parsleyDiscount = 5, minusParsley{}, minusOnion{};
    int luckyLitre = 4;
    char continuation;
    float sum{}, sumDiscount{};

    do
    {


        do
        {

            std::cout << "Добро пожаловать в магазин СОК НИКИТЫ\n";
            std::cout << "Вам будет предложен ассортимент напитков, просим вас указать номер выбранного товара\n";
            std::cout << "Фруктовые соки:\n";
            std::cout << "1. Яблочный - 90р./л\n2. Апельсиновый - 100р./л\n3. Абрикосовый - 110р./л\n4. Грушевый - 150р./л\n\n";
            std::cout << "Овощные соки:\n";
            std::cout << "5. Томатный - 70р./л\n6. Луковый - 60р./л\n7. Огуречный - 85р./л\n\n";
            std::cout << "Чаи:\n";
            std::cout << "8. Чесночный - 180р./л\n9. Петрушевый - 190р./л\n";

            std::cin >> juiceChoice;

            if (juiceChoice < 1 || juiceChoice > 9)
            {
                do
                {
                    std::cout << "Неверно введен номер товара, введите номер еще раз\n";
                    std::cin >> juiceChoice;
                } while (juiceChoice < 1 || juiceChoice > 9);
            }



            std::cout << "Введите количество литров:";
            std::cin >> litreChoice;

            if (litreChoice < 1)
            {
                do
                {
                    std::cout << "Неверно введено количество литров, введите снова\n";
                    std::cin >> litreChoice;
                } while (litreChoice < 1);
            }

            if (juiceChoice == 1)
            {
                result = apple * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 2)
            {
                result = orange * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 3)
            {
                result = apricot * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 4)
            {
                result = pear * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 5)
            {
                result = tomato * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 6)
            {
                if (litreChoice >= luckyLitre)
                {
                    result = (litreChoice - (litreChoice / luckyLitre)) * onion;
                    minusOnion = (litreChoice * onion) - result;
                    sum += result;
                    sumDiscount += minusOnion;
                }
                else
                {
                    result = onion * litreChoice;
                    sum += result;
                }
            }
            else if (juiceChoice == 7)
            {
                result = ququmber * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 8)
            {
                result = garlic * litreChoice;
                sum += result;
            }
            else if (juiceChoice == 9)
            {
                if (litreChoice >= 3)
                {
                    minusParsley = result * parsleyDiscount / 100;
                    result = result - minusParsley;
                    sum += result;
                    sumDiscount += minusParsley;
                }
                else
                {
                    result = parsley * litreChoice;
                    sum += result;
                }
            }

            if (result > discountPrice)
            {
                minusResult = result * discount / 100;
                result = result - minusResult;
                sum += result;
                sumDiscount += minusResult;
            }
            std::cout << "Желате продолжить? Введите y - если да, или n - если желаете выйти\n";
            std::cin >> continuation;
        } while (continuation == 'y');

        std::cout << "Итого к оплате: " << sum << " р." << " с учетом скидки в " << sumDiscount << " p.\n\n";

        std::cout << "Следующий покупатель, будете заказывать? Введите y - если да, или n - если желаете выйти\n";
        std::cin >> continuation;
    } while (continuation == 'y');
}
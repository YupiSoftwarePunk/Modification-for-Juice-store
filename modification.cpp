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

            std::cout << "����� ���������� � ������� ��� ������\n";
            std::cout << "��� ����� ��������� ����������� ��������, ������ ��� ������� ����� ���������� ������\n";
            std::cout << "��������� ����:\n";
            std::cout << "1. �������� - 90�./�\n2. ������������ - 100�./�\n3. ����������� - 110�./�\n4. �������� - 150�./�\n\n";
            std::cout << "������� ����:\n";
            std::cout << "5. �������� - 70�./�\n6. ������� - 60�./�\n7. ��������� - 85�./�\n\n";
            std::cout << "���:\n";
            std::cout << "8. ��������� - 180�./�\n9. ���������� - 190�./�\n";

            std::cin >> juiceChoice;

            if (juiceChoice < 1 || juiceChoice > 9)
            {
                do
                {
                    std::cout << "������� ������ ����� ������, ������� ����� ��� ���\n";
                    std::cin >> juiceChoice;
                } while (juiceChoice < 1 || juiceChoice > 9);
            }



            std::cout << "������� ���������� ������:";
            std::cin >> litreChoice;

            if (litreChoice < 1)
            {
                do
                {
                    std::cout << "������� ������� ���������� ������, ������� �����\n";
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
            std::cout << "������ ����������? ������� y - ���� ��, ��� n - ���� ������� �����\n";
            std::cin >> continuation;
        } while (continuation == 'y');

        std::cout << "����� � ������: " << sum << " �." << " � ������ ������ � " << sumDiscount << " p.\n\n";

        std::cout << "��������� ����������, ������ ����������? ������� y - ���� ��, ��� n - ���� ������� �����\n";
        std::cin >> continuation;
    } while (continuation == 'y');
}
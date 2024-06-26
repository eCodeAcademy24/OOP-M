//Да се креира класа PositiveIntegers во која што ќе се чуваат информации за:
//
// низа од позитивни броеви (>0) (динамички алоцирана низа од цели броеви)
// број на елементи во низата
// максимален капацитет на низата
// За класата да се имплементираат:
//
// потребниот конструктор (погледнете во главната функција како се креира објект од оваа класа)
// метод void increaseCapacity(int c) којшто го зголемува максималниот капацитет на низата за бројот с
// оператор за додавање на нов број во низата од позитивни броеви +=
// број се додава ако и само ако
// оператор за множење * за множење на низата со друг цел број
// Пример, низата има објекти (1 2 3 4 5) и истата се множи со 2, резултатот ќе биде (1 2 3 4 5)*2 = (2 3 6 8 10)
// оператор за делење \ за делење на низата до друг цел број
// потребно е секој елемент од низата да биде делив со тој број, како и делителот не смее да биде нула.
// оператор [] за пристап до елемент од низата
// Потребно е да се дефинираат класи за исклучоци и секој од нив да има метод void message() којшто ќе принта соодветна
// порака кога исклучокот ќе биде фатен. Можните исклучоци се следните:
//
// ArithmeticException (се фрла ако се проба да се дели со нула)
// принта порака Division by zero is not allowed
// NumbersNotDivisibleException (се фрла ако се проба да се дели низата со некој број, а барем еден елемент од низата
// не е делив со тој број)
// принта порака Division by number [делителот] is not supported
// ArrayFullException (се фрла ако се проба да се додади елемент во низа која и е исполнет максималниот капацитет)
// принта порака The array is full. Increase the capacity
// IndexOutOfBoundsException (се фрла доколку се проба да се пристапи до елемент од низата со несоодветен индекс)
// принта порака Index [индексот] is out of bounds
// NumberIsNotPositiveException (се фрла доколку се проба да се внесе во низата број што не е позитивен или е нула)
// принта порака Number [бројот] is not positive integer.
#include <iostream>
#include <cstring>
using namespace std;

class ArithmeticException
{
public:
    ArithmeticException() {}
    void print()
    {
        cout<<"Division by zero is not allowed"<<endl;
    }
};
class NumbersNotDivisibleException
{
private:
    int n;
public:
    NumbersNotDivisibleException(int n)
    {
        this->n = n;
    }
    void print()
    {
        cout<<"Division by "<<n<<" is not supported"<<endl;
    }
};
class ArrayFullException
{
public:
    ArrayFullException() {}
    void print()
    {
        cout<<"The array is full. Increase the capacity"<<endl;
    }
};
class IndexOutOfBoundsException
{
private:
    int index;
public:
    IndexOutOfBoundsException(int index)
    {
        this->index = index;
    }
    void print()
    {
        cout<<"Index "<<index<<" is out of bounds"<<endl;
    }
};
class NumberIsNotPositiveException
{
private:
    int n;
public:
    NumberIsNotPositiveException (int n)
    {
        this->n = n;
    }
    void print()
    {
        cout<<"Number "<<n<<" is not positive integer"<<endl;
    }
};

class PositiveIntegers
{
private:
    int *array;
    int numbers;
    int capacity;
public:
    PositiveIntegers ()
    {
        capacity = 0;
        array = new int[0];
        numbers = 0;
    }
    PositiveIntegers(int capacity)
    {
        this->capacity = capacity;
        array = new int[0];
        numbers = 0;
    }
    PositiveIntegers (int *array, int numbers, int capacity)
    {
        this->numbers = numbers;
        this->array = new int[numbers];
        for(int i=0; i<numbers; i++)
        {
            this->array[i] = array[i];
        }
        this->capacity = capacity;
    }
    PositiveIntegers (const PositiveIntegers &pi)
    {
        numbers = pi.numbers;
        array = new int[pi.numbers];
        for(int i=0; i<pi.numbers; i++)
        {
            array[i] = pi.array[i];
        }
        capacity = pi.capacity;
    }
    PositiveIntegers operator= (const PositiveIntegers &pi)
    {
        if(this!=&pi)
        {
            delete[]array;
            numbers = pi.numbers;
            array = new int[pi.numbers];
            for(int i=0; i<pi.numbers; i++)
            {
                array[i] = pi.array[i];
            }
            capacity = pi.capacity;
        }
        return *this;
    }
    void increaseCapacity(int c)
    {
        capacity+=c;
    }
    PositiveIntegers& operator+= (int nov)
    {
        if(numbers == capacity)
            throw ArrayFullException();
        if(nov<=0)
            throw NumberIsNotPositiveException(nov);
        int i;
        int *tmp = new int[numbers+1];
        for(i=0; i<numbers; i++)
        {
            tmp[i] = array[i];
        }
        tmp[numbers] = nov;
        delete[] array;
        numbers++;
        array = new int[numbers];
        for(i=0; i<numbers; i++)
        {
            array[i] = tmp[i];
        }
        return *this;
    }
    PositiveIntegers operator* (int broj)
    {
        PositiveIntegers nov(*this);
        for(int i=0; i<numbers; i++)
            nov.array[i] *= broj;
        return nov;
    }
    PositiveIntegers operator/(int broj)
    {
        PositiveIntegers nov(*this);
        if(broj==0)
            throw ArithmeticException();
        for(int i=0; i<nov.numbers; i++)
        {
            if(nov.array[i]%broj!=0)
                throw NumbersNotDivisibleException(broj);
            nov.array[i]/=broj;
        }
        return nov;
    }
    int& operator[] (int i) const
    {
        if(i>=numbers || i<0)
            throw IndexOutOfBoundsException(i);
        return array[i];
    }

    void print()
    {
        cout<<"Size: "<<numbers<<" Capacity: "<<capacity<<" Numbers: ";
        for(int i=0; i<numbers; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

};
int main()
{

    int n,capacity;
    cin >> n >> capacity;
    PositiveIntegers pi (capacity);
    for (int i=0; i<n; i++)
    {
        int number;
        cin>>number;
        try
        {
            pi+=number;
        }
        catch (ArrayFullException afe)
        {
            afe.print();
        }
        catch (NumberIsNotPositiveException nnpe)
        {
            nnpe.print();
        }

    }
    cout<<"===FIRST ATTEMPT TO ADD NUMBERS==="<<endl;
    pi.print();
    int incCapacity;
    cin>>incCapacity;
    pi.increaseCapacity(incCapacity);
    cout<<"===INCREASING CAPACITY==="<<endl;
    pi.print();

    int n1;
    cin>>n1;
    for (int i=0; i<n1; i++)
    {
        int number;
        cin>>number;
        try
        {
            pi+=number;
        }
        catch (ArrayFullException afe)
        {
            afe.print();
        }
        catch (NumberIsNotPositiveException nnpe)
        {
            nnpe.print();
        }
    }
    cout<<"===SECOND ATTEMPT TO ADD NUMBERS==="<<endl;

    pi.print();
    PositiveIntegers pi1;

    cout<<"===TESTING DIVISION==="<<endl;

    try
    {
        pi1 = pi/0;
        pi1.print();
    }
    catch (ArithmeticException ae)
    {
        ae.print();
    }
    catch (NumbersNotDivisibleException nnde)
    {
        nnde.print();
    }

    try
    {
        pi1 = pi/1;
        pi1.print();
    }
    catch (ArithmeticException ae)
    {
        ae.print();
    }
    catch (NumbersNotDivisibleException nnde)
    {
        nnde.print();
    }


    try
    {
        pi1 = pi/2;
        pi1.print();
    }
    catch (ArithmeticException ae)
    {
        ae.print();
    }
    catch (NumbersNotDivisibleException nnde)
    {
        nnde.print();
    }


    cout<<"===TESTING MULTIPLICATION==="<<endl;
    pi1 = pi*3;
    pi1.print();


    cout<<"===TESTING [] ==="<<endl;
    try
    {
        cout<<"PositiveIntegers[-1] = "<<pi[-1]<<endl;
    }
    catch(IndexOutOfBoundsException iobe)
    {
        iobe.print();
    }
    try
    {
        cout<<"PositiveIntegers[2] = "<<pi[2]<<endl;
    }
    catch(IndexOutOfBoundsException iobe)
    {
        iobe.print();
    }
    try
    {
        cout<<"PositiveIntegers[3] = "<<pi[3]<<endl;
    }
    catch(IndexOutOfBoundsException iobe)
    {
        iobe.print();
    }
    try
    {
        cout<<"PositiveIntegers[12] = "<<pi[12]<<endl;
    }
    catch(IndexOutOfBoundsException iobe)
    {
        iobe.print();
    }


    return 0;
}


//Input
// 6
// 3
// 1
// -10
// 0
// 2
// 3
// 4
// 3
// 5
// 0
// -5
// 1
// -2
// 3
//Output
// Number -10 is not positive integer
// Number 0 is not positive integer
// The array is full. Increase the capacity
// ===FIRST ATTEMPT TO ADD NUMBERS===
// Size: 3 Capacity: 3 Numbers: 1 2 3
// ===INCREASING CAPACITY===
// Size: 3 Capacity: 6 Numbers: 1 2 3
// Number 0 is not positive integer
// Number -5 is not positive integer
// Number -2 is not positive integer
// ===SECOND ATTEMPT TO ADD NUMBERS===
// Size: 5 Capacity: 6 Numbers: 1 2 3 1 3
// ===TESTING DIVISION===
// Division by zero is not allowed
// Size: 5 Capacity: 6 Numbers: 1 2 3 1 3
// Division by 2 is not supported
// ===TESTING MULTIPLICATION===
// Size: 5 Capacity: 6 Numbers: 3 6 9 3 9
// ===TESTING [] ===
// PositiveIntegers[-1] = Index -1 is out of bounds
// PositiveIntegers[2] = 3
// PositiveIntegers[3] = 1
// PositiveIntegers[12] = Index 12 is out of bounds
